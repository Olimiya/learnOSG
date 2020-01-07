#include "pickhandler.h"
#include <QtCore>
#include <QDebug>
#include <osgGA/AnimationPathManipulator>

PickHandler::PickHandler(): m_bPick(false), m_bFirstPush(false),
    size(1.0) ,sec(0.9)
{
    point = new osg::Vec3Array;
}

void PickHandler::setSecondsPerMeter(double s)
{
    sec = s ;
}
double PickHandler::getSecondsPerMeter()
{
    return sec ;
}
bool PickHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
{
    mv = dynamic_cast<osgViewer::View*>(&aa);
    if(!mv)
        return false;

    switch(ea.getEventType())
    {
        case osgGA::GUIEventAdapter::KEYDOWN:
        {
            qDebug() << "enter";
            auto k = ea.getKey();
            qDebug() << k;

            if (ea.getKey()== 111)//键盘o
            {
                qDebug() << "start";
                m_bPick = true;
            }
            else if (ea.getKey()== 112)//键盘p
            {
                qDebug() << "paint path";
                if(!point->size())
                    break;
                this->pushCardinal();
            }
            else if (ea.getKey()== 91)//键盘[
            {
                qDebug() << "paint animation";
                if(!point->size())
                    break;
                this->CreatePath("test.path");
                osg::ref_ptr<osgGA::AnimationPathManipulator> amp = new osgGA::AnimationPathManipulator(
                                                                        "test.path");
                mv->setCameraManipulator(amp.get ()) ;
            }
            else if (ea.getKey()== 93)//键盘]
            {
                qDebug() << "end";
                m_bPick = false;
            }
        }
            break;
        case(osgGA::GUIEventAdapter::PUSH):
        {
            if(m_bPick)
            {
                if (mv)
                    pick(mv,ea);
            }
            break;
        }
        default:
            break;
    }
    return false;
}

void PickHandler::pick(osgViewer::View* viewer, const osgGA::GUIEventAdapter& ea)
{
    osgUtil::LineSegmentIntersector::Intersections intersections;

    osg::Group* root = dynamic_cast<osg::Group*>(viewer->getSceneData());
    if (!root) return;

    if (viewer->computeIntersections(ea,intersections))
    {
        auto hitr = intersections.begin();
        osg::Vec3f temp(hitr ->getWorldIntersectPoint()) ;
        if (!m_bFirstPush)
        {
            point ->clear () ;
            point ->push_back (osg::Vec3f(temp.x(), temp.y(), 3)) ;
            ctrlPoints = DrawFirstNode(temp) ;
            root ->addChild( ctrlPoints.get() );
            m_bFirstPush = true ;
        }
        else
        {
            point ->push_back (osg::Vec3f(temp.x(), temp.y(), 3)) ;
            ctrlPoints ->addChild( DrawCtrlPoints(temp));
        }
    }
}

osg::Group* PickHandler::DrawFirstNode(osg::Vec3f position)
{
    osg::Group * root = new osg::Group () ;

    //设置几何结点
    osg::Geode* pyramidGeode = new osg::Geode();
    osg::Geometry* pyramidGeometry = new osg::Geometry();

    //可画几何结点加入
    pyramidGeode->addDrawable(pyramidGeometry);
    root->addChild(pyramidGeode);

    osg::ref_ptr <osg::Vec3Array> trangle = new osg::Vec3Array ;
    trangle ->push_back (osg::Vec3 (position.x()-4*size, position.y(), 3)) ;
    trangle ->push_back (osg::Vec3 (position.x(), position.y()-4*size, 3)) ;
    trangle ->push_back (osg::Vec3 (position.x()+4*size, position.y(), 3)) ;
    trangle ->push_back (osg::Vec3 (position.x(), position.y()+4*size, 3)) ;


    //把点充入画区
    pyramidGeometry->setVertexArray( trangle.get () );

    //设置所画格式
    osg::DrawElementsUInt * pyramidBase = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_LOOP,0);

    pyramidBase->push_back(3);
    pyramidBase->push_back(2);
    pyramidBase->push_back(1);
    pyramidBase->push_back(0);
    pyramidGeometry->addPrimitiveSet(pyramidBase);

    //颜色设置
    osg::Vec4Array* colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) ); //index 0 red
    //设置颜色
    pyramidGeometry->setColorArray(colors);
    pyramidGeometry->setColorBinding(osg::Geometry::BIND_OVERALL );
    return  root ;
}

osg::Node* PickHandler::DrawCtrlPoints(osg::Vec3f position)
{
    osg::Group * root = new osg::Group () ;
    //设置点的大小
    osg::ref_ptr <osg::Point > pointsize = new osg::Point ;
    pointsize  ->setSize (5.0) ;
    root->getOrCreateStateSet()->setAttributeAndModes(pointsize.get (),osg::StateAttribute::ON);

    //设置几何结点
    osg::Geode* pyramidGeode = new osg::Geode();
    osg::Geometry* pyramidGeometry = new osg::Geometry();

    //可画几何结点加入
    pyramidGeode->addDrawable(pyramidGeometry);
    root->addChild(pyramidGeode);


    osg::ref_ptr <osg::Vec3Array> trangle = new osg::Vec3Array ;
    trangle ->push_back (osg::Vec3 (position.x ()-2*size, position.y () , 3)) ;
    trangle ->push_back (osg::Vec3 (position.x ()-0.5f*size, position.y ()-1.5f*size , 3)) ;
    trangle ->push_back (osg::Vec3 (position.x ()-0.5f*size, position.y ()-3.5f*size , 3)) ;
    trangle ->push_back (osg::Vec3 (position.x (), position.y ()-4*size , 3)) ;
    trangle ->push_back (osg::Vec3 (position.x ()+0.5f*size, position.y ()-3.5f*size , 3)) ;
    trangle ->push_back (osg::Vec3 (position.x ()+0.5f*size, position.y ()-1.5f*size , 3)) ;
    trangle ->push_back (osg::Vec3 (position.x ()+2.0f*size, position.y () , 3)) ;
    trangle ->push_back (osg::Vec3 (position.x ()+0.5f*size, position.y ()+1.5f*size , 3)) ;
    trangle ->push_back (osg::Vec3 (position.x ()+0.5f*size, position.y () +3.5f*size,3)) ;
    trangle ->push_back (osg::Vec3 (position.x (), position.y ()+4.0f*size , 3)) ;
    trangle ->push_back (osg::Vec3 (position.x ()-0.5f*size, position.y ()+3.5f*size , 3)) ;
    trangle ->push_back (osg::Vec3 (position.x ()-0.5f*size, position.y ()+1.5f*size , 3)) ;

    //把点充入画区
    pyramidGeometry->setVertexArray( trangle.get () );

    //设置所画格式
    osg::DrawElementsUInt * pyramidBase = new osg::DrawElementsUInt(osg::PrimitiveSet::POLYGON ,0);
    pyramidBase->push_back(11);
    pyramidBase->push_back(10);
    pyramidBase->push_back(9);
    pyramidBase->push_back(8);
    pyramidBase->push_back(7);
    pyramidBase->push_back(6);
    pyramidBase->push_back(5);
    pyramidBase->push_back(4);
    pyramidBase->push_back(3);
    pyramidBase->push_back(2);
    pyramidBase->push_back(1);
    pyramidBase->push_back(0);
    pyramidGeometry->addPrimitiveSet(pyramidBase);

    //颜色设置
    osg::Vec4Array* colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f) ); //index 0 red
    //设置颜色
    pyramidGeometry->setColorArray(colors);
    pyramidGeometry->setColorBinding(osg::Geometry::BIND_OVERALL );

    return dynamic_cast<osg::Node *>(root);
}

int PickHandler::SelectSize(int s)
{
    size = 10 * s ;
    return size ;
}

void PickHandler::setPick(bool pick)
{
    m_bPick = pick ;
}

bool PickHandler::getPick()
{
    return m_bPick ;
}

osg::AnimationPath* PickHandler::CreatePath(std::string pathName)
{
    double looptime = sec * GetAllDistance() ;
    std::vector <osg::Vec3 > ::iterator iter =point->end ()  ;
    std::vector <osg::Vec3 > ::iterator iter2 ;
    iter--;
    iter2 = --iter ;
    iter ++ ;

    point ->push_back (osg::Vec3 ((*iter).x()-(*(iter2)).x (), (*(iter)).y()-(*(iter2)).y(), (*(iter)).z()-(*(iter2)).z())) ;

    osg::AnimationPath* animationPath = new osg::AnimationPath;
    animationPath->setLoopMode(osg::AnimationPath::LOOP);

    int numSamples = static_cast<int>(point ->size ()) ;

    #pragma warning(disable:4189)
    //在该情景下不使用到yaw，参见7-1的例子有会使用到（旋转）
    float yaw = 0.0f;
    float yaw_delta = 0.5;
    float roll = osg::inDegrees(90.0f);

    double time=0.0;
    double time_delta = looptime/numSamples;

    float angle = 0.0 ;

    iter = point  ->begin () ;
    for(int i=1;i<numSamples;++i, iter ++)
    {

        osg::Vec3 position(*iter);
        iter ++ ;
        if (iter != point ->end ())
        {
            //这只是一种情况
            if ((*iter).x() > position.x())
            {
                angle = 1.57f-atan(  ((*iter).y () - position.y()) /((*iter).x() - position.x())) ;
                if (angle < 0)
                    angle = 1.57f + angle ;
            } ;

            if ((*iter).x() < position.x())
            {
                angle = -(1.57f+atan(  ((*iter).y () - position.y()) /((*iter).x() - position.x()))) ;
                if (angle > 0)
                    angle = -(1.57f - angle) ;
            }
            //对于X=X的情况

        } ;

        osg::Quat rotation(  osg::Quat(roll,osg::Vec3(1.0,0.0,0.0)) * osg::Quat(-angle,osg::Vec3(0.0,0.0,1.0)));
        osg::Quat rotationY(osg::Quat ( -(3.1415926/6.0), osg::Vec3 (1.0, 0.0, 0.0))) ;
        //rotation *= rotationY ;


        animationPath->insert(time,osg::AnimationPath::ControlPoint(position,rotation));
        time += GetRunTime (position, *iter) ;

        //yaw -= yaw_delta;

        iter -- ;
    }

    std::ofstream fout(pathName.c_str());
    animationPath->write(fout);
    fout.close();

    return animationPath;
}

double PickHandler::GetAllDistance()
{
    float distant  = 0.0 ;

    osg::Vec3Array::iterator iter = point ->begin() ;

    const int size = point ->size () ;
    if (size <= 1)
        return 0;

    else
    {
        for (int i = 0 ;i < size-1 ; i++,iter ++)
        {
            osg::Vec3 temp = *iter ;
            iter ++  ;
            distant += sqrt ( (temp.x () - (*iter).x())*(temp.x () - (*iter).x())   +  (temp.y ()-(*iter).y ()) * (temp.y ()-(*iter).y())) ;
            iter -- ;
        } ;
    }
    return distant ;
}

float PickHandler::GetRunTime(osg::Vec3 res, osg::Vec3 des)
{
    float distant = sqrt (  (des.x () - res.x())*(des.x () - res.x())   + (des.y ()-res.y())*(des.y ()-res.y()) ) ;
    double init = sec ;
    return (init * distant);
}

osg::Node* PickHandler::CreateCardinal()
{
    osg::ref_ptr <osg::Vec3Array > allPoints = new osg::Vec3Array ;
    Cardinal (allPoints .get ()) ;

    osg::Group * root = new osg::Group () ;
    //设置线的大小
    osg::ref_ptr <osg::LineWidth> LineSize = new osg::LineWidth;
    LineSize ->setWidth (5.0) ;
    root->getOrCreateStateSet()->setAttributeAndModes(LineSize.get (),osg::StateAttribute::ON);

    //设置几何结点
    osg::Geode* lineGeode = new osg::Geode();
    osg::Geometry* lineGeometry = new osg::Geometry();

    //可画几何结点加入
    lineGeode->addDrawable(lineGeometry);
    root->addChild(lineGeode);


    //把点充入画区
    lineGeometry->setVertexArray( allPoints.get () );

    //设置所画格式
    osg::DrawElementsUInt * lineBase = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_LOOP ,0);
    for (int i  =0 ; i<(int)(allPoints ->size ()) ; i++)
    {
        lineBase->push_back(i);
    } ;
    lineGeometry->addPrimitiveSet(lineBase);

    //颜色设置
    osg::Vec4Array* colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.4f, 0.0f, 0.0f, 0.5f) );
    //设置颜色
    lineGeometry->setColorArray(colors);
    lineGeometry->setColorBinding(osg::Geometry::BIND_OVERALL );
    return (osg::Node *) root ;

}

void PickHandler::Cardinal(osg::ref_ptr<osg::Vec3Array> temp)
{
    //处理一头一尾两个控制点
    std::vector <osg::Vec3 > ::iterator iter = point ->begin () ;
    osg::ref_ptr <osg::Vec3Array > CtrlTwo = new osg::Vec3Array ;
    CtrlTwo ->push_back (osg::Vec3 ((*iter).x()-1, (*iter).y()-1, (*iter).z())) ;
    CtrlTwo ->insert (++(CtrlTwo ->begin ()), point ->begin (), point ->end ()) ;
    iter = point ->end () ;
    iter -- ;
    CtrlTwo ->push_back (osg::Vec3 ((*iter).x()-1, (*iter).y()-1, (*iter).z())) ;
    iter = CtrlTwo ->begin () ;

    for (  ; iter != CtrlTwo->end () ; *iter ++)

    {
        osg::Vec3  p0 = *iter++ ;
        osg::Vec3  p1 = *iter++ ;
        osg::Vec3  p2 = *iter++ ;
        if (iter == CtrlTwo ->end() )
            return ;
        osg::Vec3  p3 = *iter  ;

        iter -- ;
        iter -- ;
        iter -- ;
        float t = 0 ;
        for (; t <=1 ; t=t+0.1)
        {
            temp ->push_back ( osg::Vec3 (GetCoefficient(p0.x() , p1.x(), p2.x(), p3.x(), t), GetCoefficient(p0.y(), p1.y(), p2.y(), p3.y(), t), 3)) ;
        }
    }
}

float PickHandler::GetCoefficient(float p0, float p1, float p2, float p3, float t)
{
    float d = p1 ;

    float c = 0.5 * ( 1-t) * (p2 - p0) ;

    float a = 0.5 * ( t-1) * p0 + p1 * ( 1.5 + 0.5 * t ) - ( 1.5 + 0.5 * t) * p2 + 0.5 * ( 1-t) * p3 ;

    float b = p2 - a - d - c ;

    return ( a * t * t * t + b * t * t + c * t + d );

}

void PickHandler::pushCardinal()
{
    osg::Group * root = mv ->getSceneData() ->asGroup() ;
    root ->addChild(CreateCardinal()) ;
}

osg::Group* PickHandler::getCtrlPointsGroup()
{
    return ctrlPoints.get() ;
}

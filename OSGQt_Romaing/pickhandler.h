#pragma once

#include <osgUtil/Optimizer>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

#include <osg/Material>
#include <osg/Geode>
#include <osg/BlendFunc>
#include <osg/Depth>
#include <osg/Projection>
#include <osg/MatrixTransform>
#include <osg/Camera>
#include <osg/io_utils>
#include <osg/Point>
#include <osg/AnimationPath>
#include <osgText/Text>
#include <osg/LineWidth>
#include <sstream>
#include <osg/Group>

class PickHandler : public osgGA::GUIEventHandler
{
public:

    PickHandler() ;
    //最主要的响应点击事件（在设置了pick之后）
    bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
    virtual void pick(osgViewer::View* viewer, const osgGA::GUIEventAdapter& ea);
    osg::Group * DrawFirstNode(osg::Vec3f position);
    osg::Node * DrawCtrlPoints(osg::Vec3f position);

    int SelectSize(int s) ;
    void setPick(bool pick) ;
    bool getPick() ;

    //利用保存下的点计算路径，并保存.path文件
    osg::AnimationPath* CreatePath(std::string pathName);
    double GetAllDistance() ;
    float GetRunTime(osg::Vec3 res, osg::Vec3 des);

    void setSecondsPerMeter(double sec) ;
    double getSecondsPerMeter() ;

    //利用保存下的点计算Cardinal曲线轨迹
    osg::Node * CreateCardinal(void);
    void Cardinal(osg::ref_ptr<osg::Vec3Array> temp);
    float GetCoefficient(float p0, float p1, float p2, float p3, float t);

    //显示曲线轨迹
    void pushCardinal() ;

    osg::Group* getCtrlPointsGroup() ;

    bool m_bPick  ;
    bool m_bFirstPush ;
    osg::ref_ptr <osg::Vec3Array>  point ;
    osg::ref_ptr <osg::Group> ctrlPoints ;
    int size ;
    double sec ;
    osgViewer::View *mv ;
};

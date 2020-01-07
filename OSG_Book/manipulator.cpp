//------------------------------//------------------------------
//By FreeSouth at 2008 6 16 ieysx@163.com  www.osgChina.org
//------------------------------//------------------------------
#include "manipulator.h"
//------------------------------//------------------------------
CSouth::CSouth(void): m_fMoveSpeed(1.5f)
, m_bLeftButtonDown(false)
, m_fpushX(0)
, m_bPeng(true)
, m_fpushY(0)
, m_fAngle(2.5)
{
    m_vPosition = osg::Vec3(0.0f, 0.0f,5.0f);

    m_vRotation = osg::Vec3(osg::PI_2, 0.0f, 0.0f);
}
//------------------------------//------------------------------
CSouth::~CSouth(void)
{
}
//------------------------------//------------------------------
void CSouth::setByMatrix(const osg::Matrixd & matrix)
{

}
//------------------------------//------------------------------
void CSouth::setByInverseMatrix(const osg::Matrixd& matrix)
{

}
//------------------------------//------------------------------
osg::Matrixd CSouth::getMatrix(void) const
{
    //得到旋转后的矩阵,其实也就是视口矩阵
    osg::Matrixd mat;

    mat.makeRotate(m_vRotation._v[0], osg::Vec3(1.0f, 0.0f, 0.0f),

        m_vRotation._v[1], osg::Vec3(0.0f, 1.0f, 0.0f),

        m_vRotation._v[2], osg::Vec3(0.0f, 0.0f, 1.0f));

    return mat * osg::Matrixd::translate(m_vPosition);
}
//------------------------------//------------------------------
osg::Matrixd CSouth::getInverseMatrix(void) const
{
    osg::Matrixd mat;

    mat.makeRotate(m_vRotation._v[0], osg::Vec3(1.0f, 0.0f, 0.0f),

        m_vRotation._v[1], osg::Vec3(0.0f, 1.0f, 0.0f),

        m_vRotation._v[2], osg::Vec3(0.0f, 0.0f, 1.0f));

    return osg::Matrixd::inverse(mat * osg::Matrixd::translate(m_vPosition));
}
//------------------------------//------------------------------
bool CSouth::handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &us)
{
    float mouseX = ea.getX();

    float mouseY = ea.getY();


    switch(ea.getEventType())
    {
    case(osgGA::GUIEventAdapter::KEYDOWN):

        {

            if (ea.getKey() == 0x20)//' '
            {
                us.requestRedraw();

                us.requestContinuousUpdate(false);

                return true;
            }
            if (ea.getKey() == 0xFF50 || ea.getKey() == 0xFF95)//home
            {

                ChangePosition(osg::Vec3 (0, 0, m_fMoveSpeed)) ;

                return true;
            }
            if (ea.getKey() == 0xFF57) //end
            {

                ChangePosition(osg::Vec3 (0, 0, -m_fMoveSpeed)) ;
                return true;
            }

            if (ea.getKey() == 0x2B)//+
            {
                m_fMoveSpeed += 1.0f;

                return true;
            }

            if (ea.getKey() == 0x2D)//-
            {
                m_fMoveSpeed -= 1.0f;

                if (m_fMoveSpeed < 1.0f)
                {
                    m_fMoveSpeed = 1.0f;
                }
                return true;
            }
            if (ea.getKey() == 0xFF52 || ea.getKey () == 0x57 || ea.getKey () == 0x77)//up
            {

                ChangePosition(osg::Vec3 (0, m_fMoveSpeed * sinf(osg::PI_2+m_vRotation._v[2]), 0)) ;

                ChangePosition(osg::Vec3 (m_fMoveSpeed * cosf(osg::PI_2+m_vRotation._v[2]), 0, 0)) ;

                return true;
            }
            if (ea.getKey() == 0xFF54 || ea.getKey () == 0x53 || ea.getKey () == 0x73 )//down
            {

                ChangePosition(osg::Vec3 (0, -m_fMoveSpeed * sinf(osg::PI_2+m_vRotation._v[2]), 0)) ;

                ChangePosition(osg::Vec3(-m_fMoveSpeed * cosf(osg::PI_2+m_vRotation._v[2]), 0, 0)) ;

                return true;
            }

            if (ea.getKey () == 0x41||ea.getKey () == 0x61)
            {
                ChangePosition(osg::Vec3 (0, m_fMoveSpeed * cosf(osg::PI_2+m_vRotation._v[2]), 0)) ;

                ChangePosition(osg::Vec3 (-m_fMoveSpeed * sinf(osg::PI_2+m_vRotation._v[2]), 0, 0)) ;

                return true;
            }
            if (ea.getKey () == 0x44||ea.getKey () == 0x64)
            {
                ChangePosition(osg::Vec3 (0,-m_fMoveSpeed * cosf(osg::PI_2+m_vRotation._v[2]), 0)) ;

                ChangePosition(osg::Vec3 (m_fMoveSpeed * sinf(osg::PI_2+m_vRotation._v[2]), 0, 0)) ;
                return true;
            }

            if (ea.getKey() == 0xFF53)//Right
            {
                m_vRotation._v[2] -= osg::DegreesToRadians(m_fAngle);
            }
            if (ea.getKey()== 0xFF51)//Left
            {
                m_vRotation._v[2] += osg::DegreesToRadians(m_fAngle);
            }
            if (ea.getKey() == 0x46 || ea.getKey() == 0x66)//F
            {
                computeHomePosition();
                m_fAngle -= 0.2 ;

                return true ;
            }

            if (ea.getKey() == 0x47 || ea.getKey() == 0x67)//G
            {
                m_fAngle += 0.2 ;

                return true ;
            }



            return false;

        }

    case (osgGA::GUIEventAdapter ::PUSH ):

        if ( ea.getButton () == 1)

        {
            m_fpushX = mouseX ;
            m_fpushY = mouseY ;

            m_bLeftButtonDown = true ;
        }

        return false ;
    case (osgGA::GUIEventAdapter ::DRAG ):

        if ( m_bLeftButtonDown)

        {
            m_vRotation._v[2] -= osg::DegreesToRadians(m_fAngle * (mouseX-m_fpushX) * 0.01);

            m_vRotation._v[0] += osg::DegreesToRadians(1.1*(mouseY-m_fpushY) * 0.01) ;

            if (m_vRotation._v [0] >= 3.14)
                m_vRotation._v [0] = 3.14 ;
            if (m_vRotation._v [0] <= 0)
                m_vRotation._v [0] = 0 ;
        }

        return false ;

    case (osgGA::GUIEventAdapter ::RELEASE ):

        if ( ea.getButton () == 1)

        {
            m_bLeftButtonDown = false ;
        }

        return false ;

    default:
        return false;
    }
}
//------------------------------//------------------------------
void CSouth::ChangePosition(const osg::Vec3& delta)
{
    if (m_bPeng)
    {
        //看新值与旧值之间的连线是否与模型有交点！
        osg::Vec3 newPos = m_vPosition + delta;
        osgUtil::IntersectVisitor iv;

        osg::ref_ptr<osg::LineSegment> line = new osg::LineSegment(newPos,
            m_vPosition);

        osg::ref_ptr<osg::LineSegment> lineZ = new osg::LineSegment(newPos + osg::Vec3(0.0f, 0.0f, m_fMoveSpeed),
            newPos - osg::Vec3(0.0f, 0.0f, m_fMoveSpeed));
        iv.addLineSegment(lineZ.get());
        iv.addLineSegment (line.get()) ;
        m_node ->accept(iv);
        if (!iv.hits())
        {
            m_vPosition += delta;
        }
    }
    else
        m_vPosition += delta;
}
//------------------------------//------------------------------
float CSouth::getSpeed()
{
    return m_fMoveSpeed ;
}
//------------------------------//------------------------------
void CSouth::setSpeed(float sp)
{
    m_fMoveSpeed = sp ;
}
//------------------------------//------------------------------
void CSouth::SetPosition(osg::Vec3 &position)
{
    m_vPosition = position ;
}
void CSouth::SetPosition(double* position)
{
    m_vPosition._v[0] = position[0] ;
    m_vPosition._v[1] = position[1] ;
    m_vPosition._v[2] = position[2] ;
}
//------------------------------//------------------------------
osg::Vec3 CSouth::GetPosition()
{
    return m_vPosition ;
}
//------------------------------//------------------------------
void CSouth::setNode(osg::Node* node)
{
    m_node = node ;
}
//------------------------------//------------------------------
void CSouth::computeHomePosition(const osg::Camera *camera, bool useBoundingBox)
{
    if(m_node.get())
    {
        const osg::BoundingSphere& boundingSphere=m_node->getBound();
        osg::Vec3 bp = boundingSphere._center;
        SetPosition(bp) ;
    }
}
//------------------------------//------------------------------
void CSouth::setPeng(bool peng)
{
    m_bPeng = peng ;
}
//------------------------------//------------------------------
bool CSouth::getPeng()
{
    return m_bPeng ;
}
//------------------------------//------------------------------
void CSouth::setFpeng()
{
    m_bPeng = !m_bPeng ;
}
//------------------------------//------------------------------

/* -*-c++-*- OpenSceneGraph - 2008.6.16 by FreeSouth
 *
 * RambleSystem操作器管理类，用来管理操作器
*/
//------------------------------//------------------------------
#pragma once


//------------------------------//------------------------------
#include <osgViewer/Viewer>
#include <osgGA/CameraManipulator>
#include <osgUtil/IntersectVisitor>
#include <osg/LineSegment>
//------------------------------//------------------------------
class   CSouth: public osgGA::CameraManipulator
{
public:
    CSouth(void);
public:
    ~CSouth(void);

private:

    osg::ref_ptr<osg::Node>      m_node;

    unsigned int			m_nID;
    float					m_fMoveSpeed;
    osg::Vec3				m_vPosition;
    osg::Vec3				m_vRotation;


    bool m_bLeftButtonDown;
    float m_fpushX;
    bool m_bPeng;
    float m_fpushY;

public:
    void setPeng(bool peng) ;
    bool getPeng() ;
    void setFpeng() ;

    virtual void setNode(osg::Node*);

    // 虚函数
    virtual void setByMatrix(const osg::Matrixd& matrix);
    // 虚函数
    virtual void setByInverseMatrix(const osg::Matrixd& matrix);

    virtual osg::Matrixd getMatrix(void) const;
    // 得到逆矩阵
    virtual osg::Matrixd getInverseMatrix(void)const ;
    // 主要事件控制器
    virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);
    // 屏目角度
    float m_fAngle;
    // 位置变换函数
    void ChangePosition(const osg::Vec3& delta);

    float getSpeed() ;
    void  setSpeed(float ) ;
    void SetPosition(osg::Vec3 &position) ;
    void SetPosition(double *) ;
    osg::Vec3 GetPosition() ;

    //计算家的位置
    void computeHomePosition(const osg::Camera *camera = NULL, bool useBoundingBox = false);

};
//------------------------------//------------------------------

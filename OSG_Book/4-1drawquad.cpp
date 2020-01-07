//By FreeSouth  ieysx@163.com  www.osgChina.org  2008 6 14

#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osg/Node>
#include <osg/Geode>
#include <osg/Geometry>
#include <osgViewer/ViewerEventHandlers>

osg::ref_ptr<osg::Node> createQuad() ;

int main()
{
    osgViewer::Viewer viewer;
    osg::Group * root = new osg::Group() ;

    root ->addChild(createQuad().get()) ;

    viewer.setSceneData(root);
    //窗口大小变化事件
    viewer.addEventHandler(new osgViewer::WindowSizeHandler);

    //添加一些常用状态设置
    viewer.addEventHandler(new osgViewer::StatsHandler);
    viewer.realize();
    viewer.run();
}

osg::ref_ptr<osg::Node> createQuad()
{

    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

    //首先定义四个点
    osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array;
    geom->setVertexArray( v.get() );
    v->push_back( osg::Vec3( -1.f, 0.f, -1.f ) );
    v->push_back( osg::Vec3( 1.f, 0.f, -1.f ) );
    v->push_back( osg::Vec3( 1.f, 0.f, 1.f ) );
    v->push_back( osg::Vec3( -1.f, 0.f, 1.f ) );

    //定义颜色数组
    osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array;
    geom->setColorArray( c.get() );
    geom->setColorBinding( osg::Geometry::BIND_PER_VERTEX );
    c->push_back( osg::Vec4( 1.f, 0.f, 0.f, 1.f ) );
    c->push_back( osg::Vec4( 0.f, 1.f, 0.f, 1.f ) );
    c->push_back( osg::Vec4( 0.f, 0.f, 1.f, 1.f ) );
    c->push_back( osg::Vec4( 1.f, 1.f, 1.f, 1.f ) );

    //定义法线
    osg::ref_ptr<osg::Vec3Array> n = new osg::Vec3Array;
    geom->setNormalArray( n.get() );
    geom->setNormalBinding( osg::Geometry::BIND_OVERALL );
    n->push_back( osg::Vec3( 0.f, -1.f, 0.f ) );

    //设置顶点关联方式
    geom->addPrimitiveSet(
                new osg::DrawArrays( osg::PrimitiveSet::QUADS, 0, 4 ) );

    //几何组结点
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable( geom.get() );
    return geode.get();
}

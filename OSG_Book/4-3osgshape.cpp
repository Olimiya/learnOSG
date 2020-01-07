////By FreeSouth  ieysx@163.com  www.osgChina.org  2008 6 14

//#include <osgDB/ReadFile>
//#include <osgViewer/Viewer>
//#include <osg/Node>
//#include <osg/Geode>
//#include <osg/Geometry>
//#include <osg/ShapeDrawable>
//#include <osg/Shape>
//#include <osgViewer/ViewerEventHandlers>
//osg::ref_ptr<osg::Node> createShape() ;

//int main()
//{
//    osgViewer::Viewer viewer;
//    osg::Group * root = new osg::Group() ;

//    root ->addChild(createShape().get()) ;
//    //窗口大小变化事件
//    viewer.addEventHandler(new osgViewer::WindowSizeHandler);

//    //添加一些常用状态设置
//    viewer.addEventHandler(new osgViewer::StatsHandler);
//    viewer.setSceneData(root);
//    viewer.realize();
//    viewer.run();
//}

//osg::ref_ptr<osg::Node> createShape()
//{

//    //几何组结点
//    osg::ref_ptr<osg::Geode> geode = new osg::Geode;

//    float radius = 0.08f;
//    float height = 0.1f;

//    osg::TessellationHints* hints = new osg::TessellationHints;
//    hints->setDetailRatio(0.5f);

//    geode->addDrawable(new osg::ShapeDrawable(new osg::Sphere(osg::Vec3(0.0f,0.0f,0.0f),radius),hints));
//    geode->addDrawable(new osg::ShapeDrawable(new osg::Box(osg::Vec3(0.2f,0.0f,0.0f),2*radius),hints));
//    geode->addDrawable(new osg::ShapeDrawable(new osg::Cone(osg::Vec3(0.4f,0.0f,0.0f),radius,height),hints));
//    geode->addDrawable(new osg::ShapeDrawable(new osg::Cylinder(osg::Vec3(0.60f,0.0f,0.0f),radius,height),hints));
//    geode->addDrawable(new osg::ShapeDrawable(new osg::Capsule(osg::Vec3(0.80f,0.0f,0.0f),radius,height),hints));

//    return geode.get();
//}

//#include <osgViewer/Viewer>
//#include <osgDB/ReadFile>
//#include <osg/Geode>
//#include <osg/Geometry>
//#include <osg/StateSet>
//#include <osg/StateAttribute>
//#include <osg/Texture2D>
//#include <osg/BlendFunc>
//#include <osg/AlphaFunc>
//#include <osg/Notify>

//#include <osgViewer/ViewerEventHandlers>
//#include <osgGA/StateSetManipulator>
//#include <QDebug>


//int main()
//{
//    auto b = osgDB::Registry::instance()->loadLibrary("osgdb_svg");
//    qDebug() << b;
//    auto c = osgDB::Registry::instance()->loadLibrary("osgdb_svgd");
//    qDebug() << c;
//    auto l=osgDB::Registry::instance()->getReaderWriterForExtension("svg");
//    if(l)
//    {
//        qDebug() << l->className();
//    }

////    osgDB::Registry::instance()->getDataFilePathList().push_back("F:\\program\\learnOSG\\model");
////    osgViewer::Viewer viewer;

////    osg::ref_ptr<osg::Group> root = new osg::Group;

////    viewer.setSceneData(root);
////    //添加状态事件
////    viewer.addEventHandler( new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()) );

////    //窗口大小变化事件
////    viewer.addEventHandler(new osgViewer::WindowSizeHandler);

////    //添加一些常用状态设置
////    viewer.addEventHandler(new osgViewer::StatsHandler);
////    viewer.realize();
////    viewer.run();

//}

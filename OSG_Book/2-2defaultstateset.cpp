////By FreeSouth  ieysx@163.com  www.osgChina.org  2008 6 11

//#include <osgDB/ReadFile>
//#include <osgViewer/Viewer>
//#include <osgViewer/ViewerEventHandlers>
//#include <osgGA/StateSetManipulator>

//int main()
//{
//    osgViewer::Viewer viewer;
//    viewer.setSceneData(osgDB::readNodeFile("glider.osg"));

//    //添加状态事件
//    viewer.addEventHandler( new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()) );

//    //窗口大小变化事件
//    viewer.addEventHandler(new osgViewer::WindowSizeHandler);

//    //添加一些常用状态设置
//    viewer.addEventHandler(new osgViewer::StatsHandler);

//    viewer.realize();
//    viewer.run();
//}

////By FreeSouth  ieysx@163.com  www.osgChina.org  2008 6 11

//#include <osgDB/ReadFile>
//#include <osgViewer/Viewer>
//#include <osgViewer/ViewerEventHandlers>

//#include <osgGA/TrackballManipulator>
//#include <osgGA/FlightManipulator>
//#include <osgGA/DriveManipulator>
//#include <osgGA/KeySwitchMatrixManipulator>
//#include <osgGA/StateSetManipulator>
//#include <osgGA/AnimationPathManipulator>
//#include <osgGA/TerrainManipulator>

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

//    //添加一些操作器
//    {
//        osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> keyswitchManipulator = new osgGA::KeySwitchMatrixManipulator;

//        keyswitchManipulator->addMatrixManipulator( '1', "Trackball", new osgGA::TrackballManipulator() );
//        keyswitchManipulator->addMatrixManipulator( '2', "Flight", new osgGA::FlightManipulator() );
//        keyswitchManipulator->addMatrixManipulator( '3', "Drive", new osgGA::DriveManipulator() );
//        keyswitchManipulator->addMatrixManipulator( '4', "Terrain", new osgGA::TerrainManipulator() );
//        viewer.setCameraManipulator( keyswitchManipulator.get() );
//    }

//    //添加路径记录
//    viewer.addEventHandler(new osgViewer::RecordCameraPathHandler);


//    viewer.realize();
//    viewer.run();
//}

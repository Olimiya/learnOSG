////By FreeSouth  ieysx@163.com  www.osgChina.org  2008 6 13

//#include <osgDB/ReadFile>
//#include <osgViewer/Viewer>
//#include <osg/Node>
//#include <osg/MatrixTransform>
//#include <osgViewer/ViewerEventHandlers>

//int main()
//{
//    osgViewer::Viewer viewer;
//    osg::ref_ptr <osg::Group> root = new osg::Group() ;

//    osg::ref_ptr<osg::Node> osgcool = osgDB::readNodeFile("osgcool.osgt") ;

//    osg::ref_ptr<osg::MatrixTransform> trans = new osg::MatrixTransform ;
//    trans ->setMatrix(osg::Matrix::translate(0, 0, 2)) ;
//    trans ->addChild(osgcool.get()) ;

//    //osg::ref_ptr<osg::MatrixTransform> scale = new osg::MatrixTransform ;
//    //scale ->setMatrix(osg::Matrix::scale(0.5, 0.5, 0.5)*osg::Matrix::translate(0, 0, -2)) ;
//    //scale ->addChild(osgcool.get()) ;

//    //osg::ref_ptr<osg::MatrixTransform> rot = new osg::MatrixTransform ;
//    //rot ->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(45.0), 1, 0, 0)*osg::Matrix::scale(0.5, 0.5, 0.5)*osg::Matrix::translate(4, 0, -2)) ;
//    //rot ->addChild(osgcool.get()) ;

//    root ->addChild(osgcool.get()) ;
//    root ->addChild(trans.get()) ;
//    //root ->addChild(scale.get()) ;
//    //root ->addChild(rot.get()) ;

//    //窗口大小变化事件
//    viewer.addEventHandler(new osgViewer::WindowSizeHandler);

//    //添加一些常用状态设置
//    viewer.addEventHandler(new osgViewer::StatsHandler);
//    viewer.setSceneData(root.get());
//    viewer.realize();
//    viewer.run();
//}

//#include <osgDB/ReadFile>
//#include <osgViewer/Viewer>
//#include <osgDB/Registry>
//#include <osg/DrawPixels>


////USE_OSGPLUGIN(png)
////#pragma comment( lib,"osgdb_pngd.lib" )


//int main()
//{
//    //osgDB::Registry::instance()->loadLibrary("osgdb_pngd.dll");
//    osg::ref_ptr<osg::Group> root = new osg::Group;
//    osg::ref_ptr<osg::Image> image = osgDB::readImageFile("model/blueFlowers.png");
//    osg::ref_ptr<osg::DrawPixels> bitmap_in = new osg::DrawPixels;
//    bitmap_in->setPosition(osg::Vec3d(16445.0f,25430.0f,50.0f));
//    bitmap_in->setImage(image);

//    osg::ref_ptr<osg::Geode>geode1 = new osg::Geode;
//    geode1->addDrawable(bitmap_in.get());
//    root->addChild(geode1.get());
//    osgViewer::Viewer viewer;
////    viewer.setSceneData(osgDB::readNodeFile("model/blueFlowers.png"));
//    viewer.setSceneData(root.get());
//    viewer.realize();
//    viewer.run();
//}

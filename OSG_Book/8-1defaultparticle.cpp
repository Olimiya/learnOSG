//#include <osgDB/ReadFile>
//#include <osgViewer/Viewer>
//#include <osgParticle/PrecipitationEffect>
//#include <osg/Node>

//int main()
//{
//    osgViewer::Viewer viewer;

//    osg::ref_ptr<osgParticle::PrecipitationEffect> precipitationEffect = new osgParticle::PrecipitationEffect;
//    precipitationEffect->snow(0.5);
//    precipitationEffect->setParticleColor(osg::Vec4(1, 1, 1, 1));
//    precipitationEffect->setWind(osg::Vec3(2, 0, 0));

//    osg::Group * root = new osg::Group() ;
//    root ->addChild(precipitationEffect.get ()) ;
//    osg::Node* ceep = osgDB::readNodeFile("house.ive") ;
//    root ->addChild(ceep) ;

//    viewer.setSceneData(root);
//    viewer.realize();
//    viewer.run();
//}

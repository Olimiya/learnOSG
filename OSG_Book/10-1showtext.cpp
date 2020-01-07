//#include <osgDB/ReadFile>
//#include <osgViewer/Viewer>
//#include <osg/Geode>
//#include <osg/Depth>
//#include <osg/Camera>
//#include <osgText/Text>

//osg::Node* createHUD()
//{
//    osg::Geode* geode = new osg::Geode();
////设置字体，字体光盘文件夹IVE中可以找到
//    std::string caiyun("STCAIYUN.TTF");
////设置状态，关闭灯光
//    osg::StateSet* stateset = geode->getOrCreateStateSet();
//    stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
//    osg::Vec3 position(150.0f,500.0f,0.0f);
////设置字体属性
//    osgText::Text* text = new  osgText::Text;
//    geode->addDrawable( text );
////设置字体
//    text->setFont(caiyun);
////设置位置
//    text->setPosition(position);
//    text->setText(L"osg中国官网网站www.osgChina.org");
////设置相机
//    osg::Camera* camera = new osg::Camera;
////设置透视矩阵
//    camera->setProjectionMatrix(osg::Matrix::ortho2D(0,1024,0,768));
//    camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
//    //得到默认设置
//    camera->setViewMatrix(osg::Matrix::identity());
//    //设置背景为透明，否则的话可以设置ClearColor
//    camera->setClearMask(GL_DEPTH_BUFFER_BIT);
//    //设置渲染顺序，必须在最后渲染
//    camera->setRenderOrder(osg::Camera::POST_RENDER);
//    camera->addChild(geode);
//    return camera;
//};

//int main( int argc, char **argv )
//{
//    osgViewer::Viewer viewer;

//    osg::ref_ptr<osg::Node> scene = osgDB::readNodeFile("house.ive");
//    osg::ref_ptr<osg::Group> group  = new osg::Group;
//    if (scene.valid()) group->addChild(scene.get());
//    //创建HUD
////	　　group->addChild(createHUD());
//    group->addChild(createHUD());
//    viewer.setSceneData(group.get());
//    viewer.realize();
//    viewer.run() ;
//    return 0;
//}

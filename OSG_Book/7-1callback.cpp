//#include <osg/MatrixTransform>
//#include <osg/PositionAttitudeTransform>
//#include <osg/Geode>

//#include <osgDB/Registry>
//#include <osgDB/ReadFile>
//#include <osgGA/TrackballManipulator>
//#include <osgViewer/Viewer>


//osg::AnimationPath* createAnimationPath(const osg::Vec3& center,float radius,double looptime)
//{
//    osg::AnimationPath* animationPath = new osg::AnimationPath;
//    animationPath->setLoopMode(osg::AnimationPath::LOOP);

//    int numSamples = 40;
//    float yaw = 0.0f;
//    float yaw_delta = 2.0f*osg::PI/((float)numSamples-1.0f);
//    float roll = osg::inDegrees(30.0f);

//    double time=0.0f;
//    double time_delta = looptime/(double)numSamples;
//    for(int i=0;i<numSamples;++i)
//    {
//        osg::Vec3 position(0,0,0);
//        osg::Quat rotation(osg::Quat(roll,osg::Vec3(0.0,1.0,0.0))*osg::Quat(-(yaw+osg::inDegrees(90.0f)),osg::Vec3(0.0,0.0,1.0)));
//        animationPath->insert(time,osg::AnimationPath::ControlPoint(position,rotation));
//        yaw += yaw_delta;
//        time += time_delta;
//    }
//    return animationPath;
//}

//osg::Node* createMovingModel(const osg::Vec3& center, float radius)
//{
//    float animationLength = 10.0f;
//    osg::AnimationPath* animationPath = createAnimationPath(center,radius,animationLength);
//    osg::Group* model = new osg::Group;
//    osg::Node* fountain = osgDB::readNodeFile("fountain.osgt");
//    //fountain ->asGroup() ->getChild(0) ->setNodeMask(0) ;

//    if (fountain)
//    {
//        osg::PositionAttitudeTransform* xform = new osg::PositionAttitudeTransform;
//        xform->setUpdateCallback(new osg::AnimationPathCallback(animationPath,0.0,1.0));
//        xform->addChild(fountain);
//        model->addChild(xform);
//    }

//    return model;
//}

//osg::Node* createModel()
//{
//    osg::Vec3 center(0.0f,0.0f,0.0f);
//    float radius = 1.0f;
//    osg::Group* root = new osg::Group;
//    osg::Node* movingModel = createMovingModel(center,radius*0.8f);
//    root->addChild(movingModel);
//    return root;
//}

//int main( int argc, char **argv )
//{
//    osgViewer::Viewer viewer;
//    osg::Node* model = createModel();
//    viewer.setSceneData(model);
//    viewer.setCameraManipulator(new osgGA::TrackballManipulator());
//    viewer.realize() ;
//    return viewer.run();
//}

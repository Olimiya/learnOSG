//#include <osgViewer/Viewer>
//#include <osg/Math>
//#include <osgDB/ReadFile>
//#include <osg/NodeCallback>
//#include <osg/MatrixTransform>


//class MyTransformCallback : public osg::NodeCallback
//{
//public:

//    MyTransformCallback(float angularVelocity)
//    {
//        m_angularVelocity = angularVelocity;
//    }

//    virtual void operator() (osg::Node* node, osg::NodeVisitor* nv)
//    {
//        osg::MatrixTransform* transform = dynamic_cast<osg::MatrixTransform*>(node);
//        if (nv && transform && nv->getFrameStamp())
//        {
//            double time = nv->getFrameStamp()->getReferenceTime();
//            transform->setMatrix(osg::Matrix::translate(0.0f,1.0f+cosf(time*m_angularVelocity),0.0f));
//        }
//        traverse(node,nv);
//    }
//protected:
//    float     m_angularVelocity;

//};

//int main( int argc, char **argv )
//{
//    osgViewer::Viewer viewer;
//    osg::Group* root = new osg::Group;
//    osg::Node * node  = osgDB::readNodeFile ("glider.osg") ;
//    osg::MatrixTransform* transform = new osg::MatrixTransform();
//    transform->setUpdateCallback(new MyTransformCallback(10.0f));
//    transform->addChild(node);
//    root ->addChild (transform) ;
//    viewer.setSceneData( root );
//    viewer.realize();
//    viewer.run() ;
//    return 0;
//}

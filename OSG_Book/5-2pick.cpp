////by FreeSouth 2008 6 16
//#include <osgDB/ReadFile>
//#include <osgViewer/Viewer>
//#include <osg/Group>
//#include <osgFX/Scribe>
//#include <osgGA/GUIEventHandler>
//#include <osgUtil/LineSegmentIntersector>
//#include <osgViewer/ViewerEventHandlers>

//class CPickHandler : public osgGA::GUIEventHandler
//{
//public:
//    CPickHandler(osgViewer::Viewer* viewer):mViewer(viewer){}
//    virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
//    {
//        switch(ea.getEventType())
//        {
//            case(osgGA::GUIEventAdapter::PUSH):
//                if (ea.getButton()==1)
//                {
//                    Pick(ea.getX(), ea.getY());
//                }
//                return true;
//            default:
//                break;
//        }
//        return false;

//    }

//protected:
//    void Pick(float x, float y)
//    {
//        osgUtil::LineSegmentIntersector::Intersections intersections;
//        if (mViewer->computeIntersections(x, y, intersections))
//        {
//            for(osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin();
//                hitr != intersections.end();
//                ++hitr)
//            {

//                if (!hitr->nodePath.empty() && !(hitr->nodePath.back()->getName().empty()))
//                {

//                    const osg::NodePath& np = hitr ->nodePath ;

//                    for (int i=np.size()-1; i>=0; --i)
//                    {
//                        osgFX::Scribe* sc= dynamic_cast<osgFX::Scribe *>(np[i]);
//                        if (sc!= NULL)
//                        {
//                            if(sc ->getNodeMask() != 0)
//                                sc ->setNodeMask(0) ;
//                        }

//                    }
//                }
//            }
//        }

//    }
//    osgViewer::Viewer* mViewer ;
//};

//int main(int, char**)
//{
//    osgViewer::Viewer viewer;
//    osg::ref_ptr<osg::Group> root = new osg::Group();
//    root ->addChild(osgDB::readNodeFile("cessna.osg"));
//    osg::ref_ptr<osg::Node> cow  = osgDB::readNodeFile("cow.osg") ;

//    osg::ref_ptr<osgFX::Scribe> sc = new osgFX::Scribe() ;
//    sc ->addChild(cow.get()) ;

//    root->addChild(cow.get ());
//    root->addChild(sc.get ()) ;

//    viewer.setSceneData(root.get ());
//    viewer.addEventHandler(new CPickHandler(&viewer)) ;
//    //窗口大小变化事件
//    viewer.addEventHandler(new osgViewer::WindowSizeHandler);

//    //添加一些常用状态设置
//    viewer.addEventHandler(new osgViewer::StatsHandler);
//    viewer.realize();
//    viewer.run();
//    return 0;
//}

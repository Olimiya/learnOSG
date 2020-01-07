////By FreeSouth  ieysx@163.com  www.osgChina.org  2008 6 14

//#include <osgDB/ReadFile>
//#include <osgViewer/Viewer>
//#include <osg/Node>
//#include <osgViewer/ViewerEventHandlers>

//class UseEventHandler : public osgGA::GUIEventHandler
//{
//public:

//    virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
//    {
//        osgViewer::Viewer* viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
//        if (!viewer) return false;

//        switch(ea.getEventType())
//        {
//            case osgGA::GUIEventAdapter::KEYDOWN:
//            {
//                if (ea.getKey()== 0xFF51)//键盘向左
//                {
//                    viewer ->getSceneData() ->asGroup() ->getChild(1) ->setNodeMask(0) ;
//                    viewer ->getSceneData() ->asGroup() ->getChild(0) ->setNodeMask(1) ;
//                }

//                if (ea.getKey()== 0xFF53)//键盘向右
//                {
//                    viewer ->getSceneData() ->asGroup() ->getChild(0) ->setNodeMask(0) ;
//                    viewer ->getSceneData() ->asGroup() ->getChild(1) ->setNodeMask(1) ;
//                }
//            }
//                break;

//            case osgGA::GUIEventAdapter ::PUSH:
//                if(ea.getButton () == 4)//右键点击
//                {
//                    viewer ->getSceneData() ->asGroup() ->getChild(0) ->setNodeMask(0) ;
//                    viewer ->getSceneData() ->asGroup() ->getChild(1) ->setNodeMask(0) ;
//                }
//                break;
//            case osgGA::GUIEventAdapter::DOUBLECLICK:
//                if(ea.getButton() == 1)//左键双击
//                {
//                    viewer ->getSceneData() ->asGroup() ->getChild(0) ->setNodeMask(1) ;
//                    viewer ->getSceneData() ->asGroup() ->getChild(1) ->setNodeMask(1) ;
//                }
//                break;
//            default:
//                break;
//        }


//        return false;
//    }
//};


//int main()
//{
//    osgViewer::Viewer viewer;
//    osg::ref_ptr<osg::Group> root = new osg::Group() ;

//    root ->addChild(osgDB::readNodeFile("cow.osg")) ;
//    root ->addChild(osgDB::readNodeFile("glider.osg"));

//    viewer.setSceneData(root.get ());
//    viewer.addEventHandler(new UseEventHandler) ;
//    //窗口大小变化事件
//    viewer.addEventHandler(new osgViewer::WindowSizeHandler);

//    //添加一些常用状态设置
//    viewer.addEventHandler(new osgViewer::StatsHandler);
//    viewer.realize();
//    viewer.run();
//}



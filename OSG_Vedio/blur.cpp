//#include "OSG_Vedio/common.h"

//#include <osgViewer//Viewer>
//#include <osg/GraphicsContext>
//#include <osgGA/GUIEventHandler>
//#include <osgGA/GUIActionAdapter>
//#include <osgDB/ReadFile>
//#include <osgViewer/Viewer>

//class MB: public osg::Operation
//{
//public:
//    MB():osg::Operation("MB", true)
//    {
//        bclear = false;
//        t0 = 0;
//    }

//    virtual void operator()(osg::Object* object)
//    {
//        osg::GraphicsContext* gc = dynamic_cast<osg::GraphicsContext*>(object);
//        if(!gc) return;

//        double t = gc->getState()->getFrameStamp()->getSimulationTime();
//        if(!bclear)
//        {
//            bclear = true;
//            glClearColor(0, 0, 0,0 );
//            glClear(GL_ACCUM_BUFFER_BIT);
//            t0 = t;
//        }

//        double dt = fabs(t - t0);
//        t0 = t;
//        double s = powf(0.2, dt/0.25);
//        glAccum(GL_MULT, s);
//        glAccum(GL_ACCUM, 1-s);
//        glAccum(GL_RETURN, 1.0f);
//    }
//private:
//    bool bclear;
//    double t0;
//};

//int main()
//{
//    osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
//    viewer->setSceneData(osgDB::readNodeFile("model\\ceep.ive"));
//    viewer->realize();
//    osgViewer::Viewer::Windows windows;
//    viewer->getWindows(windows);
//    for(osgViewer::Viewer::Windows::iterator iter = windows.begin(); iter != windows.end(); ++iter)
//    {
//        (*iter)->add(new MB());
//    }
//    return viewer->run();
//}

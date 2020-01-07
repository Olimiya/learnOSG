//#include <osgDB/ReadFile>
//#include <osgDB/WriteFile>
//#include <osgViewer/Viewer>
//#include <osgGA/TrackballManipulator>
//#include <osgGA/FlightManipulator>
//#include <osgGA/AnimationPathManipulator>
//#include <iostream>


//void multipleWindowMultipleCameras(osgViewer::Viewer& viewer, bool multipleScreens)
//{
//    osg::GraphicsContext::WindowingSystemInterface* wsi = osg::GraphicsContext::getWindowingSystemInterface();
//    if (!wsi)
//    {
//        osg::notify(osg::NOTICE)<<"Error, no WindowSystemInterface available, cannot create windows."<<std::endl;
//        return;
//    }

//    unsigned int width, height;
//    wsi->getScreenResolution(osg::GraphicsContext::ScreenIdentifier(0), width, height);

//    unsigned int numCameras = 6;
//    double aspectRatioScale = (double)numCameras;
//    double translate_x = double(numCameras)-1;
//    for(unsigned int i=0; i<numCameras;++i, translate_x -= 2.0)
//    {
//        osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
//        traits->screenNum = multipleScreens ? i / 3 : 0;
//        traits->x = (i*width)/numCameras;
//        traits->y = 0;
//        traits->width = width/numCameras-1;
//        traits->height = height;
//        traits->windowDecoration = true;
//        traits->doubleBuffer = true;
//        traits->sharedContext = 0;

//        osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
//        if (gc.valid())
//        {
//            osg::notify(osg::INFO)<<"  GraphicsWindow has been created successfully."<<std::endl;
//        }
//        else
//        {
//            osg::notify(osg::NOTICE)<<"  GraphicsWindow has not been created successfully."<<std::endl;
//        }

//        osg::ref_ptr<osg::Camera> camera = new osg::Camera;
//        camera->setGraphicsContext(gc.get());
//        camera->setViewport(new osg::Viewport(0,0, width/numCameras, height));
//        GLenum buffer = traits->doubleBuffer ? GL_BACK : GL_FRONT;
//        camera->setDrawBuffer(buffer);
//        camera->setReadBuffer(buffer);

//        viewer.addSlave(camera.get(), osg::Matrix::scale(aspectRatioScale, 1.0, 1.0)*osg::Matrix::translate(translate_x, 0.0, 0.0), osg::Matrix() );
//    }
//}

//int main( int argc, char **argv )
//{
//    osgViewer::Viewer viewer ;

//    multipleWindowMultipleCameras(viewer, false);

//    viewer.setSceneData(osgDB::readNodeFile("glider.osg"));
//    viewer.realize();
//    viewer.run() ;

//    return 0;
//}

#include "map_osg_baseviewer.h"

MAP_OSG_BaseViewer::MAP_OSG_BaseViewer(osgViewer::View *view, osg::GraphicsContext *gcToShare) :
    osgEarth::QtGui::ViewWidget(view, gcToShare)
{

}

MAP_OSG_BaseViewer::MAP_OSG_BaseViewer(osgViewer::View *view, const QGLFormat &format) :
    osgEarth::QtGui::ViewWidget(view, format)
{

}

MAP_OSG_BaseViewer::~MAP_OSG_BaseViewer()
{

}

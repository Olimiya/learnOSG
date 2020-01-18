//By FreeSouth  ieysx@163.com  www.osgChina.org  2008 6 11

#include "common.h"
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int main()
{
    osgViewer::Viewer viewer;
    viewer.setSceneData(osgDB::readNodeFile("model/free.osg"));
    viewer.realize();
    viewer.run();
}
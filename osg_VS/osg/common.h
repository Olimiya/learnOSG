#ifndef COMMON_H
#define COMMON_H

#ifdef _DEBUG
#include <Windows.h>
#pragma comment(lib, "osgd.lib")
#pragma comment(lib, "osgDBd.lib")
#pragma comment(lib, "osgViewerd.lib")
#pragma comment(lib, "OpenThreadsd.lib")
#pragma comment(lib, "osgGAd.lib")
#pragma comment(lib, "osgUtild.lib")
#pragma comment(lib, "osgTextd.lib")
#pragma comment(lib, "osgWidgetd.lib")
//#pragma comment(lib, "OpenGLGUIRenderer_d.lib")
//#pragma comment(lib, "glew32.lib")
//#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "osgShadowd.lib")
#pragma comment(lib, "osgAnimationd.lib")
#pragma comment(lib, "osgParticled.lib")
#else
#pragma comment(lib, "osg.lib")
#pragma comment(lib, "osgDB.lib")
#pragma comment(lib, "osgViewer.lib")
#pragma comment(lib, "OpenThreads.lib")
#pragma comment(lib, "osgGA.lib")
#pragma comment(lib, "osgUtil.lib")
#pragma comment(lib, "osgText.lib")
#pragma comment(lib, "osgWidget.lib")
#pragma comment(lib, "CEGUIBase.lib")
#pragma comment(lib, "OpenGLGUIRenderer.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "osgShadow.lib")
#pragma comment(lib, "osgAnimation.lib")
#pragma comment(lib, "osgParticle.lib")
#endif
#include <osgViewer//Viewer>
#include <osg/GraphicsContext>
#include <osgGA/GUIEventHandler>
#include <osgGA/GUIActionAdapter>

class ChangeWindow : public osgGA::GUIEventHandler
{
public:
	ChangeWindow() { first = false; }
	bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
	{
		if (!first)
		{
			osgViewer::Viewer * viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
			osgViewer::Viewer::Windows ws;
			first = true;
			viewer->getWindows(ws);
			if (!ws.empty())
			{
				osgViewer::Viewer::Windows::iterator iter = ws.begin();
				for (; iter != ws.end(); iter++)
				{
					(*iter)->setWindowRectangle(300, 100, 800, 600);
					(*iter)->setWindowDecoration(false);
				}
			}

		}
		return false;
	}
private:
	bool first;
};

#endif // COMMON_H

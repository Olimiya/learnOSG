#include "map_osg_viewcontroller.h"
#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TerrainManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>
#include "pickhandler.h"

MAP_OSG_ViewController *MAP_OSG_ViewController::m_instance = nullptr;

MAP_OSG_ViewController::MAP_OSG_ViewController()
{
    m_instance = this;
    m_viewer.setThreadingModel(m_viewer.SingleThreaded);
    connect(&m_timer, &QTimer::timeout, this, &MAP_OSG_ViewController::paint);
    m_timer.start(20);
}

MAP_OSG_ViewController::~MAP_OSG_ViewController()
{

}

MAP_OSG_BaseViewer *MAP_OSG_ViewController::addView(const QString &earthFilePath)
{
    __initializeIfNot();
    int argc = 2;
    char **argv = new char *[2];

    char *appPath = new char[300];
    QByteArray pathByteArray = qApp->applicationFilePath().toLocal8Bit();
    memcpy_s(appPath, 300, pathByteArray.data(), rsize_t(pathByteArray.length() + 1));
    char *earthPath = new char[300];
    QByteArray earthByteArray = earthFilePath.toLocal8Bit();
    memcpy_s(earthPath, 300, earthByteArray.data(), rsize_t(earthByteArray.length() + 1));
    argv[0] = appPath;
    argv[1] = earthPath;

    osg::ArgumentParser args(&argc,argv);
    osg::ref_ptr<osg::Node> node = osgDB::readNodeFiles(args);
    if (!node.valid())
    {
        QMessageBox::critical(nullptr, QString(u8"加载地图错误"), QString(u8"[ osgDB ] readNodeFiles 未能加载地图文件\"%1\".").arg(earthPath));
        return nullptr;
    }

    // 创建一个viewer
    osgViewer::View* view = new osgViewer::View();
    MAP_OSG_BaseViewer* viewWidget = new MAP_OSG_BaseViewer(view);

    // 添加一些操作器
    osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> keyswitchManipulator = new osgGA::KeySwitchMatrixManipulator;

    keyswitchManipulator->addMatrixManipulator( '1', "Trackball", new osgGA::TrackballManipulator() );
    keyswitchManipulator->addMatrixManipulator( '2', "Flight", new osgGA::FlightManipulator() );
    keyswitchManipulator->addMatrixManipulator( '3', "Drive", new osgGA::DriveManipulator() );
    keyswitchManipulator->addMatrixManipulator( '4', "Terrain", new osgGA::TerrainManipulator() );
    view->setCameraManipulator( keyswitchManipulator.get() );

    //添加状态事件
    view->addEventHandler( new osgGA::StateSetManipulator(view->getCamera()->getOrCreateStateSet()) );

    //添加一些常用状态设置
    view->addEventHandler(new osgViewer::StatsHandler);

    //设置数据
    view->setSceneData(node.get());

    //绑定事件处理器
    view->addEventHandler(new PickHandler);
    //view->setCameraManipulator(new osgEarth::Util::EarthManipulator);
    //view->getDatabasePager()->setUnrefImageDataAfterApplyPolicy(true, false);

    m_instance->m_viewer.addView(view);

    delete[] appPath;
    delete[] earthPath;
    delete[] argv;

    return viewWidget;
}

void MAP_OSG_ViewController::removeView(MAP_OSG_BaseViewer *baseViewer)
{
    __initializeIfNot();
    m_instance->m_viewer.removeView(baseViewer->getView());
    if(m_instance)
    {
        m_instance->deleteLater();
        m_instance = nullptr;
    }
}

void MAP_OSG_ViewController::paint()
{
    if (m_viewer.getRunFrameScheme() == osgViewer::ViewerBase::CONTINUOUS ||
            m_viewer.checkNeedToDoFrame() )
    {
        m_viewer.frame();
    }
}

void MAP_OSG_ViewController::__initializeIfNot()
{
    if(m_instance == nullptr)
        m_instance = new MAP_OSG_ViewController;
}

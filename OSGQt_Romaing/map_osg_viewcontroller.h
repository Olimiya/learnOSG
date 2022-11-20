#ifndef MAP_OSG_VIEWCONTROLLER_H
#define MAP_OSG_VIEWCONTROLLER_H

/// MAP_OSG_ViewController
/// 用于控制osgViewer::View的刷新以及地图的读取。
/// 参考MAP_OSG_ExampleWindow使用该类读取地图。

#include <QObject>
#include <osg/Notify>
#include <osgViewer/CompositeViewer>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarth/FileUtils>
#include <QTimer>
#include <QWidget>
#include <QString>
#include <QApplication>
#include <QMessageBox>
#include "map_osg_baseviewer.h"

class MAP_OSG_ViewController : public QObject
{
    Q_OBJECT
public:
    static MAP_OSG_BaseViewer *addView(const QString &earthFilePath);
    static void removeView(MAP_OSG_BaseViewer *baseViewer);

signals:

public slots:
    void paint();

private:
    static inline void __initializeIfNot();
    explicit MAP_OSG_ViewController();

    QTimer m_timer;
    osgViewer::CompositeViewer m_viewer;
    static MAP_OSG_ViewController *m_instance;
};
#endif // MAP_OSG_VIEWCONTROLLER_H

#include "osg_romaingwindow.h"
#include "ui_osg_romaingwindow.h"
#include "map_osg_viewcontroller.h"
#include "pickhandler.h"
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>

OSG_RomaingWindow *OSG_RomaingWindow::instance = nullptr;
OSG_RomaingWindow::OSG_RomaingWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OSG_RomaingWindow)
{
    ui->setupUi(this);
    this->setFocus();
    osgDB::Registry::instance()->getDataFilePathList().push_back("F:\\program\\learnOSG");
    osgDB::Registry::instance()->getDataFilePathList().push_back(
        "F:/program/SimPlanning/build-planning-Desktop_Qt_5_12_1_MSVC2017_64bit-Debug/binV2/"
        "example_data/terrain");

    m_osgWidget = MAP_OSG_ViewController::addView("./world.earth");
    //    QWidget w(this);
    setCentralWidget(m_osgWidget);
}

OSG_RomaingWindow *OSG_RomaingWindow::getInstance()
{
    if (instance == nullptr)
        instance = new OSG_RomaingWindow;
    return instance;
}

OSG_RomaingWindow::~OSG_RomaingWindow()
{
    qDebug() << "delete";
    if (m_osgWidget)
        MAP_OSG_ViewController::removeView(m_osgWidget);
    osgDB::Registry::instance(true);
    delete ui;
}

void OSG_RomaingWindow::closeEvent(QCloseEvent *evnet)
{
    getInstance()->deleteLater();
}

void OSG_RomaingWindow::on_actionon_triggered()
{
    m_osgWidget = MAP_OSG_ViewController::addView("./world.earth");
    setCentralWidget(m_osgWidget);
}

void OSG_RomaingWindow::on_actionoff_triggered()
{
    MAP_OSG_ViewController::removeView(m_osgWidget);
    m_osgWidget->deleteLater();
    m_osgWidget = nullptr;
}

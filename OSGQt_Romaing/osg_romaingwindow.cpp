#include "osg_romaingwindow.h"
#include "ui_osg_romaingwindow.h"
#include "map_osg_viewcontroller.h"
#include "pickhandler.h"
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>

OSG_RomaingWindow* OSG_RomaingWindow::instance = nullptr;
OSG_RomaingWindow::OSG_RomaingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OSG_RomaingWindow)
{
    ui->setupUi(this);
    this->setFocus();
    osgDB::Registry::instance()->getDataFilePathList().push_back("F:\\program\\learnOSG");
    m_osgWidget = MAP_OSG_ViewController::addView("model/house.ive");
//    QWidget w(this);
    setCentralWidget(m_osgWidget);
}

OSG_RomaingWindow *OSG_RomaingWindow::getInstance()
{
    if(instance == nullptr)
        instance = new OSG_RomaingWindow;
    return instance;
}

OSG_RomaingWindow::~OSG_RomaingWindow()
{
    qDebug() << "delete";
    MAP_OSG_ViewController::removeView(m_osgWidget);
    osgDB::Registry::instance(true);
    delete ui;
}

void OSG_RomaingWindow::closeEvent(QCloseEvent *evnet)
{
    getInstance()->deleteLater();
}

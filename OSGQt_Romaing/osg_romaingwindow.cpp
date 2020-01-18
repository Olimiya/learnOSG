#include "osg_romaingwindow.h"
#include "ui_osg_romaingwindow.h"
#include "map_osg_viewcontroller.h"
#include "pickhandler.h"
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>

OSG_RomaingWindow::OSG_RomaingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OSG_RomaingWindow)
{
    ui->setupUi(this);
    this->setFocus();
    m_osgWidget = MAP_OSG_ViewController::addView("model/house.ive");
    QWidget w(this);
    setCentralWidget(m_osgWidget);
}

OSG_RomaingWindow::~OSG_RomaingWindow()
{
    MAP_OSG_ViewController::removeView(m_osgWidget);
    delete ui;
}

//void OSG_RomaingWindow::keyPressEvent(QKeyEvent *k)
//{
//    PickHandler *l_pickHanlder = nullptr;
//    auto l_handlers = m_osgWidget->getView()->getEventHandlers();
//    for(auto i : l_handlers)
//    {
//        auto l_handle = dynamic_cast<PickHandler*>(i.get());
//        if(l_handle != nullptr)
//        {
//            qDebug() << "defined handle";
//            l_pickHanlder = l_handle;
//        }
//    }
//    if(!l_pickHanlder)
//        return;
//    if(k->key() == Qt::Key_O)
//    {
//        qDebug() << "start";
//        l_pickHanlder->setPick(true);
//    }
//    else if(k->key() == Qt::Key_P)
//    {
//        qDebug() << "end";
//        l_pickHanlder->setPick(false);
//    }
//}

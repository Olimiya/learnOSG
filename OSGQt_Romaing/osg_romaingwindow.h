#ifndef OSG_ROMAINGWINDOW_H
#define OSG_ROMAINGWINDOW_H

#include <QMainWindow>
#include "map_osg_baseviewer.h"

namespace Ui {
    class OSG_RomaingWindow;
}

class OSG_RomaingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OSG_RomaingWindow(QWidget *parent = nullptr);
    static OSG_RomaingWindow* getInstance();
    ~OSG_RomaingWindow() override;

protected:
    //virtual void keyPressEvent(QKeyEvent *event);
    virtual void closeEvent(QCloseEvent *evnet) override;

private:
    Ui::OSG_RomaingWindow *ui;
    static OSG_RomaingWindow* instance;
    MAP_OSG_BaseViewer *m_osgWidget;
};

#endif // OSG_ROMAINGWINDOW_H

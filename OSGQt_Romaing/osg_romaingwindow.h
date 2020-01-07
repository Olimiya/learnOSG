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
    ~OSG_RomaingWindow();

protected:
    //virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::OSG_RomaingWindow *ui;
    MAP_OSG_BaseViewer *m_osgWidget;
};

#endif // OSG_ROMAINGWINDOW_H

#include <QApplication>
#include "OSGQt_Romaing/osg_romaingwindow.h"
#include <QString>
#include <QCoreApplication>
#include <QSettings>
#include <QDialog>
#include <QDebug>
#include <QFile>
//检测内存泄漏
#include <vld.h>

void writeRegedit(QString key, QString val)
{
    QSettings Setting(QSettings::NativeFormat, QSettings::SystemScope,
                      QCoreApplication::organizationName(), QCoreApplication::applicationName());
    Setting.setValue(key, val);
}

QString getRegedit(QString key)
{
    QSettings Setting(QSettings::NativeFormat, QSettings::SystemScope,
                      QCoreApplication::organizationName(), QCoreApplication::applicationName());
    QString val = Setting.value(key).toString();
    return val;
}

void removeRegedit(QString key)
{
    QSettings Setting(QSettings::NativeFormat, QSettings::SystemScope,
                      QCoreApplication::organizationName(), QCoreApplication::applicationName());
    Setting.remove(key);
}

QByteArray randomBinaryString(int length)
{
    char *buf = new char[length];
    for(int i = 0; i < length; i++)
        buf[i] = rand() % 255 + 1;
    QByteArray temp(buf);
    return temp;
}

int main(int argc, char *argv[])
{

    //管理员权限测试：
    //结果：使用.manifest + mt.exe附加管理员权限
    QApplication a(argc, argv);
//    QCoreApplication::setOrganizationName("South China University of Technology");
//    QCoreApplication::setApplicationName("Xiao Neng Ruan Jian");
//    writeRegedit("cd", "hhh");
//    auto val = getRegedit("cd");
//    removeRegedit("cd");
//    removeRegedit("cdKey");

//    OSG_RomaingWindow w;
//    w.show();
    auto temp = OSG_RomaingWindow::getInstance();
    temp->show();

//    if(val.isNull())
//    {

//    }
//    else
//    {
//        QDialog *b = new QDialog;
//        b->show();
//    }

    return a.exec();
}

#include "globalapplication.h"
#include <QKeyEvent>
#include <QDebug>
#include <QDate>

GlobalApplication::GlobalApplication(int &argc,char **argv):
QApplication(argc,argv)
{

}

GlobalApplication::~GlobalApplication()
{

}

void GlobalApplication::setWindowInstance(QWidget *wnd)
{
     widget = wnd;
}

bool GlobalApplication::notify(QObject *obj, QEvent *e)
{
    const QMetaObject* objMeta = obj->metaObject();
    QString clName = objMeta->className();

    if(e->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        if(keyEvent->key() == Qt::Key_F1)
        {
            QDBG<< clName;
            QDBG << "F1";
        }
//      widget->keyPress(keyEvent);
     }
    else if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(e);
        if(mouseEvent->buttons() == Qt::LeftButton)
        {

            QDBG << "左键";
        }
        else if (mouseEvent->buttons() == Qt::RightButton) {
            QDBG << "右键";
        }
    }
    return QApplication::notify(obj,e);
}

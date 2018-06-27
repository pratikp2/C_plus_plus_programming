#include <QtCore/QCoreApplication>
#include <QVariant>
#include <QDBusAbstractInterface>
#include <QDebug>
#include "demoifadaptor.h"
#include <QObject>

/*
 * class MyDemo is written to handle the functionality of adaptor i.e.
 *  what methods should actually do on calling from proxy..
 *
 * */

class MyDemo : public QObject
{
Q_OBJECT
public:
explicit MyDemo(QObject *parent = 0);

public Q_SLOTS:
void SayBye();
void SayHello(const QString &name, const QVariantMap &customdata);
Q_SIGNALS:
void LateEvent(const QString &eventkind);

};

MyDemo::MyDemo(QObject *parent)
{
qDebug()<<"server::Constructor Called";

}

void MyDemo::SayBye()
{
qDebug()<<"server::Say Bye";
emit LateEvent("Received SayBye Request");

}

void MyDemo::SayHello(const QString &name, const QVariantMap &customdata)
{
qDebug()<<"server::Say Hello"<<name<<customdata;
emit LateEvent("Received Hello Request");

}

int main(int argc, char *argv[])
{
    qDebug()<<"in server::main";
QCoreApplication a(argc, argv);

MyDemo* demo = new MyDemo;

new DemoIfAdaptor(demo);
/*
 *Dbus connection
 * registerService should be same in proxy and server
 * registerObject used to resgister object demo at the path /1234
 * path must be always start with "/"
 * */
QDBusConnection connection = QDBusConnection::sessionBus();
bool ret = connection.registerService("com.nokia.Demo");
ret = connection.registerObject("/1234", demo);

return a.exec();
}

#include "main.moc"

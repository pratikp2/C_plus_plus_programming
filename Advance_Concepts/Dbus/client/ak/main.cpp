#include <QtCore/QCoreApplication>
#include <QVariant>
#include <QDBusAbstractInterface>
#include <QDebug>
#include "demoif.h"
#include <QObject>
#include <QVariantMap>

/*
 * class Demo_Client is written to handle the functionality of client/proxy
 *
 * */

class Demo_Client : public QObject
{
Q_OBJECT
public:
explicit Demo_Client(QObject *parent = 0);
void call_method();

public Q_SLOTS:
void mySlot(QString);

private:
DemoIf* m_client;

};

QVariantMap map;

Demo_Client::Demo_Client(QObject *parent)
{

qDebug()<<" Demo_Client Constructor Called"<<parent;
/*
 * Register of DemoIf with the asme service as the adaptor with the same path
 * */
m_client = new DemoIf("com.nokia.Demo", "/1234", QDBusConnection::sessionBus(), 0);
QObject::connect(m_client, SIGNAL(LateEvent(QString)), this, SLOT(mySlot(QString)));
}

void Demo_Client::mySlot(QString recv_msg)
{
qDebug()<<" Demo_Client::mySlot received";
qDebug()<<recv_msg;

}

void Demo_Client::call_method()
{
qDebug()<<" Demo_Client::call_method ";
qDebug()<<" Demo_Client::call_method::SayBye ";
m_client->SayBye();

map["string"] = QVariant("foo");
map["bool"] = QVariant(false);
//qDebug()<<" Demo_Client::call_method::SayHello(Shreyas,map) ";
m_client->SayHello("Shreyas",map);

}

int main(int argc, char *argv[])
{
qDebug()<<"in client::main";
QCoreApplication a(argc, argv);

Demo_Client *demo_client= new Demo_Client;
demo_client->call_method();

return a.exec();
}

#include "main.moc"

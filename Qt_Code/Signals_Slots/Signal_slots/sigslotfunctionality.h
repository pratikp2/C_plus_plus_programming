#ifndef SIGSLOTFUNCTIONALITY_H
#define SIGSLOTFUNCTIONALITY_H

#include <QObject>
#include <QString>
#include <QDebug>

class SigSlotFunctionality : public QObject
{
    Q_OBJECT
    public:
        SigSlotFunctionality();

    signals :
        void speak_signal (QString id);

    public slots :
        void listen_slot (QString id);


};

#endif // SIGSLOTFUNCTIONALITY_H

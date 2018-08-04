#include "sigslotfunctionality.h"

SigSlotFunctionality::SigSlotFunctionality()
{

}

void SigSlotFunctionality :: listen_slot(QString id)
{
    qDebug() << "Slot is Hit : " << id;
}

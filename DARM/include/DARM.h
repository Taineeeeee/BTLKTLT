#ifndef DARM_H
#define DARM_H
#include "Shipper.h"
#include "Deliver.h"
#include "Receiver.h"
#include "Shipment.h"

class DARM: public Shipper, public Deliver, public Receiver, public Shipment
{
    public:
        void setDARM(std::string, std::string);
};

#endif // DARM_H

#include "DARM.h"

void DARM::setDARM(std::string& deliveryID, std::string& receivedID, std::string& shipmentID){
    this->deliverId = deliveryID;
    this->receiverId = receivedID;
    this->shipmentId = shipmentID;
}


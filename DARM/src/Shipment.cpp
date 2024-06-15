#include "Shipment.h"

Shipment::Shipment(){}

Shipment::~Shipment(){}

std::string Shipment::getShipmentId() const {
        return shipmentId;
    }

std::string Shipment::getShipmentName() const {
    return shipmentName;
}

int Shipment::getQuantity() const {
    return quantity;
}

Date Shipment::getReceiveDate() const {
    return receiveDate;
}

Date Shipment::getDeliveryDate() const {
    return deliveryDate;
}

ShipmentStatus Shipment::getStatus() const {
    return status;
}

PaymentStatus Shipment::getPStatus() const {
    return pstatus;
}

void Shipment::setShipmentId(std::string& id) {
    shipmentId = id;
}

void Shipment::setShipmentName(std::string& name) {
    shipmentName = name;
}

void Shipment::setQuantity(int qty) {
    quantity = qty;
}

void Shipment::setReceiveDate(Date& rDate) {
    receiveDate = rDate;
}

void Shipment::setDeliveryDate(Date& dDate) {
    deliveryDate = dDate;
}

void Shipment::setStatus(ShipmentStatus stat) {
    status = stat;
}

void Shipment::setPStatus(PaymentStatus pStat) {
    pstatus = pStat;
}

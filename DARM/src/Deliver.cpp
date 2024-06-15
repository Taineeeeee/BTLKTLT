#include "Deliver.h"

Deliver::Deliver(){}

Deliver::~Deliver(){}

std::string Deliver::getDeliverName() const {
    return deliverName;
}

std::string Deliver::getDeliverAddress() const {
    return deliverAddress;
}

std::string Deliver::getDeliverId() const {
    return deliverId;
}

int Deliver::getDeliverPhone() const {
    return deliverPhone;
}

void Deliver::setDeliverName(const std::string& name) {
    deliverName = name;
}

void Deliver::setDeliverAddress(const std::string& address) {
    deliverAddress = address;
}

void Deliver::setDeliverId(const std::string& id) {
    deliverId = id;
}

void Deliver::setDeliverPhone(int phone) {
    deliverPhone = phone;
}

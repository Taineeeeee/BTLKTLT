#include "Receiver.h"

Receiver::Receiver() {}

Receiver::~Receiver() {}

std::string Receiver::getReceiverName() const {
    return receiverName;
}

std::string Receiver::getReceiverAddress() const {
    return receiverAddress;
}

std::string Receiver::getReceiverId() const {
    return receiverId;
}

int Receiver::getReceiverPhone() const {
    return receiverPhone;
}

void Receiver::setReceiverName(const std::string& name) {
    receiverName = name;
}

void Receiver::setReceiverAddress(const std::string& address) {
    receiverAddress = address;
}

void Receiver::setReceiverId(const std::string& id) {
    receiverId = id;
}

void Receiver::setReceiverPhone(int phone) {
    receiverPhone = phone;
}

#include "Order.h"

Order::Order(Person &sender, Person &receiver, Shipper &shipper, Date &sendDate, Date &receiveDate, ShipmentStatus &status, int id, string goodsInfo)
            :sender(sender),
             receiver(receiver),
             shipper(shipper),
             sendDate(sendDate),
             receiveDate(receiveDate),
             status(status),
             id(id),
             goodsInfo(goodsInfo) {}

Order::Order(int idSender, string nameSender, string phonenumberSender, string addressSender,
      int idReceiver, string nameReceiver, string phonenumberReceiver, string addressReceiver,
      int idShipper, string nameShipper, string phonenumberShipper,
      Date sendDate,
      Date receiveDate,
      ShipmentStatus status,
      int id, string info)
      :sender(idSender,nameSender,phonenumberSender,addressSender),
       receiver(idReceiver,nameReceiver,phonenumberReceiver,addressReceiver),
       shipper(idShipper,nameShipper,phonenumberShipper),
       sendDate(sendDate),
       receiveDate(receiveDate),
       status(status),
       id(id),
       goodsInfo(info) {}

// Getter và Setter cho sendDate
Date Order::getSendDate() const{
    return sendDate;
}

void Order::setSendDate(const Date &date) {
    sendDate = date;
}

// Getter và Setter cho receiveDate
Date Order::getReceiveDate() const {
    return receiveDate;
}

void Order::setReceiveDate(const Date &date) {
    receiveDate = date;
}

// Getter và Setter cho status
ShipmentStatus Order::getStatus() const {
    return status;
}

void Order::setStatus(ShipmentStatus s) {
    status = s;
}

Person Order::getSender() const { return sender; }
void Order::setSender(const Person &s) { sender = s; }

Person Order::getReceiver() const { return receiver; }
void Order::setReceiver(const Person &r) { receiver = r; }

Shipper Order::getShipper() const { return shipper; }
void Order::setShipper(const Shipper &s) { shipper = s; }

int Order::getId() const {
    return id;
}

void Order::setId(int id) {
    this->id = id;
}

string Order::getGoodsinfor() const {
    return goodsInfo;
}

void Order::setGoodsinfor(string info) {
    goodsInfo = info;
}

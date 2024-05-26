#pragma once
class Shipment {
public:
    string shipmentId;
    Date receiveDate;
    string customerName;
    string deliveryAddress;
    string goodsInfo;
    ShipmentStatus status;

    Shipment(string id, Date date, string customer, string address, string goods)
        : shipmentId(id), receiveDate(date), customerName(customer), deliveryAddress(address), goodsInfo(goods), status(Received) {}

    void updateStatus(ShipmentStatus newStatus) {
        status = newStatus;
    }

    void printInfo() const {
        cout << "Shipment ID: " << shipmentId << "\n"
            << "Receive Date: " << dateToString(receiveDate) << "\n"
            << "Customer Name: " << customerName << "\n"
            << "Delivery Address: " << deliveryAddress << "\n"
            << "Goods Info: " << goodsInfo << "\n"
            << "Status: " << (status == Received ? "Received" : status == InTransit ? "In Transit" : "Delivered") << "\n";
    }
};


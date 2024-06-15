#ifndef SHIPMENT_H
#define SHIPMENT_H

// Shipment status enumeration
enum ShipmentStatus { Received, InTransit, Delivered };

// Payment status enumeration
enum PaymentStatus { Unpaid, Paid };

// Date structure
struct Date {
    int day, month, year;
};

class Shipment
{
    protected:
        std::string shipmentId;
        std::string shipmentName;
        int quantity;
        Date receiveDate, deliveryDate;
        ShipmentStatus status;
        PaymentStatus pstatus;
    public:
        Shipment();
        virtual ~Shipment();
        std::string getShipmentId() const;
        std::string getShipmentName() const;
        int getQuantity() const;
        Date getReceiveDate() const;
        Date getDeliveryDate() const;
        ShipmentStatus getStatus() const;
        PaymentStatus getPStatus() const;
        void setShipmentId(std::string& id);
        void setShipmentName(std::string& name);
        void setQuantity(int qty);
        void setReceiveDate(Date& rDate);
        void setDeliveryDate(Date& dDate);
        void setStatus(ShipmentStatus stat);
        void setPStatus(PaymentStatus pStat);
};

#endif // SHIPMENT_H

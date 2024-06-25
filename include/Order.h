#ifndef ORDER_H
#define ORDER_H
#include "Person.h"
#include "Shipper.h"
struct Date { int day, month, year; };

enum ShipmentStatus { Pending, InTransit, Delivered };

class Order
{
    private:
        Person         sender;
        Person       receiver;
        Shipper        shipper;
        Date           sendDate;
        Date           receiveDate;
        ShipmentStatus status;
        int            id;
        string         goodsInfo;
    public:
        Order(Person &sender, Person &receiver, Shipper &shipper, Date &sendDate, Date &receiveDate, ShipmentStatus &status, int id, string goodsInfo);

        Order(int idSender = 0, string nameSender = "", string phonenumberSender = "", string addressSender = "",
              int idReceiver = 0, string nameReceiver = "", string phonenumberReceiver = "", string addressReceiver = "",
              int idShipper = 0, string nameShipper = "", string phonenumberShipper = "",
              Date sendDate = {0,0,0},
              Date receiveDate = {0,0,0},
              ShipmentStatus status = Pending,
              int id = 0, const string info = "");

        // Getter và Setter cho sendDate
        Date getSendDate() const;
        void setSendDate(const Date &date);

        // Getter và Setter cho receiveDate
        Date getReceiveDate() const;
        void setReceiveDate(const Date &date);

        // Getter và Setter cho status
        ShipmentStatus getStatus() const;
        void setStatus(ShipmentStatus s);

        Person getSender() const;
        void setSender(const Person &s);

        Person getReceiver() const;
        void setReceiver(const Person &r);

        Shipper getShipper() const;
        void setShipper(const Shipper &s);

        int getId() const;
        void setId(int id);

        string getGoodsinfor() const;
        void setGoodsinfor(string info);
};

#endif // ORDER_H

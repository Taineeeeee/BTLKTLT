#ifndef DELIVER_H
#define DELIVER_H


class Deliver
{
    protected:
        std::string deliverName;
        std::string deliverAddress;
        std::string deliverId;
        int deliverPhone;
    public:
        Deliver();
        virtual ~Deliver();
        std::string getDeliverName() const;
        std::string getDeliverAddress() const;
        std::string getDeliverId() const;
        int getDeliverPhone() const;
        void setDeliverName(std::string& name);
        void setDeliverAddress(std::string& address);
        void setDeliverId(std::string& id);
        void setDeliverPhone(int phone);
};

#endif // DELIVER_H

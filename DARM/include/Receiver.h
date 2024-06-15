#ifndef RECEIVER_H
#define RECEIVER_H


class Receiver
{
    protected:
        std::string receiverName;
        std::string receiverAddress;
        std::string receiverId;
        int receiverPhone;
    public:
        Receiver();
        virtual ~Receiver();
        std::string getReceiverName() const;
        std::string getReceiverAddress() const;
        std::string getReceiverId() const;
        int getReceiverPhone() const;
        void setReceiverName(const std::string& name);
        void setReceiverAddress(const std::string& address);
        void setReceiverId(const std::string& id);
        void setReceiverPhone(int phone);
};

#endif // RECEIVER_H

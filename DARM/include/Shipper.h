#ifndef SHIPPER_H
#define SHIPPER_H


class Shipper
{
    protected:
        int id;
        std::string name;
        std::string phone;
    public:
        Shipper();
        virtual ~Shipper();
        int getid()const;
        std::string getname()const;
        std::string getphone()const;
        void setid(int id);
        void setname(std::string name);
        void setphone(std::string phone);
};

#endif // SHIPPER_H

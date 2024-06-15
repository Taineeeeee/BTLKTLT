#ifndef SHIPPER_H
#define SHIPPER_H
#include <string>

class Shipper
{
    protected:
        std::string id;
        std::string name;
        std::string phone;
    public:
        Shipper();
        virtual ~Shipper();
        std::string getid()const;
        std::string getname()const;
        std::string getphone()const;
        void setid(std::string id);
        void setname(std::string name);
        void setphone(std::string phone);
};

#endif // SHIPPER_H

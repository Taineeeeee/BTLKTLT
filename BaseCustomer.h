#ifndef BASECUSTOMER_H
#define BASECUSTOMER_H

#include <string>

class BaseCustomer {
public:
    std::string ID;
    std::string Name;
    std::string Address;

    BaseCustomer(std::string id, const std::string& name, const std::string& address)
        : ID(id), Name(name), Address(address) {}
};

#endif // BASECUSTOMER_H

#ifndef BASECUSTOMER_H
#define BASECUSTOMER_H

#include <string>

class BaseCustomer {
public:
    int ID;
    std::string Name;
    std::string Address;

    BaseCustomer(int id, const std::string& name, const std::string& address)
        : ID(id), Name(name), Address(address) {}
};

#endif // BASECUSTOMER_H

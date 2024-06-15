#include "Shipper.h"

Shipper::Shipper(){}

Shipper::~Shipper(){}

std::string Shipper::getid()const{
    return id;
}

std::string Shipper::getname()const{
    return name;
}

std::string Shipper::getphone()const{
    return phone;
}

void Shipper::setid(std::string id){
    this->id = id;
}

void Shipper::setname(std::string name){
    this->name = name;
}

void Shipper::setphone(std::string phone){
    this->phone = phone;
}

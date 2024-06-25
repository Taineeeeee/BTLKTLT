#ifndef SHIPPER_H
#define SHIPPER_H


#include <iostream>
#include <string>
using namespace std;

class Shipper
{
    private:
        int id;
        string name;
        string phonenumber;
    public:
        // Constructor
    Shipper(int id = 0, string name = "", string phonenumber = "")
        : id(id), name(name), phonenumber(phonenumber) {}

    int getId() ;
    void setId(int id);

    // Getter and Setter for name
    string getName() ;
    void setName(const string &name);

    // Getter and Setter for phonenumber
    string getPhonenumber() ;
    void setPhonenumber(const string &phonenumber);

    // Display function
    void display() ;
};

#endif // SHIPPER_H

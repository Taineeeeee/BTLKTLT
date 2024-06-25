#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person
{
    private:
        int id;
        string name;
        string phonenumber;
        string address;
    public:
        // Constructor
    Person(int id = 0, string name = "", string phonenumber = "", string address = "")
        : id(id), name(name), phonenumber(phonenumber), address(address) {}

    int getId() ;
    void setId(int id);

    // Getter and Setter for name
    string getName() ;
    void setName(const string &name);

    // Getter and Setter for phonenumber
    string getPhonenumber() ;
    void setPhonenumber(const string &phonenumber);

    // Getter and Setter for address
    string getAddress() ;
    void setAddress(const string &address);

    // Display function
    void display() ;
};
#endif // PERSON_H

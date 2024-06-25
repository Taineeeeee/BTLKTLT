#include "Person.h"

// Getter and Setter for id
int Person::getId()  { return id; }
void Person::setId(int id) { this->id = id; }

// Getter and Setter for name
string Person::getName()  { return name; }
void Person::setName(const string &name) { this->name = name; }

// Getter and Setter for phonenumber
string Person::getPhonenumber()  { return phonenumber; }
void Person::setPhonenumber(const string &phonenumber) { this->phonenumber = phonenumber; }

// Getter and Setter for address
string Person::getAddress()  { return address; }
void Person::setAddress(const string &address) { this->address = address; }

// Display function
void Person::display()  {
    cout << "Person Information:" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone Number: " << phonenumber << endl;
    cout << "Address: " << address << endl;
}

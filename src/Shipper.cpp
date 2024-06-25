#include "Shipper.h"

// Getter and Setter for id
int Shipper::getId()  { return id; }
void Shipper::setId(int id) { this->id = id; }

// Getter and Setter for name
string Shipper::getName()  { return name; }
void Shipper::setName(const string &name) { this->name = name; }

// Getter and Setter for phonenumber
string Shipper::getPhonenumber()  { return phonenumber; }
void Shipper::setPhonenumber(const string &phonenumber) { this->phonenumber = phonenumber; }

// Display function
void Shipper::display()  {
    cout << "Shipper Information:" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone Number: " << phonenumber << endl;
}

#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <windows.h>

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

class Date {
    public:
        int day, month, year;

        bool operator>(const Date &other) const
        {
        if (year != other.year)
            return year > other.year;
        if (month != other.month)
            return month > other.month;
        return day > other.day;
        }
};

enum ShipmentStatus { Pending, InTransit, Delivered };

class Order
{
    private:
        Person         sender;
        Person       receiver;
        Shipper        shipper;
        Date           sendDate;
        Date           receiveDate;
        ShipmentStatus status;
        int            id;
        string         goodsInfo;
    public:
        Order(Person &sender, Person &receiver, Shipper &shipper, Date &sendDate, Date &receiveDate, ShipmentStatus &status, int id, string goodsInfo);

        Order(int idSender = 0, string nameSender = "", string phonenumberSender = "", string addressSender = "",
              int idReceiver = 0, string nameReceiver = "", string phonenumberReceiver = "", string addressReceiver = "",
              int idShipper = 0, string nameShipper = "", string phonenumberShipper = "",
              Date sendDate = {0,0,0},
              Date receiveDate = {0,0,0},
              ShipmentStatus status = Pending,
              int id = 0, const string info = "");

        // Getter và Setter cho sendDate
        Date getSendDate() const;
        void setSendDate(const Date &date);

        // Getter và Setter cho receiveDate
        Date getReceiveDate() const;
        void setReceiveDate(const Date &date);

        // Getter và Setter cho status
        ShipmentStatus getStatus() const;
        void setStatus(ShipmentStatus s);
        // Getter và Setter cho Sender
        Person getSender() const;
        void setSender(const Person &s);
        // Getter và Setter cho Receiver
        Person getReceiver() const;
        void setReceiver(const Person &r);
        // Getter và Setter cho Shipper
        Shipper getShipper() const;
        void setShipper(const Shipper &s);
        // Getter và Setter cho ID
        int getId() const;
        void setId(int id);
        // Getter và Setter cho goodsinfor
        string getGoodsinfor() const;
        void setGoodsinfor(string info);
};

Order::Order(Person &sender, Person &receiver, Shipper &shipper, Date &sendDate, Date &receiveDate, ShipmentStatus &status, int id, string goodsInfo)
            :sender(sender),
             receiver(receiver),
             shipper(shipper),
             sendDate(sendDate),
             receiveDate(receiveDate),
             status(status),
             id(id),
             goodsInfo(goodsInfo) {}

Order::Order(int idSender, string nameSender, string phonenumberSender, string addressSender,
      int idReceiver, string nameReceiver, string phonenumberReceiver, string addressReceiver,
      int idShipper, string nameShipper, string phonenumberShipper,
      Date sendDate,
      Date receiveDate,
      ShipmentStatus status,
      int id, string info)
      :sender(idSender,nameSender,phonenumberSender,addressSender),
       receiver(idReceiver,nameReceiver,phonenumberReceiver,addressReceiver),
       shipper(idShipper,nameShipper,phonenumberShipper),
       sendDate(sendDate),
       receiveDate(receiveDate),
       status(status),
       id(id),
       goodsInfo(info) {}

// Getter và Setter cho sendDate
Date Order::getSendDate() const{
    return sendDate;
}

void Order::setSendDate(const Date &date) {
    sendDate = date;
}

// Getter và Setter cho receiveDate
Date Order::getReceiveDate() const {
    return receiveDate;
}

void Order::setReceiveDate(const Date &date) {
    receiveDate = date;
}

// Getter và Setter cho status
ShipmentStatus Order::getStatus() const {
    return status;
}

void Order::setStatus(ShipmentStatus s) {
    status = s;
}

Person Order::getSender() const { return sender; }
void Order::setSender(const Person &s) { sender = s; }

Person Order::getReceiver() const { return receiver; }
void Order::setReceiver(const Person &r) { receiver = r; }

Shipper Order::getShipper() const { return shipper; }
void Order::setShipper(const Shipper &s) { shipper = s; }

int Order::getId() const {
    return id;
}

void Order::setId(int id) {
    this->id = id;
}

string Order::getGoodsinfor() const {
    return goodsInfo;
}

void Order::setGoodsinfor(string info) {
    goodsInfo = info;
}

class Manage
{
    public:
        Manage();
        ~Manage();
        void Launch();
    private:
        void SaveData();
        void LoadData();

        void Menu();

        void Menu_Order();
        void Menu_Order_Add();
        void Menu_Order_Update();
        void Menu_Order_Delete();
        void Menu_Order_List();
        void Menu_Order_Search();
        void Menu_Order_List_SortID();
        void Menu_Order_List_SendDate();
        void Menu_Order_List_ReceiceDate();
        void Menu_Order_Print();
        vector<Order>::iterator findOrderById(int id);

        void Menu_Sender();
        void Menu_Sender_Add();
        void Menu_Sender_Update();
        void Menu_Sender_Delete();
        void Menu_Sender_List();
        void Menu_Sender_Search();
        vector<Person>::iterator findSenderById(int id);

        void Menu_Receiver();
        void Menu_Receiver_Add();
        void Menu_Receiver_Update();
        void Menu_Receiver_Delete();
        void Menu_Receiver_List();
        void Menu_Receiver_Search();
        vector<Person>::iterator findReceiverById(int id);

        void Menu_Shipper();
        void Menu_Shipper_Add();
        void Menu_Shipper_Update();
        void Menu_Shipper_Delete();
        void Menu_Shipper_List();
        void Menu_Shipper_Search();
        vector<Shipper>::iterator findShipperById(int id);

        string dateToString(const Date& date);

        void Header(string text);

        int getChoice(int m, int M);
        int getMenuChoice(vector<string> options);

        vector<Person>   senders;
        vector<Person>   receivers;
        vector<Shipper>  shippers;
        vector<Order>    orders;
        int              init;
        int              IdSender;
        int              IdReceiver;
        int              IdShipper;
        int              IdOrder;
};


Manage::Manage()
{
    LoadData();
}

Manage::~Manage()
{
    SaveData();
}

void Manage::Launch()
{
    Menu();
}

void Manage::SaveData()
{
    ofstream output;
    output.open("order.txt");
    for ( const auto& order : orders)
    {
        output << order.getId() << endl;
        output << order.getGoodsinfor() << endl;
        output << order.getSender().getId() << endl;
        output << order.getReceiver().getId() << endl;
        output << order.getShipper().getId() << endl;
        output << order.getSendDate().day << endl;
        output << order.getSendDate().month << endl;
        output << order.getSendDate().year << endl;
        output << order.getReceiveDate().day << endl;
        output << order.getReceiveDate().month << endl;
        output << order.getReceiveDate().year << endl;
        output << order.getStatus() << endl;
        output << endl;
    }
    output.close();

    output.open("sender.txt");
    for ( int i=0; i<senders.size(); i++)
    {
        output << senders[i].getId() << endl;
        output << senders[i].getName() << endl;
        output << senders[i].getPhonenumber() << endl;
        output << senders[i].getAddress() << endl;
        output << endl;
    }
    output.close();

    output.open("receiver.txt");
    for ( int i=0; i<receivers.size(); i++)
    {
        output << receivers[i].getId() << endl;
        output << receivers[i].getName() << endl;
        output << receivers[i].getPhonenumber() << endl;
        output << receivers[i].getAddress() << endl;
        output << endl;
    }
    output.close();

    output.open("shipper.txt");
    for ( int i=0; i<shippers.size(); i++)
    {
        output << shippers[i].getId() << endl;
        output << shippers[i].getName() << endl;
        output << shippers[i].getPhonenumber() << endl;
        output << endl;
    }
    output.close();

    output.open("id.txt");
    output << IdOrder << endl;
    output << IdSender << endl;
    output << IdReceiver << endl;
    output << IdShipper << endl;
    output.close();
}

void Manage::LoadData()
{
    int idSender, idReceiver, idShipper, idOrder;
    Order order;
    Date sendDate, receiveDate;
    int status;
    string goodsInfo;

    Person osender;
    Person oreceiver;
    Shipper oshipper;

    string name, phonenumber, address;

    ifstream input;

    input.open("sender.txt");
    while (input >> idSender)
    {
        input.ignore();
        getline(input, name);
        getline(input, phonenumber);
        getline(input, address);
        osender.setId(idSender);
        osender.setName(name);
        osender.setPhonenumber(phonenumber);
        osender.setAddress(address);
        senders.push_back(osender);
    }
    input.close();

    input.open("receiver.txt");
    while (input >> idReceiver)
    {
        input.ignore();
        getline(input, name);
        getline(input, phonenumber);
        getline(input, address);
        oreceiver.setId(idReceiver);
        oreceiver.setName(name);
        oreceiver.setPhonenumber(phonenumber);
        oreceiver.setAddress(address);
        receivers.push_back(oreceiver);
    }
    input.close();

    input.open("shipper.txt");
    while (input >> idShipper)
    {
        input.ignore();
        getline(input, name);
        getline(input, phonenumber);
        oshipper.setId(idShipper);
        oshipper.setName(name);
        oshipper.setPhonenumber(phonenumber);
        shippers.push_back(oshipper);
    }
    input.close();

    Order loadOrder;
    input.open("order.txt");
    while (input >> idOrder)
    {
        input.ignore();
        getline(input, goodsInfo);
        input >> idSender;
        input >> idReceiver;
        input >> idShipper;
        input >> sendDate.day;
        input >> sendDate.month;
        input >> sendDate.year;
        input >> receiveDate.day;
        input >> receiveDate.month;
        input >> receiveDate.year;
        input >> status;

        loadOrder.setId(idOrder);
        loadOrder.setGoodsinfor(goodsInfo);

        for (auto& sender : senders)
        {
            if (sender.getId() == idSender)
            {
                osender = sender;
                loadOrder.setSender(osender);
            }
        }

        for (auto& receiver : receivers)
        {
            if (receiver.getId() == idReceiver)
            {
                oreceiver = receiver;
                loadOrder.setReceiver(oreceiver);
            }
        }

        for (auto& shipper : shippers)
        {
            if (shipper.getId() == idShipper)
            {
                oshipper = shipper;
                loadOrder.setShipper(oshipper);
            }
        }

        loadOrder.setSendDate(sendDate);
        loadOrder.setReceiveDate(receiveDate);
        loadOrder.setStatus(static_cast<ShipmentStatus>(status));

        orders.push_back(loadOrder);
    }
    input.close();

    input.open("id.txt");
    input >> IdOrder;
    input >> IdSender;
    input >> IdReceiver;
    input >> IdShipper;
    input.close();
}


void Manage::Menu()
{
    system("CLS");
    bool done = false;
    while(!done)
    {
        system("CLS");
        Header("DELIVERY & RECEIVE MANAGEMENT");
        int choice = getMenuChoice( {"Quit", "Oder Manage", "Sender Manage", "Receiver Manage", "Shipper Manage"} );

        switch(choice)
        {
        case 0:
            done = true;
            break;
        case 1:
            system("CLS");
            Menu_Order();
            break;
        case 2:
            system("CLS");
            Menu_Sender();
            break;
        case 3:
            system("CLS");
            Menu_Receiver();
            break;
        case 4:
            system("CLS");
            Menu_Shipper();
            break;
        }
    }
}

void Manage::Menu_Order()
{
    bool done = false;
    while(!done)
    {
        system("CLS");
        Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage");
        int choice = getMenuChoice( {"Quit", "Add Order", "Update Order", "Delete Order", "All Order Information", "Search Order"} );

        switch(choice)
        {
        case 0:
            system("CLS");
            done = true;
            break;
        case 1:
            system("CLS");
            Menu_Order_Add();
            system("pause");
            break;
        case 2:
            system("CLS");
            Menu_Order_Update();
            system("pause");
            break;
        case 3:
            system("CLS");
            Menu_Order_Delete();
            system("pause");
            break;
        case 4:
            system("CLS");
            Menu_Order_List();
            break;
        case 5:
            system("CLS");
            Menu_Order_Search();
            system("pause");
            break;
        }
    }
}

void Manage::Menu_Order_Add()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Add Order");
    int idSender, idReceiver, idShipper, idOrder = IdOrder;
    Order order;
    Date sendDate, receiveDate;
    int status;
    string goodsInfo;

    Person osender;
    Person oreceiver;
    Shipper oshipper;

    cout << "Enter Good Information: ";
    getline(cin, goodsInfo);
    order.setGoodsinfor(goodsInfo);

    cout << "Enter Sender ID: ";
    cin >> idSender;
    cin.ignore();

    auto it = findSenderById(idSender);
    if ( it != senders.end())
    {
        for ( auto& sender : senders)
        {
            if (sender.getId() == idSender)
            {
                osender = sender;
                order.setSender(osender);
            }
        }
    }
    else
    {
        cout << "Sender Information not exist." << endl;
        return;
    }

    cout << "Enter Receiver ID: " ;
    cin >> idReceiver;
    cin.ignore();

    auto it1 = findReceiverById(idReceiver);
    if ( it1 != receivers.end())
    {
        for ( auto& receiver : receivers)
        {
            if (receiver.getId() == idReceiver)
            {
                oreceiver = receiver;
                order.setReceiver(oreceiver);
            }
        }
    }
    else
    {
        cout << "Sender Information not exist." << endl;
        return;
    }

    cout << "Enter Shipper ID: " ;
    cin >> idShipper;
    cin.ignore();

    auto it2 = findShipperById(idShipper);
    if ( it2 != shippers.end())
    {
        for ( auto& shipper : shippers)
        {
            if (shipper.getId() == idShipper)
            {
                oshipper = shipper;
                order.setShipper(oshipper);
            }
        }
    }
    else
    {
        cout << "Shipper Information not exist." << endl;
        return;
    }

    cout << "Enter Send Date (day month year): ";
    cin >> sendDate.day >> sendDate.month >> sendDate.year;
    cin.ignore();

    cout << "Enter Receive Date (day month year): ";
    cin >> receiveDate.day >> receiveDate.month >> receiveDate.year;
    cin.ignore();

    cout << "Enter Order Status (0: Pending, 1: InTransit, 2: Delivered): ";
    cin >> status;
    cin.ignore();

    order.setSendDate(sendDate);
    order.setReceiveDate(receiveDate);
    order.setStatus(static_cast<ShipmentStatus>(status));

    order.setId(idOrder);

    orders.push_back(order);
    system("CLS");
    Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Add Order");
    cout << "Order Added with ID: " << idOrder << endl;
    IdOrder++;
}

void Manage::Menu_Order_Update()
{
    system("CLS");
    Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Update Order");
    int id;
    cout << "Enter Shipment ID to update: ";
    cin >> id;
    cin.ignore();

    auto it = findOrderById(id);

    if ( it != orders.end() )
    {
        bool done = false;
        while(!done)
        {
            system("CLS");
            Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Update Order");
            int choice = getMenuChoice( {"Return", "Update Send Date", "Update Receive Date", "Update Status"} );

            switch(choice)
            {
            case 0:
                system("CLS");
                done = true;
                break;
            case 1:
                system("CLS");
                Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Update Order > Update Send Date");
                for (auto& order : orders) {
                    if (order.getId() == id) {
                        Date sendDate;
                        cout << "Enter new send date (day month year): ";
                        cin >> sendDate.day >> sendDate.month >> sendDate.year;
                        order.setSendDate(sendDate);
                        system("CLS");
                        Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Update Order > Update Send Date");
                        cout << "Send Date updated successfully.\n";
                    }
                }
                system("pause");
                break;
            case 2:
                system("CLS");
                Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Update Order > Update Receive Date");
                for (auto& order : orders) {
                    if (order.getId() == id) {
                        Date receiveDate;
                        cout << "Enter new receive date (day month year): ";
                        cin >> receiveDate.day >> receiveDate.month >> receiveDate.year;
                        order.setReceiveDate(receiveDate);
                        system("CLS");
                        Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Update Order > Update Receive Date");
                        cout << "Receive Date updated successfully.\n";
                    }
                }
                system("pause");
                break;
            case 3:
                system("CLS");
                Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Update Order > Update Status");
                for (auto& order : orders) {
                    if (order.getId() == id) {
                        int status;
                        cout << "Enter new status (0: Pending, 1: InTransit, 2: Delivered): ";
                        cin >> status;
                        order.setStatus(static_cast<ShipmentStatus>(status));
                        system("CLS");
                        Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Update Order > Update Status");
                        cout << "Status updated successfully.\n";
                    }
                }
                system("pause");
                break;
            }
        }
    }
    else
        cout << "Order with ID " << id << " does not exist." << endl;

}

void Manage::Menu_Order_Delete()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Delete Order");
    int id;
    cout << "Enter Order ID to delete: ";
    cin >> id;
    cin.ignore();

    auto it = findOrderById(id);

    if ( it != orders.end() )
    {
        orders.erase(it);
        system("CLS");
        Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Delete Order");
        cout << "Order deleted successfully." << endl;
    }
    else
        cout << "Order with ID " << id << " does not exist." << endl;
}

void Manage::Menu_Order_List()
{
    bool done = false;
    while(!done)
    {
        system("CLS");
        Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > All Order Information");
        int choice = getMenuChoice( {"Return", "Sort By ID", "Sort By Send Date", "Sort By Receice Date"} );

        switch(choice)
        {
        case 0:
            system("CLS");
            done = true;
            break;
        case 1:
            system("CLS");
            Menu_Order_List_SortID();
            system("pause");
            break;
        case 2:
            system("CLS");
            Menu_Order_List_SendDate();
            system("pause");
            break;
        case 3:
            system("CLS");
            Menu_Order_List_ReceiceDate();
            system("pause");
            break;
        }
    }
}

void Manage::Menu_Order_Search()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Search Order Information");
    int id;
    cout << "Enter Order ID to search: ";
    cin >> id;
    cin.ignore();

    auto it = findOrderById(id);

    if ( it != orders.end() )
    {
        for (const auto& order : orders) {
            if (order.getId() == id) {
                cout << setw(10) << "ID"
                     << setw(20) << "GOODSINFORMATION"
                     << setw(20) << "SENDER"
                     << setw(20) << "RECEIVER"
                     << setw(20) << "SHIPPER"
                     << setw(20) << "SEND DATE"
                     << setw(20) << "RECEIVE DATE"
                     << setw(20) << "STATUS" << endl;
                cout << string(140, '-') << endl;

                cout << setw(10) << order.getId()
                     << setw(20) << order.getGoodsinfor()
                     << setw(20) << order.getSender().getName()
                     << setw(20) << order.getReceiver().getName()
                     << setw(20) << order.getShipper().getName()
                     << setw(20) << dateToString(order.getSendDate())
                     << setw(20) << dateToString(order.getReceiveDate())
                     << setw(20) << (order.getStatus() == Pending ? "Pending" : order.getStatus() == InTransit ? "InTransit" : "Delivered") << endl;
            }
        }
    }
    else
        cout << "Order with ID " << id << " does not exist." << endl;
}

void Manage::Menu_Order_List_SortID()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > All Order Information > Sort By ID");

    for (int i = 0; i < orders.size() - 1; ++i)
    {
        for (int j = 0; j < orders.size() - i - 1; ++j)
        {
            if (orders[j].getId() > orders[j + 1].getId())
            {
                swap(orders[j], orders[j + 1]);
            }
        }
    }
    Menu_Order_Print();
}

void Manage::Menu_Order_List_SendDate()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > All Order Information > Sort By Send Date");

    for (int i = 0; i < orders.size() - 1; ++i)
    {
        for (int j = 0; j < orders.size() - i - 1; ++j)
        {
            if (orders[j].getSendDate() > orders[j + 1].getSendDate())
            {
                swap(orders[j], orders[j + 1]);
            }
        }
    }
    Menu_Order_Print();
}
void Manage::Menu_Order_List_ReceiceDate()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > All Order Information > Sort By Receive Date");

    for (int i = 0; i < orders.size() - 1; ++i)
    {
        for (int j = 0; j < orders.size() - i - 1; ++j)
        {
            if (orders[j].getReceiveDate() > orders[j + 1].getReceiveDate())
            {
                swap(orders[j], orders[j + 1]);
            }
        }
    }
    Menu_Order_Print();
}

void Manage::Menu_Order_Print()
{
    cout << setw(10)  << "ID"
         << setw(20) << "GOODSINFORMATION"
         << setw(20) << "SENDER"
         << setw(20) << "RECEIVER"
         << setw(20) << "SHIPPER"
         << setw(20) << "SEND DATE"
         << setw(20) << "RECEIVE DATE"
         << setw(20) << "STATUS" << endl;
    cout << string(140, '-') << endl;
    for ( const auto& order : orders)
    {
        cout << setw(10) << order.getId()
             << setw(20) << order.getGoodsinfor()
             << setw(20) << order.getSender().getName()
             << setw(20) << order.getReceiver().getName()
             << setw(20) << order.getShipper().getName()
             << setw(20) << dateToString(order.getSendDate())
             << setw(20) << dateToString(order.getReceiveDate())
             << setw(20) << (order.getStatus() == Pending ? "Pending" : order.getStatus() == InTransit ? "InTransit" : "Delivered") << endl;
    }
}

vector<Order>::iterator Manage::findOrderById(int id) {
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        if (it->getId() == id) {
            return it;
        }
    }
    return orders.end();
}

void Manage::Menu_Sender()
{
    bool done = false;
    while(!done)
    {
        system("CLS");
        Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage");
        int choice = getMenuChoice( {"Quit", "Add Sender", "Update Sender", "Delete Sender", "All Sender Information", "Search Sender"} );

        switch(choice)
        {
        case 0:
            system("CLS");
            done = true;
            break;
        case 1:
            system("CLS");
            Menu_Sender_Add();
            system("pause");
            break;
        case 2:
            system("CLS");
            Menu_Sender_Update();
            system("pause");
            break;
        case 3:
            system("CLS");
            Menu_Sender_Delete();
            system("pause");
            break;
        case 4:
            system("CLS");
            Menu_Sender_List();
            system("pause");
            break;
        case 5:
            system("CLS");
            Menu_Sender_Search();
            system("pause");
            break;
        }
    }
}

void Manage::Menu_Sender_Add()
{
    system("CLS");
    Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Add Sender");
    int id = IdSender;
    string name, phonenumber, address;

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phonenumber);

    cout << "Enter Address: ";
    getline(cin, address);

    Person newSender(id, name, phonenumber, address);
    senders.push_back(newSender);
    system("CLS");
    Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Add Sender");
    cout << "Sender Added with ID: " << id << endl;
    IdSender++;
}

void Manage::Menu_Sender_Update()
{
    system("CLS");
    Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Update Sender");
    int id;
    cout << "Enter ID to update: ";
    cin >> id;
    cin.ignore();

    auto it = findSenderById(id);

    if ( it != senders.end() )
    {
        bool done = false;
        while(!done)
        {
            system("CLS");
            Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Update Sender");
            int choice = getMenuChoice( {"Return", "Update Name", "Update Phone Number", "Update Address"} );

            switch(choice)
            {
            case 0:
                system("CLS");
                done = true;
                break;
            case 1:
                system("CLS");
                Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Update Sender > Update Name");
                for (auto& sender : senders) {
                    if (sender.getId() == id) {
                        string name;
                        cout << "Enter new name: ";
                        getline(cin, name);
                        sender.setName(name);
                        system("CLS");
                        Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Update Sender > Update Name");
                        cout << "Name updated successfully.\n";
                    }
                }
                system("pause");
                break;
            case 2:
                system("CLS");
                Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Update Sender > Update Name");
                for (auto& sender : senders) {
                    if (sender.getId() == id) {
                        string phoneNumber;
                        cout << "Enter new phone number: ";
                        cin.ignore();
                        getline(cin, phoneNumber);
                        sender.setName(phoneNumber);
                        system("CLS");
                        Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Update Sender > Update Name");
                        cout << "Phone number updated successfully.\n";
                    }
                }
                system("pause");
                break;
            case 3:
                system("CLS");
                Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Update Sender > Update Name");
                for (auto& sender : senders) {
                    if (sender.getId() == id) {
                        string address;
                        cout << "Enter new address: ";
                        cin.ignore();
                        getline(cin, address);
                        sender.setName(address);
                        system("CLS");
                        Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Update Sender > Update Name");
                        cout << "Address updated successfully.\n";
                    }
                }
                system("pause");
                break;
            }
        }
    }
    else
        cout << "Sender with " << id << " not exist." << endl;
}

void Manage::Menu_Sender_Delete()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Update Sender");
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    cin.ignore();

    auto it = findSenderById(id);

    if ( it != senders.end() )
    {
        senders.erase(it);
        system("CLS");
        Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Update Sender");
        cout << "Delete successfully." << endl;
    }
    else
        cout << "Sender with " << id << " not exist." << endl;
}

void Manage::Menu_Sender_List()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > All Sender Information");

    for (int i = 0; i < senders.size() - 1; ++i)
    {
        for (int j = 0; j < senders.size() - i - 1; ++j)
        {
            if (senders[j].getId() > senders[j + 1].getId())
            {
                swap(senders[j], senders[j + 1]);
            }
        }
    }

    cout << setw(10)  << "ID"
         << setw(20) << "NAME"
         << setw(20) << "PHONE NUMBER"
         << setw(20) << "ADDRESS" << endl;
    cout << string(100, '-') << endl;
    for ( int i=0; i<senders.size(); i++)
    {
        cout << setw(10)  << senders[i].getId()
             << setw(20) << senders[i].getName()
             << setw(20) << senders[i].getPhonenumber()
             << setw(20) << senders[i].getAddress() << endl;
    }
}

void Manage::Menu_Sender_Search()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > Search Sender Information");
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    cin.ignore();

    auto it = findSenderById(id);

    if ( it != senders.end() )
    {
        for (auto& sender : senders) {
            if (sender.getId() == id) {
                cout << setw(10) << "ID"
                     << setw(20) << "NAME"
                     << setw(20) << "PHONE NUMBER"
                     << setw(20) << "ADDRESS" << endl;
                cout << string(100, '-') << endl;

                cout << setw(10) << sender.getId()
                     << setw(20) << sender.getName()
                     << setw(20) << sender.getPhonenumber()
                     << setw(20) << sender.getAddress() << endl;
            }
        }
    }
    else
        cout << "Sender with " << id << " not exist." << endl;
}

vector<Person>::iterator Manage::findSenderById(int id) {
    for (auto it = senders.begin(); it != senders.end(); ++it) {
        if (it->getId() == id) {
            return it;
        }
    }
    return senders.end();
}

void Manage::Menu_Receiver()
{
    bool done = false;
    while(!done)
    {
        system("CLS");
        Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage");
        int choice = getMenuChoice( {"Quit", "Add Receiver", "Update Receiver", "Delete Receiver", "All Receiver Information", "Search Receiver"} );

        switch(choice)
        {
        case 0:
            system("CLS");
            done = true;
            break;
        case 1:
            system("CLS");
            Menu_Receiver_Add();
            system("pause");
            break;
        case 2:
            system("CLS");
            Menu_Receiver_Update();
            system("pause");
            break;
        case 3:
            system("CLS");
            Menu_Receiver_Delete();
            system("pause");
            break;
        case 4:
            system("CLS");
            Menu_Receiver_List();
            system("pause");
            break;
        case 5:
            system("CLS");
            Menu_Receiver_Search();
            system("pause");
            break;
        }
    }
}

void Manage::Menu_Receiver_Add()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Add Receiver");
    int id = IdReceiver;
    string name, phonenumber, address;

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phonenumber);

    cout << "Enter Address: ";
    getline(cin, address);

    Person newReceiver(id, name, phonenumber, address);
    receivers.push_back(newReceiver);
    system("CLS");
    Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Add Receiver");
    cout << "Receiver Added with ID: " << id << endl;
    IdReceiver++;
}

void Manage::Menu_Receiver_Update()
{
    system("CLS");
    Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Update Receiver");
    int id;
    cout << "Enter ID to update: ";
    cin >> id;
    cin.ignore();

    auto it = findReceiverById(id);

    if ( it != receivers.end() )
    {
        bool done = false;
        while(!done)
        {
            system("CLS");
            Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Update Receiver");

            int choice = getMenuChoice( {"Return", "Update Name", "Update Phone Number", "Update Address"} );

            switch(choice)
            {
            case 0:
                system("CLS");
                done = true;
                break;
            case 1:
                system("CLS");
                Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Update Receiver > Update Name");
                for (auto& receiver : receivers) {
                    if (receiver.getId() == id) {
                        string name;
                        cout << "Enter new name: ";
                        getline(cin, name);
                        receiver.setName(name);
                        system("CLS");
                        Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Update Receiver > Update Name");
                        cout << "Name updated successfully.\n";
                    }
                }
                system("pause");
                break;
            case 2:
                system("CLS");
                Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Update Receiver > Update Phone Number");
                for (auto& receiver : receivers) {
                    if (receiver.getId() == id) {
                        string phoneNumber;
                        cout << "Enter new phone number: ";
                        getline(cin, phoneNumber);
                        receiver.setName(phoneNumber);
                        system("CLS");
                        Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Update Receiver > Update Phone Number");
                        cout << "Phone number updated successfully.\n";
                    }
                }
                system("pause");
                break;
            case 3:
                system("CLS");
                Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Update Receiver > Update Address");
                for (auto& receiver : receivers) {
                    if (receiver.getId() == id) {
                        string address;
                        cout << "Enter new address: ";
                        getline(cin, address);
                        receiver.setName(address);
                        system("CLS");
                        Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Update Receiver > Update Address");
                        cout << "Address updated successfully.\n";
                    }
                }
                system("pause");
                break;
            }
        }
    }
    else
        cout << "Receiver with " << id << " not exist." << endl;
}

void Manage::Menu_Receiver_Delete()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Delete Receiver");
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    cin.ignore();

    auto it = findReceiverById(id);

    if ( it != receivers.end() )
    {
        receivers.erase(it);
        system("CLS");
        Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Delete Receiver");
        cout << "Delete successfully." << endl;
    }
    else
        cout << "Receiver with " << id << " not exist." << endl;
}

void Manage::Menu_Receiver_List()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > All Receiver Information");

    for (int i = 0; i < receivers.size() - 1; ++i)
    {
        for (int j = 0; j < receivers.size() - i - 1; ++j)
        {
            if (receivers[j].getId() > receivers[j + 1].getId())
            {
                swap(receivers[j], receivers[j + 1]);
            }
        }
    }

    cout << setw(10)  << "ID"
         << setw(20) << "NAME"
         << setw(20) << "PHONE NUMBER"
         << setw(20) << "ADDRESS" << endl;
    cout << string(100, '-') << endl;
    for ( int i=0; i<receivers.size(); i++)
    {
        cout << setw(10)  << receivers[i].getId()
             << setw(20) << receivers[i].getName()
             << setw(20) << receivers[i].getPhonenumber()
             << setw(20) << receivers[i].getAddress() << endl;
    }
}

void Manage::Menu_Receiver_Search()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Search Receiver Information");
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    cin.ignore();

    auto it = findReceiverById(id);

    if ( it != receivers.end() )
    {
        for (auto& receiver : receivers) {
            if (receiver.getId() == id) {
                cout << setw(10) << "ID"
                     << setw(20) << "NAME"
                     << setw(20) << "PHONE NUMBER"
                     << setw(20) << "ADDRESS" << endl;
                cout << string(100, '-') << endl;

                cout << setw(10) << receiver.getId()
                     << setw(20) << receiver.getName()
                     << setw(20) << receiver.getPhonenumber()
                     << setw(20) << receiver.getAddress() << endl;
            }
        }
    }
    else
        cout << "Receiver with " << id << " not exist." << endl;
}

vector<Person>::iterator Manage::findReceiverById(int id)
{
    for (auto it = receivers.begin(); it != receivers.end(); ++it) {
        if (it->getId() == id) {
            return it;
        }
    }
    return receivers.end();
}

void Manage::Menu_Shipper()
{
    system("CLS");
    bool done = false;
    while(!done)
    {
        system("CLS");
        Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage");
        int choice = getMenuChoice( {"Quit", "Add Shipper", "Update Shipper", "Delete Shipper", "All Shipper Information", "Search Shipper"} );

        switch(choice)
        {
        case 0:
            system("CLS");
            done = true;
            break;
        case 1:
            system("CLS");
            Menu_Shipper_Add();
            break;
        case 2:
            system("CLS");
            Menu_Shipper_Update();
            system("pause");
            break;
        case 3:
            system("CLS");
            Menu_Shipper_Delete();
            system("pause");
            break;
        case 4:
            system("CLS");
            Menu_Shipper_List();
            system("pause");
            break;
        case 5:
            system("CLS");
            Menu_Shipper_Search();
            system("pause");
            break;
        }
    }
}

void Manage::Menu_Shipper_Add()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > Add Shipper");
    int id = IdShipper;
    string name, phonenumber;

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phonenumber);

    Shipper newShipper(id, name, phonenumber);
    shippers.push_back(newShipper);
    system("CLS");
    Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > Add Shipper");
    cout << "Shipper Added with ID: " << id << endl;
    IdShipper++;
}

void Manage::Menu_Shipper_Update()
{
    system("CLS");
    Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > Update Shipper");
    int id;
    cout << "Enter ID to update: ";
    cin >> id;
    cin.ignore();

    auto it = findShipperById(id);

    if ( it != shippers.end() )
    {
        bool done = false;
        while(!done)
        {
            system("CLS");
            Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > Update Shipper");

            int choice = getMenuChoice( {"Return", "Update Name", "Update Phone Number"} );

            switch(choice)
            {
            case 0:
                system("CLS");
                done = true;
                break;
            case 1:
                system("CLS");
                Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > Update Shipper > Update Name");
                for (auto& shipper : shippers) {
                    if (shipper.getId() == id) {
                        string name;
                        cout << "Enter new name: ";
                        getline(cin, name);
                        shipper.setName(name);
                        system("CLS");
                        Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > Update Shipper > Update Name");
                        cout << "Name updated successfully.\n";
                    }
                }
                system("pause");
                break;
            case 2:
                system("CLS");
                Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > Update Shipper > Update Phone Number");
                for (auto& shipper : shippers) {
                    if (shipper.getId() == id) {
                        string phoneNumber;
                        cout << "Enter new phone number: ";
                        getline(cin, phoneNumber);
                        shipper.setPhonenumber(phoneNumber);
                        system("CLS");
                        Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > Update Shipper > Update Phone Number");
                        cout << "Phone number updated successfully.\n";
                    }
                }
                system("pause");
                break;
            }
        }
    }
    else
        cout << "Shipper with ID " << id << " does not exist." << endl;
}

void Manage::Menu_Shipper_Delete()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > Delete Shipper");
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    cin.ignore();

    auto it = findShipperById(id);

    if ( it != shippers.end() )
    {
        shippers.erase(it);
        system("CLS");
        Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > Delete Shipper");
        cout << "Delete successfully." << endl;
    }
    else
        cout << "Shipper with ID " << id << " does not exist." << endl;
}

void Manage::Menu_Shipper_List()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > All Shipper Information");

    for (int i = 0; i < shippers.size() - 1; ++i)
    {
        for (int j = 0; j < shippers.size() - i - 1; ++j)
        {
            if (shippers[j].getId() > shippers[j + 1].getId())
            {
                swap(shippers[j], shippers[j + 1]);
            }
        }
    }

    cout << setw(10)  << "ID"
         << setw(20) << "NAME"
         << setw(20) << "PHONE NUMBER"
         << endl;
    cout << string(100, '-') << endl;
    for ( int i=0; i<shippers.size(); i++)
    {
        cout << setw(10)  << shippers[i].getId()
             << setw(20) << shippers[i].getName()
             << setw(20) << shippers[i].getPhonenumber()
             << endl;
    }
}

void Manage::Menu_Shipper_Search()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > Search Shipper Information");
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    cin.ignore();

    auto it = findShipperById(id);

    if ( it != shippers.end() )
    {
        for (auto& shipper : shippers) {
            if (shipper.getId() == id) {
                cout << setw(10) << "ID"
                     << setw(20) << "NAME"
                     << setw(20) << "PHONE NUMBER"
                     << endl;
                cout << string(100, '-') << endl;

                cout << setw(10) << shipper.getId()
                     << setw(20) << shipper.getName()
                     << setw(20) << shipper.getPhonenumber()
                     << endl;
            }
        }
    }
    else
        cout << "Shipper with ID " << id << " does not exist." << endl;
}

vector<Shipper>::iterator Manage::findShipperById(int id)
{
    for (auto it = shippers.begin(); it != shippers.end(); ++it) {
        if (it->getId() == id) {
            return it;
        }
    }
    return shippers.end();
}

string Manage::dateToString(const Date& date) {
    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

void Manage::Header(string text)
{
    string dtext = text;
    cout << endl;
    cout << string(61, ' ') << "BIET DOI HIGH CODE" << endl;
    cout << string( 140, '=' ) << endl;
    int x = (140 - dtext.length() - 4) / 2;
    if (x > 0) {
        cout << string(x, ' ') << "- " << text << " -" << endl;
    } else {
        cout << text << endl;
    }
    cout << string( 140, '=' ) << endl;
    cout << endl << endl;
}

int Manage::getChoice(int m, int M)
{
    int choice;
    do {
        choice = getch() - '0';
        if ( choice < m || choice > M )
            cout << "INVALID ENTRY. TRY AGAIN" << endl;
    } while ( choice < m || choice > M );
    return choice;
}

int Manage::getMenuChoice(vector<string> options)
{
    for ( int i = 0; i < options.size(); i++)
    {

        string dtext = options[i];
        cout << string( 50, ' ' ) << string( 40, '-' ) << endl;
        int x = (140 - dtext.length() - 6 ) / 2 - 51;

            cout << string( 50, ' ' ) << "|" << string( 38, ' ' ) << "|" << endl;
            if(dtext.length()%2==0)
                cout << string( 50, ' ' ) << "|" << string(x , ' ') << "[" << i << "]" << " . " << options[i] << string(x, ' ') << "|" << endl;
            else
                cout << string( 50, ' ' ) << "|" << string(x , ' ') << "[" << i << "]" << " . " << options[i] << string(x, ' ') << " |" << endl;
            cout << string( 50, ' ' ) << "|" << string( 38, ' ' ) << "|" << endl;
    }
    cout << string( 50, ' ' ) << string( 40, '-' ) << endl;
    cout << endl;
    return getChoice( 0, options.size()-1 );
}


int main(){
    cout << left;
    Manage manage;
    manage.Launch();
    return 0;
}

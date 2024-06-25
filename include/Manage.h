#ifndef MANAGE_H
#define MANAGE_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>
#include "Person.h"
#include "Shipper.h"
#include "Order.h"

using namespace std;

class Manage
{
    public:
        Manage();
        ~Manage();
        void Launch();
    private:
        void Data();

        void Menu();

        void Menu_Order();
        void Menu_Order_Add();
        void Menu_Order_Update();
        void Menu_Order_Delete();
        void Menu_Order_List();
        void Menu_Order_Search();
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

#endif // MANAGE_H

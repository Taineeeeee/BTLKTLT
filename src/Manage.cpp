#include "Manage.h"

Manage::Manage()
{
}

Manage::~Manage()
{
}

void Manage::Launch()
{
    Data();
    Menu();
}

void Manage::Data()
{
    IdSender = 0;
    IdReceiver = 0;
    IdShipper = 0;
    IdOrder = 0;

    senders.push_back( Person(3260, "Nguyen Viet Anh", "0123456789", "Thach That - Ha Noi"));
    senders.push_back( Person(3627, "Nguyen Cong Tai", "0123456789", "Thanh Hoa"));

    receivers.push_back( Person(3666, "Tran Thi Thanh Thuy", "0123456789", "Quynh Luu - Nghe An"));

    shippers.push_back( Shipper(3692, "Phung Anh Tu", "0123456789"));

}

void Manage::Menu()
{
    system("CLS");
    bool done = false;
    while(!done)
    {
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
            system("pause");
            break;
        case 2:
            system("CLS");
            Menu_Sender();
            system("pause");
            break;
        case 3:
            system("CLS");
            Menu_Receiver();
            system("pause");
            break;
        case 4:
            system("CLS");
            Menu_Shipper();
            system("pause");
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
            system("pause");
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

    orders.push_back(order);
    system("CLS");
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
        cout << "Order deleted successfully." << endl;
    }
    else
        cout << "Order with ID " << id << " does not exist." << endl;
}

void Manage::Menu_Order_List()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > All Order Information");
    cout << setw(10)  << "ID"
         << setw(20) << "GOODSINFORMATION"
         << setw(20) << "SENDER"
         << setw(20) << "RECEIVER"
         << setw(20) << "SHIPPER"
         << setw(20) << "SEND DATE"
         << setw(20) << "RECEIVE DATE"
         << setw(20) << "STATUS" << endl;
    cout << string(160, '-') << endl;
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

void Manage::Menu_Order_Search()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Order Manage > Search Order Information");
    int id;
    cout << "Enter Order ID to search: ";
    cin >> id;
    cin.ignore();

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
            cout << string(160, '-') << endl;

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
                        cin.ignore();
                        getline(cin, name);
                        sender.setName(name);
                        system("CLS");
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
        cout << "Delete successfully." << endl;
    }
    else
        cout << "Sender with " << id << " not exist." << endl;
}

void Manage::Menu_Sender_List()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Sender Manage > All Sender Information");
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
                        cin.ignore();
                        getline(cin, name);
                        receiver.setName(name);
                        system("CLS");
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
                        cin.ignore();
                        getline(cin, phoneNumber);
                        receiver.setName(phoneNumber);
                        system("CLS");
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
                        cin.ignore();
                        getline(cin, address);
                        receiver.setName(address);
                        system("CLS");
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
    Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > Update Receiver");
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    cin.ignore();

    auto it = findReceiverById(id);

    if ( it != receivers.end() )
    {
        receivers.erase(it);
        system("CLS");
        cout << "Delete successfully." << endl;
    }
    else
        cout << "Receiver with " << id << " not exist." << endl;
}

void Manage::Menu_Receiver_List()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Receiver Manage > All Receiver Information");
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
                        cin.ignore();
                        getline(cin, name);
                        shipper.setName(name);
                        system("CLS");
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
                        cin.ignore();
                        getline(cin, phoneNumber);
                        shipper.setPhonenumber(phoneNumber);
                        system("CLS");
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
        cout << "Delete successfully." << endl;
    }
    else
        cout << "Shipper with ID " << id << " does not exist." << endl;
}

void Manage::Menu_Shipper_List()
{
    Header("DELIVERY & RECEIVE MANAGEMENT > Shipper Manage > All Shipper Information");
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
    cout << string( 100, '-' ) << endl;
    cout << "- " << text << " -" << endl;
    cout << string( 100, '-' ) << endl;
    cout << endl << endl;
}

int Manage::getChoice(int m, int M)
{
    int choice;
    do {
        cout << "Enter your choice (" << m << " - " << M << ") : ";
        cin >> choice;
        cin.ignore();
        if ( choice < m || choice > M )
            cout << "INVALID ENTRY. TRY AGAIN" << endl;
    } while ( choice < m || choice > M );
    return choice;
}

int Manage::getMenuChoice(vector<string> options)
{
    for ( int i = 0; i < options.size(); i++)
    {
        cout << i << ". " << options[i] << endl;
    }
    cout << endl;
    return getChoice( 0, options.size()-1 );
}

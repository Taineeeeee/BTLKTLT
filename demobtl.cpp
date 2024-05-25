#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

enum ShipmentStatus { Received, InTransit, Delivered };
enum ShipperStatus { Free, Busy };

struct Date {
    int day;
    int month;
    int year;
};

struct Date inputDate() {
    Date date;
    cout << "Enter day: ";
    cin >> date.day;
    cout << "Enter month: ";
    cin >> date.month;
    cout << "Enter year: ";
    cin >> date.year;
    return date;
}

string dateToString(const Date& date) {
    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

void inputString(char* str, int length, const char* prompt) {
    cout << prompt;
    cin.ignore(); // Ignore newline left in buffer
    cin.getline(str, length);
}

class Shipment {
public:
    string shipmentId;
    Date receiveDate;
    string customerName;
    string deliveryAddress;
    string goodsInfo;
    ShipmentStatus status;

    Shipment(string id, Date date, string customer, string address, string goods)
        : shipmentId(id), receiveDate(date), customerName(customer), deliveryAddress(address), goodsInfo(goods), status(Received) {}

    void updateStatus(ShipmentStatus newStatus) {
        status = newStatus;
    }

    void printInfo() const {
        cout << "Shipment ID: " << shipmentId << "\n"
             << "Receive Date: " << dateToString(receiveDate) << "\n"
             << "Customer Name: " << customerName << "\n"
             << "Delivery Address: " << deliveryAddress << "\n"
             << "Goods Info: " << goodsInfo << "\n"
             << "Status: " << (status == Received ? "Received" : status == InTransit ? "In Transit" : "Delivered") << "\n";
    }
};

class Customer {
public:
    string customerId;
    string customerName;
    string address;
    string phoneNumber;

    Customer(string id, string name, string addr, string phone)
        : customerId(id), customerName(name), address(addr), phoneNumber(phone) {}

    void printInfo() const {
        cout << "Customer ID: " << customerId << "\n"
             << "Customer Name: " << customerName << "\n"
             << "Address: " << address << "\n"
             << "Phone Number: " << phoneNumber << "\n";
    }
};

class Inventory {
public:
    string goodsId;
    string goodsType;
    int quantity;
    double price;

    Inventory(string id, string type, int qty, double cost)
        : goodsId(id), goodsType(type), quantity(qty), price(cost) {}

    void updateQuantity(int newQty) {
        quantity = newQty;
    }

    void printInfo() const {
        cout << "Goods ID: " << goodsId << "\n"
             << "Goods Type: " << goodsType << "\n"
             << "Quantity: " << quantity << "\n"
             << "Price: " << price << "\n";
    }
};

class Shipper {
public:
    string shipperId;
    string shipperName;
    ShipperStatus status;
    vector<Shipment> shipments;

    Shipper(string id, string name)
        : shipperId(id), shipperName(name), status(Free) {}

    void addShipment(Shipment& shipment) {
        shipments.push_back(shipment);
        status = Busy;
    }

    void updateStatus(ShipperStatus newStatus) {
        status = newStatus;
    }

    void printInfo() const {
        cout << "Shipper ID: " << shipperId << "\n"
             << "Shipper Name: " << shipperName << "\n"
             << "Status: " << (status == Free ? "Free" : "Busy") << "\n"
             << "Shipments: \n";
        for (const auto& shipment : shipments) {
            shipment.printInfo();
            cout << "\n";
        }
    }
};

void receiveShipment(vector<Shipment>& shipments) {
    string id, customer, address, goods;
    Date date;
    cout << "Enter Shipment ID: ";
    cin >> id;
    cout << "Enter Receive Date:\n";
    date = inputDate();
    char customerName[100], deliveryAddress[100], goodsInfo[100];
    inputString(customerName, 100, "Enter Customer Name: ");
    inputString(deliveryAddress, 100, "Enter Delivery Address: ");
    inputString(goodsInfo, 100, "Enter Goods Info: ");
    shipments.push_back(Shipment(id, date, customerName, deliveryAddress, goodsInfo));
}

void listShipments(const vector<Shipment>& shipments) {
    for (const auto& shipment : shipments) {
        shipment.printInfo();
        cout << "\n";
    }
}

void updateShipment(vector<Shipment>& shipments) {
    string id;
    cout << "Enter Shipment ID to update: ";
    cin >> id;
    for (auto& shipment : shipments) {
        if (shipment.shipmentId == id) {
            Date date;
            int status;
            cout << "Enter new Receive Date:\n";
            date = inputDate();
            char customerName[100], deliveryAddress[100], goodsInfo[100];
            inputString(customerName, 100, "Enter new Customer Name: ");
            inputString(deliveryAddress, 100, "Enter new Delivery Address: ");
            inputString(goodsInfo, 100, "Enter new Goods Info: ");
            cout << "Enter new Status (0: Received, 1: In Transit, 2: Delivered): ";
            cin >> status;
            shipment.receiveDate = date;
            shipment.customerName = customerName;
            shipment.deliveryAddress = deliveryAddress;
            shipment.goodsInfo = goodsInfo;
            shipment.status = static_cast<ShipmentStatus>(status);
            return;
        }
    }
    cout << "Shipment not found.\n";
}

void deleteShipment(vector<Shipment>& shipments) {
    string id;
    cout << "Enter Shipment ID to delete: ";
    cin >> id;
    shipments.erase(remove_if(shipments.begin(), shipments.end(),
        [&id](Shipment& shipment) { return shipment.shipmentId == id; }), shipments.end());
}

void addCustomer(vector<Customer>& customers) {
    string id, phone;
    cout << "Enter Customer ID: ";
    cin >> id;
    char name[100], address[100];
    inputString(name, 100, "Enter Customer Name: ");
    inputString(address, 100, "Enter Address: ");
    cout << "Enter Phone Number: ";
    cin >> phone;
    customers.push_back(Customer(id, name, address, phone));
}

void listCustomers(const vector<Customer>& customers) {
    for (const auto& customer : customers) {
        customer.printInfo();
        cout << "\n";
    }
}

void updateCustomer(vector<Customer>& customers) {
    string id;
    cout << "Enter Customer ID to update: ";
    cin >> id;
    for (auto& customer : customers) {
        if (customer.customerId == id) {
            char name[100], address[100];
            string phone;
            inputString(name, 100, "Enter new Customer Name: ");
            inputString(address, 100, "Enter new Address: ");
            cout << "Enter new Phone Number: ";
            cin >> phone;
            customer.customerName = name;
            customer.address = address;
            customer.phoneNumber = phone;
            return;
        }
    }
    cout << "Customer not found.\n";
}

void deleteCustomer(vector<Customer>& customers) {
    string id;
    cout << "Enter Customer ID to delete: ";
    cin >> id;
    customers.erase(remove_if(customers.begin(), customers.end(),
        [&id](Customer& customer) { return customer.customerId == id; }), customers.end());
}

void addInventory(vector<Inventory>& inventories) {
    string id, type;
    int qty;
    double cost;
    cout << "Enter Goods ID: ";
    cin >> id;
    cout << "Enter Goods Type: ";
    cin >> type;
    cout << "Enter Quantity: ";
    cin >> qty;
    cout << "Enter Price: ";
    cin >> cost;
    inventories.push_back(Inventory(id, type, qty, cost));
}

void listInventory(const vector<Inventory>& inventories) {
    for (const auto& inventory : inventories) {
        inventory.printInfo();
        cout << "\n";
    }
}

void updateInventory(vector<Inventory>& inventories) {
    string id;
    cout << "Enter Goods ID to update: ";
    cin >> id;
    for (auto& inventory : inventories) {
        if (inventory.goodsId == id) {
            string type;
            int qty;
            double cost;
            cout << "Enter new Goods Type: ";
            cin >> type;
            cout << "Enter new Quantity: ";
            cin >> qty;
            cout << "Enter new Price: ";
            cin >> cost;
            inventory.goodsType = type;
            inventory.quantity = qty;
            inventory.price = cost;
            return;
        }
    }
    cout << "Inventory not found.\n";
}

void deleteInventory(vector<Inventory>& inventories) {
    string id;
    cout << "Enter Goods ID to delete: ";
    cin >> id;
    inventories.erase(remove_if(inventories.begin(), inventories.end(),
        [&id](Inventory& inventory) { return inventory.goodsId == id; }), inventories.end());
}

void addShipper(vector<Shipper>& shippers) {
    string id;
    char name[100];
    cout << "Enter Shipper ID: ";
    cin >> id;
    inputString(name, 100, "Enter Shipper Name: ");
    shippers.push_back(Shipper(id, name));
}

void listShippers(const vector<Shipper>& shippers) {
    for (const auto& shipper : shippers) {
        shipper.printInfo();
        cout << "\n";
    }
}

void updateShipper(vector<Shipper>& shippers) {
    string id;
    cout << "Enter Shipper ID to update: ";
    cin >> id;
    for (auto& shipper : shippers) {
        if (shipper.shipperId == id) {
            char name[100];
            int status;
            inputString(name, 100, "Enter new Shipper Name: ");
            cout << "Enter new Status (0: Free, 1: Busy): ";
            cin >> status;
            shipper.shipperName = name;
            shipper.status = static_cast<ShipperStatus>(status);
            return;
        }
    }
    cout << "Shipper not found.\n";
}

void deleteShipper(vector<Shipper>& shippers) {
    string id;
    cout << "Enter Shipper ID to delete: ";
    cin >> id;
    shippers.erase(remove_if(shippers.begin(), shippers.end(),
        [&id](Shipper& shipper) { return shipper.shipperId == id; }), shippers.end());
}

int main() {
    vector<Shipment> shipments;
    vector<Customer> customers;
    vector<Inventory> inventories;
    vector<Shipper> shippers;

    int choice;
    do {
        cout << "Menu:\n"
             << "1. Receive Shipment\n"
             << "2. List Shipments\n"
             << "3. Update Shipment\n"
             << "4. Delete Shipment\n"
             << "5. Add Customer\n"
             << "6. List Customers\n"
             << "7. Update Customer\n"
             << "8. Delete Customer\n"
             << "9. Add Inventory\n"
             << "10. List Inventory\n"
             << "11. Update Inventory\n"
             << "12. Delete Inventory\n"
             << "13. Add Shipper\n"
             << "14. List Shippers\n"
             << "15. Update Shipper\n"
             << "16. Delete Shipper\n"
             << "17. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                receiveShipment(shipments);
                break;
            case 2:
                listShipments(shipments);
                break;
            case 3:
                updateShipment(shipments);
                break;
            case 4:
                deleteShipment(shipments);
                break;
            case 5:
                addCustomer(customers);
                break;
            case 6:
                listCustomers(customers);
                break;
            case 7:
                updateCustomer(customers);
                break;
            case 8:
                deleteCustomer(customers);
                break;
            case 9:
                addInventory(inventories);
                break;
            case 10:
                listInventory(inventories);
                break;
            case 11:
                updateInventory(inventories);
                break;
            case 12:
                deleteInventory(inventories);
                break;
            case 13:
                addShipper(shippers);
                break;
            case 14:
                listShippers(shippers);
                break;
            case 15:
                updateShipper(shippers);
                break;
            case 16:
                deleteShipper(shippers);
                break;
        }
    } while (choice != 17);

    return 0;
}

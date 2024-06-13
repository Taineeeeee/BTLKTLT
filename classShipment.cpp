#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Shipment status enumeration
enum ShipmentStatus { Received, InTransit, Delivered };

// Payment status enumeration
enum PaymentStatus { Unpaid, Paid };

// Date structure
struct Date {
    int day, month, year;
};

// Convert date to string
string dateToString(const Date& date) {
    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

// Shipment class definition
class Shipment {
public:
    string shipmentId;
    Date receiveDate, deliveryDate;
    string customerName, deliveryAddress, goodsInfo;
    ShipmentStatus status;
    PaymentStatus pstatus;

    Shipment(string id, Date rdate, string customer, string address, string goods, Date ddate)
        : shipmentId(move(id)), receiveDate(move(rdate)), deliveryDate(move(ddate)), customerName(move(customer)), deliveryAddress(move(address)), goodsInfo(move(goods)), status(Received), pstatus(Unpaid) {}

    void printInfo() const {
        cout << "Shipment ID: " << shipmentId << "\n"
            << "Receive Date: " << dateToString(receiveDate) << "\n"
            << "Delivery Date: " << dateToString(deliveryDate) << "\n"
            << "Customer Name: " << customerName << "\n"
            << "Delivery Address: " << deliveryAddress << "\n"
            << "Goods Info: " << goodsInfo << "\n"
            << "Shipment Status: " << (status == Received ? "Received" : status == InTransit ? "In Transit" : "Delivered") << "\n"
            << "Payment Status: " << (pstatus == Unpaid ? "Unpaid" : "Paid") << "\n";
    }
};

// ShipmentManager class definition
class ShipmentManager {
private:
    vector<Shipment> shipments;

public:
    void addShipment() {
        string id, customer, address, goods;
        Date rdate, ddate;
        int statusChoice, pstatusChoice;

        cout << "-- Enter the information for new Shipment --" << endl;
        cout << "Shipment ID: "; cin >> id;
        cout << "Receive Date (day month year): "; cin >> rdate.day >> rdate.month >> rdate.year;
        cout << "Delivery Date (day month year): "; cin >> ddate.day >> ddate.month >> ddate.year;
        cout << "Customer Name: "; cin.ignore(); getline(cin, customer);
        cout << "Delivery Address: "; getline(cin, address);
        cout << "Goods information: "; getline(cin, goods);
        cout << "Shipment Status: Received (0) / InTransit (1) / Delivered (2): "; cin >> statusChoice;
        cout << "Payment Status: Unpaid (0) / Paid (1): "; cin >> pstatusChoice;

        Shipment shipment(id, rdate, customer, address, goods, ddate);
        shipment.status = static_cast<ShipmentStatus>(statusChoice);
        shipment.pstatus = static_cast<PaymentStatus>(pstatusChoice);

        shipments.push_back(move(shipment));
        cout << "Add shipment successfully!" << endl;
    }

    void findShipment(const string& id) {
        auto it = find_if(shipments.begin(), shipments.end(), [&id](const Shipment& s) { return s.shipmentId == id; });

        if (it == shipments.end()) {
            cout << "Shipment with ID " << id << " not found." << endl;
            return;
        }

        cout << "Shipment with ID " << id << " found." << endl;
        it->printInfo();
    }

    void updateShipment(const string& id) {
        auto it = find_if(shipments.begin(), shipments.end(), [&id](const Shipment& s) { return s.shipmentId == id; });

        if (it == shipments.end()) {
            cout << "Shipment with ID " << id << " not found." << endl;
            return;
        }

        int choice;
        do {
            cout << "Select the information to update:\n";
            cout << "1. Receive Date\n2. Delivery Date\n3. Customer Name\n4. Delivery Address\n5. Goods Info\n6. Shipment Status\n7. Payment Status\n0. Exit\n";
            cout << "Enter your choice: "; cin >> choice;

            switch (choice) {
            case 1:
                cout << "Enter new Received Date (day month year): ";
                cin >> it->receiveDate.day >> it->receiveDate.month >> it->receiveDate.year; break;
            case 2:
                cout << "Enter new Delivery Date (day month year): ";
                cin >> it->deliveryDate.day >> it->deliveryDate.month >> it->deliveryDate.year; break;
            case 3:
                cout << "Enter new Customer Name: ";
                cin.ignore(); getline(cin, it->customerName); break;
            case 4:
                cout << "Enter new Delivery Address: ";
                cin.ignore(); getline(cin, it->deliveryAddress); break;
            case 5:
                cout << "Enter new Goods Info: ";
                cin.ignore(); getline(cin, it->goodsInfo); break;
            case 6:
                cout << "Enter new Shipment Status: Received (0) / InTransit (1) / Delivered (2): ";
                int statusChoice; cin >> statusChoice; it->status = static_cast<ShipmentStatus>(statusChoice); break;
            case 7:
                cout << "Enter new Payment Status: Unpaid (0) / Paid (1): ";
                int pstatusChoice; cin >> pstatusChoice; it->pstatus = static_cast<PaymentStatus>(pstatusChoice); break;
            case 0:
                cout << "Exiting update menu." << endl; break;
            default:
                cout << "Invalid choice!" << endl; break;
            }
        } while (choice != 0);
    }

    void removeShipment(const string& id) {
        auto it = remove_if(shipments.begin(), shipments.end(), [&id](const Shipment& s) { return s.shipmentId == id; });

        if (it != shipments.end()) {
            shipments.erase(it, shipments.end());
            cout << "Shipment with ID " << id << " has been removed." << endl;
        }
        else {
            cout << "Shipment with ID " << id << " not found." << endl;
        }
    }

    void printAllShipments() const {
        for (const auto& shipment : shipments) {
            shipment.printInfo();
            cout << "------------------------\n";
        }
    }

    void sortShipmentsById(bool ascending = true) {
        std::sort(shipments.begin(), shipments.end(),
            [ascending](const Shipment& a, const Shipment& b) {
                return ascending ? (a.shipmentId < b.shipmentId) : (a.shipmentId > b.shipmentId);
            });
    }

    void sortShipmentsByName(bool ascending = true) {
        std::sort(shipments.begin(), shipments.end(),
            [ascending](const Shipment& a, const Shipment& b) {
                return ascending ? (a.customerName < b.customerName) : (a.customerName > b.customerName);
            });
    }
};

void menuShipment() {
    ShipmentManager manager;
    int choice;
    string id;

    do {
        cout << "SHIPMENT MENU\n1. Display all shipments\n2. Add shipment\n3. Find shipment\n4. Update shipment\n5. Remove shipment\n6. Sort shipments\n0. Exit\n";
        cout << "Enter your choice: "; cin >> choice;

        switch (choice) {
        case 1: manager.printAllShipments(); break;
        case 2: manager.addShipment(); break;
        case 3:
            cout << "Enter Shipment ID to find: "; cin >> id;
            manager.findShipment(id); break;
        case 4:
            cout << "Enter Shipment ID to update: "; cin >> id;
            manager.updateShipment(id); break;
        case 5:
            cout << "Enter Shipment ID to remove: "; cin >> id;
            manager.removeShipment(id); break;
        case 6:
            int sortChoice, orderChoice;
            cout << "1. Sort by ID\n2. Sort by Name" << endl;
            cout << "Enter your choice: "; cin >> sortChoice;
            cout << "1. Ascending\n2. Descending" << endl;
            cout << "Enter your choice: "; cin >> orderChoice;
            if (sortChoice == 1) {
                manager.sortShipmentsById(orderChoice == 1);
                cout << "Shipments sorted by ID!" << endl;
            }
            else if (sortChoice == 2) {
                manager.sortShipmentsByName(orderChoice == 1);
                cout << "Shipments sorted by Name!" << endl;
            }
            else {
                cout << "Invalid sort choice!" << endl;
            }
            break;
        case 0:
            cout << "Exiting the program." << endl; break;
        default:
            cout << "Invalid choice!" << endl; break;
        }
    } while (choice != 0);
}

int main() {
    menuShipment();
    return 0;
}

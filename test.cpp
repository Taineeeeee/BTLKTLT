#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "BaseCustomer.h"

class Customer : public BaseCustomer {
public:
    std::string Phone;

    //Customer() : BaseCustomer(), Phone() {}

    Customer(int id, const std::string& name, const std::string& address, const std::string& phone)
        : BaseCustomer(id, name, address), Phone(phone) {}
};

class CustomerManager {
public:
    std::vector<Customer> listCustomer;

    void addCustomer();
    void deleteCustomer();
    void fixCustomer();
    void printlistCustomer() const;
    Customer getCustomer(int id) const;
};

std::string inputstring(const std::string &prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

void CustomerManager::addCustomer() {
    int id;
    std::string name, address, phone;

    std::cout << "Enter customer ID: ";
    std::cin >> id;
    std::cin.ignore();
    name = inputstring("Enter customer name: ");
    address = inputstring("Enter customer address: ");
    std::cout << "Enter customer phone number: ";
    std::cin >> phone;

    listCustomer.push_back(Customer(id, name, address, phone));
}

void CustomerManager::deleteCustomer() {
    int id;
    std::cout << "Enter customer ID to delete: ";
    std::cin >> id;

    auto it = std::find_if(listCustomer.begin(), listCustomer.end(), [id](const Customer &ci) {
        return ci.ID == id;
    });

    if (it != listCustomer.end()) {
        listCustomer.erase(it);
        std::cout << "Customer deleted successfully.\n";
    } else {
        std::cout << "Customer with ID " << id << " does not exist!\n";
    }
}

void CustomerManager::fixCustomer() {
    int id;
    std::cout << "Enter customer ID to fix: ";
    std::cin >> id;

    auto it = std::find_if(listCustomer.begin(), listCustomer.end(), [id](const Customer &ci) {
        return ci.ID == id;
    });

    if (it != listCustomer.end()) {
        std::cout << "What information do you want to edit?\n";
        std::cout << "1. ID\n2. Name\n3. Address\n4. Phone\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline left in buffer

        switch (choice) {
            case 1:
                std::cout << "Enter the new customer ID: ";
                std::cin >> it->ID;
                std::cin.ignore();
                break;
            case 2:
                it->Name = inputstring("Enter the new customer name: ");
                break;
            case 3:
                it->Address = inputstring("Enter the new customer address: ");
                break;
            case 4:
                std::cout << "Enter the new customer phone number: ";
                std::cin >> it->Phone;
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } else {
        std::cout << "Customer with ID " << id << " does not exist!\n";
    }
}

void CustomerManager::printlistCustomer() const {
    for (const auto &kh : listCustomer) {
        std::cout << "\nCustomer ID: " << kh.ID;
        std::cout << "\nCustomer Name: " << kh.Name;
        std::cout << "\nCustomer Address: " << kh.Address;
        std::cout << "\nCustomer Phone Number: " << kh.Phone << "\n";
    }
}

Customer CustomerManager::getCustomer(int id) const {
    for (const auto& kh : listCustomer) {
        if (kh.ID == id) {
            return kh;
        }
    }
    throw std::invalid_argument("Customer ID not found.");
}

void menuCustomer(CustomerManager& manager){
    int choice;
    do {
        std::cout << "1. Delete customer\n";
        std::cout << "2. Add customer\n";
        std::cout << "3. Edit customer\n";
        std::cout << "4. Print customer list\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline left in buffer
        switch (choice) {
            case 1:
                manager.deleteCustomer();
                break;
            case 2:
                manager.addCustomer();
                break;
            case 3:
                manager.fixCustomer();
                break;
            case 4:
                manager.printlistCustomer();
                break;
            case 5:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 5);
}

/*class shipment*/
// Shipment status enumeration
enum ShipmentStatus { Received, InTransit, Delivered };

// Payment status enumeration
enum PaymentStatus { Unpaid, Paid };

// Date structure
struct Date {
    int day, month, year;
};

// Convert date to string
std::string dateToString(const Date& date) {
    return std::to_string(date.day) + "/" + std::to_string(date.month) + "/" + std::to_string(date.year);
}

class Shipment : public BaseCustomer {
public:
    std::string shipmentId;
    Date receiveDate, deliveryDate;
    std::string goodsInfo;
    ShipmentStatus status;
    PaymentStatus pstatus;

    Shipment(std::string id, Date rdate, const BaseCustomer& customer, std::string goods, Date ddate)
        : BaseCustomer(customer), shipmentId(std::move(id)), receiveDate(std::move(rdate)), deliveryDate(std::move(ddate)), goodsInfo(std::move(goods)), status(Received), pstatus(Unpaid) {}

    void printInfo() const {
        std::cout << "Shipment ID: " << shipmentId << "\n"
            << "Receive Date: " << dateToString(receiveDate) << "\n"
            << "Delivery Date: " << dateToString(deliveryDate) << "\n"
            << "Customer Name: " << Name << "\n"
            << "Delivery Address: " << Address << "\n"
            << "Goods Info: " << goodsInfo << "\n"
            << "Shipment Status: " << (status == Received ? "Received" : status == InTransit ? "In Transit" : "Delivered") << "\n"
            << "Payment Status: " << (pstatus == Unpaid ? "Unpaid" : "Paid") << "\n";
    }
};

// ShipmentManager class definition
class ShipmentManager {
private:
    std::vector<Shipment> shipments;

public:
    void addShipment(const BaseCustomer& customer) {
        std::string id, goods;
        Date rdate, ddate;

        std::cout << "-- Enter the information for new Shipment --" << std::endl;
        std::cout << "Shipment ID: ";
        std::cin >> id;
        std::cout << "Receive Date (dd mm yyyy): ";
        std::cin >> rdate.day >> rdate.month >> rdate.year;
        std::cout << "Delivery Date (dd mm yyyy): ";
        std::cin >> ddate.day >> ddate.month >> ddate.year;
        std::cin.ignore();
        std::cout << "Goods Info: ";
        std::getline(std::cin, goods);

        Shipment newShipment(id, rdate, customer, goods, ddate);
        shipments.push_back(newShipment);
        std::cout << "Shipment added successfully!" << std::endl;
    }

    void findShipment(const std::string& id) {
        auto it = std::find_if(shipments.begin(), shipments.end(), [&id](const Shipment& s) { return s.shipmentId == id; });

        if (it == shipments.end()) {
            std::cout << "Shipment with ID " << id << " not found." << std::endl;
            return;
        }

        std::cout << "Shipment with ID " << id << " found." << std::endl;
        it->printInfo();
    }

    void updateShipment(const std::string& id) {
        auto it = std::find_if(shipments.begin(), shipments.end(), [&id](const Shipment& s) { return s.shipmentId == id; });

        if (it == shipments.end()) {
            std::cout << "Shipment with ID " << id << " not found." << std::endl;
            return;
        }

        int choice;
        do {
            std::cout << "Select the information to update:\n";
            std::cout << "1. Receive Date\n2. Delivery Date\n3. Customer Name\n4. Delivery Address\n5. Goods Info\n6. Shipment Status\n7. Payment Status\n0. Exit\n";
            std::cout << "Enter your choice: "; std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Enter new Received Date (day month year): ";
                    std::cin >> it->receiveDate.day >> it->receiveDate.month >> it->receiveDate.year; break;
                case 2:
                    std::cout << "Enter new Delivery Date (day month year): ";
                    std::cin >> it->deliveryDate.day >> it->deliveryDate.month >> it->deliveryDate.year; break;
                case 3:
                    std::cout << "Enter new Customer Name: ";
                    std::cin.ignore(); std::getline(std::cin, it->Name); break;
                case 4:
                    std::cout << "Enter new Delivery Address: ";
                    std::cin.ignore(); std::getline(std::cin, it->Address); break;
                case 5:
                    std::cout << "Enter new Goods Info: ";
                    std::cin.ignore(); std::getline(std::cin, it->goodsInfo); break;
                case 6:
                    std::cout << "Enter new Shipment Status: Received (0) / InTransit (1) / Delivered (2): ";
                    int statusChoice; std::cin >> statusChoice; it->status = static_cast<ShipmentStatus>(statusChoice); break;
                case 7:
                    std::cout << "Enter new Payment Status: Unpaid (0) / Paid (1): ";
                    int pstatusChoice; std::cin >> pstatusChoice; it->pstatus = static_cast<PaymentStatus>(pstatusChoice); break;
                case 0:
                    std::cout << "Exiting update menu." << std::endl; break;
                default:
                    std::cout << "Invalid choice!" << std::endl; break;
            }
        } while (choice != 0);
    }

    void removeShipment(const std::string& id) {
        auto it = std::remove_if(shipments.begin(), shipments.end(), [&id](const Shipment& s) { return s.shipmentId == id; });

        if (it != shipments.end()) {
            shipments.erase(it, shipments.end());
            std::cout << "Shipment with ID " << id << " has been removed." << std::endl;
        } else {
            std::cout << "Shipment with ID " << id << " not found." << std::endl;
        }
    }

    void printAllShipments() const {
        for (const auto& shipment : shipments) {
            shipment.printInfo();
            std::cout << "------------------------\n";
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
                return ascending ? (a.Name < b.Name) : (a.Name > b.Name);
            });
    }
};

void menuShipment(ShipmentManager& manager) {
    int choice;
    std::string id;

    do {
        std::cout << "SHIPMENT MENU\n1. Display all shipments\n2. Add shipment\n3. Find shipment\n4. Update shipment\n5. Remove shipment\n6. Sort shipments\n0. Exit\n";
        std::cout << "Enter your choice: "; std::cin >> choice;
        std::cin.ignore(); // Ignore newline left in buffer
        switch (choice) {
            case 1: manager.printAllShipments(); break;
            case 2: 
                {
                    BaseCustomer customer(1, "John Doe", "123 Main St"); // Sample customer
                    manager.addShipment(customer); 
                }
                break;
            case 3:
                std::cout << "Enter Shipment ID to find: "; std::cin >> id;
                manager.findShipment(id); break;
            case 4:
                std::cout << "Enter Shipment ID to update: "; std::cin >> id;
                manager.updateShipment(id); break;
            case 5:
                std::cout << "Enter Shipment ID to remove: "; std::cin >> id;
                manager.removeShipment(id); break;
            case 6:
                int sortChoice, orderChoice;
                std::cout << "1. Sort by ID\n2. Sort by Name" << std::endl;
                std::cout << "Enter your choice: "; std::cin >> sortChoice;
                std::cout << "1. Ascending\n2. Descending" << std::endl;
                std::cout << "Enter your choice: "; std::cin >> orderChoice;
                if (sortChoice == 1) {
                    manager.sortShipmentsById(orderChoice == 1);
                    std::cout << "Shipments sorted by ID!" << std::endl;
                } else if (sortChoice == 2) {
                    manager.sortShipmentsByName(orderChoice == 1);
                    std::cout << "Shipments sorted by Name!" << std::endl;
                } else {
                    std::cout << "Invalid sort choice!" << std::endl;
                }
                break;
            case 0:
                std::cout << "Exiting the program." << std::endl; break;
            default:
                std::cout << "Invalid choice!" << std::endl; break;
        }
    } while (choice != 0);
}

int main() {
    std::cout << "Moi ban chon dich vu\n";
    int choice;
    CustomerManager customerManager;
    ShipmentManager shipmentManager;
    
    do {
        std::cout << "1. Customer\n";
        std::cout << "2. Shipment\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline left in buffer
        switch (choice) {
            case 1:
                menuCustomer(customerManager);
                break;
            case 2:
                menuShipment(shipmentManager);
                break;
            case 3:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 3);
    return 0;
}

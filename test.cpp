#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "BaseCustomer.h"

// Lớp Customer kế thừa từ BaseCustomer
class Customer : public BaseCustomer {
public:
    std::string Phone; // Số điện thoại khách hàng

    Customer(int id, const std::string& name, const std::string& address, const std::string& phone)
        : BaseCustomer(id, name, address), Phone(phone) {}
};

// Quản lý danh sách khách hàng
class CustomerManager {
public:
    std::vector<Customer> listCustomer; // Danh sách khách hàng

    void addCustomer(); // Thêm khách hàng mới
    void deleteCustomer(); // Xóa khách hàng
    void fixCustomer(); // Sửa thông tin khách hàng
    void printlistCustomer() const; // In danh sách khách hàng
    Customer getCustomer(int id) const; // Lấy thông tin khách hàng theo ID
};

// Hàm nhập chuỗi từ người dùng với prompt
std::string inputstring(const std::string &prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

// Thêm khách hàng mới vào danh sách
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

    listCustomer.push_back(Customer(id, name, address, phone)); // Thêm khách hàng vào danh sách
}

// Xóa khách hàng khỏi danh sách
void CustomerManager::deleteCustomer() {
    int id;
    std::cout << "Enter customer ID to delete: ";
    std::cin >> id;

    // Tìm khách hàng trong danh sách
    auto it = std::find_if(listCustomer.begin(), listCustomer.end(), [id](const Customer &ci) {
        return ci.ID == id;
    });

    if (it != listCustomer.end()) {
        listCustomer.erase(it); // Xóa khách hàng khỏi danh sách
        std::cout << "Customer deleted successfully.\n";
    } else {
        std::cout << "Customer with ID " << id << " does not exist!\n";
    }
}

// Sửa thông tin khách hàng
void CustomerManager::fixCustomer() {
    int id;
    std::cout << "Enter customer ID to fix: ";
    std::cin >> id;

    // Tìm khách hàng trong danh sách
    auto it = std::find_if(listCustomer.begin(), listCustomer.end(), [id](const Customer &ci) {
        return ci.ID == id;
    });

    if (it != listCustomer.end()) {
        std::cout << "What information do you want to edit?\n";
        std::cout << "1. ID\n2. Name\n3. Address\n4. Phone\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Bỏ qua newline trong bộ đệm

        // Cập nhật thông tin khách hàng theo lựa chọn
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

// In danh sách khách hàng
void CustomerManager::printlistCustomer() const {
    for (const auto &kh : listCustomer) {
        std::cout << "\nCustomer ID: " << kh.ID;
        std::cout << "\nCustomer Name: " << kh.Name;
        std::cout << "\nCustomer Address: " << kh.Address;
        std::cout << "\nCustomer Phone Number: " << kh.Phone << "\n";
    }
}

// Lấy thông tin khách hàng theo ID
Customer CustomerManager::getCustomer(int id) const {
    for (const auto& kh : listCustomer) {
        if (kh.ID == id) {
            return kh;
        }
    }
    throw std::invalid_argument("Customer ID not found.");
}

// Menu quản lý khách hàng
void menuCustomer(CustomerManager& manager){
    int choice;
    do {
        std::cout << "\t\tBIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================MENU-CUSTOMER===================\n";
        std::cout << "==            1.Delete customer                   ==\n";
        std::cout << "==            2.Add customer                      ==\n";
        std::cout << "==            3.Edit customer                     ==\n";
        std::cout << "==            4.Print customer list               ==\n";
        std::cout << "==            5.Exit                              ==\n";
        std::cout << "====================================================\n";
        std::cout <<"Enter your choice:"; 
        std::cin >> choice;
        std::cin.ignore(); // Bỏ qua newline trong bộ đệm
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

// Enum trạng thái vận chuyển
enum ShipmentStatus { Received, InTransit, Delivered };

// Enum trạng thái thanh toán
enum PaymentStatus { Unpaid, Paid };

// Cấu trúc ngày tháng
struct Date {
    int day, month, year;
};

// Chuyển đổi ngày tháng sang chuỗi
std::string dateToString(const Date& date) {
    return std::to_string(date.day) + "/" + std::to_string(date.month) + "/" + std::to_string(date.year);
}

// Lớp Shipment kế thừa từ BaseCustomer
class Shipment : public BaseCustomer {
public:
    std::string shipmentId;
    Date receiveDate, deliveryDate;
    std::string goodsInfo;
    ShipmentStatus status;
    PaymentStatus pstatus;

    Shipment(std::string id, Date rdate, const BaseCustomer& customer, std::string goods, Date ddate)
        : BaseCustomer(customer), shipmentId(std::move(id)), receiveDate(std::move(rdate)), deliveryDate(std::move(ddate)), goodsInfo(std::move(goods)), status(Received), pstatus(Unpaid) {}

    // In thông tin lô hàng
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

// Quản lý danh sách lô hàng
class ShipmentManager {
private:
    std::vector<Shipment> shipments; // Danh sách lô hàng

public:
    void addShipment(const CustomerManager& customerManager); // Thêm lô hàng mới
    void findShipment(const std::string& id) const; // Tìm lô hàng theo ID
    void updateShipment(const std::string& id); // Cập nhật thông tin lô hàng
    void removeShipment(const std::string& id); // Xóa lô hàng
    void printAllShipments() const; // In danh sách lô hàng
    void sortShipmentsById(bool ascending = true); // Sắp xếp lô hàng theo ID
    void sortShipmentsByName(bool ascending = true); // Sắp xếp lô hàng theo tên khách hàng
};

// Thêm lô hàng mới vào danh sách
void ShipmentManager::addShipment(const CustomerManager& customerManager) {
    std::string id, goods;
    Date rdate, ddate;
    int customerId;

    std::cout << "-- Enter the information for new Shipment --" << std::endl;
    std::cout << "Shipment ID: ";
    std::cin >> id;
    std::cout << "Receive Date (dd mm yyyy): ";
    std::cin >> rdate.day >> rdate.month >> rdate.year;
    std::cout << "Delivery Date (dd mm yyyy): ";
    std::cin >> ddate.day >> ddate.month >> ddate.year;
    std::cout << "Customer ID: ";
    std::cin >> customerId;

    try {
        Customer customer = customerManager.getCustomer(customerId);
        std::cout << "Goods Info: ";
        std::cin.ignore();
        std::getline(std::cin, goods);

        shipments.push_back(Shipment(id, rdate, customer, goods, ddate));
        std::cout << "Shipment added successfully!\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

// Tìm lô hàng theo ID và in thông tin
void ShipmentManager::findShipment(const std::string& id) const {
    auto it = std::find_if(shipments.begin(), shipments.end(), [&id](const Shipment& shipment) {
        return shipment.shipmentId == id;
    });

    if (it != shipments.end()) {
        it->printInfo();
    } else {
        std::cout << "Shipment with ID " << id << " not found!\n";
    }
}

// Cập nhật thông tin lô hàng
void ShipmentManager::updateShipment(const std::string& id) {
    auto it = std::find_if(shipments.begin(), shipments.end(), [&id](Shipment& shipment) {
        return shipment.shipmentId == id;
    });

    if (it != shipments.end()) {
        int choice;
        std::cout << "What information do you want to update?\n";
        std::cout << "1. Status\n2. Payment Status\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter new status (0: Received, 1: In Transit, 2: Delivered): ";
                int newStatus;
                std::cin >> newStatus;
                if (newStatus >= 0 && newStatus <= 2) {
                    it->status = static_cast<ShipmentStatus>(newStatus);
                    std::cout << "Shipment status updated!\n";
                } else {
                    std::cout << "Invalid status!\n";
                }
                break;
            case 2:
                std::cout << "Enter new payment status (0: Unpaid, 1: Paid): ";
                int newPaymentStatus;
                std::cin >> newPaymentStatus;
                if (newPaymentStatus >= 0 && newPaymentStatus <= 1) {
                    it->pstatus = static_cast<PaymentStatus>(newPaymentStatus);
                    std::cout << "Payment status updated!\n";
                } else {
                    std::cout << "Invalid payment status!\n";
                }
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } else {
        std::cout << "Shipment with ID " << id << " not found!\n";
    }
}

// Xóa lô hàng khỏi danh sách
void ShipmentManager::removeShipment(const std::string& id) {
    auto it = std::find_if(shipments.begin(), shipments.end(), [&id](const Shipment& shipment) {
        return shipment.shipmentId == id;
    });

    if (it != shipments.end()) {
        shipments.erase(it);
        std::cout << "Shipment removed successfully!\n";
    } else {
        std::cout << "Shipment with ID " << id << " not found!\n";
    }
}

// In danh sách tất cả các lô hàng
void ShipmentManager::printAllShipments() const {
    if (shipments.empty()) {
        std::cout << "No shipments available.\n";
        return;
    }
    for (const auto& shipment : shipments) {
        shipment.printInfo();
        std::cout << "--------------------------------\n";
    }
}

// Sắp xếp lô hàng theo ID
void ShipmentManager::sortShipmentsById(bool ascending) {
    std::sort(shipments.begin(), shipments.end(), [ascending](const Shipment& a, const Shipment& b) {
        return ascending ? a.shipmentId < b.shipmentId : a.shipmentId > b.shipmentId;
    });
}

// Sắp xếp lô hàng theo tên khách hàng
void ShipmentManager::sortShipmentsByName(bool ascending) {
    std::sort(shipments.begin(), shipments.end(), [ascending](const Shipment& a, const Shipment& b) {
        return ascending ? a.Name < b.Name : a.Name > b.Name;
    });
}

// Menu quản lý lô hàng
void menuShipment(ShipmentManager& shipmentManager, const CustomerManager& customerManager) {
    int choice;
    do {
        std::cout << "\t\tBIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================MENU-SHIPMENT====================\n";
        std::cout << "==            1. Add shipment                      ==\n";
        std::cout << "==            2. Find shipment                     ==\n";
        std::cout << "==            3. Update shipment                   ==\n";
        std::cout << "==            4. Remove shipment                   ==\n";
        std::cout << "==            5. Print all shipments               ==\n";
        std::cout << "==            6. Sort shipments by ID              ==\n";
        std::cout << "==            7. Sort shipments by name            ==\n";
        std::cout << "==            8. Exit                              ==\n";
        std::cout << "=====================================================\n";
        std::cout <<"Enter your choice:";
        std::cin >> choice;

        switch (choice) {
            case 1:
                shipmentManager.addShipment(customerManager);
                break;
            case 2:
                {
                    std::string id;
                    std::cout << "Enter Shipment ID to find: ";
                    std::cin >> id;
                    shipmentManager.findShipment(id);
                }
                break;
            case 3:
                {
                    std::string id;
                    std::cout << "Enter Shipment ID to update: ";
                    std::cin >> id;
                    shipmentManager.updateShipment(id);
                }
                break;
            case 4:
                {
                    std::string id;
                    std::cout << "Enter Shipment ID to remove: ";
                    std::cin >> id;
                    shipmentManager.removeShipment(id);
                }
                break;
            case 5:
                shipmentManager.printAllShipments();
                break;
            case 6:
                shipmentManager.sortShipmentsById();
                break;
            case 7:
                shipmentManager.sortShipmentsByName();
                break;
            case 8:
                std::cout << "Exiting the shipment management system.\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 8);
}

int main() {
    CustomerManager customerManager;
    ShipmentManager shipmentManager;

    int mainChoice;
    do {
        std::cout << "\t\tBIET DOI HIGH CODE\t" << std::endl;
        std::cout << "=======================MAIN MENU======================\n";
        std::cout << "==            1. Customer management                ==\n";
        std::cout << "==            2. Shipment management                ==\n";
        std::cout << "==            3. Exit                               ==\n";
        std::cout << "======================================================\n";
        std::cout <<"Enter your choice:";                 
        std::cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                menuCustomer(customerManager);
                break;
            case 2:
                menuShipment(shipmentManager, customerManager);
                break;
            case 3:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (mainChoice != 3);

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

struct Shipper {
    std::string Name;
    std::string ID;
    int Phone;
};

// Class quản lý shipper
class ShipperManager {
    std::vector<Shipper> listShipper;

    // Hàm nhập chuỗi từ shipper
    std::string inputString(const std::string &prompt);

    // Hàm tìm kiếm shipper theo mã shipper
    std::vector<Shipper>::iterator searchID(const std::string &shipperID);

    // Hàm tìm kiếm shipper theo điện thoại
    std::vector<Shipper>::iterator searchPhone(const int &phone);

public:
    // Hàm xóa shipper
    void deleteShipper();

    // Hàm thêm shipper
    void addShipper();

    // Hàm sửa shipper
    void fixShipper();

    // Hàm in danh sách shipper
    void printListShipper() const;

    // Hàm menu
    void menu();
};

// Hàm nhập chuỗi từ shipper
std::string ShipperManager::inputString(const std::string &prompt) {
    std::cout << prompt;
    std::string input;
    char buffer[100];
    if (fgets(buffer, 100, stdin)) {
        buffer[strcspn(buffer, "\n")] = 0;
        input = buffer;
    }
    return input;
}

// Hàm tìm kiếm shipper theo mã
std::vector<Shipper>::iterator ShipperManager::searchID(const std::string &shipperID) {
    return std::find_if(listShipper.begin(), listShipper.end(), [&shipperID](const Shipper &shipper) { return shipper.ID == shipperID; });
}

// Xóa shipper
void ShipperManager::deleteShipper() {
    std::string shipperID = inputString("Enter the shipper ID to delete: ");
    auto it = searchID(shipperID);
    if (it != listShipper.end()) {
        listShipper.erase(it);
        std::cout << "Shipper with ID " << shipperID << " has been deleted!\n";
    } else {
        std::cout << "Shipper with ID " << shipperID << " does not exist!\n";
    }
}

// Thêm shipper
void ShipperManager::addShipper() {
    Shipper shipper;
    shipper.ID = inputString("Enter the shipper ID to add: ");
    shipper.Name = inputString("Enter the shipper's name: ");
    std::cout << "Enter the shipper's phone number: ";
    std::cin >> shipper.Phone;
    std::cin.ignore();

    // Kiểm tra xem shipper tồn tại chưa
    auto it = searchID(shipper.ID);
    if (it != listShipper.end()) {
        std::cout << "Shipper with ID " << shipper.ID << " already exists!\n";
    } else {
        listShipper.push_back(shipper);
        std::cout << "Shipper added successfully!\n";
    }
}

// Hàm sửa shipper
void ShipperManager::fixShipper() {
    Shipper shipper;
    shipper.ID = inputString("Enter the shipper ID to modify: ");

    // Sửa thông tin shipper
    auto it = searchID(shipper.ID);
    if (it != listShipper.end()) {
        std::cout << "Select the field to modify:\n"
                     "1. Shipper ID\n"
                     "2. Shipper Name\n"
                     "3. Shipper Phone Number\n";
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                it->ID = inputString("Enter the new shipper ID: ");
                break;
            case 2:
                it->Name = inputString("Enter the new shipper name: ");
                break;
            case 3:
                std::cout << "Enter the new shipper phone number: ";
                std::cin >> it->Phone;
                std::cin.ignore();
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } else {
        std::cout << "Shipper with ID " << shipper.ID << " does not exist!\n";
    }
}

// Hàm in danh sách shipper
void ShipperManager::printListShipper() const {
    for (const auto& shipper : listShipper) {
        std::cout << "\nShipper ID: " << shipper.ID;
        std::cout << "\nShipper Name: " << shipper.Name;
        std::cout << "\nShipper Phone Number: " << shipper.Phone << "\n";
    }
}

// Hàm menu
void ShipperManager::menu() {
    int choice;
    do {
        std::cout << "1. Delete shipper\n";
        std::cout << "2. Add shipper\n";
        std::cout << "3. Modify shipper\n";
        std::cout << "4. Print shipper information\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                deleteShipper();
                break;
            case 2:
                addShipper();
                break;
            case 3:
                fixShipper();
                break;
            case 4:
                printListShipper();
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 5);
}

int main() {
    ShipperManager shipperManager;
    shipperManager.menu();
    return 0;
}

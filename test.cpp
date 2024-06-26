#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

class BaseCustomer {
protected:
    std::string ID;
    std::string Name;
    std::string Address;
public:    
    BaseCustomer(std::string id, const std::string& name, const std::string& address)
        : ID(id), Name(name), Address(address) {}
    std::string getID() const { return ID; }
    std::string getName() const { return Name; }
    std::string getAddress() const { return Address; }
friend class SenderManagement;
friend class ReceiverManagement;
friend class ShipmentManager;
};

// Lớp Customer kế thừa từ BaseCustomer
class Person : public BaseCustomer {
public:
    std::string Phone; 

    Person(const std::string& id, const std::string& name, const std::string& address, const std::string& phone)
        : BaseCustomer(id, name, address), Phone(phone) {}
};

// Quản lý danh sách người gửi
class SenderManagement {
public:
    std::vector<Person> listSenders; // Danh sách người gửi

    void addSender(); // Thêm người gửi mới
    void deleteSender(); // Xóa người gửi
    void fixSender(); // Sửa thông tin người gửi
    void findSenderbyID(); // Tìm người gửi
    void printlistSenders() const; // In danh sách người gửi
    Person getSender(std::string id) const; // Lấy thông tin người gửi theo ID

friend class ShipmentManager;
};

// Quản lý danh sách người nhận
class ReceiverManagement {
public:
    std::vector<Person> listReceivers; // Danh sách người nhận

    void addReceiver(); // Thêm người nhận mới
    void deleteReceiver(); // Xóa người nhận
    void fixReceiver(); // Sửa thông tin người nhận
    void findReceiverbyID(); // Tìm người nhận
    void printlistReceivers() const; // In danh sách người nhận
    Person getReceiver(std::string id) const; // Lấy thông tin người nhận theo ID

friend class ShipmentManager;
};

// Hàm nhập chuỗi từ người dùng với prompt
std::string inputstring(const std::string &prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

// Thêm người gửi mới vào danh sách
void SenderManagement::addSender() {
    system("CLS"); // Xóa màn hình
    std::string id, name, address, phone;

    std::cout << "Enter sender ID: ";
    std::cin >> id;
    std::cin.ignore();
    name = inputstring("Enter sender name: ");
    address = inputstring("Enter sender address: ");
    std::cout << "Enter sender phone number: ";
    std::cin >> phone;

    listSenders.push_back(Person(id, name, address, phone)); // Thêm người gửi vào danh sách
    std::cout << "Sender added successfully!\n";
    system("pause"); // Tạm dừng chương trình
}

// Xóa người gửi khỏi danh sách
void SenderManagement::deleteSender() {
    system("CLS"); // Xóa màn hình
    std::string id;
    std::cout << "Enter sender ID to delete: ";
    std::cin >> id;

    auto it = std::find_if(listSenders.begin(), listSenders.end(), [&id](const Person& sender) {
        return sender.ID == id;
    });

    if (it != listSenders.end()) {
        listSenders.erase(it);
        std::cout << "Sender deleted successfully!\n";
    } else {
        std::cout << "Sender not found!\n";
    }
    system("pause"); // Tạm dừng chương trình
}

// Sửa thông tin người gửi
void SenderManagement::fixSender() {
    system("CLS"); // Xóa màn hình
    std::string id;
    std::cout << "Enter sender ID to modify: ";
    std::cin >> id;
    std::cin.ignore();

    auto it = std::find_if(listSenders.begin(), listSenders.end(), [&id](const Person& sender) {
        return sender.ID == id;
    });

    if (it != listSenders.end()) {
        it->Name = inputstring("Enter new sender name: ");
        it->Address = inputstring("Enter new sender address: ");
        std::cout << "Enter new sender phone number: ";
        std::cin >> it->Phone;
        std::cout << "Sender information updated successfully!\n";
    } else {
        std::cout << "Sender not found!\n";
    }
    system("pause"); // Tạm dừng chương trình
}

// Tìm người gửi theo ID
void SenderManagement::findSenderbyID() {
    system("CLS"); // Xóa màn hình
    std::string id;
    std::cout << "Enter sender ID to find: ";
    std::cin >> id;

    auto it = std::find_if(listSenders.begin(), listSenders.end(), [&id](const Person& sender) {
        return sender.ID == id;
    });

    if (it != listSenders.end()) {
        std::cout << "Sender found:\n";
        std::cout << "ID: " << it->ID << "\nName: " << it->Name << "\nAddress: " << it->Address << "\nPhone: " << it->Phone << "\n";
    } else {
        std::cout << "Sender not found!\n";
    }
    system("pause"); // Tạm dừng chương trình
}

// In danh sách người gửi
void SenderManagement::printlistSenders() const {
    system("CLS"); // Xóa màn hình
    std::cout << "List of Senders:\n";
    for (const auto& sender : listSenders) {
        std::cout << "ID: " << sender.ID << "\nName: " << sender.Name << "\nAddress: " << sender.Address << "\nPhone: " << sender.Phone << "\n-------------------\n";
    }
    system("pause"); // Tạm dừng chương trình
}

// Lấy thông tin người gửi theo ID
Person SenderManagement::getSender(std::string id) const {
    auto it = std::find_if(listSenders.begin(), listSenders.end(), [&id](const Person& sender) {
        return sender.ID == id;
    });

    if (it != listSenders.end()) {
        return *it;
    } else {
        throw std::runtime_error("Sender not found");
    }
}

// Thêm người nhận mới vào danh sách
void ReceiverManagement::addReceiver() {
    system("CLS"); // Xóa màn hình
    std::string id, name, address, phone;

    std::cout << "Enter receiver ID: ";
    std::cin >> id;
    std::cin.ignore();
    name = inputstring("Enter receiver name: ");
    address = inputstring("Enter receiver address: ");
    std::cout << "Enter receiver phone number: ";
    std::cin >> phone;

    listReceivers.push_back(Person(id, name, address, phone)); // Thêm người nhận vào danh sách
    std::cout << "Receiver added successfully!\n";
    system("pause"); // Tạm dừng chương trình
}

// Xóa người nhận khỏi danh sách
void ReceiverManagement::deleteReceiver() {
    system("CLS"); // Xóa màn hình
    std::string id;
    std::cout << "Enter receiver ID to delete: ";
    std::cin >> id;

    auto it = std::find_if(listReceivers.begin(), listReceivers.end(), [&id](const Person& receiver) {
        return receiver.ID == id;
    });

    if (it != listReceivers.end()) {
        listReceivers.erase(it);
        std::cout << "Receiver deleted successfully!\n";
    } else {
        std::cout << "Receiver not found!\n";
    }
    system("pause"); // Tạm dừng chương trình
}

// Sửa thông tin người nhận
void ReceiverManagement::fixReceiver() {
    system("CLS"); // Xóa màn hình
    std::string id;
    std::cout << "Enter receiver ID to modify: ";
    std::cin >> id;
    std::cin.ignore();

    auto it = std::find_if(listReceivers.begin(), listReceivers.end(), [&id](const Person& receiver) {
        return receiver.ID == id;
    });

    if (it != listReceivers.end()) {
        it->Name = inputstring("Enter new receiver name: ");
        it->Address = inputstring("Enter new receiver address: ");
        std::cout << "Enter new receiver phone number: ";
        std::cin >> it->Phone;
        std::cout << "Receiver information updated successfully!\n";
    } else {
        std::cout << "Receiver not found!\n";
    }
    system("pause"); // Tạm dừng chương trình
}

// Tìm người nhận theo ID
void ReceiverManagement::findReceiverbyID() {
    system("CLS"); // Xóa màn hình
    std::string id;
    std::cout << "Enter receiver ID to find: ";
    std::cin >> id;

    auto it = std::find_if(listReceivers.begin(), listReceivers.end(), [&id](const Person& receiver) {
        return receiver.ID == id;
    });

    if (it != listReceivers.end()) {
        std::cout << "Receiver found:\n";
        std::cout << "ID: " << it->ID << "\nName: " << it->Name << "\nAddress: " << it->Address << "\nPhone: " << it->Phone << "\n";
    } else {
        std::cout << "Receiver not found!\n";
    }
    system("pause"); // Tạm dừng chương trình
}

// In danh sách người nhận
void ReceiverManagement::printlistReceivers() const {
    system("CLS"); // Xóa màn hình
    std::cout << "List of Receivers:\n";
    for (const auto& receiver : listReceivers) {
        std::cout << "ID: " << receiver.ID << "\nName: " << receiver.Name << "\nAddress: " << receiver.Address << "\nPhone: " << receiver.Phone << "\n-------------------\n";
    }
    system("pause"); // Tạm dừng chương trình
}

// Lấy thông tin người nhận theo ID
Person ReceiverManagement::getReceiver(std::string id) const {
    auto it = std::find_if(listReceivers.begin(), listReceivers.end(), [&id](const Person& receiver) {
        return receiver.ID == id;
    });

    if (it != listReceivers.end()) {
        return *it;
    } else {
        throw std::runtime_error("Receiver not found");
    }
}

// Menu quản lý người gửi
void menuSender(SenderManagement& manager){
    int choice;
    do {
        system("CLS"); // Xóa màn hình
        std::cout << "\t\tBIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================MENU-SENDER===================\n";
        std::cout << "==            1.Add Sender                      ==\n";
        std::cout << "==            2.Delete Sender                   ==\n";
        std::cout << "==            3.Edit Sender                     ==\n";
        std::cout << "==            4.Find Sender                     ==\n";
        std::cout << "==            5.Print Sender list               ==\n";
        std::cout << "==            6.Exit                            ==\n";
        std::cout << "==================================================\n";
        std::cout <<" Enter your choice:"; 
        std::cin >> choice;
        std::cin.ignore(); // Bỏ qua newline trong bộ đệm
        switch (choice) {
            case 1:
                manager.addSender();
                break;
            case 2:
                manager.deleteSender();
                break;
            case 3:
                manager.fixSender();
                break;
            case 4:
                manager.findSenderbyID();
                break;    
            case 5:
                manager.printlistSenders();
                break;
            case 6:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                system("pause"); // Tạm dừng chương trình
                break;
        }
    } while (choice != 6);
}

// Menu quản lí người nhận
void menuReceiver(ReceiverManagement& manager){
    int choice;
    do {
        system("CLS"); // Xóa màn hình
        std::cout << "\t\tBIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================MENU-RECEIVER===================\n";
        std::cout << "==            1.Add Receiver                      ==\n";
        std::cout << "==            2.Delete Receiver                   ==\n";
        std::cout << "==            3.Edit Receiver                     ==\n";
        std::cout << "==            4.Find Receiver                     ==\n";
        std::cout << "==            5.Print Receiver list               ==\n";
        std::cout << "==            6.Exit                              ==\n";
        std::cout << "====================================================\n";
        std::cout <<"Enter your choice:"; 
        std::cin >> choice;
        std::cin.ignore(); // Bỏ qua newline trong bộ đệm
        switch (choice) {
            case 1:
                manager.addReceiver();
                break;
            case 2:
                manager.deleteReceiver();
                break;
            case 3:
                manager.fixReceiver();
                break;
            case 4:
                manager.findReceiverbyID();
                break;    
            case 5:
                manager.printlistReceivers();
                break;
            case 6:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                system("pause"); // Tạm dừng chương trình
                break;
        }
    } while (choice != 6);
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

// Lớp Shipment 
class Shipment  {
public:
    std::string shipmentId;
    Date receiveDate, deliveryDate;
    std::string goodsInfo;
    ShipmentStatus status;
    PaymentStatus pstatus;
    Person sender;
    Person receiver;


    Shipment(std::string id, Date rdate, const Person& send,const Person& recei, std::string goods, Date ddate)
        : shipmentId(std::move(id)), receiveDate(std::move(rdate)), deliveryDate(std::move(ddate)), goodsInfo(std::move(goods)), status(Received), pstatus(Unpaid),sender(send),receiver(recei) {}

    // In thông tin lô hàng
    void printInfo() const {
        std::cout << "Shipment ID: " << shipmentId << "\n"
            << "Receive Date: " << dateToString(receiveDate) << "\n"
            << "Delivery Date: " << dateToString(deliveryDate) << "\n"
            << "Sender Name: " << sender.getName() << "\n"
            << "Sender Address: " << sender.getAddress() << "\n"
            << "Receiver Name: " << receiver.getName() << "\n"
            << "Receiver Address: " << receiver.getAddress() << "\n"
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
    void addShipment(const SenderManagement& send,const ReceiverManagement& recei); // Thêm lô hàng mới
    void findShipment(const std::string& id) const; // Tìm lô hàng theo ID
    void updateShipment(const std::string& id); // Cập nhật thông tin lô hàng
    void removeShipment(const std::string& id); // Xóa lô hàng
    void printListShipment() const; // In danh sách lô hàng
    void sortShipmentsById(bool ascending = true); // Sắp xếp lô hàng theo ID
};
// Thêm lô hàng mới
void ShipmentManager::addShipment(const SenderManagement& send,const ReceiverManagement& recei) {
    system("CLS"); // Xóa màn hình
    std::string shipmentId, goodsInfo, senId, receId;
    Date receiveDate, deliveryDate;

    std::cout << "Enter shipment ID: ";
    std::cin >> shipmentId;
    std::cout << "Enter receive date (day month year): ";
    std::cin >> receiveDate.day >> receiveDate.month >> receiveDate.year;
    std::cout << "Enter Sender ID: ";
    std::cin >> senId;
    std::cout << "Enter Receiver ID: ";
    std::cin >> receId;

    Person sender = send.getSender(senId);
    Person receiver = recei.getReceiver(receId);

    std::cin.ignore(); // Bỏ qua newline trong bộ đệm
    std::cout << "Enter goods info: ";
    std::getline(std::cin, goodsInfo);
    std::cout << "Enter delivery date (day month year): ";
    std::cin >> deliveryDate.day >> deliveryDate.month >> deliveryDate.year;

    shipments.emplace_back(shipmentId, receiveDate,sender,receiver, goodsInfo, deliveryDate); // Thêm lô hàng vào danh sách
    std::cout << "Shipment added successfully.\n";
    system("pause"); // Tạm dừng chương trình
}

// Tìm lô hàng theo ID
void ShipmentManager::findShipment(const std::string& id) const {
    system("CLS"); // Xóa màn hình
    auto it = std::find_if(shipments.begin(), shipments.end(), [&id](const Shipment& shipment) {
        return shipment.shipmentId == id;
    });

    if (it != shipments.end()) {
        it->printInfo();
    } else {
        std::cout << "Shipment with ID " << id << " not found!\n";
    }
    system("pause"); // Tạm dừng chương trình
}

// Cập nhật thông tin lô hàng
void ShipmentManager::updateShipment(const std::string& id) {
    system("CLS"); // Xóa màn hình
    auto it = std::find_if(shipments.begin(), shipments.end(), [&id](const Shipment& shipment) {
        return shipment.shipmentId == id;
    });

    if (it != shipments.end()) {
        int choice;
        std::cout << "What information do you want to edit?\n";
        std::cout << "1. Shipment Status\n";
        std::cout << "2. Payment Status\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int status;
                std::cout << "Enter new status (0: Received, 1: In Transit, 2: Delivered): ";
                std::cin >> status;
                if (status >= 0 && status <= 2) {
                    it->status = static_cast<ShipmentStatus>(status);
                    std::cout << "Shipment status updated successfully.\n";
                } else {
                    std::cout << "Invalid status value.\n";
                }
                break;
            case 2:
                int pstatus;
                std::cout << "Enter new payment status (0: Unpaid, 1: Paid): ";
                std::cin >> pstatus;
                if (pstatus >= 0 && pstatus <= 1) {
                    it->pstatus = static_cast<PaymentStatus>(pstatus);
                    std::cout << "Payment status updated successfully.\n";
                } else {
                    std::cout << "Invalid payment status value.\n";
                }
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } else {
        std::cout << "Shipment with ID " << id << " not found!\n";
    }
    system("pause"); // Tạm dừng chương trình
}

// Xóa lô hàng khỏi danh sách
void ShipmentManager::removeShipment(const std::string& id) {
    system("CLS"); // Xóa màn hình
    auto it = std::find_if(shipments.begin(), shipments.end(), [&id](const Shipment& shipment) {
        return shipment.shipmentId == id;
    });

    if (it != shipments.end()) {
        shipments.erase(it); // Xóa lô hàng khỏi danh sách
        std::cout << "Shipment removed successfully.\n";
    } else {
        std::cout << "Shipment with ID " << id << " not found!\n";
    }
    system("pause"); // Tạm dừng chương trình
}

// Sắp xếp lô hàng theo ID
void ShipmentManager::sortShipmentsById(bool ascending) {
    system("CLS");
    std::cout<<"Shipments sort by ID successfully\n";
    system("pause");
    std::sort(shipments.begin(), shipments.end(), [ascending](const Shipment& a, const Shipment& b) {
    return ascending ? a.shipmentId < b.shipmentId : a.shipmentId > b.shipmentId;
});
}

// In danh sách lô hàng
void ShipmentManager::printListShipment() const {
    system("CLS"); // Xóa màn hình
    for (const auto& shipment : shipments) {
        shipment.printInfo();
        std::cout << "\n";
    }
    system("pause"); // Tạm dừng chương trình
}

// Menu quản lý lô hàng
void menuShipment(ShipmentManager& shipmentManager, const SenderManagement sender,const ReceiverManagement receiver) {
    int choice;
    do {
        system("CLS"); // Xóa màn hình
        std::cout << "\t\tBIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================MENU-SHIPMENT===================\n";
        std::cout << "==            1. Add Shipment                     ==\n";
        std::cout << "==            2. Find Shipment                    ==\n";
        std::cout << "==            3. Update Shipment                  ==\n";
        std::cout << "==            4. Remove Shipment                  ==\n";
        std::cout << "==            5. Print Shipment List              ==\n";
        std::cout << "==            6. Sort shipments by ID             ==\n";
        std::cout << "==            7. Exit                             ==\n";
        std::cout << "====================================================\n";
        std::cout <<"Enter your choice:";
        std::cin >> choice;
        std::cin.ignore(); // Bỏ qua newline trong bộ đệm
        switch (choice) {
            case 1:
                shipmentManager.addShipment(sender,receiver);
                break;
            case 2:
                {
                    std::string id;
                    std::cout << "Enter shipment ID to find: ";
                    std::cin >> id;
                    shipmentManager.findShipment(id);
                }
                break;
            case 3:
                {
                    std::string id;
                    std::cout << "Enter shipment ID to update: ";
                    std::cin >> id;
                    shipmentManager.updateShipment(id);
                }
                break;
            case 4:
                {
                    std::string id;
                    std::cout << "Enter shipment ID to remove: ";
                    std::cin >> id;
                    shipmentManager.removeShipment(id);
                }
                break;
            case 5:
                shipmentManager.printListShipment();
                break;    
            case 6:
                shipmentManager.sortShipmentsById("Shipment will sort by ID!\n\n\n");
                break;
            case 7:
                std::cout << "Exiting the shipment management system.\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                system("pause"); // Tạm dừng chương trình
                break;
    }
} while (choice != 7);
}
int main() {
    SenderManagement sender;
    ReceiverManagement receiver;
    ShipmentManager shipmentManager;

    int choice;
    do {
        system("CLS"); // Xóa màn hình
        std::cout << "\t\tBIET DOI HIGH CODE\t" << std::endl;
        std::cout << "=======================MENU=========================\n";
        std::cout << "==            1. Sender Management                ==\n";
        std::cout << "==            2. Receiver Management              ==\n";
        std::cout << "==            3. Shipment Management              ==\n";
        std::cout << "==            4. Exit                             ==\n";
        std::cout << "====================================================\n";
        std::cout <<"Enter your choice:"; 
        std::cin >> choice;
        std::cin.ignore(); // Bỏ qua newline trong bộ đệm
        switch (choice) {
            case 1:
                menuSender(sender);
                break;
            case 2:
                menuReceiver(receiver);
                break;
            case 3:
                menuShipment(shipmentManager,sender,receiver);
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                system("pause"); // Tạm dừng chương trình
                break;
        }
    } while (choice != 4);

    return 0;
}
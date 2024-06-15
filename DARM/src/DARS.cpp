#include "DARS.h"
#include <iostream>
#include <windows.h>
#include <vector>

std::vector <Shipment> shipments;
std::vector <Shipper> shippers;
std::vector <Deliver> delivers;
std::vector <Receiver> receivers;
std::vector <DARM> darm;

void menu() {
    int choice;
    while (true) {
        system("CLS");
        std::cout << "Menu:\n";
        std::cout << "1. Add Shipment\n";
        std::cout << "2. Update Shipment\n";
        std::cout << "3. Delete Shipment\n";
        std::cout << "4. Add Deliver\n";
        std::cout << "5. Update Deliver\n";
        std::cout << "6. Delete Deliver\n";
        std::cout << "7. Add Receiver\n";
        std::cout << "8. Update Receiver\n";
        std::cout << "9. Delete Receiver\n";
        std::cout << "10. Add Shipper\n";
        std::cout << "11. Update Shipper\n";
        std::cout << "12. Delete Shipper\n";
        std::cout << "13. Find Info by ID\n";
        std::cout << "14. Print Shipment Info\n";
        std::cout << "15. Print Shipper Info\n";
        std::cout << "16. Print Customer Info\n";
        std::cout << "17. Print All Shipment Info\n";
        std::cout << "18. Print All Shipper Info\n";
        std::cout << "19. Print All Customer Info\n";
        std::cout << "20. Print All Shipment Of Customer\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system("CLS");
                addShipment();
                system("pause");
                break;
            case 2:
                system("CLS");
                updateShipment();
                system("pause");
                break;
            case 3:
                system("CLS");
                deleteShipment();
                system("pause");
                break;
            case 4:
                system("CLS");
                addDeliver();
                system("pause");
                break;
            case 5:
                system("CLS");
                updateDeliver();
                system("pause");
                break;
            case 6:
                system("CLS");
                deleteDeliver();
                system("pause");
                break;
            case 7:
                system("CLS");
                addReceiver();
                system("pause");
                break;
            case 8:
                system("CLS");
                updateReceiver();
                system("pause");
                break;
            case 9:
                system("CLS");
                deleteReceiver();
                system("pause");
                break;
            case 10:
                system("CLS");
                addShipper();
                system("pause");
                break;
            case 11:
                system("CLS");
                updateShipper();
                system("pause");
                break;
            case 12:
                system("CLS");
                deleteShipper();
                system("pause");
                break;
            case 13: {
                system("CLS");
                std::string id;
                std::cout << "Enter ID to find info: ";
                std::cin >> id;
                findInfoById(id);
                system("pause");
                break;
            }
            case 14: {
                system("CLS");
                std::string id;
                std::cout << "Enter shipment ID to print info: ";
                std::cin >> id;
                printShipmentInfo(id);
                system("pause");
                break;
            }
            case 15: {
            //    system("CLS");
                std::string id;
                std::cout << "Enter shipper ID to print info: ";
                std::cin >> id;
                printShipperInfo(id);
               // system("pause");
                break;
            }
            case 16: {
                system("CLS");
                std::string id;
                std::cout << "Enter customer ID to print info: ";
                std::cin >> id;
                printCustomerInfo(id);
                system("pause");
                break;
            }
            case 17:
                system("CLS");
                printAllShipmentInfo();
                system("pause");
                break;
            case 18:
                system("CLS");
                printAllShipperInfo();
                system("pause");
                break;
            case 19:
                system("CLS");
                printAllCustomerInfo();
                system("pause");
                break;
            case 20:
                system("CLS");
                printAllShipmentOfCustomer();
                system("pause");
                break;

            case 0:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void findInfoById(std::string id) {
    bool found = false;
    for (const auto& shipment : shipments) {
        if (shipment.getShipmentId() == id) {
            std::cout << "Shipment found: " << shipment.getShipmentName() << "\n";
            found = true;
            break;
        }
    }
    for (const auto& shipper : shippers) {
        if (shipper.getid() == id) {
            std::cout << "Shipper found: " << shipper.getname() << "\n";
            found = true;
            break;
        }
    }
    for (const auto& deliver : delivers) {
        if (deliver.getDeliverId() == id) {
            std::cout << "Deliver found: " << deliver.getDeliverName() << "\n";
            found = true;
            break;
        }
    }
    for (const auto& receiver : receivers) {
        if (receiver.getReceiverId() == id) {
            std::cout << "Receiver found: " << receiver.getReceiverName() << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "No information found for ID: " << id << "\n";
    }
}

void addShipment() {
    Deliver newDeliver;
    std::string deliverName, deliverAddress, deliverId;
    int deliverPhone;

    std::cout << "Enter deliver ID: ";
    std::cin >> deliverId;
    bool found = false;
    for(const auto& deliver : delivers){
        if (deliver.getDeliverId() == deliverId) {
            found = true;
            break;
        }
    }
    if(found == true)
        std::cout << "This deliverer information has been previously saved!" << std::endl;
    else{
        newDeliver.setDeliverId(deliverId);
        std::cout << "Enter deliver name: ";
        std::cin.ignore();
        std::getline(std::cin, deliverName);
        newDeliver.setDeliverName(deliverName);
        std::cout << "Enter deliver address: ";
        std::getline(std::cin, deliverAddress);
        newDeliver.setDeliverAddress(deliverAddress);
        std::cout << "Enter deliver phone: ";
        std::cin >> deliverPhone;
        newDeliver.setDeliverPhone(deliverPhone);
        delivers.push_back(newDeliver);
        std::cout << "Deliver added successfully.\n";
    }

    Receiver newReceiver;
    std::string receiverName, receiverAddress, receiverId;
    int receiverPhone;

    std::cout << "Enter receiver ID: ";
    std::cin >> receiverId;
    found = false;
    for(const auto& receiver : receivers){
        if (receiver.getReceiverId() == receiverId) {
            found = true;
            break;
        }
    }
    if(found == true)
        std::cout << "This receiver information has been previously saved!" << std::endl;
    else{
        newReceiver.setReceiverId(receiverId);
        std::cout << "Enter receiver name: ";
        std::cin.ignore();
        std::getline(std::cin, receiverName);
        newReceiver.setReceiverName(receiverName);
        std::cout << "Enter receiver address: ";
        std::getline(std::cin, receiverAddress);
        newReceiver.setReceiverAddress(receiverAddress);
        std::cout << "Enter receiver phone: ";
        std::cin >> receiverPhone;
        newReceiver.setReceiverPhone(receiverPhone);
        receivers.push_back(newReceiver);
        std::cout << "Receiver added successfully.\n";
    }

    Shipment newShipment;
    std::string shipmentId, name;
    int qty;
    Date dDate;

    std::cout << "Enter shipment ID: ";
    std::cin >> shipmentId;
    newShipment.setShipmentId(shipmentId);
    std::cout << "Enter shipment name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    newShipment.setShipmentName(name);
    std::cout << "Enter quantity: ";
    std::cin >> qty;
    newShipment.setQuantity(qty);
    newShipment.setDeliveryDate(dDate);
    shipments.push_back(newShipment);
    std::cout << "Shipment added successfully.\n";

    DARM newDarm;
    newDarm.setDARM(deliverId, receiverId, shipmentId);
    darm.push_back(newDarm);
}

void updateShipment() {
    std::string id;
    std::cout << "Enter shipment ID to update: ";
    std::cin >> id;
    for (auto& shipment : shipments) {
        if (shipment.getShipmentId() == id) {
            std::string name;
            int qty;
            std::cout << "Enter new shipment name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            shipment.setShipmentName(name);
            std::cout << "Enter new quantity: ";
            std::cin >> qty;
            shipment.setQuantity(qty);
            std::cout << "Shipment updated successfully.\n";
            return;
        }
    }
    std::cout << "Shipment with ID " << id << " not found.\n";
}

void deleteShipment() {
    std::string id;
    std::cout << "Enter shipment ID to delete: ";
    std::cin >> id;
    for (auto it = shipments.begin(); it != shipments.end(); ++it) {
        if (it->getShipmentId() == id) {
            shipments.erase(it);
            std::cout << "Shipment deleted successfully.\n";
            return;
        }
    }
    std::cout << "Shipment with ID " << id << " not found.\n";
}

void addDeliver() {
    Deliver newDeliver;
    std::string name, address, id;
    int phone;

    std::cout << "Enter deliver ID: ";
    std::cin >> id;
    bool found = false;
    for(const auto& deliver : delivers){
        if (deliver.getDeliverId() == id) {
            found = true;
            break;
        }
    }
    if(found == true)
        std::cout << "This deliverer information has been previously saved!" << std::endl;
    else{
        newDeliver.setDeliverId(id);
        std::cout << "Enter deliver name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        newDeliver.setDeliverName(name);
        std::cout << "Enter deliver address: ";
        std::getline(std::cin, address);
        newDeliver.setDeliverAddress(address);
        std::cout << "Enter deliver phone: ";
        std::cin >> phone;
        newDeliver.setDeliverPhone(phone);
        delivers.push_back(newDeliver);
        std::cout << "Deliver added successfully.\n";
    }
}

void updateDeliver() {
    std::string id;
    std::cout << "Enter deliver ID to update: ";
    std::cin >> id;
    for (auto& deliver : delivers) {
        if (deliver.getDeliverId() == id) {
            std::string name, address;
            int phone;
            std::cout << "Enter new deliver name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            deliver.setDeliverName(name);
            std::cout << "Enter new deliver address: ";
            std::getline(std::cin, address);
            deliver.setDeliverAddress(address);
            std::cout << "Enter new deliver phone: ";
            std::cin >> phone;
            deliver.setDeliverPhone(phone);
            std::cout << "Deliver updated successfully.\n";
            return;
        }
    }
    std::cout << "Deliver with ID " << id << " not found.\n";
}

void deleteDeliver() {
    std::string id;
    std::cout << "Enter deliver ID to delete: ";
    std::cin >> id;
    for (auto it = delivers.begin(); it != delivers.end(); ++it) {
        if (it->getDeliverId() == id) {
            delivers.erase(it);
            std::cout << "Deliver deleted successfully.\n";
            return;
        }
    }
    std::cout << "Deliver with ID " << id << " not found.\n";
}

void addReceiver() {
    Receiver newReceiver;
    std::string name, address, id;
    int phone;

    std::cout << "Enter receiver ID: ";
    std::cin >> id;
    bool found = false;
    for(const auto& receiver : receivers){
        if (receiver.getReceiverId() == id) {
            found = true;
            break;
        }
    }
    if(found == true)
        std::cout << "This receiver information has been previously saved!" << std::endl;
    else{
        newReceiver.setReceiverId(id);
        std::cout << "Enter receiver name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        newReceiver.setReceiverName(name);
        std::cout << "Enter receiver address: ";
        std::getline(std::cin, address);
        newReceiver.setReceiverAddress(address);
        std::cout << "Enter receiver phone: ";
        std::cin >> phone;
        newReceiver.setReceiverPhone(phone);
        receivers.push_back(newReceiver);
        std::cout << "Receiver added successfully.\n";
    }
}

void updateReceiver() {
    std::string id;
    std::cout << "Enter receiver ID to update: ";
    std::cin >> id;
    for (auto& receiver : receivers) {
        if (receiver.getReceiverId() == id) {
            std::string name, address;
            int phone;
            std::cout << "Enter new receiver name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            receiver.setReceiverName(name);
            std::cout << "Enter new receiver address: ";
            std::getline(std::cin, address);
            receiver.setReceiverAddress(address);
            std::cout << "Enter new receiver phone: ";
            std::cin >> phone;
            receiver.setReceiverPhone(phone);
            std::cout << "Receiver updated successfully.\n";
            return;
        }
    }
    std::cout << "Receiver with ID " << id << " not found.\n";
}

void deleteReceiver() {
    std::string id;
    std::cout << "Enter receiver ID to delete: ";
    std::cin >> id;
    for (auto it = receivers.begin(); it != receivers.end(); ++it) {
        if (it->getReceiverId() == id) {
            receivers.erase(it);
            std::cout << "Receiver deleted successfully.\n";
            return;
        }
    }
    std::cout << "Receiver with ID " << id << " not found.\n";
}

void addShipper() {
    Shipper newShipper;
    std::string id;
    std::string name, phone;

    std::cout << "Enter shipper ID: ";
    std::getline(std::cin, id);
    newShipper.setid(id);
    std::cout << "Enter shipper name: ";
    std::getline(std::cin, name);
    newShipper.setname(name);
    std::cout << "Enter shipper phone: ";
    std::getline(std::cin, phone);
    newShipper.setphone(phone);
    shippers.push_back(newShipper);
    std::cout << "Shipper added successfully.\n";
}

void updateShipper() {
    std::string id;
    std::cout << "Enter shipper ID to update: ";
    std::getline(std::cin, id);
    for (auto& shipper : shippers) {
        if (shipper.getid() == id) {
            std::string name, phone;
            std::cout << "Enter new shipper name: ";
            std::getline(std::cin, name);
            shipper.setname(name);
            std::cout << "Enter new shipper phone: ";
            std::getline(std::cin, phone);
            shipper.setphone(phone);
            std::cout << "Shipper updated successfully.\n";
            return;
        }
    }
    std::cout << "Shipper with ID " << id << " not found.\n";
}

void deleteShipper() {
    std::string id;
    std::cout << "Enter shipper ID to delete: ";
    std::getline(std::cin, id);
    for (auto it = shippers.begin(); it != shippers.end(); ++it) {
        if (it->getid() == id) {
            shippers.erase(it);
            std::cout << "Shipper deleted successfully.\n";
            return;
        }
    }
    std::cout << "Shipper with ID " << id << " not found.\n";
}

void printShipmentInfo(std::string id) {
    for (const auto& shipment : shipments) {
        if (shipment.getShipmentId() == id) {
            std::cout << "Shipment ID: " << shipment.getShipmentId() << "\n";
            std::cout << "Shipment Name: " << shipment.getShipmentName() << "\n";
            std::cout << "Quantity: " << shipment.getQuantity() << "\n";
            return;
        }
    }
    std::cout << "Shipment with ID " << id << " not found.\n";
}

void printShipperInfo(std::string id) {
    for (const auto& shipper : shippers) {
        if (shipper.getid() == id) {
            std::cout << "Shipper ID: " << shipper.getid() << "\n";
            std::cout << "Name: " << shipper.getname() << "\n";
            std::cout << "Phone: " << shipper.getphone() << "\n";
            return;
        }
    }
    std::cout << "Shipper with ID " << id << " not found.\n";
}

void printCustomerInfo(std::string id) {
    for (const auto& receiver : receivers) {
        if (receiver.getReceiverId() == id) {
            std::cout << "Receiver ID: " << receiver.getReceiverId() << "\n";
            std::cout << "Name: " << receiver.getReceiverName() << "\n";
            std::cout << "Address: " << receiver.getReceiverAddress() << "\n";
            std::cout << "Phone: " << receiver.getReceiverPhone() << "\n";
            return;
        }
    }
    std::cout << "Receiver with ID " << id << " not found.\n";
}

void printAllShipmentInfo() {
    for (const auto& shipment : shipments) {
        std::cout << "Shipment ID: " << shipment.getShipmentId() << "\n";
        std::cout << "Shipment Name: " << shipment.getShipmentName() << "\n";
        std::cout << "Quantity: " << shipment.getQuantity() << "\n";
    }
}

void printAllShipperInfo() {
    for (const auto& shipper : shippers) {
        std::cout << "Shipper ID: " << shipper.getid() << "\n";
        std::cout << "Name: " << shipper.getname() << "\n";
        std::cout << "Phone: " << shipper.getphone() << "\n";
    }
}

void printAllCustomerInfo() {
    for (const auto& receiver : receivers) {
        std::cout << "Receiver ID: " << receiver.getReceiverId() << "\n";
        std::cout << "Name: " << receiver.getReceiverName() << "\n";
        std::cout << "Address: " << receiver.getReceiverAddress() << "\n";
        std::cout << "Phone: " << receiver.getReceiverPhone() << "\n";
    }
}

void printAllShipmentOfCustomer() {
    std::string customerId;
    std::cout << "Enter customer ID to print all shipments: ";
    std::cin >> customerId;
    bool found = false;
    for (const auto& dar : darm) {
        if (dar.getDeliverId()==customerId || dar.getReceiverId()==customerId) {
            printShipmentInfo(dar.getShipmentId());
            found = true;
        }
    }
    if (!found) {
        std::cout << "No shipments found for customer ID " << customerId << "\n";
    }
}

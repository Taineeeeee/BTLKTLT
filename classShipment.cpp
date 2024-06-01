#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// Ba trạng thái của đơn hàng: Đã nhận, Đang giao, Đã giao
enum ShipmentStatus { Received, InTransit, Delivered };
// Cấu trúc date
struct Date {
    int day;
    int month;
    int year;
};
//Chuyển đổi date sang chữ để in
string dateToString(const Date& date) {
    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}
//Lớp vận chuyển
class Shipment {
private:
    vector<Shipment> shipments;
public:
    string shipmentId; // Mã đơn giao
    Date receiveDate; // Ngày nhận đơn
    Date deliveryDate; // Ngày giao đơn
    string customerName; // Tên người gửi đơn
    string deliveryAddress; // Địa chỉ cần giao
    string goodsInfo; // Thông tin hàng hoá trong đơn
    ShipmentStatus status; // Trạng thái đơn hàng

    Shipment() = default;
    // Hàm tạo
    Shipment(string id, Date rdate, string customer, string address, string goods, Date ddate)
        : shipmentId(move(id)), receiveDate(move(rdate)), deliveryDate(move(ddate)), customerName(move(customer)), deliveryAddress(move(address)), goodsInfo(move(goods)), status(Received) {}
    // Thêm một đơn hàng
    void addShipment() {
        Shipment shipment;
        cout << "-- Enter the information for new Shipment --" << endl;
        cout << "Shipment ID: ";
        cin >> shipment.shipmentId;
        cout << "Receive Date: ";
        cin >> shipment.receiveDate.day >> shipment.receiveDate.month >> shipment.receiveDate.year;
        cout << "Delivery Date: ";
        cin >> shipment.deliveryDate.day >> shipment.deliveryDate.month >> shipment.deliveryDate.year;
        cout << "Customer Name: ";
        cin.ignore();
        getline(cin, shipment.customerName);
        cout << "Delivery Address: ";
        getline(cin, shipment.deliveryAddress);
        cout << "Goods infomation: ";
        getline(cin, shipment.goodsInfo);
        cout << "Status: Received (0) / InTransit (1) / Delivered (2): ";
        int statusChoice;
        cin >> statusChoice;
        shipment.status = static_cast<ShipmentStatus>(statusChoice);
        shipments.push_back(shipment);
    }
    // Cập nhât đơn hàng
    void updateShipment() {
        cout << "Enter the shippment ID needs to be updated: ";
    }
    // Xóa một đơn hàng theo ID
    void removeShipment(const string& shipmentId) {
        auto it = remove_if(shipments.begin(), shipments.end(), [&shipmentId](const Shipment& shipment) {
            return shipment.shipmentId == shipmentId;
            });
        if (it != shipments.end()) {
            shipments.erase(it, shipments.end());
            cout << "Shipment with ID " << shipmentId << " has been removed.\n";
        }
        else {
            cout << "Shipment with ID " << shipmentId << " not found.\n";
        }
    }

    // Hàm cập nhật trạng thái đơn hàng
    void updateStatus(ShipmentStatus newStatus) {
        status = newStatus;
    }
    // Hàm in thông tin đơn hàng
    void printInfo() const {
        cout << "Shipment ID: " << shipmentId << "\n"
            << "Receive Date: " << dateToString(receiveDate) << "\n"
            << "Delivery Date: " << dateToString(deliveryDate) << "\n"
            << "Customer Name: " << customerName << "\n"
            << "Delivery Address: " << deliveryAddress << "\n"
            << "Goods Info: " << goodsInfo << "\n"
            << "Status: " << (status == Received ? "Received" : status == InTransit ? "In Transit" : "Delivered") << "\n";
    }
    //Hàm in tất cả đơn hàng
    void printAllShipments() const {
        for (const auto& shipment : shipments) {
            shipment.printInfo();
            cout << "------------------------\n";
        }
    }
};

int main() {
    int userChoice;
    Shipment manager; // tạo 1 biến quản lí
    do {
        cout << "SHIPMENT MENU" << endl;
        cout << "1. Display all shipments" << endl;
        cout << "2. Add shipment" << endl;
        cout << "3. Update shipment" << endl;
        cout << "4. Remove Shipment" << endl;
        cout << "5. Find Shipment by ID" << endl;
        cout << "0. Back to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
        case 1:
            manager.printAllShipments();
            break;
        case 2:
            manager.addShipment();
            break;
        case 0:
            cout << "Back to main menu!!!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (userChoice != 0);
    return 0;
}

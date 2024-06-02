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
    void addShipment(const Shipment& shipment) {
        shipments.push_back(shipment);
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
    Date receiveDate1 = { 28, 5, 2024 };
    Date deliveryDate1 = { 28, 5, 2025 };
    Date receiveDate2 = { 29, 5, 2024 };
    Date deliveryDate2 = { 29, 5, 2025 };

    Shipment manager; // tạo 1 biến quản lí

    Shipment shipment1("20233260", receiveDate1, "Viet Anh", "B5 Dormitory", "Books", deliveryDate1);
    Shipment shipment2("20233261", receiveDate2, "Tai Le", "HUST", "Electronics", deliveryDate2);

    manager.addShipment(shipment1);
    manager.addShipment(shipment2);

    cout << "Initial Shipments:\n";
    manager.printAllShipments();

    // Test update tay
    shipment1.updateStatus(InTransit);
    shipment1.printInfo();
    shipment1.updateStatus(Delivered);
    shipment1.printInfo();

    // Test thêm đơn
    // dùng auto. sẽ sửa để có menu ra vào 
    auto addShipmentManually = [&manager]() {
        string id, customer, address, goods;
        Date receiveDate, deliveryDate;

        cout << "Enter Shipment ID: ";
        cin >> id;
        cout << "Enter Receive Date (day month year): ";
        cin >> receiveDate.day >> receiveDate.month >> receiveDate.year;
        cout << "Enter Delivery Date (day month year): ";
        cin >> deliveryDate.day >> deliveryDate.month >> deliveryDate.year;
        cout << "Enter Customer Name: ";
        cin.ignore(); // Xoá bộ dệm
        getline(cin, customer);
        cout << "Enter Delivery Address: ";
        getline(cin, address);
        cout << "Enter Goods Info: ";
        getline(cin, goods);

        Shipment newShipment(id, receiveDate, customer, address, goods, deliveryDate);
        manager.addShipment(newShipment);
    };
    //Thêm tay 1 đơn
    addShipmentManually();

    // test sau khi thêm
    cout << "Shipments after adding manually:\n";
    manager.printAllShipments();

    // Test xoá bằng tay 
    manager.removeShipment("20233261");
    cout << "Shipments after removal:\n";
    manager.printAllShipments();

    return 0;
}

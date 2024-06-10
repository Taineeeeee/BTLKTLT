#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// Ba trạng thái của đơn hàng: Đã nhận, Đang giao, Đã giao
enum ShipmentStatus { Received, InTransit, Delivered };
// Hai trạng thái thanh toán cảu đơn hàng
enum PaymentStatus { Unpaid, Paid };

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
    PaymentStatus pstatus;
    Shipment() = default;
    // Hàm tạo
    Shipment(string id, Date rdate, string customer, string address, string goods, Date ddate)
        : shipmentId(move(id)), receiveDate(move(rdate)), deliveryDate(move(ddate)), customerName(move(customer)), deliveryAddress(move(address)), goodsInfo(move(goods)), status(Received), pstatus(Unpaid) {}
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
        cout << "Shipment Status: Received (0) / InTransit (1) / Delivered (2): ";
        int statusChoice, pstatusChoice;
        cin >> statusChoice;
        shipment.status = static_cast<ShipmentStatus>(statusChoice);
        cout << "Payment Status: Unpaid (0) / Paid (1): ";
        cin >> pstatusChoice;
        shipment.pstatus = static_cast<PaymentStatus>(pstatusChoice);
        cout << "Add shipment succesfully!" << endl;
        shipments.push_back(shipment);
    }
    // Tìm đơn hàng theo ID
    vector<Shipment>::iterator findShipment(const string& id) {
        int userChoice1;
        auto it = std::find_if(shipments.begin(), shipments.end(),
            [&id](const Shipment& shipment) { return shipment.shipmentId == id; });
        if (it == shipments.end()) {
            // Không tìm thấy
            std::cout << "Shipment with ID " << id << " not found." << std::endl;
            return it;
        }
        else {
            // Tìm thấy
            std::cout << "Shipment with ID " << id << " found." << std::endl;
            do {
                cout << "1. Display information of ShipmentID: " << id << endl;
                cout << "2. Update ShipmentID: " << id << endl;
                cout << "3. Remove ShipmentID: " << id << endl;
                cout << "0. Back to SHIPMENT menu" << endl;
                cout << "Enter your choice: ";
                cin >> userChoice1;
                switch (userChoice1) {
                case 1:
                    cout << "------------------------\n";
                    it->printInfo();
                    cout << "------------------------\n";
                    break;
                case 2:
                    updateShipment(id);
                    break;
                case 3:
                    removeShipment(id);
                    return shipments.end(); //thoát khỏi vòng lặp xoá
                case 0:
                    cout << "Back to SHIPMENT menu!!!" << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }
            } while (userChoice1 != 0);
            return it;
        }
    }
    // Cập nhât đơn hàng
    void updateShipment(const string& id) {
        auto it = std::find_if(shipments.begin(), shipments.end(),
            [&id](const Shipment& shipment) { return shipment.shipmentId == id; });
        int userChoice2;
        do {
            cout << "------------------------\n";
            cout << "Select the information to update " << endl;
            cout << "1. Receive Date" << endl;
            cout << "2. Delivery Date" << endl;
            cout << "3. Customer Name" << endl;
            cout << "4. Delivery Address" << endl;
            cout << "5. Goods Info" << endl;
            cout << "6. Shipment Status" << endl;
            cout << "7. Payment Status" << endl;
            cout << "0. Back to Find Shipment MENU" << endl;
            cout << "Enter your choice: ";
            cin >> userChoice2;
            switch (userChoice2) {
            case 1:
                cout << "Enter new Received Date: ";
                cin >> it->receiveDate.day >> it->receiveDate.month >> it->receiveDate.year;
                cout << "Update shipment successfully!" << endl;
                break;
            case 2:
                cout << "Enter new Delivery Date: ";
                cin >> it->deliveryDate.day >> it->deliveryDate.month >> it->deliveryDate.year;
                cout << "Update shipment successfully!" << endl;
                break;
            case 3:
                cout << "Enter new Customer Name: ";
                cin.ignore();
                getline(cin, it->customerName);
                cout << "Update shipment successfully!" << endl;
                break;
            case 4:
                cout << "Enter new Delivery Address: ";
                cin.ignore();
                getline(cin, it->deliveryAddress);
                cout << "Update shipment successfully!" << endl;
                break;
            case 5:
                cout << "Enter new Goods Info: ";
                cin.ignore();
                getline(cin, it->goodsInfo);
                cout << "Update shipment successfully!" << endl;
                break;
            case 6:
                cout << "Enter new Shipment Status: Received (0) / InTransit (1) / Delivered (2): ";
                int statusChoice;
                cin >> statusChoice;
                it->status = static_cast<ShipmentStatus>(statusChoice);
                cout << "Update shipment successfully!" << endl;
                break;
            case 7:
                cout << "Enter new Payment Status: Unpaid (0) / Paid (1): ";
                int pstatusChoice;
                cin >> pstatusChoice;
                it->pstatus = static_cast<PaymentStatus>(pstatusChoice);
                cout << "Update shipment successfully!" << endl;
                break;
            case 0:
                cout << "Back to Find Shipment MENU" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        } while (userChoice2 != 0);

    }
    // Xóa một đơn hàng theo ID
    void removeShipment(const string& id) {
        auto it = remove_if(shipments.begin(), shipments.end(), [&id](const Shipment& shipment) {
            return shipment.shipmentId == id;
            });
        if (it != shipments.end()) {
            shipments.erase(it, shipments.end());
            cout << "Shipment with ID " << id << " has been removed.\n";
        }
        else {
            cout << "Shipment with ID " << id << " not found.\n";
        }
    }
    // Hàm in thông tin đơn hàng
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
    //Hàm in tất cả đơn hàng
    void printAllShipments() const {
        cout << "------------------------\n";
        for (const auto& shipment : shipments) {
            shipment.printInfo();
            cout << "------------------------\n";
        }
    }
    // Hàm trả về con trỏ
    Shipment* shipmentPointer(const string& id) {
        for (auto& shipment : shipments) {
            if (shipment.shipmentId == id) {
                return &shipment;
            }
        }
        return nullptr;
    }
};

int main() {
    int userChoice0;
    string id;
    Shipment manager; // tạo 1 biến quản lí
    Shipment* p; // tạo 1 biến con trỏ
    do {
        cout << "SHIPMENT MENU" << endl;
        cout << "1. Display all shipments" << endl;
        cout << "2. Add shipment" << endl;
        cout << "3. Find Shipment by ID" << endl;
        cout << "0. Back to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice0;

        switch (userChoice0) {
        case 1:
            manager.printAllShipments();
            break;
        case 2:
            manager.addShipment();
            break;
        case 3:
            cout << "Enter the shipment ID to search for: ";
            cin.ignore();
            getline(cin, id);
            manager.findShipment(id);
            break;
        case 0:
            cout << "Back to main menu!!!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (userChoice0 != 0);
    return 0;
}

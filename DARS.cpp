/*Delivery and Receiving System*/
#include<iostream>
#include<math.h>
#include <vector>
#include <algorithm>
#include<string>
#include<cstring>


//***********************************************************************************************************************************
//class shipment

// Ba trạng thái của đơn hàng: Đã nhận, Đang giao, Đã giao
enum ShipmentStatus { Received, InTransit, Delivered };
// Hai trạng thái thanh toán của đơn hàng
enum PaymentStatus { Unpaid, Paid };

// Cấu trúc date
struct Date {
    int day;
    int month;
    int year;
};

// Chuyển đổi date sang chữ để in
std::string dateToString(const Date& date) {
    return std::to_string(date.day) + "/" + std::to_string(date.month) + "/" + std::to_string(date.year);
}

// Lớp vận chuyển
class Shipment {
private:
    std::vector<Shipment> shipments;
public:
    std::string shipmentId; // Mã đơn giao
    Date receiveDate; // Ngày nhận đơn
    Date deliveryDate; // Ngày giao đơn
    std::string customerName; // Tên người gửi đơn
    std::string deliveryAddress; // Địa chỉ cần giao
    std::string goodsInfo; // Thông tin hàng hoá trong đơn
    ShipmentStatus status; // Trạng thái đơn hàng
    PaymentStatus pstatus;

    Shipment();
    Shipment(std::string id, Date rdate, std::string customer, std::string address, std::string goods, Date ddate);
    void addShipment();
    std::vector<Shipment>::iterator findShipment(const std::string& id);
    void updateShipment();
    void removeShipment(const std::string& shipmentId);
    void updateStatus(ShipmentStatus newStatus);
    void printInfo() const;
    void printAllShipments() const;
};

Shipment::Shipment() = default;

Shipment::Shipment(std::string id, Date rdate, std::string customer, std::string address, std::string goods, Date ddate)
    : shipmentId(std::move(id)), receiveDate(std::move(rdate)), deliveryDate(std::move(ddate)), customerName(std::move(customer)), deliveryAddress(std::move(address)), goodsInfo(std::move(goods)), status(Received), pstatus(Unpaid) {}

void Shipment::addShipment() {
    Shipment shipment;
    std::cout << "-- Enter the information for new Shipment --" << std::endl;
    std::cout << "Shipment ID: ";
    std::cin >> shipment.shipmentId;
    std::cout << "Receive Date: ";
    std::cin >> shipment.receiveDate.day >> shipment.receiveDate.month >> shipment.receiveDate.year;
    std::cout << "Delivery Date: ";
    std::cin >> shipment.deliveryDate.day >> shipment.deliveryDate.month >> shipment.deliveryDate.year;
    std::cout << "Customer Name: ";
    std::cin.ignore();
    std::getline(std::cin, shipment.customerName);
    std::cout << "Delivery Address: ";
    std::getline(std::cin, shipment.deliveryAddress);
    std::cout << "Goods information: ";
    std::getline(std::cin, shipment.goodsInfo);
    std::cout << "Shipment Status: Received (0) / InTransit (1) / Delivered (2): ";
    int statusChoice, pstatusChoice;
    std::cin >> statusChoice;
    shipment.status = static_cast<ShipmentStatus>(statusChoice);
    std::cout << "Payment Status: Unpaid (0) / Paid (1): ";
    std::cin >> pstatusChoice;
    shipment.pstatus = static_cast<PaymentStatus>(pstatusChoice);
    std::cout << "Add shipment successfully!" << std::endl;
    shipments.push_back(shipment);
}

std::vector<Shipment>::iterator Shipment::findShipment(const std::string& id) {
    auto it = std::find_if(shipments.begin(), shipments.end(),
        [&id](const Shipment& shipment) { return shipment.shipmentId == id; });
    if (it == shipments.end()) {
        // Shipment not found
        std::cout << "Shipment with ID " << id << " not found." << std::endl;
        return it;
    } else {
        // Shipment found
        std::cout << "Shipment with ID " << id << " found." << std::endl;
        return it;
    }
}

void Shipment::updateShipment() {
    std::cout << "Enter the shipment ID needs to be updated: ";
}

void Shipment::removeShipment(const std::string& shipmentId) {
    auto it = std::remove_if(shipments.begin(), shipments.end(), [&shipmentId](const Shipment& shipment) {
        return shipment.shipmentId == shipmentId;
    });
    if (it != shipments.end()) {
        shipments.erase(it, shipments.end());
        std::cout << "Shipment with ID " << shipmentId << " has been removed.\n";
    } else {
        std::cout << "Shipment with ID " << shipmentId << " not found.\n";
    }
}

void Shipment::updateStatus(ShipmentStatus newStatus) {
    status = newStatus;
}

void Shipment::printInfo() const {
    std::cout << "Shipment ID: " << shipmentId << "\n"
        << "Receive Date: " << dateToString(receiveDate) << "\n"
        << "Delivery Date: " << dateToString(deliveryDate) << "\n"
        << "Customer Name: " << customerName << "\n"
        << "Delivery Address: " << deliveryAddress << "\n"
        << "Goods Info: " << goodsInfo << "\n"
        << "Shipment Status: " << (status == Received ? "Received" : status == InTransit ? "In Transit" : "Delivered") << "\n"
        << "Payment Status: " << (pstatus == Unpaid ? "Unpaid" : "Paid") << "\n";
}

void Shipment::printAllShipments() const {
    std::cout << "------------------------\n";
    for (const auto& shipment : shipments) {
        shipment.printInfo();
        std::cout << "------------------------\n";
    }
}


//***********************************************************************************************************************************

// class customer
struct Khachhang{
    std::string Name;
    std::string Address;
    std::string ID;
    int Phone;
 };
 //Class quan li khach hang
 class Customer{
    std::vector<Khachhang> listCustomer;

    //Ham nhap chuoi tu khach hang
    std::string inputstring(const std::string &nhapchuoi);

    //Ham tim kiem khach hang theo ma khach hang
    std::vector<Khachhang>:: iterator searchID(const std::string &maKhachhang);

    //Ham tim kiem khach hang theo dien thoai
    std::vector<Khachhang>:: iterator searchPhone(const int &sdt);

    public:
    //Ham xoa khach hang
    void deleteCustomer();

    //Ham them khach hang
    void addCustomer();

    //Ham sua khach hang
    void fixCustomer();

    //Ham in danh sach khach hang
    void printlistCustomer() const;

 };

 //Ham nhap chuoi tu khach hang
std::string Customer::inputstring(const std::string &nhapchuoi){
    std::cout<< nhapchuoi;
    std::string nhapc;
    char buffer[100];
    if (fgets(buffer, 100, stdin)) {
        buffer[strcspn(buffer, "\n")] = 0; 
        nhapc = buffer;
    }
    return nhapc;
 }

 //Ham tim kiem khach hang theo ma
std::vector<Khachhang>::iterator Customer::searchID(const std::string &maKhachhang){
    return std:: find_if(listCustomer.begin(),listCustomer.end(),[&maKhachhang] (const Khachhang &kh) { return kh.ID == maKhachhang; });
 }

//Xoa hang hoa
void Customer::deleteCustomer(){
    std::string maKhachhang = inputstring("Nhap ma khach hang can xoa: ");
    auto it = searchID(maKhachhang);
    if(it != listCustomer.end()){
        listCustomer.erase(it);
    } else {
        std::cout<<"Ma khach hang"<<maKhachhang<<"Khong ton tai!";
    }
}

//Them khach hang
void Customer::addCustomer(){
    Khachhang khachhang;
    khachhang.ID = inputstring("Nhap ma khach hang can them: ");
    khachhang.Name = inputstring("Nhap ho ten khach hang can them: ");
    khachhang.Address = inputstring("Nhap dia chi khach hang can them: ");
    std::cout<<"Nhap so dien thoai khach hang can them: ";
    std::cin>>khachhang.Phone;
    std::cin.ignore();

//Kiem tra xem khach hang ton tai chua
    auto it = searchID(khachhang.ID);
    if(it != listCustomer.end()){
        std::cout<<"Khach hang voi ma"<<khachhang.ID<<"da ton tai!";
    } else {
        std::cout<<"Khach hang voi ma"<<khachhang.ID<<"Khong ton tai!";
    }
}

//Ham sua khach hang
void Customer::fixCustomer(){
    Khachhang khachhang;
    khachhang.ID = inputstring("Nhap ma khach hang can sua: ");

//Sua thong tin khach hang
    auto it = searchID(khachhang.ID);
    if(it != listCustomer.end()){
        std::cout<<"Chon tieu chi can sua:\n"
                   "1. Ma khach hang\n"
                   "2. Ho ten khach hang\n"
                   "3. Dia chi khach hang\n"
                   "4. So dien thoai khach hang\n";
        int choice;
        std::cout<<"Nhap lua chon: ";
        std::cin>>choice;
        switch (choice) {
            case 1:
            it->ID = inputstring("Nhap ma khach hang moi: ");
            std::cin.ignore();
            break;
            case 2:
            it->Name = inputstring("Nhap ho ten moi cua khach hang: ");
            std::cin.ignore();
            break;
            case 3:
            it->Address = inputstring("Nhap dia chi moi cua khach hang: ");
            std::cin.ignore();
            break;
            case 4:
            std::cout<<"Nhap so dien thoai moi cua khach hang: ";
            std::cin>>it->Phone;
            break;
        };

    } else {
        std::cout<<"Khach hang voi ma"<<khachhang.ID<<"Khong ton tai!";
    }
}

//Ham in danh sach khach hang
void Customer::printlistCustomer()const{
    for(const auto& kh: listCustomer){
        std::cout<< "\nMa khach hang: " <<" " << kh.ID;
        std::cout<< "\nHo ten khach hang: " <<" " << kh.Name;
        std::cout<< "\nDia chi khach hang: " <<" " << kh.Address;
        std::cout<< "\nSo dien thoai khach hang: " <<" " << kh.Phone;
    }
}

//***********************************************************************************************************************************
// Struct để lưu trữ thông tin về hàng hóa
struct HangHoa {
    std::string maHangHoa;
    std::string loaiHangHoa;
    int soLuongTonKho;
    double giaThanh;
};

// Class quản lý hàng hóa
class QuanLyKho {
private:
    std::vector<HangHoa> danhSachHangHoa;

    // Hàm để nhập chuỗi từ người dùng
    std::string nhapChuoi(const std::string &thongBao);

    // Hàm tìm kiếm hàng hóa theo mã
    std::vector<HangHoa>::iterator timHangHoa(const std::string &maHangHoa);

public:
    // Thêm hàng hóa mới
    void themHangHoa();

    // Sửa thông tin hàng hóa
    void suaHangHoa();

    // Xóa hàng hóa
    void xoaHangHoa();

    // Cập nhật số lượng tồn kho
    void capNhatSoLuongTonKho();

    // In thông tin tất cả hàng hóa
    void inThongTin() const;
};

// Hàm để nhập chuỗi từ người dùng
std::string QuanLyKho::nhapChuoi(const std::string &thongBao) {
    std::cout << thongBao;
    std::string input;
    char buffer[256];
    if (fgets(buffer, 256, stdin)) {
        buffer[strcspn(buffer, "\n")] = 0; // Loại bỏ ký tự xuống dòng, hàm strcspn dùng để check coi có kí tự xuống dòng trong string buffer hay không
        input = buffer;
    }
    return input;
}

// Hàm tìm kiếm hàng hóa theo mã
std::vector<HangHoa>::iterator QuanLyKho::timHangHoa(const std::string &maHangHoa) {
    return std::find_if(danhSachHangHoa.begin(), danhSachHangHoa.end(),
                        [&maHangHoa](const HangHoa &hh) { return hh.maHangHoa == maHangHoa; });
}

// Thêm hàng hóa mới
void QuanLyKho::themHangHoa() {
    HangHoa hangHoa;
    int n;
    std::cout<<"Quy khach muon nhap bao nhieu loai hang:\n";
    std::cout<<"Nhap so loai hang can them:";
    std::cin>>n;
    for(int i=0;i<n;i++){
    std::cout<<"LOAI HANG THU "<<i+1<<":\n";    
    std::cout<<"Nhap ma hang hoa:";
    std::cin>>hangHoa.maHangHoa ;
    std::cin.ignore();
    hangHoa.loaiHangHoa = nhapChuoi("Nhap loai hang hoa: ");
    std::cout << "Nhap so luong ton kho: ";
    std::cin >> hangHoa.soLuongTonKho;
    std::cout << "Nhap gia thanh: ";
    std::cin >> hangHoa.giaThanh;
    std::cin.ignore(); // Xóa bộ đệm trước khi sử dụng fgets lần tiếp theo

    // Kiểm tra xem hàng hóa đã tồn tại chưa
    auto it = timHangHoa(hangHoa.maHangHoa);
    if (it != danhSachHangHoa.end()) {
        std::cerr << "Hang hoa voi ma " << hangHoa.maHangHoa << " da ton tai.\n";
    } else {
        danhSachHangHoa.push_back(hangHoa);
    }
    }
}

// Sửa thông tin hàng hóa
void QuanLyKho::suaHangHoa() {
    std::string maHangHoa = nhapChuoi("Nhap ma hang hoa can sua: ");
    auto it = timHangHoa(maHangHoa);
    if (it != danhSachHangHoa.end()) {
        std::cout<<"Chon tieu chi can thay doi:\n"
                 <<"1.Loai hang hoa\n"
                 <<"2.So luong hang hoa\n"
                 <<"3.Gia thanh\n";
        int choice1;
        std::cout<<"Nhap lua chon:";
        std::cin>>choice1;         
        switch (choice1) {
            case 1:
                it->loaiHangHoa = nhapChuoi("Nhap loai hang hoa moi: ");
                std::cout << "Nhap so luong ton kho moi: ";
                std::cin >> it->soLuongTonKho;
                std::cout << "Nhap gia thanh moi: ";
                std::cin >> it->giaThanh;
                std::cin.ignore(); // Xóa bộ đệm trước khi sử dụng fgets lần tiếp theo;
                break;
            case 2:
                std::cout << "Nhap so luong ton kho moi: ";
                std::cin >> it->soLuongTonKho;
                break;
            case 3:
                std::cout << "Nhap gia thanh moi: ";
                std::cin >> it->giaThanh;
                break;
                 
    };
    }
    else {
        std::cerr << "Hang hoa voi ma " << maHangHoa << " khong ton tai.\n";
    }
}

// Xóa hàng hóa
void QuanLyKho::xoaHangHoa() {
    std::string maHangHoa = nhapChuoi("Nhap ma hang hoa can xoa: ");
    auto it = timHangHoa(maHangHoa);
    if (it != danhSachHangHoa.end()) {
        danhSachHangHoa.erase(it);
    } else {
        std::cerr << "Hang hoa voi ma " << maHangHoa << " khong ton tai.\n";
    }
}

// Cập nhật số lượng tồn kho
void QuanLyKho::capNhatSoLuongTonKho() {
    std::string maHangHoa = nhapChuoi("Nhap ma hang hoa can cap nhat so luong: ");
    int soLuongMoi;
    std::cout << "Nhap so luong ton kho moi: ";
    std::cin >> soLuongMoi;
    std::cin.ignore(); // Xóa bộ đệm trước khi sử dụng fgets lần tiếp theo

    auto it = timHangHoa(maHangHoa);
    if (it != danhSachHangHoa.end()) {
        it->soLuongTonKho = soLuongMoi;
    } else {
        std::cerr << "Hang hoa voi ma " << maHangHoa << " khong ton tai.\n";
    }
}

// In thông tin tất cả hàng hóa
void QuanLyKho::inThongTin() const {
    for (const auto& hh : danhSachHangHoa) {
        std::cout << "Ma hang hoa: " << hh.maHangHoa
                  << ", Loai hang hoa: " << hh.loaiHangHoa
                  << ", So luong ton kho: " << hh.soLuongTonKho
                  << ", Gia thanh: " << hh.giaThanh << "\n";
    }
}
//***********************************************************************************************************************************
int main(){

}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

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
        buffer[strcspn(buffer, "\n")] = 0; // Loại bỏ ký tự xuống dòng
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
    hangHoa.maHangHoa = nhapChuoi("Nhap ma hang hoa: ");
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

int main() {
    QuanLyKho khol;
    int choice;
    do {
        std::cout << "1. Them hang hoa\n";
        std::cout << "2. Sua hang hoa\n";
        std::cout << "3. Xoa hang hoa\n";
        std::cout << "4. Cap nhat so luong ton kho\n";
        std::cout << "5. In thong tin hang hoa\n";
        std::cout << "6. Thoat\n";
        std::cout << "Nhap lua chon: ";
        std::cin >> choice;
        std::cin.ignore(); // Xóa bộ đệm trước khi nhập chuỗi

        switch (choice) {
            case 1:
                khol.themHangHoa();
                break;
            case 2:
                khol.suaHangHoa();
                break;
            case 3:
                khol.xoaHangHoa();
                break;
            case 4:
                khol.capNhatSoLuongTonKho();
                break;
            case 5:
                khol.inThongTin();
                break;
            case 6:
                std::cout << "Thoat chuong trinh.\n";
                break;
            default:
                std::cout << "Lua chon khong hop le!\n";
                break;
        }
    } while (choice != 6);

    return 0;
}

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
    void inThongTin();
};

// Thêm hàng hóa mới
void QuanLyKho::themHangHoa() {
    HangHoa hangHoa;
    std::cout << "Nhap ma hang hoa: ";
    std::cin >> hangHoa.maHangHoa;
    std::cout << "Nhap loai hang hoa: ";
    std::cin >> hangHoa.loaiHangHoa;
    std::cout << "Nhap so luong ton kho: ";
    std::cin >> hangHoa.soLuongTonKho;
    std::cout << "Nhap gia thanh: ";
    std::cin >> hangHoa.giaThanh;
    
    danhSachHangHoa.push_back(hangHoa);
}

// Sửa thông tin hàng hóa
void QuanLyKho::suaHangHoa() {
    std::string maHangHoa;
    HangHoa hangHoaMoi;
    std::cout << "Nhap ma hang hoa can sua: ";
    std::cin >> maHangHoa;
    std::cout << "Nhap loai hang hoa moi: ";
    std::cin >> hangHoaMoi.loaiHangHoa;
    std::cout << "Nhap so luong ton kho moi: ";
    std::cin >> hangHoaMoi.soLuongTonKho;
    std::cout << "Nhap gia thanh moi: ";
    std::cin >> hangHoaMoi.giaThanh;

    auto it = std::find_if(danhSachHangHoa.begin(), danhSachHangHoa.end(),
                           [&maHangHoa](HangHoa& hh) { return hh.maHangHoa == maHangHoa; });
    if (it != danhSachHangHoa.end()) {
        hangHoaMoi.maHangHoa = maHangHoa;
        *it = hangHoaMoi;
    } else {
        std::cerr << "Hang hoa voi ma " << maHangHoa << " khong ton tai.\n";
    }
}

// Xóa hàng hóa
void QuanLyKho::xoaHangHoa() {
    std::string maHangHoa;
    std::cout << "Nhap ma hang hoa can xoa: ";
    std::cin >> maHangHoa;

    auto it = std::remove_if(danhSachHangHoa.begin(), danhSachHangHoa.end(),
                             [&maHangHoa](HangHoa& hh) { return hh.maHangHoa == maHangHoa; });
    if (it != danhSachHangHoa.end()) {
        danhSachHangHoa.erase(it, danhSachHangHoa.end());
    } else {
        std::cerr << "Hang hoa voi ma " << maHangHoa << " khong ton tai.\n";
    }
}

// Cập nhật số lượng tồn kho
void QuanLyKho::capNhatSoLuongTonKho() {
    std::string maHangHoa;
    int soLuongMoi;
    std::cout << "Nhap ma hang hoa can cap nhat so luong: ";
    std::cin >> maHangHoa;
    std::cout << "Nhap so luong ton kho moi: ";
    std::cin >> soLuongMoi;

    auto it = std::find_if(danhSachHangHoa.begin(), danhSachHangHoa.end(),
                           [&maHangHoa](HangHoa& hh) { return hh.maHangHoa == maHangHoa; });
    if (it != danhSachHangHoa.end()) {
        it->soLuongTonKho = soLuongMoi;
    } else {
        std::cerr << "Hang hoa voi ma " << maHangHoa << " khong ton tai.\n";
    }
}

// In thông tin tất cả hàng hóa
void QuanLyKho::inThongTin() {
    for (const auto& hh : danhSachHangHoa) {
        std::cout << "Ma hang hoa: " << hh.maHangHoa
                  << ", Loai hang hoa: " << hh.loaiHangHoa
                  << ", So luong ton kho: " << hh.soLuongTonKho
                  << ", Gia thanh: " << hh.giaThanh << "\n";
    }
}
int main() {
    QuanLyKho ql;
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
        
        switch (choice) {
            case 1:
                ql.themHangHoa();
                break;
            case 2:
                ql.suaHangHoa();
                break;
            case 3:
                ql.xoaHangHoa();
                break;
            case 4:
                ql.capNhatSoLuongTonKho();
                break;
            case 5:
                ql.inThongTin();
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
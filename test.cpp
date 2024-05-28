#include<iostream>
#include<vector>
#include<string>


struct HangHoa{
    std::string tenHangHoa;
    std::string Giathanh;
   
};

// Class quản lý hàng hóa
class Customer {
private:
    std::vector<HangHoa> danhSachHangHoa;
    
public:

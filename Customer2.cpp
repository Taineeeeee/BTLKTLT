#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

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

    //Ham menu
    void menu();

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

//Ham menu
void Customer::menu(){
    int choice;
    do {
        std::cout << "1. Xoa khach hang \n";
        std::cout << "2. Them khach hang \n";
        std::cout << "3. Sua khach hang \n";
        std::cout << "4. In thong tin kahch hang \n";
        std::cout << "5. Thoat\n";
        std::cout << "Nhap lua chon: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                deleteCustomer();
                break;
            case 2:
                addCustomer();
                break;
            case 3:
                fixCustomer();
                break;
            case 4:
                printlistCustomer();
                break;
            case 5:
                std::cout << "Thoat chuong trinh.\n";
                break;
            default:
                std::cout << "Lua chon khong hop le!\n";
                break;
        }
    } while (choice != 5);

}
int main(){
    Customer khachhang;
    khachhang.menu();   
    return 0;
}
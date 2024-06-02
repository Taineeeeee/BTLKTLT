#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

class Shipper
{
    private:
        int id;
        std::string name;
        std::string phone;
    public:
        int getid()const{return id;}
        std::string getname()const{return name;}
        std::string getphone()const{return phone;}
        void setid(int id){this->id = id;}
        void setname(std::string name){this->name = name;}
        void setphone(std::string phone){this->phone = phone;}
        void input(){
            std::cout << "Nhap thong tin: " << std::endl;
            std::cout << "Nhap id:";
            std::cin >> id;
            std::cout << "Nhap ten:";
            std::cin.ignore();
            getline(std::cin, name);
            std::cout << "Nhap so dien thoai:";
            getline(std::cin, phone);
            std::cout << "Nhap thanh cong!";
        }
        void display(){
            std::cout << "Thong tin: " << std::endl;
            std::cout << "Ten: " << name << std::endl;
            std::cout << "ID: " << id << std::endl;
            std::cout << "So dien thoai: " << phone << std::endl;
        }
};

std::vector <Shipper> shippers;

bool find_id(std::string id, const Shipper& shipper){
    return std::to_string(shipper.getid()) == id;
}

bool find_phone(std::string phone, const Shipper& shipper){
    return shipper.getphone() == phone;
}

std::vector<Shipper>::iterator find(std::string idx, bool(*findidx)(std::string, const Shipper&)){
    return std::find_if(shippers.begin(), shippers.end(), [&idx, findidx](const Shipper& shipper){return findidx(idx, shipper);});
}

void add_shipper(){
    system("CLS");
    Shipper addshipper;
    std::vector<Shipper>::iterator it;
    int id;
    std::string name;
    std::string phone;
    std::cout << "--Nhap thong tin shipper--" << std::endl;
    do{
    std::cout << "Nhap id: ";
    std::cin >> id;
    it = find(std::to_string(id), find_id);
    if(it!=shippers.end()){
        std::cerr << "ID: " << id << "da ton tai!" << std::endl;
    }else{
        addshipper.setid(id);
    }
    }while(it != shippers.end());
    std::cout << "Nhap ten: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    addshipper.setname(name);
    do{
    std::cout << "Nhap so dien thoai: ";
    std::getline(std::cin, phone);
    it = find(phone, find_phone);
    if(it!=shippers.end()){
        std::cerr << "So dien thoai: " << phone << "da ton tai!" << std::endl;
    }else{
        addshipper.setphone(phone);
    }
    }while (it != shippers.end());
    shippers.push_back(addshipper);
}

void update_shipper(){
    system("CLS");
    if(shippers.size()!=0){
        int id;
        std::vector<Shipper>::iterator it;
        std::cout << "--Sua thong tin shipper--" << std::endl;
        do{
            std::cout << "Nhap id shipper: ";
            std::cin >> id;
            it = find(std::to_string(id), find_id);
            if(it==shippers.end()){
                std::cerr << "ID: " << id << "khong ton tai!" << std::endl;
            }else{
                std::cout << "Thong tin cu: " << std::endl;
                it->display();
                std::cout << "Hay sua lai thong tin: " << std::endl;
                int new_id;
                std::string new_name;
                std::string new_phone;
                std::vector<Shipper>::iterator it1;
                do{
                    std::cout << "Nhap id: ";
                    std::cin >> new_id;
                    it1 = find(std::to_string(new_id), find_id);
                    if(it1 != shippers.end() && new_id != it1->getid()){
                        std::cerr << "ID: " << new_id << "da ton tai!" << std::endl;
                    }else{
                        it1->setid(new_id);
                    }
                }while (it1 != shippers.end() && new_id != it1->getid());
                std::cout << "Nhap ten: ";
                std::cin.ignore();
                std::getline(std::cin, new_name);s
                it->setname(new_name);
                std::vector<Shipper>::iterator it2;
                do{
                    std::cout << "Nhap so dien thoai: ";
                    std::getline(std::cin, new_phone);
                    it2 = find(new_phone, find_phone);
                    if(it2!=shippers.end() && new_phone!=it2->getphone()){
                        std::cerr << "So dien thoai: " << new_phone << "da ton tai!" << std::endl;
                    }else{
                        it2->setphone(new_phone);
                    }
                }while (it2 != shippers.end() && new_phone!=it2->getphone());
            }
        }while (it == shippers.end());
    }else{
        std::cout << "Chua co shipper!" << std::endl;
    }
}

void delete_shipper(){
    system("CLS");
    if(shippers.size()!=0){
        std::cout << "--Xoa thong tin shipper--" << std::endl;
        int id;
        std::vector<Shipper>::iterator it;
        do{
            std::cout << "Nhap ID shipper muon xoa: ";
            std::cin >> id;
            it = find(std::to_string(id), find_id);
            if(it==shippers.end()){
                std::cerr << "ID: " << id << "khong ton tai!" << std::endl;
            }else{
                shippers.erase(it);
                break;
            }
        }while(it==shippers.end());
    }else{
        std::cout << "Chua co shipper!" << std::endl;
    }
}

void list_shipper(){
    system("CLS");
    std::cout << "--Danh sach cac shipper--" << std::endl;
    int i=1;
    for(std::vector<Shipper>::iterator it = shippers.begin(); it!=shippers.end(); it++){
        std::cout << "Thong tin cua shipper so " << i << ":" << std::endl;
        it->display();
        i++;
    }
}

void menu(){
    int choice;
    while(1){
        system("CLS");
        std::cout << "1. Them thong tin shipper\n";
        std::cout << "2. Sua thong tin shipper\n";
        std::cout << "3. Xoa thong tin shipper\n";
        std::cout << "4. Thong tin cua tat ca shipper\n";
        std::cout << "5. Thoat\n";
        std::cout << "Nhap lua chon: ";
        std::cin >> choice;
        std::cin.ignore();
        switch(choice){
            case 1:
                add_shipper();
                break;
            case 2:
                update_shipper();
                break;
            case 3:
                delete_shipper();
                break;
            case 4:
                list_shipper();
                break;
            case 5:
                std::cout << "Thoat chuong trinh!" << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le!\n";
                break;
        }
    }
}
int main(){
    menu();
    return 0;
}

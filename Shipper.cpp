#include <iostream>
#include <string>
using namespace std;

class Shipper
{
    private:
        int id;
        string name;
        string phone;
    public:
        int getid(){return id;}
        string getname(){return name;}
        string getphone(){return phone;}
        void setid(int id){this->id = id;}
        void setname(string name){this->name = name;}
        void setphone(string phone){this->phone = phone;}
        void input(){
            cout << "Nhap thong tin: " << endl;
            cout << "Nhap id:";
            cin >> id;
            cout << "Nhap ten:";
            cin.ignore();
            getline(cin, name);
            cout << "Nhap so dien thoai:";
            getline(cin, phone);
            cout << "Nhap thanh cong!";
        }
        void display(){
            cout << "Thong tin: " << endl;
            cout << "Ten: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "So dien thoai: " << phone << endl;
        }
};
int main(){
    Shipper sp;
    sp.input();
    sp.display();
    return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    

    int choice;
    do {
        cout << " __________________________________________________ " << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|                                                      |" << endl;
        cout << "|______________________________________________________|" << endl;
        cout << "|                                                      |" << endl;
        cout << "|              System delivery and receipt             |" << endl;
        cout << "|______________________________________________________|" << endl;
        cout << "|*                                                    *|" << endl;
        cout << "|   ||\\"<<"\\        //|| ||======  ||\\"<<"\\    || ||       || |" << endl;
        cout << "|   || \\"<<"\\      // || ||        || \\"<<"\\   || ||       || |" << endl;
        cout << "|   ||  \\"<<"\\    //  || ||======  ||  \\"<<"\\  || ||       || |" << endl;
        cout << "|   ||   \\"<<"\\  //   || ||        ||   \\"<<"\\ || ||       || |" << endl;
        cout << "|   ||    \\"<<"\\//    || ||======  ||    \\"<<"\\||  \\"<<"\\=====// |" << endl;
        cout << "|______________________________________________________|" << endl;
        cout << "|                                                      |" << endl;
        cout << "|  1.  Receive Shipment                                |" << endl;
        cout << "|  2.  List Shipment                                   |" << endl;
        cout << "|  3.  Update Shipment                                 |" << endl;
        cout << "|  4.  Delete Shipment                                 |" << endl;
        cout << "|  5.  Add Customer                                    |" << endl;
        cout << "|  6.  List Customer                                   |" << endl;
        cout << "|  7.  Update Customer                                 |" << endl;
        cout << "|  8.  Delete Customer                                 |" << endl;
        cout << "|  9.  Add Inventory                                   |" << endl;
        cout << "|  10. List Inventory                                  |" << endl;
        cout << "|  11. Update Inventory                                |" << endl;
        cout << "|  12. Delete Inventory                                |" << endl;
        cout << "|  13. Add Shipper                                     |" << endl;
        cout << "|  14. List Shipper                                    |" << endl;
        cout << "|  15. Update Shipper                                  |" << endl;
        cout << "|  16. Delete Shipper                                  |" << endl;
        cout << "|  17.Exit                                             |" << endl;
        cout << "|*____________________________________________________*|" << endl;
        cout << "                                                        " << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            
    } while (choice != 17);

    return 0;
}

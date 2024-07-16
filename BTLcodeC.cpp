#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

struct Date { int day, month, year; };

enum ShipmentStatus { Pending, InTransit, Delivered, Returned };
enum PaymentStatus { Unpaid, Paid };
enum ShipperStatus { ReadyToDeliver, Delivering };

#define MAX_PEOPLE 100
#define MAX_STRING 100

typedef struct {
    char name[MAX_STRING];
    char address[MAX_STRING];
    char id[MAX_STRING];
    char tel[MAX_STRING];
    int shipments;
} Person;

void displayPerson(const Person* person) {
    printf("%-10s %-20s %-20s %-16s %-10d\n",
        person->id,
        person->name,
        person->address,
        person->tel,
        person->shipments);
}

Person* findPersonById(Person* persons, int size, const char* id) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(persons[i].id, id) == 0) {
            return &persons[i];
        }
    }
    return NULL;
}

int find_by_id(Person* list, int size, const char* id) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(list[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

void addPerson(Person* list, int* size, const char* role) {
    system("CLS");
    char name[MAX_STRING], address[MAX_STRING], id[MAX_STRING], tel[MAX_STRING];

    printf("Enter %s ID: ", role);
    scanf("%s", id);
    getchar();  

    if (find_by_id(list, *size, id) != -1) {
        printf("%s with ID %s already exists. Please enter a new ID.\n", role, id);
        system("pause");
        return;
    }

    printf("Enter %s Name: ", role);
    fgets(name, MAX_STRING, stdin);
    name[strcspn(name, "\n")] = '\0';  

    printf("Enter %s Address: ", role);
    fgets(address, MAX_STRING, stdin);
    address[strcspn(address, "\n")] = '\0';  

    printf("Enter %s Tel: ", role);
    scanf("%s", tel);
    getchar();  

    strcpy(list[*size].name, name);
    strcpy(list[*size].address, address);
    strcpy(list[*size].id, id);
    strcpy(list[*size].tel, tel);

    (*size)++;

    printf("%s added successfully!\n", role);
    system("pause");
}

void deletePerson(Person* list, int* size, const char* role) {
    system("CLS");
    char id[MAX_STRING];

    printf("Enter %s ID to delete: ", role);
    scanf("%s", id);
    getchar();  

    int index = find_by_id(list, *size, id);
    if (index != -1) {
        for (int i = index; i < *size - 1; ++i) {
            list[i] = list[i + 1];
        }
        (*size)--;
        printf("%s with ID %s deleted successfully!\n", role, id);
    } else {
        printf("%s with ID %s does not exist.\n", role, id);
    }
    system("pause");
}

void printAllPersons(const Person* list, int size, const char* role) {
    system("CLS");
    printf("%-10s %-20s %-20s %-16s %-10s\n", "ID", "Name", "Address", "Tel", "Shipments");
    printf("%s\n", "---------------------------------------------------------------------------------");

    for (int i = 0; i < size; ++i) {
        displayPerson(&list[i]);
    }

    system("pause");
}

int compareAscending(const void* a, const void* b) {
    Person* personA = (Person*)a;
    Person* personB = (Person*)b;
    return strcmp(personA->id, personB->id);
}

int compareDescending(const void* a, const void* b) {
    Person* personA = (Person*)a;
    Person* personB = (Person*)b;
    return strcmp(personB->id, personA->id);
}

void sortPersonById(Person* list, int size, int ascending) {
    if (ascending) {
        qsort(list, size, sizeof(Person), compareAscending);
    } else {
        qsort(list, size, sizeof(Person), compareDescending);
    }
}

void findPerson(const Person* list, int size, const char* role) {
    system("CLS");
    char id[MAX_STRING];
    
    printf("Enter %s ID to find: ", role);
    scanf("%s", id);
    getchar(); 

    int found = 0;
    for (int i = 0; i < size; ++i) {
        if (strcmp(list[i].id, id) == 0) {
            displayPerson(&list[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%s with ID %s does not exist. Returning to main menu.\n", role, id);
    }
    system("pause");
}

typedef struct {
    char shipmentId[MAX_STRING];
    Date sendDate;
    Date receiveDate;
    Person sender;
    Person receiver;
    char goods[MAX_STRING];
    ShipmentStatus status;
    PaymentStatus paymentStatus;
} Shipment;

void displayPersonForShipment(const Person* person) {
    printf("Name: %s\n", person->name);
    printf("Address: %s\n", person->address);
}

const char* dateToString(Date date) {
    static char buffer[11];
    snprintf(buffer, sizeof(buffer), "%02d/%02d/%04d", date.day, date.month, date.year);
    return buffer;
}

void displayShipment(const Shipment* shipment, const Person* sender, const Person* receiver) {
    printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "ID", "Send Date", "Receive Date", "Goods Info", "Status", "Payment Status");
    printf("%-15d%-15s%-15s%-15s%-15s%-15s\n",
           shipment->shipmentId,
           dateToString(shipment->sendDate),
           dateToString(shipment->receiveDate),
           shipment->goods,
           shipment->status == Pending ? "Pending" :
           shipment->status == InTransit ? "In Transit" :
           shipment->status == Delivered ? "Delivered" : "Returned",
           shipment->paymentStatus == Unpaid ? "Unpaid" : "Paid");
    
    printf("-----Sender information:\n");
    displayPersonForShipment(sender);
    
    printf("-----Receiver information:\n");
    displayPersonForShipment(receiver);
    
    for (int i = 0; i < 100; i++) {
        putchar('-');
    }
    printf("\n");
}

void printAllShipments(const Shipment* shipments, size_t size, const Person* senders, const Person* receivers) {
    system("cls");
    printf("All Shipments:\n");
    for (size_t i = 0; i < size; ++i) {
        displayShipment(&shipments[i], &senders[i], &receivers[i]);
    }
    system("pause");
}

int findShipmentById(Shipment* shipments, int size, const char* id) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(shipments[i].shipmentId, id) == 0) {
            return 1;
        }
    }
    return 0;
}

void addShipment(Shipment* shipmentList, int* shipmentSize, Person* senders, int senderSize, Person* receivers, int receiverSize) {
    system("CLS");
    int status, pstatus;
    char goods[MAX_STRING], shipmentId[MAX_STRING], senderId[MAX_STRING], receiverId[MAX_STRING];
    Date sDate, rDate;

    printf("Enter the information for new Shipment\n");

    printf("Enter the Sender ID: ");
    scanf("%s", senderId);

    Person* sender = findPersonById(senders, senderSize, senderId);
    if (sender == NULL) {
        printf("Person with ID %s not found.\n", senderId);
        system("pause");
        return;
    }

    printf("Enter the Receiver ID: ");
    scanf("%s", receiverId);

    Person* receiver = findPersonById(receivers, receiverSize, receiverId);
    if (receiver == NULL) {
        printf("Person with ID %s not found.\n", receiverId);
        system("pause");
        return;
    }

    printf("Enter the Shipment ID: ");
    scanf("%s", shipmentId);

    if (findShipmentById(shipmentList, *shipmentSize, shipmentId)) {
        printf("Shipment with ID %s already exists.\n", shipmentId);
        system("pause");
        return;
    }

    printf("Send Date (day month year): "); 
    scanf("%d %d %d", &sDate.day, &sDate.month, &sDate.year);
    printf("Receive Date (day month year): "); 
    scanf("%d %d %d", &rDate.day, &rDate.month, &rDate.year);
    getchar(); 
    printf("Goods information: "); 
    fgets(goods, MAX_STRING, stdin);
    goods[strcspn(goods, "\n")] = 0; 
    printf("Shipment Status: Pending (0) / InTransit (1) / Delivered (2) / Returned (3): "); 
    scanf("%d", &status);
    printf("Payment Status: Unpaid (0) / Paid (1): "); 
    scanf("%d", &pstatus);

    Shipment newShipment;
    strcpy(newShipment.shipmentId, shipmentId);
    newShipment.sendDate = sDate;
    newShipment.receiveDate = rDate;
    newShipment.sender = *sender;
    newShipment.receiver = *receiver;
    strcpy(newShipment.goods, goods);
    newShipment.status = (ShipmentStatus)status;
    newShipment.paymentStatus = (PaymentStatus)pstatus;

    shipmentList[*shipmentSize] = newShipment;
    (*shipmentSize)++;

    sender->shipments++;
    receiver->shipments++;

    printf("Shipment added successfully!\n");
    system("pause");
}

int findShipmentIndexById(Shipment* shipments, int size, const char* id) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(shipments[i].shipmentId, id) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteShipment(Shipment* shipmentList, int* shipmentSize, Person* senders, int senderSize, Person* receivers, int receiverSize) {
    system("CLS");
    char id[MAX_STRING];
    printf("Enter Shipment ID to delete: ");
    scanf("%s", id);

    int index = findShipmentIndexById(shipmentList, *shipmentSize, id);
    if (index != -1) {

        Person* sender = findPersonById(senders, senderSize, shipmentList[index].sender.id);
        if (sender == NULL) {
            printf("Sender with ID %s not found.\n", shipmentList[index].sender.id);
            system("pause");
            return;
        }

        Person* receiver = findPersonById(receivers, receiverSize, shipmentList[index].receiver.id);
        if (receiver == NULL) {
            printf("Receiver with ID %s not found.\n", shipmentList[index].receiver.id);
            system("pause");
            return;
        }

        sender->shipments--;
        receiver->shipments--;

        for (int i = index; i < (*shipmentSize) - 1; ++i) {
            shipmentList[i] = shipmentList[i + 1];
        }
        (*shipmentSize)--;

        printf("Shipment with ID %s deleted successfully!\n", id);
        system("pause");
    } else {
        printf("Shipment with ID %s does not exist.\n", id);
        system("pause");
    }
}

int compareAscendingShipment(const void* a, const void* b) {
    Shipment* shipmentA = (Shipment*)a;
    Shipment* shipmentB = (Shipment*)b;
    return (shipmentA->shipmentId - shipmentB->shipmentId);
}

int compareDescendingShipment(const void* a, const void* b) {
    Shipment* shipmentA = (Shipment*)a;
    Shipment* shipmentB = (Shipment*)b;
    return (shipmentB->shipmentId - shipmentA->shipmentId);
}

void sortShipmentsById(Shipment* list, size_t size, int ascending) {
    if (ascending) {
        qsort(list, size, sizeof(Shipment), compareAscendingShipment);
    } else {
        qsort(list, size, sizeof(Shipment), compareDescendingShipment);
    }
}

int main() {
    Person senders[MAX_PEOPLE];
    Person receivers[MAX_PEOPLE];
    Shipment shipments[MAX_PEOPLE];
    int senderSize = 0, receiverSize = 0, shipmentSize = 0;
    int choice;

    while (1) {
        system("CLS");
        printf("Menu:\n");
        printf("1. Add Sender\n");
        printf("2. Add Receiver\n");
        printf("3. Add Shipment\n");
        printf("4. Delete Sender\n");
        printf("5. Delete Receiver\n");
        printf("6. Delete Shipment\n");
        printf("7. Print All Senders\n");
        printf("8. Print All Receivers\n");
        printf("9. Print All Shipments\n");
        printf("10. Sort Senders by ID\n");
        printf("11. Sort Receivers by ID\n");
        printf("12. Sort Shipments by ID\n");
        printf("13. Find Sender by ID\n");
        printf("14. Find Receiver by ID\n");
        printf("15. Find Shipment by ID\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addPerson(senders, &senderSize, "Sender");
                break;
            case 2:
                addPerson(receivers, &receiverSize, "Receiver");
                break;
            case 3:
                addShipment(shipments, &shipmentSize, senders, senderSize, receivers, receiverSize);
                break;
            case 4:
                deletePerson(senders, &senderSize, "Sender");
                break;
            case 5:
                deletePerson(receivers, &receiverSize, "Receiver");
                break;
            case 6:
                deleteShipment(shipments, &shipmentSize, senders, senderSize, receivers, receiverSize);
                break;
            case 7:
                printAllPersons(senders, senderSize, "Senders");
                break;
            case 8:
                printAllPersons(receivers, receiverSize, "Receivers");
                break;
            case 9:
                printAllShipments(shipments, shipmentSize, senders, receivers);
                break;
            case 10:
                sortPersonById(senders, senderSize, 1);
                printf("Senders sorted by ID in ascending order.\n");
                system("pause");
                break;
            case 11:
                sortPersonById(receivers, receiverSize, 1);
                printf("Receivers sorted by ID in ascending order.\n");
                system("pause");
                break;
            case 12:
                sortShipmentsById(shipments, shipmentSize, 1);
                printf("Shipments sorted by ID in ascending order.\n");
                system("pause");
                break;
            case 13:
                findPerson(senders, senderSize, "Sender");
                break;
            case 14:
                findPerson(receivers, receiverSize, "Receiver");
                break;
            case 15:
                findShipmentById(shipments, shipmentSize, "Shipment");
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                system("pause");
        }
    }

    return 0;
}





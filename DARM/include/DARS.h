#ifndef DARS_H_INCLUDED
#define DARS_H_INCLUDED
#include "DARM.h"
#include "Shipper.h"
#include "Deliver.h"
#include "Receiver.h"
#include "Shipment.h"


void menu();
void findInfoById(std::string);
void addShipment();
void updateShipment();
void deleteShipment();
void addDeliver();
void updateDeliver();
void deleteDeliver();
void addReceiver();
void updateReceiver();
void deleteReceiver();
void addShipper();
void updateShipper();
void deleteShipper();
void printShipmentInfo(std::string);
void printShipperInfo(std::string);
void printCustomerInfo(std::string);
void printAllShipmentInfo();
void printAllShipperInfo();
void printAllCustomerInfo();
void printAllShipmentOfCustomer();

#endif // DARS_H_INCLUDED

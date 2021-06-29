/*Jonathan Brashears
* 9/26/2016
* CS 102
* Homework 3
* Reads a file of transactions, calculates total, and accepts payment
*/
#include <iostream>
#include <string>
#include <iomanip>
#include "storeItem.h"

using namespace std;
//StoreItem functions
storeItem::storeItem()
{
    ItemName = "placeholder";
    MSRP = 0.00;
    discount = 0.00;
    price = 0.00;
}

//Constructor for StoreItem
void storeItem::itemInfo(string name, double scanPrice)
{
    ItemName = name;
    MSRP = scanPrice;
}

//Setters for StoreItem
void storeItem::setDiscount(double discountPercent)
{
    discount = discountPercent;
}

void storeItem::calculatePrice()
{
    double conversion = 0.00;
    conversion = 1-(0.01 * discount);
    price = MSRP * conversion;
}

//Getters for StoreItem
double storeItem::getPrice()
{
    calculatePrice();
    return price;
}

double storeItem::getMSRP()
{
    return MSRP;
}

string storeItem::getItemName()
{
    return ItemName;
}

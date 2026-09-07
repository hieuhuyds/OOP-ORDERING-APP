#include "OrderItem.h"
#include <iostream>

using namespace std;

// Constructor: chot lai gia va so luong tai thoi diem checkout
// finalPrice / quantity khong duoc am
OrderItem::OrderItem(string productId, string productName, double finalPrice,
                     int quantity)
    : productId(productId), productName(productName),
      finalPrice(finalPrice >= 0 ? finalPrice : 0.0),
      quantity(quantity >= 0 ? quantity : 0) {}

// Getters
string OrderItem::getProductId() const { return productId; }

string OrderItem::getProductName() const { return productName; }

double OrderItem::getFinalPrice() const { return finalPrice; }

int OrderItem::getQuantity() const { return quantity; }

// Subtotal = finalPrice * quantity
double OrderItem::getSubtotal() const { return finalPrice * quantity; }

void OrderItem::display() const {
  cout << "  - " << productName << " (ID: " << productId << ")" << endl;
  cout << "    Don gia: " << finalPrice << endl;
  cout << "    So luong: " << quantity << endl;
  cout << "    Thanh tien: " << getSubtotal() << endl;
}
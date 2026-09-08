#include "OrderItem.h"
#include <iostream>
// Constructor: chot lai gia va so luong tai thoi diem checkout
// finalPrice / quantity khong duoc am
OrderItem::OrderItem(std::string productId, std::string productName, double finalPrice,
    int quantity)
    : productId(productId), productName(productName),
    finalPrice(finalPrice >= 0 ? finalPrice : 0.0),
    quantity(quantity >= 0 ? quantity : 0) {
}

// Getters
std::string OrderItem::getProductId() const { return productId; }

std::string OrderItem::getProductName() const { return productName; }

double OrderItem::getFinalPrice() const { return finalPrice; }

int OrderItem::getQuantity() const { return quantity; }

// Subtotal = finalPrice * quantity
double OrderItem::getSubtotal() const { return finalPrice * quantity; }

void OrderItem::display() const {
    std::cout << "  - " << productName << " (ID: " << productId << ")" << std::endl;
    std::cout << "    Don gia: " << finalPrice << std::endl;
    std::cout << "    So luong: " << quantity << std::endl;
    std::cout << "    Thanh tien: " << getSubtotal() << std::endl;
}
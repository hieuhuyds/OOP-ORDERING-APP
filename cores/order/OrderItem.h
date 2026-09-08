#pragma once
#include <string>
#include <string>

// OrderItem la snapshot cua san pham tai thoi diem checkout
class OrderItem {
private:
    std::string productId;
    std::string productName;
    double finalPrice;
    int quantity;

public:
    OrderItem(std::string productId = "", std::string productName = "",
        double finalPrice = 0.0, int quantity = 0);

    // Getters
    std::string getProductId() const;
    std::string getProductName() const;
    double getFinalPrice() const;
    int getQuantity() const;

    // Subtotal = finalPrice * quantity
    double getSubtotal() const;

    void display() const;
};
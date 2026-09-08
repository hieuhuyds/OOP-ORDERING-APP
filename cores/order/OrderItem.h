#pragma once
#include <string>
using namespace std;

// OrderItem la snapshot cua san pham tai thoi diem checkout
class OrderItem {
private:
  string productId;
  string productName;
  double finalPrice;
  int quantity;

public:
  OrderItem(string productId = "", string productName = "",
            double finalPrice = 0.0, int quantity = 0);

  // Getters
  string getProductId() const;
  string getProductName() const;
  double getFinalPrice() const;
  int getQuantity() const;

  // Subtotal = finalPrice * quantity
  double getSubtotal() const;

  void display() const;
};
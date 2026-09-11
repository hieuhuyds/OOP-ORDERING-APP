#pragma once
#include "../products/Product.h"
#include "CartItem.h"
#include <string>
#include <vector>

class ShoppingCart {
private:
  std::vector<CartItem> items;

public:
  ShoppingCart();

  // Them Product vao gio hang
  // - Neu Product da co trong gio -> cong don quantity, khong tao item trung ID
  // - Khong cho quantity vuot qua stock cua Product
  bool addProduct(Product *product, int quantity = 1);

  // Xoa san pham khoi gio theo Product ID
  bool removeProduct(const std::string &productId);

  void displayCart() const;

  // Subtotal = tong subtotal cua tat ca CartItem
  double calculateSubtotal() const;

  bool isEmpty() const;
  void clear();

  const std::vector<CartItem>& getItems() const;
};
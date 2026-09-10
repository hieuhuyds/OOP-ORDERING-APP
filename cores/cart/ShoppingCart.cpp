#include "ShoppingCart.h"
#include <iostream>

ShoppingCart::ShoppingCart() {}

// Them san pham vao gio hang
// - product == nullptr hoac quantity <= 0 -> bo qua
// - Neu Product da co trong gio -> cong don quantity, khong tao CartItem moi
// - Quantity cuoi cung khong duoc vuot qua stock hien tai cua Product
void ShoppingCart::addProduct(Product *product, int quantity) {
  if (product == nullptr || quantity <= 0)
    return;

  for (auto &item : items) {
    if (item.getProduct()->getId() == product->getId()) {
      int maxAddable = product->getStock() - item.getQuantity();
      if (maxAddable <= 0)
        return; // da dat toi han stock, khong the them nua

      int addQuantity = (quantity < maxAddable) ? quantity : maxAddable;
      item.increaseQuantity(addQuantity);
      return;
    }
  }

  // Chua co trong gio -> tao CartItem moi, gioi han theo stock
  int addQuantity =
      (quantity < product->getStock()) ? quantity : product->getStock();
  if (addQuantity <= 0)
    return;

  items.push_back(CartItem(product, addQuantity));
}

// Xoa san pham khoi gio theo Product ID
void ShoppingCart::removeProduct(const std::string &productId) {
  for (auto it = items.begin(); it != items.end(); ++it) {
    if (it->getProduct()->getId() == productId) {
      items.erase(it);
      return;
    }
  }
}

// Hien thi toan bo gio hang
void ShoppingCart::displayCart() const {
  if (isEmpty()) {
    std::cout << "Gio hang trong." << std::endl;
    return;
  }

  std::cout << "===== GIO HANG =====" << std::endl;
  for (const auto &item : items) {
    Product *product = item.getProduct();
    std::cout << "- " << product->getName() << " (ID: " << product->getId()
              << ")" << std::endl;
    std::cout << "    Don gia: " << product->calculateFinalPrice() << std::endl;
    std::cout << "    So luong: " << item.getQuantity() << std::endl;
    std::cout << "    Thanh tien: " << item.getSubtotal() << std::endl;
  }
  std::cout << "Tong tien (subtotal): " << calculateSubtotal() << std::endl;
}

// Subtotal = tong subtotal cua tat ca CartItem
double ShoppingCart::calculateSubtotal() const {
  double subtotal = 0.0;
  for (const auto &item : items) {
    subtotal += item.getSubtotal();
  }
  return subtotal;
}

bool ShoppingCart::isEmpty() const { return items.empty(); }

// Xoa toan bo gio hang. Khong delete Product
void ShoppingCart::clear() { items.clear(); }
    
const std::vector<CartItem>& ShoppingCart::getItems() const { return items; }

#include "ShoppingCart.h"
#include <iostream>

ShoppingCart::ShoppingCart() {}

// Them san pham vao gio hang
// - product == nullptr hoac quantity <= 0 -> bo qua
// - Neu Product da co trong gio -> cong don quantity, khong tao CartItem moi
// - Quantity cuoi cung khong duoc vuot qua stock hien tai cua Product
bool ShoppingCart::addProduct(Product* product, int quantity)
{
    // Kiem tra san pham va so luong
    if (product == nullptr || quantity <= 0)
    {
        return false;
    }

    // Tim xem san pham da co trong gio hang chua
    for (auto& item : items)
    {
        if (item.getProduct()->getId() == product->getId())
        {
            int currentQuantity = item.getQuantity();
            int newQuantity = currentQuantity + quantity;

            // Khong cho vuot qua stock
            if (newQuantity > product->getStock())
            {
                return false;
            }

            item.increaseQuantity(quantity);
            return true;
        }
    }

    // San pham chua co trong gio hang
    // Kiem tra quantity co vuot stock khong
    if (quantity > product->getStock())
    {
        return false;
    }

    items.emplace_back(product, quantity);
    return true;
}

// Xoa san pham khoi gio theo Product ID
bool ShoppingCart::removeProduct(const std::string& productId)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->getProduct()->getId() == productId)
        {
            items.erase(it);
            return true;
        }
    }

    return false;
}

// Hien thi toan bo gio hang
void ShoppingCart::displayCart() const {
  if (isEmpty()) {
    std::cout << "Cart is empty!" << std::endl;
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

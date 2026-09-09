#pragma once
#include "../products/Product.h"
#include "CartItem.h"
#include <string>
#include <vector>


// ShoppingCart quan ly danh sach CartItem cua khach hang
// ShoppingCart khong so huu Product -> khong bao gio delete Product
class ShoppingCart {
private:
  std::vector<CartItem> items;

public:
  ShoppingCart();

  // Them Product vao gio hang
  // - Neu Product da co trong gio -> cong don quantity, khong tao item trung ID
  // - Khong cho quantity vuot qua stock cua Product
  void addProduct(Product *product, int quantity = 1);

  // Xoa san pham khoi gio theo Product ID
  void removeProduct(const std::string &productId);

  void displayCart() const;

  // Subtotal = tong subtotal cua tat ca CartItem
  double calculateSubtotal() const;

  bool isEmpty() const;
  void clear();

  const std::vector<CartItem>& getItems() const;

  **Thay đổi : **
	  -Đổi từ :
  `std: : vector<CartItem> getItems() const`
	  - Thành:
  `const std::vector<CartItem>&getItems() const`

	  * *Lý do:**
	  -Trả về tham chiếu đến `items` thay vì tạo bản copy của toàn bộ `std::vector<CartItem>`.
	  - Có `const` để bên ngoài chỉ đọc danh sách CartItem, không sửa trực tiếp `items`.
	  - `ShoppingCart.cpp` phải sửa signature cho khớp với `.h`.

};
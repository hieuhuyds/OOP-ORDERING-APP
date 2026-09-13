## OOP Ordering Application

------------------------------------------------------------------------

# 1. Tổng quan project

## Mục tiêu

Ứng dụng cho phép người dùng:

1.  Xem danh sách sản phẩm.
2.  Tìm kiếm sản phẩm theo ID.
3.  Thêm sản phẩm vào giỏ hàng.
4.  Xem giỏ hàng.
5.  Xóa sản phẩm khỏi giỏ hàng.
6.  Checkout và nhập thông tin khách hàng.
7.  Tính tiền sản phẩm, phí vận chuyển và tổng tiền.
8.  Cập nhật stock sau khi đặt hàng.
9.  Lưu và xem lịch sử đơn hàng.

## Cấu trúc project

``` text
OOP-ORDERING-APP/
├── main.cpp                                      # Điểm bắt đầu chương trình
├── app/
│   ├── OrderingApplication.h                     # Khai báo giao diện và các chức năng chính của ứng dụng
│   └── OrderingApplication.cpp                   # Điều khiển menu và luồng hoạt động của chương trình
│
├── cores/
│   ├── products/                                 # Các class sản phẩm và xử lý đặc điểm từng loại
│   │   ├── Product.h                             # Abstract class, định nghĩa thông tin và interface chung
│   │   ├── Product.cpp                           # Cài đặt các chức năng chung của Product
│   │   ├── BookProduct.h                         # Class sản phẩm sách
│   │   ├── BookProduct.cpp
│   │   ├── GameProduct.h                         # Class sản phẩm game
│   │   ├── GameProduct.cpp
│   │   ├── MusicProduct.h                        # Class sản phẩm âm nhạc
│   │   ├── MusicProduct.cpp
│   │
│   ├── customer/                                 # Quản lý thông tin khách hàng
│   │   ├── Customer.h
│   │   └── Customer.cpp
│   │
│   ├── cart/                                     # Quản lý giỏ hàng
│   │   ├── CartItem.h                            # Đại diện cho một sản phẩm trong giỏ hàng
│   │   ├── CartItem.cpp
│   │   ├── ShoppingCart.h                        # Quản lý danh sách sản phẩm trong giỏ
│   │   └── ShoppingCart.cpp
│   │
│   └── order/                                    # Quản lý thông tin đơn hàng
│       ├── OrderItem.h                           # Đại diện cho một sản phẩm trong đơn hàng
│       ├── OrderItem.cpp
│       ├── Order.h                               # Lưu thông tin và tính toán của đơn hàng
│       └── Order.cpp
│
├── manage/                                       # Các class quản lý và xử lý nghiệp vụ
│   ├── ProductManage.h                           # Quản lý danh sách Product
│   ├── ProductManage.cpp
│   ├── OrderManage.h                             # Xử lý checkout và quản lý Order History
│   ├── OrderManage.cpp
│   ├── FileManage.h                              # Khai báo các thao tác đọc/ghi file
│   └── FileManage.cpp                            # Cài đặt các thao tác đọc/ghi file
│
└── data/                                         # Dữ liệu của chương trình
    ├── products.txt                              # Lưu thông tin sản phẩm và tồn kho
    └── OrderHistory.txt                          # Lưu lịch sử đơn hàng
```

------------------------------------------------------------------------

# 2. Class Relationship

## Sơ đồ tổng quát

``` mermaid
classDiagram

class Product {
    <<abstract>>
    #string id
    #string name
    #double price
    #int stockQuantity
    #string category
    +getId()
    +getName()
    +getPrice()
    +getStock()
    +setPrice()
    +setStock()
    +displayInfo()*
    +calculateFinalPrice()*
    +getType()*
}

class BookProduct {
    -string author
    -int pages
    +displayInfo()
    +calculateFinalPrice()
    +getType()
}

class GameProduct {
    -string platform
    -string genre
    +displayInfo()
    +calculateFinalPrice()
    +getType()
}

class MusicProduct {
    -string artist
    -int durationMinutes
    +displayInfo()
    +calculateFinalPrice()
    +getType()
}

Product <|-- BookProduct
Product <|-- GameProduct
Product <|-- MusicProduct

class Customer {
    -string name
    -string phone
    -string email
    -string address
    +input()
    +display()
}

class CartItem {
    -Product* product
    -int quantity
    +getProduct()
    +getQuantity()
    +increaseQuantity()
    +decreaseQuantity()
    +getSubtotal()
}

class ShoppingCart {
    -vector~CartItem~ items
    +addProduct()
    +removeProduct()
    +displayCart()
    +calculateSubtotal()
    +isEmpty()
    +clear()
    +getItems()
}

CartItem --> Product
ShoppingCart *-- CartItem

class OrderItem {
    -string productId
    -string productName
    -double finalPrice
    -int quantity
    +getSubtotal()
    +display()
}

class Order {
    -string orderId
    -time_t orderDate
    -time_t expectedDeliveryDate
    -Customer customer
    -string deliveryAddress
    -vector~OrderItem~ items
    -double shippingFee
    -double totalPayment
    +calculateTotal()
    +displayOrder()
}

Order *-- OrderItem
Order --> Customer

class ProductManage {
    -vector~Product*~ products
    +loadProducts()
    +saveProducts()
    +findProductById()
    +displayProducts()
    +getProducts()
}

ProductManage --> Product

class OrderManage {
    -vector~Order~ orders
    +checkout()
    +displayOrderHistory()
    +generateOrderId()
}

OrderManage --> Order
OrderManage --> ProductManage
OrderManage --> ShoppingCart

class FileManage {
    <<utility>>
    +readFile()
    +writeFile()
    +appendFile()
}

ProductManage --> FileManage
OrderManage --> FileManage

class OrderingApplication {
    -ProductManage productManage
    -OrderManage orderManage
    -ShoppingCart cart
    -Customer customer
    +run()
    +displayMenu()
    +viewProducts()
    +searchProduct()
    +addProductToCart()
    +viewCart()
    +removeProductFromCart()
    +checkout()
    +viewOrderHistory()
}

OrderingApplication --> ProductManage
OrderingApplication --> OrderManage
OrderingApplication --> ShoppingCart
OrderingApplication --> Customer
```

------------------------------------------------------------------------

# 3. Program Flow

```text
START
  ↓
OrderingApplication                 # Điều khiển menu và luồng chính của chương trình
  ↓
View / Search Products              # Xem hoặc tìm kiếm sản phẩm
  ↓
Add Product to Cart                 # Thêm sản phẩm và số lượng vào giỏ hàng
  ↓
ShoppingCart                        # Lưu và quản lý các sản phẩm trong giỏ
  ↓
Checkout                            # Bắt đầu quá trình đặt hàng
  ↓
Enter Customer Information          # Nhập tên, số điện thoại, email và địa chỉ
  ↓
Check Stock                         # Kiểm tra sản phẩm và số lượng tồn kho
  ↓
Create OrderItem                    # Chuyển sản phẩm từ giỏ hàng thành OrderItem
  ↓
Create Order                        # Tạo đơn hàng mới
  ↓
Calculate Total                     # Tính subtotal, phí vận chuyển và tổng tiền
  ↓
Update Product Stock                # Trừ số lượng sản phẩm sau khi đặt hàng thành công
  ↓
Save Order History                  # Lưu đơn hàng vào OrderHistory.txt
  ↓
Clear Shopping Cart                 # Xóa các sản phẩm khỏi giỏ sau khi checkout
  ↓
View Order History                  # Xem lại các đơn hàng đã lưu
  ↓
END
```

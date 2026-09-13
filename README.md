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
├── main.cpp
├── app/
│   ├── OrderingApplication.h
│   └── OrderingApplication.cpp
│
├── cores/
│   ├── products/
│   │   ├── Product.h
│   │   ├── Product.cpp
│   │   ├── BookProduct.h
│   │   ├── BookProduct.cpp
│   │   ├── GameProduct.h
│   │   ├── GameProduct.cpp
│   │   ├── MusicProduct.h
│   │   └── MusicProduct.cpp
│   │
│   ├── customer/
│   │   ├── Customer.h
│   │   └── Customer.cpp
│   │
│   ├── cart/
│   │   ├── CartItem.h
│   │   ├── CartItem.cpp
│   │   ├── ShoppingCart.h
│   │   └── ShoppingCart.cpp
│   │
│   └── order/
│       ├── OrderItem.h
│       ├── OrderItem.cpp
│       ├── Order.h
│       └── Order.cpp
│
├── manage/
│   ├── ProductManage.h
│   ├── ProductManage.cpp
│   ├── OrderManage.h
│   ├── OrderManage.cpp
│   ├── FileManage.h
│   └── FileManage.cpp
│
└── data/
    ├── products.txt
    └── OrderHistory.txt
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

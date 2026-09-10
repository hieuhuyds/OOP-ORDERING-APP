#pragma once

#include "../manage/ProductManage.h"
#include "../manage/OrderManage.h"
#include "../cores/cart/ShoppingCart.h"
#include "../cores/customer/Customer.h"
#include "../cores/products/Product.h"

class OrderingApplication
{
private:
    ProductManage productManage;
    OrderManage orderManage;
    ShoppingCart cart;
    Customer customer;

    void addProductToCart();
    void viewCart() const;
    void removeProductFromCart();
    void checkout();
    void viewOrderHistory() const;

public:
    void run();
    void displayMenu() const;
    void viewProducts() const;
    void searchProduct() const;
};
#pragma once
#include "../cores/order/Order.h"
#include "../cores/cart/ShoppingCart.h"
#include "ProductManage.h"
#include "../cores/customer/Customer.h"
#include <vector>
#include <string>

class OrderManage {
private:
    std::vector<Order> orders;

public:
    bool checkout(const Customer& customer, ShoppingCart& cart, ProductManage& productManage);
    void displayOrderHistory() const;
    std::string generateOrderId() const;
};
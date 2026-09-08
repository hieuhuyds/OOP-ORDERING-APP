#pragma once
#include <string>
#include <vector>
#include <ctime>
#include "../customer/Customer.h"
#include "OrderItem.h"
class Order{
private:
    std::string orderId;
    std::time_t orderDate, expectedDeliveryDate;
    Customer customer;
    std::string deliveryAddress;
    std::vector<OrderItem> items;
    double shippingFee,totalPayment;
public:
    Order(std::string orderId="",Customer customer=Customer(),std::string deliveryAddress="",std::vector<OrderItem>items={});
    std::string getOrderId() const;
    std::time_t getOrderDate() const;
    std::time_t getExpectedDeliveryDate()const;
    Customer getCustomer() const;
    std::string getDeliveryAddress() const;
    std::vector<OrderItem> getItems() const;   
    double getShippingFee() const;
    double getTotalPayment() const;
    double calculateTotal();
    void displayOrder() const;

};

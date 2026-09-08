#pragma once
#include <string>
#include <vector>
#include <ctime>
#include "../customer/Customer.h"
#include "OrderItem.h"
class Order{
private:
    string orderId;
    time_t orderDate, expectedDeliveryDate;
    Customer customer;
    string deliveryAddress;
    vector<OrderItem> items;
    double shippingFee,totalPayment;
public:
    Order(string orderId="",Customer customer=Customer(),string deliveryAddress="",vector<OrderItem>items={});
    string getOrderId() const;
    time_t getOrderDate() const;
    time_t getExpectedDeliveryDate()const;
    Customer getCustomer() const;
    string getDeliveryAddress() const;
    vector<OrderItem> getItems() const;   
    double getShippingFee() const;
    double getTotalPayment() const;
    double calculateTotal();
    void displayOrder() const;

};

#include "Order.h"
#include <iostream>
Order :: Order(std::string orderId,Customer customer,std::string deliveryAddress,std::vector<OrderItem>items)
: orderId(orderId) , customer(customer), deliveryAddress(deliveryAddress),items(items),orderDate(time(nullptr)),
expectedDeliveryDate(orderDate+3*24*60*60), shippingFee(0), totalPayment(0){

}
std::string Order :: getOrderId() const{
    return orderId;
}
std::time_t Order :: getOrderDate() const{
    return orderDate;
}
std::time_t Order:: getExpectedDeliveryDate() const {
    return expectedDeliveryDate;
}
Customer Order :: getCustomer() const {
    return customer;
}
std::string Order ::getDeliveryAddress() const{
    return deliveryAddress;
}
std::vector<OrderItem> Order :: getItems() const{
    return items;
}
double Order:: getShippingFee() const{
    return shippingFee;
}
double Order::getTotalPayment() const{
    return totalPayment;
}
double Order :: calculateTotal(){
    double subtotal = 0;
        for(OrderItem item:items){
            subtotal += item.getSubtotal();
    }
    if(subtotal<500000){
        shippingFee = 30000;
    }
    else{
        shippingFee =0;
    }
    totalPayment =subtotal + shippingFee;
    return totalPayment;
};
std::string formatDate(std::time_t t){
    std::tm* timeInfo = std::localtime(&t);
    std::string day = std::to_string(timeInfo->tm_mday);
    std::string month = std::to_string(timeInfo->tm_mon+1);
    std::string year = std::to_string(timeInfo->tm_year + 1900);
    return day + "/" + month +"/" +year;
}
void Order :: displayOrder() const {
    std::cout<<"ID: "<< orderId<< std::endl;
    std::cout<<"Order Date: " << formatDate(orderDate) << std::endl;
    customer.display();
    std::cout<< "Delivery Address: " << deliveryAddress << std::endl;
    std::cout<<"ExpectedDeliveryDate: "<<formatDate(expectedDeliveryDate)<< std::endl;
    std::cout<< "Item: " << std::endl;
    for(OrderItem item:items){
        item.display();
        std::cout<<"------------------"<< std::endl;
    }
    std::cout << "Shipping Fee: " << shippingFee << std::endl;
    std::cout << "Total Payment: " << totalPayment << std::endl;

}
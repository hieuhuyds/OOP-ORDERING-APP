#include "Order.h"
#include <iostream>
Order :: Order(string orderId,Customer customer,string deliveryAddress,vector<OrderItem>items)
: orderId(orderId) , customer(customer), deliveryAddress(deliveryAddress),items(items),orderDate(time(nullptr)),
expectedDeliveryDate(time(nullptr)+3*24*60*60), shippingFee(0), totalPayment(0){

}
string Order :: getOrderId() const{
    return orderId;
}
time_t Order :: getOrderDate() const{
    return orderDate;
}
time_t Order:: getExpectedDeliveryDate() const {
    return expectedDeliveryDate;
}
Customer Order :: getCustomer() const {
    return customer;
}
string Order ::getDeliveryAddress() const{
    return deliveryAddress;
}
vector<OrderItem> Order :: getItems() const{
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
string formatDate(time_t t){
    tm* timeInfo = localtime(&t);
    string day = to_string(timeInfo->tm_mday);
    string month = to_string(timeInfo->tm_mon+1);
    string year = to_string(timeInfo->tm_year + 1900);
    return day + "/" + month +"/" +year;
}
void Order :: displayOrder() const {
    cout<<"ID: "<< orderId<< endl;
    cout<<"Order Date: " << formatDate(orderDate) << endl;
    customer.display();
    cout<< "Delivery Address: " << deliveryAddress << endl;
    cout<<"ExpectedDeliveryDate: "<<formatDate(expectedDeliveryDate)<< endl;
    cout<< "Item: " << endl;
    for(OrderItem item:items){
        item.display();
        cout<<"------------------"<< endl;
    }
    cout << "Shipping Fee: " << shippingFee << endl;
    cout << "Total Payment: " << totalPayment << endl;

}
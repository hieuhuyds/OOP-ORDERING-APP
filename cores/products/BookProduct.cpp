#include "BookProduct.h"
#include <iostream>


BookProduct::BookProduct(string id, string name, double price, int stockQuantity, string author, int pages)
    : Product(id,name,price,stockQuantity,"Book") , Author(author),Pages(pages)
{
}
string BookProduct :: getAuthor() const {
    return Author;
}
int BookProduct :: getPages() const {
    return Pages;
}
string BookProduct::getType() const
{
    return "Book";
}
double BookProduct::calculateFinalPrice() const{
    if(Pages>500){
        return price * 1.05;
    }
    else
        return price;
}
void BookProduct::displayInfo() const{
    cout<<"ID: "<< id<< endl;
    cout<<"Name: "<<name<< endl;
    cout<<"Price: "<<calculateFinalPrice()<<endl;
    cout<<"StockQuantity: "<< stockQuantity<< endl;
    cout<<"Category: "<<category<< endl;
    cout<<"Author: "<<Author<< endl;
    cout<<"Pages: "<<Pages<<endl;

}

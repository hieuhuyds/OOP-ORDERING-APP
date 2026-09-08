#include "BookProduct.h"
#include <iostream>

BookProduct::BookProduct(std::string id, std::string name, double price, int stockQuantity, std::string author, int pages)
    : Product(id, name, price, stockQuantity, "Book"), Author(author), Pages(pages)
{
}
std::string BookProduct::getAuthor() const {
    return Author;
}
int BookProduct::getPages() const {
    return Pages;
}
std::string BookProduct::getType() const
{
    return "Book";
}
double BookProduct::calculateFinalPrice() const {
    if (Pages > 500) {
        return price * 1.05;
    }
    else
        return price;
}
void BookProduct::displayInfo() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Price: " << calculateFinalPrice() << std::endl;
    std::cout << "StockQuantity: " << stockQuantity << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Author: " << Author << std::endl;
    std::cout << "Pages: " << Pages << std::endl;

}

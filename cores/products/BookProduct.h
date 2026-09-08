#pragma once
#include <string>
#include "Product.h"

class BookProduct : public Product
{
private:
    std::string Author;
    int Pages;

public:
    BookProduct(std::string id = "", std::string name = "", double price = 0, int stockQuantity = 0, std::string author = "", int pages = 0);
    std::string getAuthor() const;
    int getPages() const;
    void displayInfo() const override;
    double calculateFinalPrice() const override;
    std::string getType() const override;
};

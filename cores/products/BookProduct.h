#pragma once
#include "Product.h"

class BookProduct : public Product
{
private:
    string Author;
    int Pages;

public:
    BookProduct(string id ="", string name="",double price= 0,int stockQuantity= 0,string author = "", int pages = 0);
    string getAuthor() const;
    int getPages() const;
     void displayInfo() const override; 
     double calculateFinalPrice() const override  ;
     string getType() const override;
};

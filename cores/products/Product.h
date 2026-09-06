#pragma once
#include <string>
using namespace std;

class Product
{
protected:
    string id;
    string name;
    double price;
    int stockQuantity;
    string category;

public:
    Product(string id = "", string name = "", double price = 0.0, int stockQuantity = 0, string category = "");

    virtual ~Product() = default;

    string getId() const;
    string getName() const;
    double getPrice() const;
    int getStock() const;
    string getCategory() const;

    void setPrice(double price);
    void setStock(int quantity);

    virtual void displayInfo() const = 0;
    virtual double calculateFinalPrice() const = 0;
    virtual string getType() const = 0;

    bool operator==(const Product& other) const;
};
#pragma once
#include <string>
#include <string>

class Product
{
protected:
    std::string id;
    std::string name;
    double price;
    int stockQuantity;
    std::string category;

public:
    Product(std::string id = "", std::string name = "", double price = 0.0, int stockQuantity = 0, std::string category = "");

    virtual ~Product() = default;

    std::string getId() const;
    std::string getName() const;
    double getPrice() const;
    int getStock() const;
    std::string getCategory() const;

    void setPrice(double price);
    void setStock(int quantity);

    virtual void displayInfo() const = 0;
    virtual double calculateFinalPrice() const = 0;
    virtual std::string getType() const = 0;

    bool operator==(const Product& other) const;
};
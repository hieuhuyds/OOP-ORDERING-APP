#include "Product.h"

using namespace std;

// Constructor
Product::Product(string id, string name, double price, int stockQuantity, string category)
    : id(id), name(name), price(price >= 0 ? price : 0.0), stockQuantity(stockQuantity >= 0 ? stockQuantity : 0), category(category)
{
}

// Getters
string Product::getId() const
{
    return id;
}

string Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}

int Product::getStock() const
{
    return stockQuantity;
}

string Product::getCategory() const
{
    return category;
}

// Setters
void Product::setPrice(double price)
{
    if (price >= 0)
        this->price = price;
}

void Product::setStock(int quantity)
{
    if (quantity >= 0)
        stockQuantity = quantity;
}

// Operator ==
bool Product::operator==(const Product& other) const
{
    return id == other.id;
}
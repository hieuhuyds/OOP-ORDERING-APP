#include "GameProduct.h"
#include <iostream>
using namespace std;
GameProduct::GameProduct(string id, string name, double price, int stockQuantity, string platform, string genre)
    : Product(id, name, price, stockQuantity, "Game"), platform(platform), genre(genre) {}

string GameProduct::getPlatform() const {
    return platform;
}

string GameProduct::getGenre() const {
    return genre;
}   

void GameProduct::displayInfo() const 
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Price: $" << price << endl;
    cout << "Stock Quantity: " << stockQuantity << endl;
    cout << "Category: " << category << endl;
    cout << "Platform: " << platform << endl;
    cout << "Genre: " << genre << endl;
}

double GameProduct::calculateFinalPrice() const 
{
    if (platform == "Console")
    {
        return price * 1.05; 
    }
    return price;
}

string GameProduct::getType() const 
{
    return "Game";
}
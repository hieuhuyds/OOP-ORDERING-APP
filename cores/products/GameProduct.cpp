#include "GameProduct.h"
#include <iomanip>
#include <iostream>

GameProduct::GameProduct(std::string id, std::string name, double price, int stockQuantity, std::string platform, std::string genre)
    : Product(id, name, price, stockQuantity, "Game"), platform(platform), genre(genre) {
}

std::string GameProduct::getPlatform() const {
    return platform;
}

std::string GameProduct::getGenre() const {
    return genre;
}

void GameProduct::displayInfo() const
{
    std::cout << "\n==================== PRODUCT LIST ====================\n";
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Price: " << std::fixed << std::setprecision(0) << calculateFinalPrice() << std::endl;
    std::cout << "Stock Quantity: " << stockQuantity << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Platform: " << platform << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "-------------------------------------------------------\n";
}

double GameProduct::calculateFinalPrice() const
{
    if (platform == "Console")
    {
        return price * 1.05;
    }
    return price;
}

std::string GameProduct::getType() const
{
    return "Game";
}
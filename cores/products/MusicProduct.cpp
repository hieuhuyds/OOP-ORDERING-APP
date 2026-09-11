#include "MusicProduct.h"
#include <iomanip>
#include <iostream>

// Constructor: dùng initializer list, gọi constructor Product và truyền
// category = "Music"
MusicProduct::MusicProduct(std::string id, std::string name, double price,
    int stockQuantity, std::string artist,
    int durationMinutes)
    : Product(id, name, price, stockQuantity, "Music"), artist(artist),
    durationMinutes(durationMinutes) {
}

// Getters
std::string MusicProduct::getArtist() const { return artist; }

int MusicProduct::getDurationMinutes() const { return durationMinutes; }

// getType
std::string MusicProduct::getType() const { return "Music"; }

// calculateFinalPrice: durationMinutes > 60 -> tang 5%, nguoc lai giu nguyen
double MusicProduct::calculateFinalPrice() const {
    if (durationMinutes > 60) {
        return price * 1.05;
    }
    else {
        return price;
    }
}

// displayInfo: hien thi thong tin chung cua Product + artist, durationMinutes
void MusicProduct::displayInfo() const {
    std::cout << "\n==================== PRODUCT LIST ====================\n";
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Price: " << std::fixed << std::setprecision(0) << calculateFinalPrice() << std::endl;
    std::cout << "Stock Quantity: " << stockQuantity << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Artist: " << artist << std::endl;
    std::cout << "Duration (minutes): " << durationMinutes << std::endl;
    std::cout << "-------------------------------------------------------\n";
}
#include "MusicProduct.h"
#include <iostream>

// Constructor: dùng initializer list, gọi constructor Product và truyền
// category = "Music"
MusicProduct::MusicProduct(string id, string name, double price,
                           int stockQuantity, string artist,
                           int durationMinutes)
    : Product(id, name, price, stockQuantity, "Music"), artist(artist),
      durationMinutes(durationMinutes) {}

// Getters
string MusicProduct::getArtist() const { return artist; }

int MusicProduct::getDurationMinutes() const { return durationMinutes; }

// getType
string MusicProduct::getType() const { return "Music"; }

// calculateFinalPrice: durationMinutes > 60 -> tang 5%, nguoc lai giu nguyen
double MusicProduct::calculateFinalPrice() const {
  if (durationMinutes > 60) {
    return price * 1.05;
  } else {
    return price;
  }
}

// displayInfo: hien thi thong tin chung cua Product + artist, durationMinutes
void MusicProduct::displayInfo() const {
  cout << "ID: " << id << endl;
  cout << "Name: " << name << endl;
  cout << "Price: " << calculateFinalPrice() << endl;
  cout << "StockQuantity: " << stockQuantity << endl;
  cout << "Category: " << category << endl;
  cout << "Artist: " << artist << endl;
  cout << "Duration (minutes): " << durationMinutes << endl;
}
#pragma once
#include "Product.h"

class MusicProduct : public Product {
private:
  string artist;
  int durationMinutes;

public:
  MusicProduct(string id = "", string name = "", double price = 0,
               int stockQuantity = 0, string artist = "",
               int durationMinutes = 0);

  string getArtist() const;
  int getDurationMinutes() const;

  void displayInfo() const override;
  double calculateFinalPrice() const override;
  string getType() const override;
};
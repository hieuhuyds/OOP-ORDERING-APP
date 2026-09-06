#pragma once
#include "Product.h"
#include <string>
using namespace std;

class GameProduct : public Product {
private:
    string platform;
    string genre;
public:
    GameProduct(string id = "", string name = "", double price = 0.0, int stockQuantity = 0, string platform = "", string genre = "");

    string getPlatform() const;
    string getGenre() const;

    void displayInfo() const override;
    double calculateFinalPrice() const override;
    string getType() const override;
      
};

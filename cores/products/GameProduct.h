#pragma once
#include <string>
#include "Product.h"
#include <string>

class GameProduct : public Product {
private:
    std::string platform;
    std::string genre;
public:
    GameProduct(std::string id = "", std::string name = "", double price = 0.0, int stockQuantity = 0, std::string platform = "", std::string genre = "");

    std::string getPlatform() const;
    std::string getGenre() const;

    void displayInfo() const override;
    double calculateFinalPrice() const override;
    std::string getType() const override;

};

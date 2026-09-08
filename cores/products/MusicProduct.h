#pragma once
#include <string>
#include "Product.h"

class MusicProduct : public Product {
private:
    std::string artist;
    int durationMinutes;

public:
    MusicProduct(std::string id = "", std::string name = "", double price = 0,
        int stockQuantity = 0, std::string artist = "",
        int durationMinutes = 0);

    std::string getArtist() const;
    int getDurationMinutes() const;

    void displayInfo() const override;
    double calculateFinalPrice() const override;
    std::string getType() const override;
};
#pragma once

#include "../products/Product.h"

class CartItem {
private:
    Product* product;
    int quantity;

public:
    CartItem(Product* product, int quantity = 1);

    Product* getProduct() const;
    int getQuantity() const;

    void increaseQuantity(int amount = 1);
    void decreaseQuantity(int amount = 1);

    double getSubtotal() const;
};
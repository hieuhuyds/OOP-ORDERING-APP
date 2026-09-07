#pragma once
#include <vector>
#include "CartItem.h"
using namespace std;

class ShoppingCart {
    private:
        vector<CartItem> items;
public:
    bool addProduct(const CartItem& item);
    void removeProduct(const CartItem& item);
    void displayCart() const;
    double calculateSubtotal() const;
    bool isEmpty() const;
    void clear();
    const vector<CartItem>& getItems() const;
};

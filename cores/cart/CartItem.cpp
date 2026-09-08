#include "CartItem.h"

CartItem::CartItem(Product* product, int quantity) 
    : product(product), quantity(quantity < 0 ? 0 : quantity) {}

Product* CartItem::getProduct() const {
    return product;
}

int CartItem::getQuantity() const {
    return quantity;
}

void CartItem::increaseQuantity(int amount) {
    if (amount > 0) {
        quantity += amount;
    }
}

void CartItem::decreaseQuantity(int amount) {
    if (amount > 0) {
        quantity -= amount;
        if (quantity < 0) {
            quantity = 0;
        }
    }
}

double CartItem::getSubtotal() const {
    if (product != nullptr) {
        return product->calculateFinalPrice() * quantity;
    }
    return 0.0;
}
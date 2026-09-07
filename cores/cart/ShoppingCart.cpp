#include "ShoppingCart.h"
#include <iostream>
using namespace std;

bool ShoppingCart::addProduct(const CartItem& item) 
{
     if (item.getProduct() == nullptr || item.getQuantity() <= 0)
        return false;
    for (CartItem& existingItem : items) 
    {
        if (existingItem.getProduct()->getId() == item.getProduct()->getId()) 
        {
            if (existingItem.getQuantity() + item.getQuantity() > existingItem.getProduct()->getStock()) 
            {
                cout << "Cannot add product: Exceeds available stock." << endl;
                return false;
            }
            existingItem.increaseQuantity(item.getQuantity());
            return true;
        }
    }
    if (item.getQuantity() > item.getProduct()->getStock()) 
        {
            cout << "Cannot add product: Exceeds available stock." << endl;
            return false;
        }

    items.push_back(item);
    return true;
}   
void ShoppingCart::removeProduct(const CartItem& item) 
{
    for (vector<CartItem>::iterator it = items.begin(); it != items.end(); ++it)
    {
        if (it->getProduct()->getId() == item.getProduct()->getId()) 
        {
            items.erase(it);
            return;
        }
    }
}
void ShoppingCart::displayCart() const 
{
    if (items.empty()) 
    {
        cout << "Shopping cart is empty." << endl;
        return;
    }

    cout << "Shopping Cart:" << endl;
    for (const CartItem& item : items) 
    {
        cout << "Product: " << item.getProduct()->getName() 
             << ", Quantity: " << item.getQuantity() 
             << ", Price: $" << item.getProduct()->getPrice() 
             << ", Subtotal: $" << item.getSubtotal() << endl;
    }
}
double ShoppingCart::calculateSubtotal() const 
{
    double subtotal = 0.0;
    for (const CartItem& item : items) 
    {
        subtotal += item.getSubtotal();
    }
    return subtotal;
}
bool ShoppingCart::isEmpty() const 
{
    return items.empty();
}
void ShoppingCart::clear() 
{
    items.clear();
}
const vector<CartItem>& ShoppingCart::getItems() const 
{
    return items;
}
    
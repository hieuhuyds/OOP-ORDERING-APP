#include "OrderingApplication.h"
#include <iostream>
#include <string>

#include "OrderingApplication.h"
#include <iostream>
#include <string>

void OrderingApplication::displayMenu() const {
  std::cout << "\n========== ORDERING APPLICATION ==========\n";
  std::cout << "1. View products\n";
  std::cout << "2. Search product\n";
  std::cout << "3. Add product to cart\n";
  std::cout << "4. View cart\n";
  std::cout << "5. Remove product from cart\n";
  std::cout << "6. Checkout\n";
  std::cout << "7. View order history\n";
  std::cout << "0. Exit\n";
  std::cout << "==========================================\n";
}

void OrderingApplication::run() {
  productManage.loadProducts("data/products.txt");

  int choice;

  do {
    displayMenu();
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      viewProducts();
      break;

    case 2:
      searchProduct();
      break;

    case 3:
      addProductToCart();
      break;

    case 4:
      viewCart();
      break;

    case 5:
      removeProductFromCart();
      break;

    case 6:
      checkout();
      break;

    case 7:
      viewOrderHistory();
      break;

    case 0:
      std::cout << "Goodbye!\n";
      break;

    default:
      std::cout << "Invalid choice!\n";
    }

  } while (choice != 0);
}

void OrderingApplication::viewProducts() const {
  productManage.displayProducts();
}

void OrderingApplication::searchProduct() const {
  std::string productId;

  std::cout << "Enter Product ID: ";
  std::cin >> productId;

  Product *product = productManage.findProductById(productId);

  if (product != nullptr) {
    product->displayInfo();
  } else {
    std::cout << "Product not found!\n";
  }
}

void OrderingApplication::addProductToCart()
{
    std::string productId;
    int quantity;

    std::cout << "Enter Product ID: ";
    std::cin >> productId;

    Product* product = productManage.findProductById(productId);

    if (product == nullptr)
    {
        std::cout << "Product not found!\n";
        return;
    }

    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    if (quantity <= 0)
    {
        std::cout << "Invalid quantity!\n";
        return;
    }

    if (cart.addProduct(product, quantity))
    {
        std::cout << "Product added to cart!\n";
    }
    else
    {
        std::cout << "Not enough stock!\n";
    }
}

void OrderingApplication::viewCart() const { cart.displayCart(); }

void OrderingApplication::removeProductFromCart()
{
    std::string productId;

    std::cout << "Enter Product ID to remove: ";
    std::cin >> productId;

    if (cart.removeProduct(productId))
    {
        std::cout << "Product removed from cart!\n";
    }
    else
    {
        std::cout << "Product not found in cart!\n";
    }
}

void OrderingApplication::checkout() {
  if (cart.isEmpty()) {
    std::cout << "Cart is empty! Cannot checkout.\n";
    return;
  }

  std::cout << "\n--- Enter customer information ---\n";
  customer.input();

  bool success = orderManage.checkout(customer, cart, productManage);

  if (success) {
    std::cout << "Checkout successful!\n";
  } else {
    std::cout << "Checkout failed! Please check your cart or product stock.\n";
  }
}

void OrderingApplication::viewOrderHistory() const {
  orderManage.displayOrderHistory();
}
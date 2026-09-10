#pragma once
#include <vector>
#include <string>
#include "Product.h"

class ProductManage {
private:
    std::vector<Product*> products;
public:
    ProductManage();
    ~ProductManage();

    void loadProducts(const std::string& filename);
    bool saveProducts(const std::string& filename) const;
    Product* findProductById(const std::string& productId) const;
    void displayProducts() const;
    const std::vector<Product*>& getProducts() const;
    ProductManage(const ProductManage&) = delete;
    ProductManage& operator=(const ProductManage&) = delete;

};
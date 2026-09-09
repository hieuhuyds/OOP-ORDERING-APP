#include "ProductManage.h"
#include "Product.h"
#include "BookProduct.h"
#include "GameProduct.h"
#include "MusicProduct.h"
#include <fstream>
#include <sstream>

ProductManage::ProductManage() {
}
ProductManage::~ProductManage() {
    for (Product* product : products) {
        delete product;
    }
    products.clear();
}
void ProductManage::loadProducts(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return;
}
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        std::istringstream iss(line);
        std::string type;
        std::string id;
        std::string name;
        std::string priceStr;
        std::string stockStr;
        std::string attribute1;
        std::string attribute2;

        std::getline(iss, type, '|');
        std::getline(iss, id, '|');
        std::getline(iss, name, '|'); 
        std::getline(iss, priceStr, '|');
        std::getline(iss, stockStr, '|');
        std::getline(iss, attribute1, '|'); 
        std::getline(iss, attribute2, '|');

        double price = std::stod(priceStr);
        int stock = std::stoi(stockStr);
        Product* product = nullptr;
        if (type == "BOOK") {
            int pages = std::stoi(attribute2);
            product = new BookProduct(id, name, price, stock, attribute1, pages);
        } else if (type == "GAME") {
            product = new GameProduct(id, name, price, stock, attribute1, attribute2);
        } else if (type == "MUSIC") {
            int duration = std::stoi(attribute2);
            product = new MusicProduct(id, name, price, stock, attribute1, duration);
        }
        if (product != nullptr) {
            products.push_back(product);
        }
    }
    file.close();
}
bool ProductManage::saveProducts(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    for (Product* product : products){
        if(product == nullptr) {
            continue;
        }
        BookProduct* book = dynamic_cast<BookProduct*>(product);
        if (book != nullptr) {
            file << "BOOK|" << book->getId() << "|" << book->getName() << "|" << book->getPrice() << "|" << book->getStock() << "|" << book->getAuthor() << "|" << book->getPages() << "\n";
            continue;
        }
        GameProduct* game = dynamic_cast<GameProduct*>(product);
        if (game != nullptr) {
            file << "GAME|" << game->getId() << "|" << game->getName() << "|" << game->getPrice() << "|" << game->getStock() << "|" << game->getPlatform() << "|" << game->getGenre() << "\n";
            continue;
        }
        MusicProduct* music = dynamic_cast<MusicProduct*>(product);
        if (music != nullptr) {
             file << "MUSIC|" << music->getId() << "|" << music->getName() << "|" << music->getPrice() << "|" << music->getStock() << "|" << music->getArtist() << "|" << music->getDurationMinutes() << "\n";
            continue;
        }
    }
    file.close();
    return true;
}
Product* ProductManage::findProductById(const std::string& productId) const {
    for (Product* product : products) {
        if (product != nullptr && product->getId() == productId) {
            return product;
        }
    }
    return nullptr;
}
void ProductManage::displayProducts() const {
    for (const Product* product : products) {
        if (product != nullptr) {
            product->displayInfo();
        }
    }
}
const std::vector<Product*>& ProductManage::getProducts() const {
    return products;
}
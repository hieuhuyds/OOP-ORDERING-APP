#include "OrderManage.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <ctime>

std::string formatOrderHistoryDate(std::time_t t)
{
    std::tm timeInfo{};
    localtime_s(&timeInfo, &t);

    std::string day = std::to_string(timeInfo.tm_mday);
    std::string month = std::to_string(timeInfo.tm_mon + 1);
    std::string year = std::to_string(timeInfo.tm_year + 1900);

    if (day.length() == 1)
        day = "0" + day;

    if (month.length() == 1)
        month = "0" + month;

    return day + "/" + month + "/" + year;
}

std::string OrderManage::generateOrderId() const {
    int maxId = 0;
    std::ifstream file("data/OrderHistory.txt");

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;

            size_t pos = line.find('|');
            if (pos != std::string::npos) {
                std::string idStr = line.substr(0, pos);
                if (idStr.length() > 2 && idStr.substr(0, 2) == "DH") {
                    try {
                        int num = std::stoi(idStr.substr(2));
                        if (num > maxId) {
                            maxId = num;
                        }
                    } catch (...) {}
                }
            }
        }
        file.close();
    }

    int newId = maxId + 1;
    std::ostringstream oss;
    oss << "DH" << std::setw(3) << std::setfill('0') << newId;
    return oss.str();
}

bool OrderManage::checkout(const Customer& customer, ShoppingCart& cart, ProductManage& productManage) {
    if (cart.getItems().empty()) {
        return false;
    }

    // 1. Kiểm tra tồn kho của tất cả sản phẩm
    for (const auto& item : cart.getItems()) {
        if (item.getProduct() == nullptr) return false;
        Product* p = productManage.findProductById(item.getProduct()->getId());
        if (p == nullptr || item.getQuantity() > p->getStock()) {
            return false;
        }
    }

    // 2. Tạo OrderItem và trừ stock
    std::vector<OrderItem> orderItems;
    for (const auto& item : cart.getItems()) {
        Product* p = productManage.findProductById(item.getProduct()->getId());
        
        OrderItem orderItem(p->getId(), p->getName(), p->calculateFinalPrice(), item.getQuantity()); // chỉnh sửa p->getPrice thành p->calculateFinalPrice vì lấy giá bán cuối
        orderItems.push_back(orderItem);

        p->setStock(p->getStock() - item.getQuantity());
    }

    productManage.saveProducts("data/products.txt");

    // 3. Tạo đơn hàng Order
    std::string orderId = generateOrderId();
    Order order(orderId, customer, customer.getAddress(), orderItems);
    order.calculateTotal();

    // 4. Ghi file OrderHistory.txt
    std::ofstream file("data/OrderHistory.txt", std::ios::app);
    if (file.is_open()) {
        file << order.getOrderId() << "|"
             << order.getOrderDate() << "|"
             << customer.getName() << "|"
             << customer.getPhone() << "|"
             << customer.getEmail() << "|"
             << customer.getAddress() << "|";

        for (size_t i = 0; i < orderItems.size(); ++i) {
            const auto& it = orderItems[i];
            file << it.getProductId() << ","
                 << it.getProductName() << ","
                 << it.getFinalPrice() << ","
                 << it.getQuantity() << ","
                 << it.getSubtotal();
            if (i + 1 < orderItems.size()) {
                file << ";";
            }
        }

        file << "|" << order.getShippingFee() << "|"
             << order.getTotalPayment() << "|"
             << order.getExpectedDeliveryDate() << "\n";
        file.close();
    }

    orders.push_back(order);
    cart.clear();

    return true;
}

void OrderManage::displayOrderHistory() const {
    std::ifstream file("data/OrderHistory.txt");
    if (!file.is_open()) {
        std::cout << "Chua co lich su don hang!\n";
        return;
    }

    std::string line;
    std::cout << "\n=================== LICH SU DON HANG ===================\n";
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string orderId, date, name, phone, email, address, itemsStr, shipFee, total, deliveryDate;

        std::getline(ss, orderId, '|');
        std::getline(ss, date, '|');
        std::getline(ss, name, '|');
        std::getline(ss, phone, '|');
        std::getline(ss, email, '|');
        std::getline(ss, address, '|');
        std::getline(ss, itemsStr, '|');
        std::getline(ss, shipFee, '|');
        std::getline(ss, total, '|');
        std::getline(ss, deliveryDate, '|');

        std::time_t orderDate = std::stoll(date);

        std::cout << "Ma DH: " << orderId
            << " | Ngay dat: "
            << formatOrderHistoryDate(orderDate)
            << "\n";
        std::cout << "Khach hang: " << name << " - " << phone << " (" << address << ")\n";
        std::cout << "Danh sach san pham:\n";

        std::stringstream itemsSS(itemsStr);
        std::string itemToken;
        while (std::getline(itemsSS, itemToken, ';')) {
            std::stringstream itemBuf(itemToken);
            std::string pId, pName, pPrice, pQty, pSubtotal;
            std::getline(itemBuf, pId, ',');
            std::getline(itemBuf, pName, ',');
            std::getline(itemBuf, pPrice, ',');
            std::getline(itemBuf, pQty, ',');
            std::getline(itemBuf, pSubtotal, ',');

            std::cout << "  + [" << pId << "] " << pName
                << " x" << pQty
                << " (Gia: " << std::stod(pPrice)
                << " -> Thanh tien: " << std::stod(pSubtotal) << ")\n";
        }
        std::cout << std::fixed << std::setprecision(0);

        std::cout << "Phi ship: " << std::stod(shipFee)
            << " | Tong thanh toan: " << std::stod(total) << "\n";

        std::time_t expectedDeliveryDate = std::stoll(deliveryDate);
        std::cout << "Ngay giao du kien: "
            << formatOrderHistoryDate(expectedDeliveryDate)
            << "\n";
        std::cout << "--------------------------------------------------------\n";
    }
    file.close();
}
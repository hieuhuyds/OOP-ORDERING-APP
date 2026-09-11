#include "Customer.h"
Customer::Customer(std::string name, std::string phone, std::string email, std::string address)
    : name(name), phone(phone), email(email), address(address)
{
}

// Getter
std::string Customer::getName() const {
    return name;
}

std::string Customer::getPhone() const {
    return phone;
}

std::string Customer::getEmail() const {
    return email;
}

std::string Customer::getAddress() const {
    return address;
}

// Setter
void Customer::setName(std::string newName) {
    name = newName;
}

void Customer::setPhone(std::string newPhone) {
    phone = newPhone;
}

void Customer::setEmail(std::string newEmail) {
    email = newEmail;
}

void Customer::setAddress(std::string newAddress) {
    address = newAddress;
}

// Nhập thông tin
void Customer::input() {
    std::cout << "Full Name: ";
    getline(std::cin >> std::ws, name);

    std::cout << "Phone Number: ";
    getline(std::cin, phone);

    std::cout << "Email: ";
    getline(std::cin, email);

    std::cout << "Address: ";
    getline(std::cin, address);
}

// Hiển thị thông tin
void Customer::display() const {
    std::cout << "Full Name: " << name << std::endl;
    std::cout << "Phone Numer: " << phone << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Address: " << address << std::endl;
}
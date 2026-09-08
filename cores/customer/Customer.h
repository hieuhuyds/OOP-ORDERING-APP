#pragma once
#include <string>
#include <iostream>
#include <string>

class Customer
{
private:
    std::string name;
    std::string phone;
    std::string email;
    std::string address;

public:
    Customer(std::string name = "", std::string phone = "", std::string email = "", std::string address = "");

    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;
    std::string getAddress() const;

    void setName(std::string newName);
    void setPhone(std::string newPhone);
    void setEmail(std::string newEmail);
    void setAddress(std::string newAddress);

    void input();
    void display() const;
};

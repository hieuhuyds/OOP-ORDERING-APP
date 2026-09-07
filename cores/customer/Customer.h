#pragma once
#include <iostream>
#include <string>

using namespace std;

class Customer 
{
private:
    string name;
    string phone;
    string email;
    string address;

public:
    Customer(string name = "", string phone = "", string email = "", string address = "");

    string getName() const;
    string getPhone() const;
    string getEmail() const;
    string getAddress() const;

    void setName(string newName);
    void setPhone(string newPhone);
    void setEmail(string newEmail);
    void setAddress(string newAddress);

    void input();
    void display() const;
};

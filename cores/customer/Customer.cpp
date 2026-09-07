#include "Customer.h"

using namespace std;

Customer::Customer(string name, string phone, string email, string address)
    : name(name), phone(phone), email(email), address(address)
{
}

// Getter
string Customer::getName() const {
    return name;
}

string Customer::getPhone() const {
    return phone;
}

string Customer::getEmail() const {
    return email;
}

string Customer::getAddress() const {
    return address;
}

// Setter
void Customer::setName(string newName) {
    name = newName;
}

void Customer::setPhone(string newPhone) {
    phone = newPhone;
}

void Customer::setEmail(string newEmail) {
    email = newEmail;
}

void Customer::setAddress(string newAddress) {
    address = newAddress;
}

// Nhập thông tin
void Customer::input() {
    cout << "Nhap Name: ";
    getline(cin >> ws, name);

    cout << "Nhap Phone: ";
    getline(cin, phone);

    cout << "Nhap Email: ";
    getline(cin, email);

    cout << "Nhap Address: ";
    getline(cin, address);
}

// Hiển thị thông tin
void Customer::display() const {
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;
    cout << "Address: " << address << endl;
}
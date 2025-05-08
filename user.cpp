#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "restaurant.h"

using namespace std;

class User {
public:
    string username;
    string password;  // Added password field
    string address;
    vector<pair<Restaurant, vector<FoodItem>>> orderHistory;

    User(string uname, string pass, string addr) : username(uname), password(pass), address(addr) {}

    void addToHistory(const Restaurant& rest, const vector<FoodItem>& items) {
        orderHistory.emplace_back(rest, items);
    }

    void displayHistory() const {
        cout << "\n=== Order History for " << username << " ===" << endl;
        for (const auto& order : orderHistory) {
            cout << "Restaurant: " << order.first.name << endl;
            cout << "Items ordered:" << endl;
            for (const auto& item : order.second) {
                cout << "  - " << item.name << " ($" << item.price << ")" << endl;
            }
            cout << "---------------------" << endl;
        }
    }
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

User* registerUser(vector<User>& users) {
    string username, password, address;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password (at least 6 characters): ";
    getline(cin, password);

    if (password.length() < 6) {
        cout << "Password must be at least 6 characters long!" << endl;
        return nullptr;
    }

    cout << "Enter delivery address: ";
    getline(cin, address);

    users.emplace_back(username, password, address);
    cout << "Registration successful!" << endl;

    return &users.back();
}

User* loginUser(const vector<User>& users) {
    string username, password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    for (auto& user : users) {
        if (user.username == username && user.password == password) {
            cout << "Login successful!" << endl;
            return &user;
        }
    }
    cout << "Invalid username or password!" << endl;
    return nullptr;
}
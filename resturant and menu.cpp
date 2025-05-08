#include <iostream>
#include <vector>
#include "food_item.h"

using namespace std;

// Class to represent a restaurant
class Restaurant {
public:
    string name;
    string cuisine;
    vector<FoodItem> menu;

    Restaurant(string n, string c) : name(n), cuisine(c) {}

    void addFoodItem(const FoodItem& item) {
        menu.push_back(item);
    }

    void displayMenu() const {
        cout << "\n=== " << name << " (" << cuisine << ") Menu ===" << endl;
        for (size_t i = 0; i < menu.size(); ++i) {
            cout << i + 1 << ". " << menu[i].name 
                 << " - $" << menu[i].price << "\n   "
                 << menu[i].description << endl;
        }
    }
};
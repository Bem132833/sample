#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

#include <string>
using namespace std;

class FoodItem {
public:
    string name;
    double price;
    string description;

    FoodItem(string n, double p, string d) : name(n), price(p), description(d) {}

    void display() const {
        cout << name << " - $" << price << "\n   " << description << endl;
    }
};

#endif
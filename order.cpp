#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "user_info.cpp"
#include "restaurant.cpp"

using namespace std;

int estimateDeliveryTime() {
    return 20 + rand() % 41; // Random time between 20 and 60
}

int main() {
    srand(time(0)); // Seed random for delivery time

    vector<Restaurant> restaurants;
    vector<User> users;
    User* currentUser = nullptr;

    // Create restaurants
    Restaurant r1("KK Restaurant", "Ethiopian");
    r1.addFoodItem(FoodItem("Doro Wot", 12.99, "Spicy chicken stew with boiled eggs"));
    r1.addFoodItem(FoodItem("Tibs", 10.99, "Sautéed beef with onions and spices"));
    r1.addFoodItem(FoodItem("Shiro", 8.99, "Chickpea flour stew with berbere spice"));
    restaurants.push_back(r1);

    Restaurant r2("Kibnesh", "Ethiopian");
    r2.addFoodItem(FoodItem("Kitfo", 14.99, "Minced beef with mitmita spice"));
    r2.addFoodItem(FoodItem("Firfir", 9.99, "Shredded injera with spicy sauce"));
    r2.addFoodItem(FoodItem("Vegetable Combo", 11.99, "Assorted vegetarian dishes"));
    restaurants.push_back(r2);

    Restaurant r3("Teachers Lounge", "International");
    r3.addFoodItem(FoodItem("Spaghetti Bolognese", 10.49, "Classic Italian pasta with meat sauce"));
    r3.addFoodItem(FoodItem("Chicken Curry", 11.99, "Indian-style curry with rice"));
    r3.addFoodItem(FoodItem("Greek Salad", 8.99, "Fresh vegetables with feta cheese"));
    restaurants.push_back(r3);

    Restaurant r4("Workers Cafe", "Fast Food");
    r4.addFoodItem(FoodItem("Cheeseburger", 6.99, "Classic beef burger with cheese"));
    r4.addFoodItem(FoodItem("Chicken Sandwich", 7.49, "Crispy chicken fillet with mayo"));
    r4.addFoodItem(FoodItem("French Fries", 3.99, "Golden crispy potatoes"));
    restaurants.push_back(r4);

    while (true) {
        cout << "\n===== Online Food Ordering System =====" << endl;
        if (currentUser) {
            cout << "Logged in as: " << currentUser->username << endl;
            cout << "1. Browse Restaurants\n2. View Order History\n3. Logout\n4. Exit\n";
        } else {
            cout << "1. Register\n2. Login\n3. Browse Restaurants (Guest)\n4. Exit\n";
        }

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        clearInput();

        if (currentUser) {
            switch (choice) {
                case 1: { // Browse Restaurants
                    cout << "\nAvailable Restaurants:" << endl;
                    for (size_t i = 0; i < restaurants.size(); ++i) {
                        cout << i + 1 << ". " << restaurants[i].name << " (" << restaurants[i].cuisine << ")" << endl;
                    }

                    int restChoice;
                    cout << "Select a restaurant (0 to cancel): ";
                    cin >> restChoice;
                    clearInput();

                    if (restChoice > 0 && restChoice <= static_cast<int>(restaurants.size())) {
                        Restaurant& selectedRest = restaurants[restChoice - 1];
                        selectedRest.displayMenu();

                        vector<FoodItem> cart;
                        while (true) {
                            cout << "\nEnter item number to add to cart (0 to finish): ";
                            int itemChoice;
                            cin >> itemChoice;
                            clearInput();

                            if (itemChoice == 0) break;
                            if (itemChoice > 0 && itemChoice <= static_cast<int>(selectedRest.menu.size())) {
                                cart.push_back(selectedRest.menu[itemChoice - 1]);
                                cout << "Added " << selectedRest.menu[itemChoice - 1].name << " to cart." << endl;
                            } else {
                                cout << "Invalid choice!" << endl;
                            }
                        }
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip> 

using namespace std;

struct Item {
    string name;
    double price;
};

struct CartItem {
    Item item;
    int quantity;
};

void showItems(const vector<Item>& items) {
    cout << "\nAvailable items:\n";
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i].name << " - $"
             << fixed << setprecision(2) << items[i].price << '\n';
    }
}

int getValidatedIntInput(const string& prompt, int min, int max) {
    int input;
    while (true) {
        cout << prompt;
        if (cin >> input && input >= min && input <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        } else {
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void addToCart(vector<CartItem>& cart, const Item& item, int quantity) {
    for (auto& cartItem : cart) {
        if (cartItem.item.name == item.name) {
            cartItem.quantity += quantity;
            return;
        }
    }
    cart.push_back({item, quantity});
}

void showCart(const vector<CartItem>& cart) {
    if (cart.empty()) {
        cout << "\nYour cart is empty.\n";
        return;
    }
    double total = 0;
    cout << "\nYour cart:\n";
    for (size_t i = 0; i < cart.size(); ++i) {
        const auto& cartItem = cart[i];
        double cost = cartItem.item.price * cartItem.quantity;
        cout << i + 1 << ". " << cartItem.item.name << " x " << cartItem.quantity << " = $"
             << fixed << setprecision(2) << cost << '\n';
        total += cost;
    }
    cout << "Total so far: $" << fixed << setprecision(2) << total << "\n";
}

void updateCartItem(vector<CartItem>& cart) {
    if (cart.empty()) {
        cout << "\nYour cart is empty. Nothing to update.\n";
        return;
    }
    showCart(cart);
    int itemIndex = getValidatedIntInput("Select the item number to update quantity (0 to cancel): ", 0, (int)cart.size());
    if (itemIndex == 0) return;

    int newQty = getValidatedIntInput("Enter new quantity (0 to remove): ", 0, 1000);

    if (newQty == 0) {
        cart.erase(cart.begin() + itemIndex - 1);
        cout << "Item removed from cart.\n";
    } else {
        cart[itemIndex - 1].quantity = newQty;
        cout << "Quantity updated.\n";
    }
}

void clearCart(vector<CartItem>& cart) {
    cart.clear();
    cout << "\nCart has been cleared.\n";
}

void cartManagementMenu(vector<CartItem>& cart) {
    while (true) {
        cout << "\nCart Management Menu:\n"
             << "1. View cart\n"
             << "2. Update item quantity\n"
             << "3. Clear cart\n"
             << "4. Return to main menu\n";

        int choice = getValidatedIntInput("Choose an option: ", 1, 4);

        if (choice == 1) {
            showCart(cart);
        } else if (choice == 2) {
            updateCartItem(cart);
        } else if (choice == 3) {
            clearCart(cart);
        } else if (choice == 4) {
            break;
        }
    }
}

void showMenu() {
    cout << "\nMenu:\n"
         << "1. Shop for items\n"
         << "2. View/manage cart\n"
         << "3. Checkout and exit\n";
}

int main() {
    vector<Item> items = {
        {"Apple", 0.99},
        {"Banana", 0.59},
        {"Orange", 0.79},
        {"Milk", 2.49},
        {"Bread", 1.99}
    };
    vector<CartItem> cart;

    cout << "Welcome to the Simple Shop!\n";

    while (true) {
        showMenu();
        int choice = getValidatedIntInput("Choose an option: ", 1, 3);

        if (choice == 1) {
            showItems(items);
            int itemChoice = getValidatedIntInput("Select item number to buy (0 to cancel): ", 0, (int)items.size());
            if (itemChoice == 0) continue;
            int qty = getValidatedIntInput("Enter quantity: ", 1, 1000);
            addToCart(cart, items[itemChoice - 1], qty);
            cout << qty << " x " << items[itemChoice - 1].name << " added to cart.\n";
        }
        else if (choice == 2) {
            cartManagementMenu(cart);
        }
        else if (choice == 3) {
            showCart(cart);
            cout << "Thank you for shopping! Goodbye.\n";
            break;
        }
    }
    return 0;
}

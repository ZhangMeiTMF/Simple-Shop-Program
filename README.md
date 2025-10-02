# 🛒 Simple Shop (C++ Console Application)

This is a basic C++ console application that simulates a simple shopping experience. Users can browse items, add them to a cart, manage the cart, and proceed to checkout.

---

## 📋 Features

- ✅ Browse available items with names and prices  
- 🛍️ Add items to cart with specified quantity  
- 🧺 View cart contents with total cost  
- ✏️ Update item quantities or remove them from the cart  
- ❌ Clear the cart entirely  
- 💸 Checkout with final summary  
- 📎 Input validation to prevent crashes from invalid user input

---

## 🧱 Technologies Used

- Language: **C++**
- Libraries: Standard C++ Libraries (`iostream`, `vector`, `string`, `iomanip`, etc.)

---

## 🚀 How to Run

### 1. **Clone or Download the Repository**
```bash
git clone https://github.com/yourusername/simpleshop-cpp.git
cd simpleshop-cpp
```

### 2. **Compile the Program**

You can use any C++ compiler. Here's an example with `g++`:

```bash
g++ -o SimpleShop main.cpp
```

### 3. **Run the Program**

```bash
./SimpleShop
```

---

## 📸 Sample Output

```
Welcome to the Simple Shop!

Menu:
1. Shop for items
2. View/manage cart
3. Checkout and exit
Choose an option: 1

Available items:
1. Apple - $0.99
2. Banana - $0.59
...
Select item number to buy (0 to cancel): 1
Enter quantity: 3
3 x Apple added to cart.
```

---

## 🧠 Code Structure

- `Item` — structure to store item name and price
- `CartItem` — structure for items added to the cart with quantity
- `showItems()` — displays available items
- `addToCart()` — adds items to the cart
- `showCart()` — displays cart contents and total
- `updateCartItem()` — allows editing or removing items from cart
- `clearCart()` — clears all cart contents
- `cartManagementMenu()` — cart options (view, update, clear)
- `main()` — handles program flow and user interaction

---

## 🔧 Future Improvements

- Add support for saving/loading cart from a file
- Add category filtering or search
- Add discounts or tax calculation
- Improve UI with colors (using libraries like `ncurses` or `termcolor`)

---

## 🧑‍💻 Author

**Your Name**  
Feel free to reach out or open issues for improvements or feedback!

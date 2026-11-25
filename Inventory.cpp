


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Product {
public:
    string id, name;
    double price;
    int quantity, minimumStock;

    Product(string i, string n, double p, int q, int m) {
        id = i;
        name = n;
        price = p;
        quantity = q;
        minimumStock = m;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct() {
        string id, name;
        double price;
        int quantity, minimum;

        cout << "Enter product ID: ";
        cin >> id;

        for (const auto& p : products) {
            if (p.id == id) {
                cout << "Product ID already exists!\n";
                return;
            }
        }

        cout << "Enter product name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter price (BZD): ";
        cin >> price;

        cout << "Enter quantity: ";
        cin >> quantity;

        cout << "Enter minimum stock: ";
        cin >> minimum;

        if (price <= 0 || quantity < 0 || minimum < 0) {
            cout << "Invalid information!\n";
            return;
        }

        products.push_back(Product(id, name, price, quantity, minimum));
        cout << "Product added successfully!\n";
    }

    void viewProducts() {
        if (products.empty()) {
            cout << "No products available.\n";
            return;
        }

        for (const auto& p : products) {
            cout << "\nID: " << p.id;
            cout << "\nName: " << p.name;
            cout << "\nPrice: BZD $" << fixed << setprecision(2) << p.price;
            cout << "\nQuantity: " << p.quantity;
            cout << "\nMinimum Stock: " << p.minimumStock << "\n";
        }
    }

    void searchProduct() {
        string id;
        cout << "Enter product ID: ";
        cin >> id;

        for (const auto& p : products) {
            if (p.id == id) {
                cout << "Product found!\n";
                cout << "Name: " << p.name << "\n";
                cout << "Price: BZD $" << p.price << "\n";
                cout << "Quantity: " << p.quantity << "\n";
                return;
            }
        }

        cout << "Product not found.\n";
    }

    void restockProduct() {
        string id;
        int amount;

        cout << "Enter product ID: ";
        cin >> id;

        for (auto& p : products) {
            if (p.id == id) {
                cout << "Enter quantity to add: ";
                cin >> amount;

                if (amount <= 0) {
                    cout << "Invalid quantity.\n";
                    return;
                }

                p.quantity += amount;
                cout << "Stock updated successfully!\n";
                return;
            }
        }

        cout << "Product not found.\n";
    }

    void recordSale() {
        string id;
        int amount;

        cout << "Enter product ID: ";
        cin >> id;

        for (auto& p : products) {
            if (p.id == id) {
                cout << "Enter quantity sold: ";
                cin >> amount;

                if (amount <= 0 || amount > p.quantity) {
                    cout << "Invalid quantity or insufficient stock.\n";
                    return;
                }

                p.quantity -= amount;

                cout << "Sale completed!\n";
                cout << "Total: BZD $" << fixed << setprecision(2)
                     << p.price * amount << "\n";
                return;
            }
        }

        cout << "Product not found.\n";
    }

    void lowStock() {
        bool found = false;

        cout << "\n--- LOW STOCK PRODUCTS ---\n";

        for (const auto& p : products) {
            if (p.quantity <= p.minimumStock) {
                cout << p.name << " - Quantity: " << p.quantity << "\n";
                found = true;
            }
        }

        if (!found)
            cout << "No low-stock products.\n";
    }

    void inventorySummary() {
        int totalUnits = 0;
        double totalValue = 0;

        for (const auto& p : products) {
            totalUnits += p.quantity;
            totalValue += p.price * p.quantity;
        }

        cout << "\n--- INVENTORY SUMMARY ---\n";
        cout << "Total products: " << products.size() << "\n";
        cout << "Total units: " << totalUnits << "\n";
        cout << "Inventory value: BZD $" << fixed
             << setprecision(2) << totalValue << "\n";
    }
};

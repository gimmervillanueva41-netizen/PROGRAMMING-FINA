
#include <iostream>
#include "Inventory.cpp"
using namespace std;

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\n===== ABC MINI MART =====\n";
        cout << "1. Add Product\n";
        cout << "2. View All Products\n";
        cout << "3. Search Product\n";
        cout << "4. Restock Product\n";
        cout << "5. Record Sale\n";
        cout << "6. View Low Stock\n";
        cout << "7. Inventory Summary\n";
        cout << "8. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.addProduct();
                break;

            case 2:
                inventory.viewProducts();
                break;

            case 3:
                inventory.searchProduct();
                break;

            case 4:
                inventory.restockProduct();
                break;

            case 5:
                inventory.recordSale();
                break;

            case 6:
                inventory.lowStock();
                break;

            case 7:
                inventory.inventorySummary();
                break;

            case 8:
                cout << "Thank you for using ABC Mini Mart!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 8);

    return 0;
}

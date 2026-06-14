#include "Menu.h"
#include <iostream>
using namespace std;
void SupermarketMenu(Supermarket& supermarket)
{
    while (true)
    {
        int choice = -1;

        cout << R"( 
==================== SUPERMARKET MENU ====================

                [0] - EXIT

                PRODUCTS

    [1] - View all products   [2] - Add product
    
    [3] - Remove product      [4] - Sell product
    
                SEARCH

       [5] - Search product by name

===========================================================

Enter your choice --> )";

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << " -- EXIT MENU -- " << endl;
            return;

        case 1:
            supermarket.printAllProducts();
            break;

        case 2:
        {
            AddProductMenu(supermarket);
            break;
        }

        case 3:
        {
            string name;
            cout << "Enter product name to remove: ";
            cin >> name;
            supermarket.removeProduct(name);
            break;
        }

        case 4:
        {
            string name;
            int quantity;
            cout << "Enter product name to sell: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> quantity;
            supermarket.sellProduct(name, quantity);
            break;
        }

        case 5:
        {
            string name;
            cout << "Enter product name to search: ";
            cin >> name;
            supermarket.PrintFindName(name);
            break;
        }

        default:
            cout << "Error !!!  Invalid choice -->  Try again !!!" << endl;
        }
    }
}

void AddProductMenu(Supermarket& supermarket)
{
    while (true)
    {
        int choice = -1;

        cout << R"( 
==================== ADD PRODUCT MENU ====================

                [0] - BACK

                CHOOSE PRODUCT TYPE

    [1] - Add FOOD product
    [2] - Add INDUSTRIAL product

===========================================================

Enter your choice: )";

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << " --EXIT MENU ADD_Product-- " << endl;
            return;

        case 1:
        {
            string name, expiration;
            double price;
            int quantity, category;

            cout << "\nEnter FOOD product name: ";
            cin.ignore();
            getline(cin, name);
            for (char& c : name)
                if (c == ' ') c = '_';

            cout << "Enter price: ";
            cin >> price;

            cout << "Enter quantity: ";
            cin >> quantity;

            cout << R"( 
        Choose FOOD category:

        [0] - NONE_CATEGORY_FOOD
        [1] - DAIRY
        [2] - BAKERY
        [3] - MEAT
        [4] - CONFECTIONERY
        [5] - FRUITS & VEGGIES

 Enter category number: )";
            cin >> category;

            cout << "Enter expiration date (YYYY-MM-DD): ";
            cin >> expiration;

            supermarket.addProduct(new FoodProduct(name, price, quantity, (FoodCategory)category, expiration));
          
            cout << "\nFood product added!\n";
            break;
        }

        case 2:
        {
            string name, manufacturer;
            double price;
            int quantity, category;

            cout << "\nEnter INDUSTRIAL product name: ";
            cin.ignore();
            getline(cin, name);
            for (char& c : name)
                if (c == ' ') c = '_';

            cout << "Enter price: ";
            cin >> price;

            cout << "Enter quantity: ";
            cin >> quantity;

            cout << R"( 
            Choose INDUSTRIAL category:

        [0] - NONE_CATEGORY
        [1] - ELECTRONICS
        [2] - CHEMICALS
        [3] - TEXTILE
        [4] - TOYS
        [5] - FRUITS_VEGGIES


Enter category number: )";
            cin >> category;

            cout << "Enter manufacturer (Ukraine / Import): ";
            cin >> manufacturer;

            bool isUkr = (manufacturer == "Ukraine");

            supermarket.addProduct(new IndustrialProduct(name, price, quantity, (IndustrialCategory)category, isUkr));
          
            cout << "\nIndustrial product added!\n";
            break;
        }

        default:
            cout << "Error !!!  Invalid choice -->  Try again !!!" << endl;
        }
    }

}

// 1_OOP_C++_Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Product.h"
#include "FoodProduct.h"
#include "IndustrialProduct.h"
#include "Supermarket.h"
#include "Menu.h"
using namespace std;




int main()
{
    // Створюємо кілька товарів
    //FoodProduct milk("Milk", 32.5, 10, DAIRY, "2025-06-01");
    //FoodProduct bread("Bread", 18.0, 5, BAKERY, "2025-05-20");

    //IndustrialProduct laptop("Laptop", 25000, 2, ELECTRONICS, false);
    //IndustrialProduct soap("Soap", 25, 30, CHEMICALS, true);

    //// Демонстрація виводу
    //cout << "=== FOOD PRODUCTS ===" << endl;
    //milk.print();
    //cout << endl;

    //bread.print();
    //cout << endl;

    //cout << "=== INDUSTRIAL PRODUCTS ===" << endl;
    //laptop.print();
    //cout << endl;

    //soap.print();
    //cout << endl;

    // //Показати загальну кількість товарів у супермаркеті
    //cout << "=== TOTAL QUANTITY IN SUPERMARKET ===" << endl;
    //cout <<"\t\t" << Product::getTotalQuantity() << endl;

    // ------------------------------------- 
    cout<<"----- Supermarket -----" << endl;
    Supermarket careffur;

    //careffur.addProduct(new FoodProduct("Milk", 32.5, 10, DAIRY, "2025-06-01"));
    //careffur.addProduct(new IndustrialProduct("Laptop", 25000, 2, ELECTRONICS, false));
    //careffur.addProduct(new  FoodProduct ("Bread", 18.0, 5, BAKERY, "2025-05-20"));
    //   
    //careffur.writeToFileSupermarket("supermarket.txt");
    
    
    careffur.readFromFileSupermarket("supermarket.txt");
    
    
    //careffur.printAllProducts();
    

    //
    //
    //careffur.addProduct(new  IndustrialProduct("Soap", 25, 30, CHEMICALS, true));

    //careffur.readFromFileSupermarket("supermarket.txt");
    //
    //careffur.addProduct(new FoodProduct("Cheese", 18.0, 10, DAIRY, "2025-06-20"));
    //careffur.addProduct(new FoodProduct("Cheese", 18.0, 5, DAIRY, "2025-06-20"));

    //careffur.addProduct(new  IndustrialProduct("SoapMentol", 25, 10, CHEMICALS, true));
    //careffur.printAllProducts();
    //careffur.printProductsByCategories();
    //careffur.PrintFindName("Cheese");
    //careffur.removeProduct("Cheese");
    //careffur.addProduct(new FoodProduct("Cheese", 18.0, 10, DAIRY, "2025-06-20"));
    //careffur.sellProduct("Cheese", 2);
   
    //careffur.printAllProducts();


    SupermarketMenu(careffur);



}



#pragma once
#include <vector>
#include <string>
#include "Product.h"
#include "FoodProduct.h"
#include "IndustrialProduct.h"

class Supermarket
{
public:
    // --- БАЗОВІ ОПЕРАЦІЇ ---
    // 1 Додавання  продукту(товару) у базу(врахувати, що товар  у базі може бути наявний або ні )
    void addProduct(Product* product); 

    // 2  Збереження бази товарів( у файл)
    void writeToFileSupermarket(const string& filename) const; 

    // 3 Завантаження бази товарів з файлу
    void readFromFileSupermarket(const string& filename);


    // 4 Перегляд  продуктів(товарів)
    void printAllProducts() const;

    // 5 Перегляд  продуктів(товарів) по категоріях
    void printProductsByCategories() const;

    // 6 Пошук товару з видачею інфо поро товар
    void PrintFindName(const string& name) const;

    // 6* Пошук товару для роботи з ним 
    Product* findProduct(const string& name);
   
    // 7 Видалення за назвою
    void removeProduct(const string& name); 
        // Пошук товару

    // 8 для друк чек
    void printReceipt(const Product* p, int quantity) const;
    // 8_ продаж
    void sellProduct(const string& name, int quantity); 
    
private:
	vector<Product*> products;
};


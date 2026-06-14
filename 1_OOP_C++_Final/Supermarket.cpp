#include "Supermarket.h"
#include "fstream"
int Product::totalQuantity = 0;


// 1 Додавання  продукту(товару) у базу(врахувати, що товар  у базі може бути наявний або ні )
void Supermarket::addProduct(Product* product)
{
    
    for (auto& p : products)
    {
        if (p->getName() == product->getName())
        {
            p->setQuantity(p->getQuantity() + product->getQuantity());
            delete product; // бо не додаєм новий щоб не було витоку
            writeToFileSupermarket("supermarket.txt");
            return;
        }
    }
    products.push_back(product);
    writeToFileSupermarket("supermarket.txt");

}

// 2 Збереження бази товарів( у файл)
void Supermarket::writeToFileSupermarket(const string& filename) const
{
    fstream file(filename, ios::out);
    if (!file.is_open())
    {
        cout << "Error opening file for write" << endl;
        return;
    }

    for (auto p : products)
    {
        // FoodProduct
        if (auto fp = dynamic_cast<FoodProduct*>(p))
        {
            file << "Food " << fp->getName() << " " << fp->getPrice() << " " << fp->getQuantity() << " " << fp->getCategory() << " " << fp->getExpirationDate() << "\n";
                
        }
        // IndustrialProduct
        else if (auto ip = dynamic_cast<IndustrialProduct*>(p))
        {
            file << "Industrial " << ip->getName() << " " << ip->getPrice() << " " << ip->getQuantity() << " " << ip->getCategory() << " " << (ip->getIsUkrainian() ? "Ukraine" : "Import") << "\n";
                
        }
    }
    // cout << " write is OK " << endl;
}

// 3 Завантаження бази товарів з файлу
void Supermarket::readFromFileSupermarket(const string& filename)
{
    fstream file(filename, ios::in);
    if (!file.is_open())
    {
        cout << "Error file not found !!! " << endl;
        return;
    }
    for (auto p : products)
        delete p;
    products.clear();
    Product::totalQuantity = 0;
    string type;
    while (file >> type)
    {
        if (type == "Food")
        {
            string name, expiration;
            double price;
            int quantity, category;

            file >> name >> price >> quantity >> category >> expiration;

            products.push_back(
                new FoodProduct(name, price, quantity, (FoodCategory)category, expiration)
            );
        }
        else if (type == "Industrial")
        {
            string name, manufacturer;
            double price;
            int quantity, category;

            file >> name >> price >> quantity >> category >> manufacturer;

            bool isUkr = (manufacturer == "Ukraine");

            products.push_back(
                new IndustrialProduct(name, price, quantity, (IndustrialCategory)category, isUkr)
            );
        }
    }

    cout << " read is OK " << endl;
}

// 4 Перегляд  продуктів(товарів)
void Supermarket::printAllProducts() const
{
    if (products.empty())
    {
        cout << "Supermarket is empty!" << endl;
        return;
    }

    cout << "\n=== ALL PRODUCTS IN SUPERMARKET ===\n";

    for (auto& p : products)
    {
        p->print();  
        cout << endl;
    }

    cout << "=== TOTAL QUANTITY IN SUPERMARKET ===" << endl;
    cout <<"\t\t" << Product::getTotalQuantity() << endl;
}

// 5 Перегляд  продуктів(товарів) по категоріях

void Supermarket::printProductsByCategories() const
{
    if (products.empty())
    {
        cout << "Supermarket is empty!" << endl;
        return;
    }

    cout << "\n\t=== PRODUCTS SORTED BY CATEGORIES ===\n";

    cout << "\n\t--- FOOD PRODUCTS ---\n";

    for (int cat = 0; cat <= 4; cat++) 
    {
        cout << "\nCategory " << cat << ":\n";

        for (auto& p : products)
        {
            if (auto fp = dynamic_cast<FoodProduct*>(p))
            {
                if (fp->getCategory() == cat)
                {
                    fp->print();
                    cout << endl;
                }
            }
        }
    }

    cout << "\n\t--- INDUSTRIAL PRODUCTS ---\n";

    for (int cat = 0; cat <= 4; cat++) 
    {
        cout << "\nCategory " << cat << ":\n";

        for (auto& p : products)
        {
            if (auto ip = dynamic_cast<IndustrialProduct*>(p))
            {
                if (ip->getCategory() == cat)
                {
                    ip->print();
                    cout << endl;
                }
            }
        }
    }
    cout << "=== TOTAL QUANTITY IN SUPERMARKET ===" << endl;
    cout << "\t\t" << Product::getTotalQuantity() << endl;
}
// 6 Пошук товару з видачею інфо поро товар
void Supermarket::PrintFindName(const string& name) const
{
    if (products.empty())
    {
        cout << "Supermarket is empty!" << endl;
        return;
    }

    for (auto& p : products)
    {
        if (p->getName() == name)
        {
            cout << "\n=== PRODUCT FOUND ===\n";
            p->print();
            return;
        }
    }

    cout << "\nProduct with name \"" << name << "\" not found.\n";
}

// 6* Пошук товару для роботи з ним 
Product* Supermarket::findProduct(const string& name)
{
    for (auto& p : products)
    {
        if (p->getName() == name)
            return p;
    }
    return nullptr;
}

// 7 Видалення за назвою
void Supermarket::removeProduct(const string& name)
{
    if (products.empty())
    {
        cout << "Supermarket is empty!" << endl;
        return;
    }

    for (size_t i = 0; i < products.size(); i++)
    {
        if (products[i]->getName() == name)
        {
            cout << "Product \"" << name << "\" removed.\n";

            delete products[i]; 
            products.erase(products.begin() + i); 

            writeToFileSupermarket("supermarket.txt");
            return;
        }
    }

    cout << "Product \"" << name << "\" not found.\n";

}
// 8 для друк чек
void Supermarket::printReceipt(const Product* p, int quantity) const
{
    double sum = p->getPrice() * quantity;

    cout << "\n===== RECEIPT =====\n";
    cout << "Product:  " << p->getName() << "\n";
    cout << "Price:    " << p->getPrice() << "\n";
    cout << "Quantity: " << quantity << "\n";
    cout << "----------------------\n";
    cout << "TOTAL:    " << sum << "\n";
    cout << "=====================\n";
}

// 8_ продаж
void Supermarket::sellProduct(const string& name, int quantity)
{
    if (quantity <= 0)
    {
        cout << "Quantity must be positive.\n";
        return;
    }

    Product* p = findProduct(name);

    if (p == nullptr)
    {
        cout << "Product \"" << name << "\" not found.\n";
        return;
    }

    if (p->getQuantity() < quantity)
    {
        cout << "Not enough quantity in stock.\n";
        cout << "Available: " << p->getQuantity() << "\n";
        return;
    }

    printReceipt(p, quantity);
    
    p->setQuantity(p->getQuantity() - quantity);

    if (p->getQuantity() == 0)
    {
        cout << "Product \"" << name << "\" is now out of stock and removed.\n";

        for (size_t i = 0; i < products.size(); i++)
        {
            if (products[i] == p)
            {
                delete products[i];
                products.erase(products.begin() + i);
                break;
            }
        }
    }

    writeToFileSupermarket("supermarket.txt");
}

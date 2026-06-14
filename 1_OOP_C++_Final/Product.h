#pragma once
#include <iostream>
using namespace std;
class Product
{

public:
    Product(const string& name = "NoName", double price = 0.0, int quantity = 0)
    {
        setName(name);
        setPrice(price);
        setQuantity(quantity);
    }

    virtual ~Product()
    {
        totalQuantity -= quantity;
    }

    virtual void print() const = 0;

    
    string getName() const
    { 
        return name;
    }

    double getPrice() const 
    { 
        return price;
    }
    int getQuantity() const
    { 
        return quantity; 
    }

   
    void setName(const string& name)
    {
        if (name.empty())
            throw invalid_argument("Name can not be empty");

        this->name = name;
    }

    void setPrice(double price)
    {
        if (price < 0)
            throw invalid_argument("Price can not be negative");

        this->price = price;
    }

    void setQuantity(int quantity)
    {
        if (quantity < 0)
            throw invalid_argument("Quantity can not be negative");

        this->quantity = quantity;
        totalQuantity += quantity;
    }

    static int getTotalQuantity()
    {
        return totalQuantity;
    }

protected:
    string name;
    double price;
    int quantity;

    static int totalQuantity;
};



#pragma once
#include "Product.h"

enum IndustrialCategory { NONE_CATEGORY_IND, ELECTRONICS, CHEMICALS, TEXTILE, TOYS, STATIONERY };

class IndustrialProduct :
    public Product
{
    friend class Supermarket;
public:
    
    IndustrialProduct(const string& name = "NoName",
        double price = 0.0,
        int quantity = 0,
        IndustrialCategory category = IndustrialCategory::NONE_CATEGORY_IND,
        bool isUkrainianManufacturer = false)
        : Product(name, price, quantity)
    {
        setCategory(category);
        setIsUkrainian(isUkrainianManufacturer);
    }
    void setCategory(IndustrialCategory category)
    {
        if (category >= NONE_CATEGORY_IND && category <= STATIONERY)
            this->category = category;
        else
            this->category = NONE_CATEGORY_IND;
    }
    void setIsUkrainian(bool isUkrainianManufacturer)
    {
        this->isUkrainianManufacturer = isUkrainianManufacturer;
    }

    IndustrialCategory getCategory() const { return category; }
    bool getIsUkrainian() const { return isUkrainianManufacturer; }

    void print() const override
    {
        cout << " Industrial Product :: " << name << endl;
        cout << " Price              :: " << price << endl;
        cout << " Quantity           :: " << quantity << endl;
        cout << " Category           :: " << getCategoryName() << endl;
        cout << " Manufacturer       :: " << (isUkrainianManufacturer ? "Ukraine" : "Import") << endl;
        cout << " ----------------------------------- " << endl;
        //cout << " Total Products     :: " << getTotalQuantity() << endl;
    }


private:
    
    IndustrialCategory category = IndustrialCategory::NONE_CATEGORY_IND;
    bool isUkrainianManufacturer = false;

    string getCategoryName() const
    {
        switch (category)
        {
        case ELECTRONICS: 
            return "Electronics";
        case CHEMICALS:   
            return "Chemicals";
        case TEXTILE:    
            return "Textile";
        case TOYS:       
            return "Toys";
        case STATIONERY:  
            return "Stationery";
        default:         
            return "None";
        }
    }
};


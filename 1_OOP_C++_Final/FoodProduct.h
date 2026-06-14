#pragma once
#include "Product.h"

enum FoodCategory { NONE_CATEGORY_FOOD, DAIRY, BAKERY, MEAT, CONFECTIONERY, FRUITS_VEGGIES };
class FoodProduct
	: public Product
{
	friend class Supermarket;
public:
	FoodProduct(const string& name = "NoName", double price = 0.0, int quantity = 0, FoodCategory category = FoodCategory::NONE_CATEGORY_FOOD, const string& expirationDate = "NoDate")		
		: Product(name, price, quantity)
	{
		setCategory(category);
		setExpirationDate(expirationDate);
	}

	void setCategory(FoodCategory category)
	{
		if (category >= NONE_CATEGORY_FOOD && category <= FRUITS_VEGGIES)
			this->category = category;
		else
			this->category = NONE_CATEGORY_FOOD;

	}

	void setExpirationDate(const string& expirationDate)
	{
		if (expirationDate.empty())
			this->expirationDate = "NoDate";
		else
			this->expirationDate = expirationDate;
	}
	FoodCategory getCategory() const { return category; }
	string getExpirationDate() const { return expirationDate; }

	void print() const override
	{
		cout << " Food Product    :: " << name << endl;
		cout << " Price           :: " << price << endl;
		cout << " Quantity        :: " << quantity << endl;
		cout << " Category        :: " << getCategoryName() << endl;
		cout << " Expiration Date :: " << expirationDate << endl;
		cout << " ---------------------------------- " << endl;
		//cout << " Total Products  :: " << getTotalQuantity() << endl;
	}

private:
	
	FoodCategory category = FoodCategory::NONE_CATEGORY_FOOD;
	string expirationDate = "NoDate";

	string getCategoryName() const
	{
		switch (category)
		{
		case DAIRY:
			return "Dairy";
		case BAKERY:
			return "Bakery";
		case MEAT:
			return "Meat";
		case CONFECTIONERY:
			return "Confectionery";
		case FRUITS_VEGGIES:
			return "Fruits & Veggies";
		default:
			return "None";
		}
	}
};


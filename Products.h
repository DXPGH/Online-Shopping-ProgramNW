#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class Products
{
private:
	string idCode;
	string title;
	string description;
	double price;
	int quantityAvailable;

public:
	Products(string id1, string t1, string d1, double p1, int qa1);
	string getIdCode();
	string getTitle();
	string getDescription();
	double getPrice();
	int getQuantityAvailable();
	void decreaseQuantity();
};
#endif#pragma once

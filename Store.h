#ifndef STORE_H
#define STORE_H
#include <string>
#include "Customer.h"
#include "Product.h"

using namespace std;

class Store {

private:
	vector<Product*> inventory;
	vector<Customer*> members;

public:
	void addProduct(Product* pr);
	void addMember(Customer* c);
	Product* getProductFromID(string);
	Customer* getMemberFromID(string);
	void productSearch(string str);
	void addProductToMemberCart(string pID, string c1ID);
	void checkOutMember(string c1ID);
};
#endif#pragma once
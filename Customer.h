#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include "Product.h"

using namespace std;

class Customer {

private:
	vector<string> cart;
	string name;
	string accountID;
	bool AdminUser;

public:
	Customer(string n, string a, bool pm);
	string getAccountID();
	string getAccountName();
	vector<string> getCart();
	void addProductToCart(string);
	bool isAdminUser();
	void emptyCart();
};
#endif

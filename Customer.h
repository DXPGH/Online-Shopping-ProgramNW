#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include "Product.h"
#include "Login.h"

using namespace std;

class Customer {

private:
	vector<string> cart;
	string accountID;
	bool AdminUser;

public:
	Customer(string a, bool pm);
	string getAccountID();
	vector<string> getCart();
	void addProductToCart(string);
	bool isAdminUser();
	void emptyCart();
};
#endif

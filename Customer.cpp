#include <iostream>
#include <string>
#include "Customer.h" //it will include Customer.hpp file

using namespace std;

Customer::Customer(string cname, string act, bool admin) {
    name = cname;
    accountID = act;
    AdminUser = admin;
}

string Customer::getAccountID() //this method returns the AccountID
{
    return accountID;
}

string Customer::getAccountName() //this method returns the AccountName
{
    return name;
}

vector<string> Customer::getCart() //this method returns Cart
{
    return cart;
}

void Customer::addProductToCart(string PrID) {
    cart.push_back(PrID);
}

bool Customer::isAdminUser() {
    return AdminUser;
}

void Customer::emptyCart() {
    cart.clear();
}
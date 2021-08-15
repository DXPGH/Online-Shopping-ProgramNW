#include <iostream>
#include <string>
#include <algorithm>
#include "Store.h" //it will include the file Store.h
#include "Product.h" //it will include the file Product.h
#include "Customer.h" //it will include the file Customer.h

using namespace std;

string toLowerCase(string str1) //toLowerCase method is used here for string
{
    transform(str1.begin(), str1.end(), str1.begin(), (int(*)(int))tolower);
    return str1;
}

void Store::addProduct(Product* prodt) {
    inventory.push_back(prodt);
}

void Store::addMember(Customer* custr) {
    members.push_back(custr);
}

Product* Store::getProductFromID(string prId) {
    for (int i = 0; i < inventory.size(); i++) {
        if (prId.compare(inventory[i]->getIdCode()) == 0) {
            return inventory[i];
        }
    }
    return NULL;
}

Customer* Store::getMemberFromID(string c1Id) {
    for (int i = 0; i < members.size(); i++) {
        if (c1Id.compare(members[i]->getAccountID()) == 0) {
            return members[i];
        }
    }
    return NULL;
}

void Store::productSearch(string s1) {

    s1 = toLowerCase(s1);

    cout << "***Search Result***" << endl;

    for (int i = 0; i < inventory.size(); i++) {

        string t_title1 = toLowerCase(inventory[i]->getTitle());

        string t_Des1 = toLowerCase(inventory[i]->getDescription());

        if (t_title1.find(s1) != string::npos || t_Des1.find(s1) != string::npos) {
            cout << "\nTitle: " << inventory[i]->getTitle() << ",\nIdCode: " << inventory[i]->getIdCode() << ",\nPrice: $" << inventory[i]->getPrice() << ",\nDescription:" << inventory[i]->getDescription() << endl;
        }
    }
}

void Store::addProductToMemberCart(string prID, std::string c1ID) {
    Product* pr = getProductFromID(prID);
    Customer* c1 = getMemberFromID(c1ID);

    if (pr != NULL && c1 != NULL) {

        if (pr->getQuantityAvailable() > 0) {
            c1->addProductToCart(prID);
        }
        else {
            cout << "Sorry, product " << prID << " is currently out of stock." << endl;
        }
    }
    else {
        if (pr == NULL) {
            cout << "Product " << prID << " not found." << endl;
        }
        if (pr == NULL) {
            cout << "Member " << c1ID << " not found." << endl;
        }
    }
}

void Store::checkOutMember(string c1ID) {

    Customer* c1 = getMemberFromID(c1ID);

    if (c1 == NULL) {
        cout << "Member " << c1ID << " not found." << endl;
    }
    else {
        cout << "\n\n*** Cart for CheckOut *** " << endl;

        vector<string> cart = c1->getCart();
        double subTotal = 0;
        int totalItems = 0;

        for (int i = 0; i < cart.size(); i++) {

            Product* pr = getProductFromID(cart[i]);

            if (pr->getQuantityAvailable() > 0) //condition to check the quatity availability of the product
            {
                cout << "Title: " << pr->getTitle() << ", Price: $" << pr->getPrice() << endl;
                subTotal += pr->getPrice();
                totalItems++;
                pr->decreaseQuantity();
            }
            else {
                cout << "Sorry, product " << cart[i] << ", " << pr->getTitle() << " is no longer available." << endl;
            }
        }

        if (totalItems == 0) {
            cout << "There are no items in the cart." << endl;
            return;
        }
        double shippingCost = (c1->isPremiumMember()) ? 0 : 0.07 * subTotal;
        double final = subTotal + shippingCost;

        cout << "Sub-Total: $" << subTotal << ", \nShipping Cost: $" << shippingCost << ", \nFinal Total Cost: $" << final << endl;
    }
}
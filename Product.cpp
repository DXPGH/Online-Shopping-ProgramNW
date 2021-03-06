#include "Product.h"
#include <iostream>
#include <string>

using namespace std;

Product::Product(string idcde, string ptitle, string des1, double cst, int qnty)
{
	idCode = idcde;
	title = ptitle;
	description = des1;
	price = cst;
	quantityAvailable = qnty;
}

string Product::getIdCode() //this method is used here to get the Idcode of the product.
{
    return idCode;
}

string Product::getTitle() //this method is used here to get the title of the product.
{
    return title;
}

string Product::getDescription() //this method is used here to get the description of the product.
{
    return description;
}

double Product::getPrice() //this method returns price of the product
{
    return price;
}

int Product::getQuantityAvailable() //this method return the avaiable quantity
{
    return quantityAvailable;
}

void Product::decreaseQuantity() //this method decreases the quantity
{
    quantityAvailable--;
}

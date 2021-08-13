#include "Products.h"
#include <iostream>
#include <string>

using namespace std;

Products::Products(string idcde, string ptitle, string des1, double cst, int qnty)
{
	idCode = idcde;
	title = ptitle;
	description = des1;
	price = cst;
	quantityAvailable = qnty;
}

string Products::getIdCode() //this method is used here to get the Idcode of the product.
{
    return idCode;
}

string Products::getTitle() //this method is used here to get the title of the product.
{
    return title;
}

string Products::getDescription() //this method is used here to get the description of the product.
{
    return description;
}

double Products::getPrice() //this method returns price of the product
{
    return price;
}

int Products::getQuantityAvailable() //this method return the avaiable quantity
{
    return quantityAvailable;
}

void Products::decreaseQuantity() //this method decreases the quantity
{
    quantityAvailable--;
}

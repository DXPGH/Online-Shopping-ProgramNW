#include <iostream>
#include "Product.h"
#include "Customer.h"
#include "Store.h" 
#include "Login.h"

using namespace std;

int main()
{

    Customer* c1 = new Customer("TheRock", false); //pass values for customer that is customer name and ID
    Product* pr1 = new Product("1", "GPU 3090", "Very very fast graphics card", 2500, 1); //product 1
    Product* pr2 = new Product("2", "GPU 3080ti", "Faster than 3090", 2600, 2); //product 2
    Product* pr3 = new Product("3", "GPU 3070", "Slower than a 3080ti", 1500, 1); //product 3
    Product* pr4 = new Product("4", "GPU 3060ti", "Slower than a 3070", 1000, 3); //product 4
    Product* pr5 = new Product("5", "GPU 6600xt", "Somewhat same performance as the 3060ti", 375, 14); //product 5
    Product* pr6 = new Product("6", "GPU 6700xt", "Better performance than the 6600xt", 1000, 12); //product 6
    Product* pr7 = new Product("7", "GPU 6800xt", "Even better performance than the 6700xt and very similar to the 3080ti", 1400, 3); //product 7
    Product* pr8 = new Product("8", "Air Can for PC Cleaning", "Can of compressed air perfect for cleaning up your dirty computer", 20, 50); //product 8
    Product* pr9 = new Product("9", "TEST GPU 4060", "Claimed faster than 3060ti", 3000, 1); //product 9
    Product* pr10 = new Product("10", "TEST GPU 3070", "Claimed faster than 3070", 3500, 1); //product 10

    Store* s1 = new Store(); //create a new variable s1

//Add Customer and Products to the new store created s1

    s1->addMember(c1);
    s1->addProduct(pr1);
    s1->addProduct(pr2);
    s1->addProduct(pr3);
    s1->addProduct(pr4);
    s1->addProduct(pr5);
    s1->addProduct(pr6);
    s1->addProduct(pr7);
    s1->addProduct(pr8);
    s1->addProduct(pr9);
    s1->addProduct(pr10);

    User user; //ceate a new variable for user

    user.perform_verify_login(); //Perform login

    int choice, quantity;
    int productcount = 10;
    double price;
    string search, product, id, title, description;

    if (user.loginType == 1) {  //Checks if the login is a Seller/Admin
        Customer* c2 = new Customer(user.usernameInput, true);
        do //The menu for an admin user
        {
            cout << "1. Product Search" << endl << "2. Add Product" << endl << "3. Exit" << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Please input whatever you would like to search for." << endl;
                cin >> search;
                s1->productSearch(search);
                break;
            case 2:
                productcount++;

                if (productcount == 11)
                {
                    cout << "Please input product ID, Title, Description, Price, and Quantity" << endl;
                    cin >> id;
                    cin >> title;
                    cin >> description;
                    cin >> price;
                    cin >> quantity;
                    Product* pr11 = new Product(id, title, description, price, quantity);
                    s1->addProduct(pr11);
                }
                else if (productcount == 12)
                {
                    cout << "Please input product ID, Title, Description, Price, and Quantity" << endl;
                    cin >> id;
                    cin >> title;
                    cin >> description;
                    cin >> price;
                    cin >> quantity;
                    Product* pr12 = new Product(id, title, description, price, quantity);
                    s1->addProduct(pr12);
                }
                else if (productcount == 13)
                {
                    cout << "Please input product ID, Title, Description, Price, and Quantity" << endl;
                    cin >> id;
                    cin >> title;
                    cin >> description;
                    cin >> price;
                    cin >> quantity;
                    Product* pr13 = new Product(id, title, description, price, quantity);
                    s1->addProduct(pr13);
                }
                else if (productcount == 14)
                {
                    cout << "Please input product ID, Title, Description, Price, and Quantity" << endl;
                    cin >> id;
                    cin >> title;
                    cin >> description;
                    cin >> price;
                    cin >> quantity;
                    Product* pr14 = new Product(id, title, description, price, quantity);
                    s1->addProduct(pr14);
                }
                else if (productcount == 15)
                {
                    cout << "Please input product ID, Title, Description, Price, and Quantity" << endl;
                    cin >> id;
                    cin >> title;
                    cin >> description;
                    cin >> price;
                    cin >> quantity;
                    Product* pr15 = new Product(id, title, description, price, quantity);
                    s1->addProduct(pr15);
                }
                else
                {
                    cout << "You have reached the maximum amount of products that can be listed" << endl;
                }
                break;
            case 3:
                cout << "Have a nice day" << endl;
                return 3;
            }
        } while (choice != 3);
    }
    else if (user.loginType == 2 || user.loginType == 3) //Checks if the login is a Customer/Guest
    {
        Customer* c3 = new Customer(user.usernameInput, false);
        do //The menu for Customers/Guests
        {
            cout << "1. Product Search" << endl << "2. Add product to cart" << endl << "3.Empty Cart" << endl << "4. Check out" << endl << "5. Exit" << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Please input whatever you would like to search for." << endl;
                cin >> search;
                s1->productSearch(search);
                break;
            case 2:
                cout << "Please input the product id that you would like to add to your cart" << endl;
                cin >> product;
                s1->addProductToMemberCart(product, c1->getAccountID());
                cout << "You have added an item to your cart\n";
                break;
            case 3:
                c1->emptyCart();
                cout << "Cart has been emptied" << endl;
                break;
            case 4:
                s1->checkOutMember(c1->getAccountID());
                break;
            case 5:
                cout << "Thanks for shopping with us" << endl;
                return 5;
            }
        } while (choice != 5);
    }
    else //If the login in input is not 1-3
    {
    cout << "You logged in incorrectly";
    }
    system("pause");
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Login.h"
#include "Customer.h"

using namespace std;

void User::perform_verify_login() //to verify login
{
    cout << "Which login would you like to access?\n1.Seller\n2.Customer\n3.Guest\n4.Sign Up\n5.Exit\nPlease input menu option number: "; // Login Menu
    cin >> loginType;

    if (loginType == 1) { // Seller Login type

        cout << "Enter your seller username: ";
        cin >> usernameInput;

        int userID = getFile(usernameInput, "userUFile.txt"); // checks the username file for the inputed username 

        if (userID != 0) {  // If the username was found, it is a non-zero integer. This is checked here.

            cout << "Enter password: ";
            cin >> passwordInput;

            int passID = getFile(passwordInput, "userPFile.txt"); // checks the username file for the inputed password

            if (userID == passID) {
                cout << "\nSuccessfully logged into Online Shopping as a seller.\n";
                confirmed = 1;
            }
            else {
                cout << "Invalid password. Please try again.\n";
                perform_verify_login();
            }
        }
        else {
            cout << "Username not found. Please try again.\n";
            perform_verify_login();
        }
    }
    else if (loginType == 2) {

        cout << "Enter your customer username: ";
        cin >> usernameInput;

        int userID = getFile(usernameInput, "userUFile.txt");

        if (userID != 0) {

            cout << "Enter password: ";
            cin >> passwordInput;

            int passID = getFile(passwordInput, "userPFile.txt");

            if (userID == passID) {
                cout << "\nSuccessfully logged into Online Shopping as a customer.\n";
                confirmed = 1;  // confirming user logged in
            }
            else {
                cout << "Invalid password. Please try again.\n";
                perform_verify_login();
            }
        }
        else {
            cout << "Username not found. Please try again.\n";
            perform_verify_login();
        }
    }
    else if (loginType == 3) {  // guest signed in
        cout << "Successfully logged into Online Shopping as a guest.\n";
    }
    else if (loginType == 4) {  // New user sign up
        cout << "You have selected to make a new sign in.\n";
        cout << "Please input your username: ";
        cin >> usernameInput;
        cout << "\nPlease input your password: ";
        cin >> passwordInput;

        addUser(usernameInput, passwordInput);

        if (addedUser = 1) {
            cout << "\nYour sign up was successful. Please sign in with your new login credentials.\n";
            perform_verify_login();
        }
        else {
            perform_verify_login();
        }
    }
    else if (loginType == 5) {
        exit;
    }
    else {
        cout << "Invalid input. Please try again";
        perform_verify_login();
    }
}

void User::addUser(const string userN, const string passW) {

    if (getFile(userN, "userUFile.txt")) {
        cout << "That username is already in use.";
        return;
    }

    int id = 1 + prevID();
    saveFile(id, userN, "userUFile.txt");
    saveFile(id, passW, "userPFile.txt");
    addedUser = 1;
}

int User::prevID() {

    fstream inFile;
    string p;

    inFile.open("userUFile.txt");
    inFile.seekg(0, ios::end);

    if (inFile.tellg() == -1) {
        return 0;
    }

    for (int i = -1; p.find("*") == string::npos; i--) {
        inFile.seekg(i, ios::end);
        inFile >> p;
    }

    inFile.close();
    p.erase(0, 4);

    int id;
    stringstream(p) >> id;

    return id;
}

int User::getFile(string input, const char* f) {

    string line;
    fstream inFile;

    string curr;

    inFile.open(f, ios::in);

    while (1) {

        inFile >> curr;

        if (curr.find("*ID:") != string::npos) {
            if (input == line) {
                inFile.close();
                curr.erase(0, 4);
                int id;
                istringstream(curr) >> id;
                return id;
            }
            else {
                line = "";
            }
        }
        else {
            line += curr;
        }
        if (inFile.peek() == EOF) {
            inFile.close();
            return 0;
        }

    }
}

void User::saveFile(const int& id, string line, const char* f) {

    fstream inFile;
    inFile.open(f, ios::app);

    inFile.seekg(0, ios::end);

    if (inFile.tellg() != 0) {
        inFile << "\n";
    }

    inFile.seekg(0, ios::beg);

    inFile << line << "\n*ID:" << id;
    inFile.close();
}

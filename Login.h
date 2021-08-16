#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class User {

private:
    int addedUser = 0;
    int id = 1;

public:
    int loginType;
    string usernameInput;
    string passwordInput;
    bool confirmed = 0;

    void perform_verify_login();
    void addUser(const string userN, const string passW);
    int prevID();
    int getFile(string input, const char* f);
    void saveFile(const int& id, string line, const char* f);
};
#endif
#include <iostream>
#include <string>

using namespace std;
class customer
{
    string firstName, lastName, address, city, state;
    int zipcode, phoneNum;
   

public:
    void get_details(void)
    {
        cout << "Enter your first name:" << endl;
        cin >> firstName; 
        cout << "\nEnter your last name:" << endl;
        cin >> lastName;
        cin.ignore();

        cout << "\nEnter your address:" << endl;
        getline(cin, address);
        cout << "\nEnter your city:" << endl;
        cin >> city;
        cout << "\nEnter your state:" << endl;
        cin >> state;
        cout << "\nEnter your zipcode:" << endl;
        cin >> zipcode;
        cout << "\nEnter your phone number: Format(2223334444)" << endl;
        cin >> phoneNum;
        


    }
    void display_details(void);


};
void customer::display_details(void)
{
    cout << "\nFIRST NAME: " << firstName << endl;
    cout << "LAST NAME: " << lastName << endl;
    cout << "ADDRESS: " << address << endl;
    cout << "CITY: " << city << endl; 
    cout << "STATE: " << state << endl;
    cout << "ZIP CODE: " << zipcode << endl;
    cout << "PHONE NUMBER: " << phoneNum << endl;


}

int main()
{
    customer p;
    p.get_details();
    p.display_details();
    return 0;
}

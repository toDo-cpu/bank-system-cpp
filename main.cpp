#include <iostream>
using namespace std;

class Customer {

    public:
        string name;
        string username;
        string password;
        string email;

        double money;
};

int main () {

    Customer user;

    user.name = "Jack";
    user.username = "Wilson";

    cout << user.name << "|" << user.username;

    return 0;
}
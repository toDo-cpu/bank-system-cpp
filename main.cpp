#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Bank {
    public :
        void openAccount(string name , int number , double money=0.0) {
            accounts_name.push_back(name);
            accounts_number.push_back(number);
            accounts_cash.push_back(money);
        }
        vector getAccountsNameList() {
            return accounts_name;
        }
        vector getAccountsNumberList() {
            return accounts_number;
        }
        vector getAccountsCashList() {

        }
    private :  
        vector < string >   accounts_name;
        vector < int >      accounts_number;
        vector < double >   accounts_cash;
};
class Menu {
    public : 
        void printHeader() {
            std::cout << headerMenu << std::endl;
        }
        void setMenuToHome() {
            std::cout << homeMenu << std::endl;
        }
        void setMenuToAccountStatus(Bank& sysbank) {
            char input = '1';
            do {
                printHeader();
                std::cout << "\t 1.See yours accounts" << std::endl;
                std::cout << "\t 2.Close an account" << std::endl;
                std::cout << "\t 3.Back" << std::endl;

                std::cout << "[@]: "; std::cin >> input;

                switch(input) {
                    case '1' : 
                        printAccounts(sysbank);
                        break;
                    case '2' :
                        closeAccounts();
                        break;
                }
            } while (input != '3');
            std::cout << accountListMenu << std::endl;
        }
        void printAccounts(Bank& sysbank) {
            sysbank.printAccountsInfo();
        }
        void closeAccounts() {
            std::cout << "CLOSE AN ACCOUNT" << std::endl;
        }
        void setMenuToDepositMoney() {
            std::cout << depositMoneyMenu << std::endl;
        }
        void setMenuToMakeTransfer() {
            
            char input = '1';
            do  {
                printHeader();

                std::cout << "\t 1.Make new transfer" << std::endl;
                std::cout << "\t 2.Transfer history" << std::endl;
                std::cout << "\t 3.Back" << std::endl;
                
                std::cout << "[@]: "; std::cin >> input;
                switch(input) {
                    case '1' : 
                        doTransfer();
                        break;
                    case '2' :
                        showTransactionHistory();
                        break;
                }
            }while(input != '3');
    
        }
        void doTransfer() {

            double amount               = 0.000 ;
            string account_name         = "";
            string user_password        = "";
            string account_destination  = "";
            char transfer               = 'y';
            do {

                std::cout << headerMenu << std::endl;
                
                std::cout << "\t Please enter your password..." << std::endl;
                std::cout << "[@]: "; std::cin >> user_password;
                
                std::cout << "\t Wich account do you want to use ? " << std::endl;
                std::cout << "[@]: "; std::cin >> account_name;
                
                std::cout << "\t How much money do you want to transfer ? " << std::endl;
                std::cout << "[@]: "; std::cin >> amount; 
                
                std::cout << "\t Who is the recipient of the transaction ? " << std::endl;
                std::cout << "[@]: "; std::cin >> account_destination;

                std::cout << "\t Account \t :" << account_name << std::endl;
                std::cout << "\t Amount \t :" << amount  << std::endl;
                std::cout << "\t To \t\t :" << account_destination <<std::endl;

                std::cout << "do you want to do the trasnfer ? (y/n) "; std::cin >> transfer ;
                
            } while(transfer != 'y');

            std::cout << "TRANSFER !" <<std::endl;

        }
        void showTransactionHistory() {
            std::cout << "Transaction history" << std::endl;
        }
        void setMenuToOpenAccount(Bank& banksys) {
            
            printHeader();

            string new_accounts_name = "root";
            int new_accounts_number = 0;
            double new_accounts_cash = 0.0;

            std::cout << "\t Enter your new account name" << std::endl;
            std::cout << "[@]: "; std::cin >> new_accounts_name;
            
            std::cout << "\t Enter your new account number" << std::endl;
            std::cout << "[@]: "; std::cin >> new_accounts_number;

            std::cout << "\t Deposit cash on your account ? ( type 0 to don't deposit )" << std::endl;
            std::cout << "[@]: "; std::cin >> new_accounts_number;

            banksys.openAccount(new_accounts_name , new_accounts_number , new_accounts_cash);

        }

    private:
        string headerMenu = "------------------------BANK------------------------";
        string homeMenu = "\t 1.See your accounts status\n\t 2.Deposit money on a account\n\t 3.Make a transfer\n\t 4.Open an account\n\t 5.Exit";
        string accountListMenu = "\t Account stauts menu !";
        string depositMoneyMenu = "\t Deposit money here !";
        string makeTransferMenu = "\t Make a transfer here !";
        string openAnAccountMenu = "\t Open a new account here !";

        Bank bank;
};
int main () {
    Menu menu;
    Bank sysbank;

    char input = '0';

    do {

        menu.printHeader();
        menu.setMenuToHome();
        
        std::cout << "[@]: "; std::cin >> input;
        
        switch(input) {
            case '1' : 
                menu.setMenuToAccountStatus(sysbank);
                break;
            case '2' : 
                menu.setMenuToDepositMoney();
                break;
            case '3' :
                menu.setMenuToMakeTransfer();
                break;
            case '4' :
                menu.setMenuToOpenAccount(sysbank);
                break;
        }

    } while (input != '5');

    std::cout << "Bye bye !" << std::endl;

    return 0;
}
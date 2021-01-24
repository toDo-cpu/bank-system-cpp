#include <iostream>
#include <iomanip>
#include <string>

using std::string;

class Menu {
    public : 

        string headerMenu = "------------------------BANK------------------------";
        string homeMenu = "\t 1.See your accounts status\n\t 2.Deposit money on a account\n\t 3.Make a transfer\n\t 4.Open an account\n\t 5.Exit";
        string accountListMenu = "\t Account stauts menu !";
        string depositMoneyMenu = "\t Deposit money here !";
        string makeTransferMenu = "\t Make a transfer here !";
        string openAnAccountMenu = "\t Open a new account here !";
    
        void printHeader() {
            std::cout << headerMenu << std::endl;
        }

        void setMenuToHome() {
            std::cout << homeMenu << std::endl;
        }

        void setMenuToAccountStatus() {
            std::cout << accountListMenu << std::endl;
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

        void setMenuToOpenAccount() {
            std::cout << openAnAccountMenu << std::endl;
        }
};

class Customer {
    
}

int main () {

    char input = '0';
    Menu menu;
    
    do {

        menu.printHeader();
        menu.setMenuToHome();
        
        std::cout << "[@]: "; std::cin >> input;
        
        switch(input) {
            case '1' : 
                menu.setMenuToAccountStatus();
                break;
            case '2' : 
                menu.setMenuToDepositMoney();
                break;
            case '3' :
                menu.setMenuToMakeTransfer();
                break;
            case '4' :
                menu.setMenuToOpenAccount();
                break;
        }

    } while (input != '5');

    std::cout << "Bye bye !" << std::endl;

    return 0;
}

 /*std::cout << "------------------------BANK------------------------" << std::endl;
            std::cout << "\t 1.See your accounts status"<< std::endl;
            std::cout << "\t 2.Deposit money on a account"<<  std::endl;
            std::cout << "\t 3.Make a transfer"<<  std::endl;
            std::cout << "\t 4.Open an account"<<  std::endl;
            std::cout << "\t 5.Exit" << std::endl;*/
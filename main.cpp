#include <iostream>
#include <iomanip>
#include <string>
class Menu {
    public :
        char menuAskByUser ;
        char setMenu(char menu) {

            switch(menu) {
                case '1' : 
                    setMenuToHome();
                    prompt(menu);
                    return menuAskByUser;
                    break;
                case ''
            }

        }
    private : 
        
        void prompt(char onMenu) {
        
            std::cout << "[" << onMenu <<"] : "; std::cin >> menuAskByUser;
        
        }
        void setMenuToHome() {
        
            std::cout << "------------------------BANK------------------------" << std::endl;
            std::cout << "\t 1.See your accounts status"<< std::endl;
            std::cout << "\t 2.Deposit money on a account"<<  std::endl;
            std::cout << "\t 3.Make a transfer"<<  std::endl;
            std::cout << "\t 4.Open an account"<<  std::endl;
            std::cout << "\t 5.Exit" << std::endl;
        
        }
};

int main () {

    char input = '1';
    Menu draw;

    do {

        input = draw.setMenu(input);

    } while (input != '5');

    std::cout << "Bye bye !" << std::endl;

    return 0;
}
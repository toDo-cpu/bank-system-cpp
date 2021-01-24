#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
void ClearScrollback()
{
    cout << "\x1B[3J\x1B[H";
}

int main()
{
    int i = 0;
    string test = "hello";
    cout << test;   
    std::cin >> i;
    
    cout << "\r" << "goodbye" << std::flush;
    return EXIT_SUCCESS;
}
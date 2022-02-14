#include <iostream>
#include <string>
#include "utility.h"
#include "calc.h"

int main()
{
    std::cout << "Please type 'Exit'" << std::endl;
    std::string str{};
    int count = 0;
    while (str != "Exit")
    {
        std::cin >> str;
        count++;
        std::cout << count << std::endl;
    }
    int c = Add(1, 2);
    Print(1, c);

    return 0;
}
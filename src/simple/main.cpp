#include "header.h"
#include "utility.h"
#include "calc.h"

int main()
{
    std::cout << "Hello" << std::endl;
    int c = Add(1, 2);
    Print(1, c);
    calc_fft();

    return 0;
}
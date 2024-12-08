#include <iostream>
#include "func.h"

int main() {
    Func myFunc;
    double x;
    int n;

    std::cout << "Enter the value of x (|x| < 1): ";
    std::cin >> x;
    std::cout << "Enter the number of terms (n): ";
    std::cin >> n;

    double result = myFunc.FuncA(n, x);
    std::cout << "arth(" << x << ") ≈ " << result << std::endl;

    return 0;
}
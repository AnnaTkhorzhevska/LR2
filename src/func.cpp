#include "func.h"
#include <cmath>  // Для функції pow
#include <iostream>

double Func::FuncA(int n, double x) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += (pow(x, 2 * i + 1) / (2 * i + 1));
    }
    return sum;
}
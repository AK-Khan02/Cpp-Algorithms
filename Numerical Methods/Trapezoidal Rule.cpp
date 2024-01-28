#include <iostream>
#include <cmath>

double f(double x) {
    // Example function: x^2
    return x*x;
}

double trapezoidal(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (func(a) + func(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        sum += func(a + i * h);
    }

    return sum * h;
}

int main() {
    // Example 1: Integral of x^2 from 0 to 2
    double integral = trapezoidal(f, 0, 2, 10);
    std::cout << "Integral: " << integral << std::endl;

    // Additional examples can be added here with different functions, intervals, and n values

    return 0;
}

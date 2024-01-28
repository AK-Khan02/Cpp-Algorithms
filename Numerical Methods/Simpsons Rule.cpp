#include <iostream>
#include <cmath>

double f(double x) {
    // Example function: x^4 - 2x + 1
    return x*x*x*x - 2*x + 1;
}

double simpson(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for (int i = 1; i < n; i += 2) {
        sum += 4 * func(a + i * h);
    }

    for (int i = 2; i < n-1; i += 2) {
        sum += 2 * func(a + i * h);
    }

    return sum * h / 3;
}

int main() {
    // Example 1: Integral of x^4 - 2x + 1 from 0 to 1
    double integral = simpson(f, 0, 1, 10);
    std::cout << "Integral: " << integral << std::endl;

    // Additional examples can be added here with different functions, intervals, and n values

    return 0;
}

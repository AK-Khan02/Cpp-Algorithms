#include <iostream>
#include <cmath>

double f(double x) {
    // Example function: x^2 - 4
    return x*x - 4;
}

double f_prime(double x) {
    // Derivative of the above function: 2*x
    return 2*x;
}

double newtonRaphson(double (*func)(double), double (*func_prime)(double), double initialGuess, double tol) {
    double x = initialGuess;
    double h = func(x) / func_prime(x);

    while (std::abs(h) >= tol) {
        h = func(x) / func_prime(x);
        x = x - h;
    }

    return x;
}

int main() {
    // Example 1: Root of x^2 - 4
    double root = newtonRaphson(f, f_prime, 3, 0.001);
    std::cout << "Root: " << root << std::endl;

    // Additional examples can be added here with different functions, derivatives, and initial guesses

    return 0;
}

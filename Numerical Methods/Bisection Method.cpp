#include <iostream>
#include <cmath> // For fabs()

double f(double x) {
    // Example function: x^3 - x - 2
    return x*x*x - x - 2;
}

double bisection(double (*func)(double), double a, double b, double tol) {
    if (func(a) * func(b) >= 0) {
        std::cerr << "You have not assumed right a and b\n";
        return 0;
    }

    double c = a;
    while ((b-a) >= tol) {
        // Find middle point
        c = (a+b)/2;

        // Check if middle point is root
        if (func(c) == 0.0)
            break;

        // Decide the side to repeat the steps
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

int main() {
    double a = -200, b = 300, tol = 0.001;
    double root = bisection(f, a, b, tol);
    std::cout << "The root is: " << root << std::endl;
    return 0;
}

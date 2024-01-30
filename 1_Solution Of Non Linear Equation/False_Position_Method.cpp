#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    // Define the function for which you want to find the root
    // Example: return x^3 - 2
    return pow(x, 3) - 2;
}

double falsePosition(double a, double b, double tolerance, int maxIterations)
{
    double c;          // Root approximation
    double fa, fb, fc; // Function values at a, b, and c
    int iteration = 0; // Iteration counter

    do
    {
        fa = func(a);
        fb = func(b);
        if ((fa * fb) > 0)
        {
            cout << "Root does not lies between " << a << " and " << b << endl;
            return NAN;
        }
        if (fa < 0)
        {
            a = a;
            b = b;
        }
        else
        {
            swap(a, b);
        }
        // Calculate the root approximation using the false position formula
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));
        fc = func(c);

        if (fc == 0.0)
        {
            // The root is found
            break;
        }
        else if (fc < 0)
        {
            // Update the interval [a, b] for the next iteration
            a = c;
        }
        else
        {
            // Update the interval [a, b] for the next iteration
            b = c;
        }

        iteration++;

    } while (fabs(b - a) > tolerance && iteration < maxIterations);

    cout << "Iterations: " << iteration << endl;
    return c;
}

int main()
{
    // Initial interval [a, b]
    double a = 1.2;
    double b = 1.3;

    // Tolerance and maximum number of iterations
    double tolerance = 0.0001;
    int maxIterations = 100;

    // Find the root using the false position method
    double root = falsePosition(a, b, tolerance, maxIterations);

    // Display the root
    cout << "Root: " << root << endl;

    return 0;
}

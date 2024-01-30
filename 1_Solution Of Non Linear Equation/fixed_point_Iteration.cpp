#include <iostream>
#include <cmath>

using namespace std;
// Define the function for which you want to find the root
double func(double x)
{
    // Example: g(x) = 1/((x + 1)^(1/2))
    return sqrt(1 / (x + 1));
}

double fixedPointIteration(double initialGuess, double tolerance, int maxIterations)
{
    double x = initialGuess;
    int iteration = 0;
    do
    {
        double newX = func(x);

        if (fabs(newX - x) < tolerance)
        {
            // Convergence reached
            break;
        }

        x = newX;
        iteration++;

    } while (iteration < maxIterations);

    cout << "Iterations: " << iteration << endl;

    return x;
}

int main()
{
    // Initial guess
    double initialGuess = 0;

    // Tolerance and maximum number of iterations
    double tolerance = 0.0001;
    int maxIterations = 100;

    // Find the root using fixed-point iteration
    double root = fixedPointIteration(initialGuess, tolerance, maxIterations);

    // Display the root
    cout << "Root: " << root << endl;
    return 0;
}

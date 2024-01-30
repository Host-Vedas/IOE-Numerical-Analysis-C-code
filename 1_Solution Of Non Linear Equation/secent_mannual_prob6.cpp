#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// define function
double fun_for_root(double x)
{
    return pow(x, 3) + pow(x, 2) + x + 7;
}
// define secent function
double secent(double x0, double x1, double accuracy, int maxIteration)
{
    double x2;
    for (int i = 0; i < maxIteration; i++)
    {
        x2 = x1 - (((x1 - x0) * fun_for_root(x1)) / (fun_for_root(x1) - fun_for_root(x0)));
        // if (fabs(fun_for_root(x2)) < accuracy)
        if (fabs((x1 - x0) / x1) < accuracy)
        {
            cout << "Solution converged after " << i + 1 << " Iteration ";
            return x2;
        }
        x0 = x1;
        x1 = x2;
    }
    cout << "Faild to reach solution after " << maxIteration << endl;
    return NAN;
}
int main()
{
    double x0, x1, accuracy;
    int maxIteration;
    cout << "Enter initial guess x0 -> ";
    cin >> x0;
    cout << "Enter initial guess x1 -> ";
    cin >> x1;
    cout << "Enter accuracy needed -> ";
    cin >> accuracy;
    cout << "Maximum iteration to get root -> ";
    cin >> maxIteration;
    // check validity of the guess
    if ((fun_for_root(x0) * fun_for_root(x1) > 0))
    {
        cout << "Invalid guess" << endl;
        return -1;
    }
    // assign guess in proper variable
    if (fun_for_root(x0) < 0)
    {
        x0 = x0;
        x1 = x1;
    }
    else
    {
        swap(x0, x1);
    }
    // call secent function
    double root = secent(x0, x1, accuracy, maxIteration);
    if (!isnan(root))
    {
        cout << "The root is " << setprecision(8) << root;
    }
    else
    {
        cout << "Failed to get root with given accuracy with given iteration " << endl;
    }

    return 0;
}
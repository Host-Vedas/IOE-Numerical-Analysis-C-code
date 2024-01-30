#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
float f(float x)
{
    return x * log10(x) - 1.2;
}
float df(float x)
{
    return log10(x) + 0.43429;
}
int main()
{
    int itr, max_itr;
    float f_df_ratio, x0, x1, error;
    cout << "Enter x0, allowed error, maximum iterations" << endl;
    cin >> x0 >> error >> max_itr;
    cout << fixed;
    for (itr = 1; itr <= max_itr; itr++)
    {
        f_df_ratio = f(x0) / df(x0);
        x1 = x0 - f_df_ratio;
        cout << "Iteration no." << setw(3) << itr << " x = " << setw(9) << setprecision(6) << x1 << endl;
        if (fabs(f_df_ratio) < error)
        {
            cout << "After " << setw(3) << itr << "iterations root = " << setw(8) << setprecision(6) << x1;
            return 0;
        }
        x0 = x1;
    }
    cout << "Iteratiions not sufficientr, solutions does not converge " << endl;
    return 1;
}
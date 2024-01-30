#include <iostream>
#include <cmath>
using namespace std;
//  function
//     x^3 - 2*x - 5 = 0 Ans : 2.0948

// define function
float func(float x)
{
    return (pow(x, 3) - 2 * x - 5);
}

float Bisection(float a, float b, float Error, int itr)
{
    for (int i = 0; i <= itr; i++)
    {
        if (func(a) < 0)
        {
            a = a;
            b = b;
        }
        else
        {
            swap(a, b);
        }
        if (func(a) * func(b) > 0)
        {
            cout << "Root does not lies between " << a << " and " << b << endl;
            return -100001;
        }
        float x;
        x = (a + b) / 2;
        if (abs((b - a) / b) <= Error)
        {
            cout << "Iteration No :- " << i << endl;
            return x;
        }
        if (func(x) < 0)
        {
            a = x;
        }
        else
        {
            b = x;
        }
    }
    cout << "Root is not possible upto interation " << itr << endl;
     return -100001;
}
int main()
{
    float a, b, itr, Error;
    cout << "Enter a";
    cin >> a;
    cout << "Enter b";
    cin >> b;
    cout << "Enter No of iterration ";
    cin >> itr;
    cout << "Precision or error upto place value ";
    cin >> Error;
    cout << "The required root of non linear equation is " << Bisection(a, b, Error, itr);
    return 0;
}
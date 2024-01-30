#include <iostream>
using namespace std;
float LagrangeInterpolation(float point, float x[n], float y[n])
{
    float y_point = 0;
    for (int i = 0; i <= n; i++)
    {
        float num = 1;
        float den = 1;

        for (int j = 0; j <= n; i++)
        {
            if (i != j)
            {
                num *= (x - x[j]);
                den *= (x[i] - x[j]);
            }
        }
        y_point += ((num / den) * y[i]);
    }
}
int main()
{
    int n;
    cout << "Enter no of data point for interpolation " << endl;
    cin >> n;
    float x[n], y[n];
    for (int i = 0; i <= n; i++)
    {
        cout << "x[" << i << "] :- ";
        cin >> x[i];
        cout << endl;
        cout << "y[" << i << "] :- ";
        cin >> y[i];
        cout << endl;
    }
    return 0;
}
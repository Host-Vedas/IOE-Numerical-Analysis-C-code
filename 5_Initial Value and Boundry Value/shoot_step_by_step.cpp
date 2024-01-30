#include <iostream>
#include <iomanip>
using namespace std;

double f(double x, double y, double z)
{
    return z;
}

double g(double x, double y, double z)
{
    return x - y + z;
}

void Huns(double x_initial, double &y_initial, double &z_initial, double h)
{
    double x0 = x_initial;
    double y0 = y_initial;
    double z0 = z_initial;

    double k_1 = h * f(x0, y0, z0);
    double l_1 = h * g(x0, y0, z0);
    double k_2 = h * f(x0 + h, y0 + k_1, z0 + l_1);
    double l_2 = h * g(x0 + h, y0 + k_1, z0 + l_1);

    y_initial = y0 + (k_1 + k_2) / 2;
    z_initial = z0 + (l_1 + l_2) / 2;
}

int main()
{
    double x_a, x_b, ya, y_a, y_a1, y_b, z_a, z_b, h, m1, m2;
    x_a = 0;
    x_b = 1;
    ya = y_a1 = y_a = 2;
    y_b = 3;
    m1 = z_a = 2;
    m2 = z_b = 4;
    h = 0.5;

    // Performing the shooting method
    cout << "x = " << x_a << "     y(" << x_a << ") = " << ya << "      z(" << x_a << ") = " << z_a << endl;
    for (int i = 0; i < 2; i++)
    {
        Huns(x_a, y_a, z_a, h);
        x_a += h;
        cout << fixed << setprecision(3);
        cout << "x = " << setw(4) << x_a << "   y(" << setw(4) << x_a << ") = " << setw(7) << y_a << "   z(" << setw(4) << x_a << ") = " << setw(7) << z_a << endl;
    }
    cout << endl
         << endl;
    double b1 = y_a;

    x_a = 0; // Reset x_a to its initial value
    cout << "x = " << x_a << "     y(" << x_a << ") = " << y_a1 << "      z(" << x_a << ") = " << z_b << endl;
    for (int i = 0; i < 2; i++)
    {
        Huns(x_a, y_a1, z_b, h);
        x_a += h;
        cout << fixed << setprecision(3);
        cout << "x = " << setw(4) << x_a << "   y(" << setw(4) << x_a << ") = " << setw(7) << y_a1 << "   z(" << setw(4) << x_a << ") = " << setw(7) << z_b << endl;
    }
    cout << endl
         << endl;
    double b2 = y_a1;

    // Calculate m3
    double z0, m3 = m2 - ((b2 - y_b) / (b2 - b1)) * (m2 - m1);
    z0 = m3;

    x_a = 0; // Reset x_a to its initial value
    cout << "x = " << x_a << "     y(" << x_a << ") = " << ya << "      z(" << x_a << ") = " << m3 << endl;
    for (int i = 0; i < 2; i++)
    {
        Huns(x_a, y_a, m3, h);
        x_a += h;
        cout << fixed << setprecision(3);
        cout << "x = " << setw(4) << x_a << "   y(" << setw(4) << x_a << ") = " << setw(7) << y_a << "   z(" << setw(4) << x_a << ") = " << setw(7) << m3 << endl;
    }
    cout << endl
         << endl;
    return 0;
}

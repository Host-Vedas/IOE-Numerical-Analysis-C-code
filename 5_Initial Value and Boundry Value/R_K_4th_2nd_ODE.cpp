#include <iostream>
#include <iomanip>
using namespace std;

// Define the second-order ODE
// y'' = f(x, y, y')
// Example:
/*
    y'' + y' + y = 0
    y'' = -y' - y

    let : y' = z,then
    z' = -z-y

    here,
    y' = z      ........... f(x,y,z)
    z' = -z-y   ........... g(x,y,z)
*/
// Define the first derivative of the original dependent variable
// z = y'

/*
we are solving
y" = x*y'^2 - y^2
*/
double f(double x, double y, double z)
{
    // z = y'
    return z;
}

double g(double x, double y, double z)
{
    //  z' = -z-y   ........... g(x,y,z)
    return (x * z * z - y * y);
}

void rungeKutta(double x, double y, double z, double h, double xn)
{
    double x0 = x;
    double y0 = y;
    double z0 = z;

    cout << fixed;

    while (x < xn)
    {
        double k1_z = h * f(x0, y0, z0);
        // cout << " k1_z :- " << setprecision(4) << k1_z << endl;
        double k1_y = h * g(x0, y0, z0);
        // cout << " k1_y :- " << setprecision(4) << k1_y << endl << endl;
        double k2_z = h * f(x0 + h / 2, y0 + k1_z / 2, z0 + k1_y / 2);
        // cout << " k2_z :- " << setprecision(4) << k2_z << endl;
        double k2_y = h * g(x0 + h / 2, y0 + k1_z / 2, z0 + k1_y / 2);
        // cout << " k2_y :- " << setprecision(4) << k2_y << endl << endl;
        double k3_z = h * f(x0 + h / 2, y0 + k2_z / 2, z0 + k2_y / 2);
        // cout << " k3_z :- " << k3_z << endl;
        // cout << "f(x0 + h / 2, y0 + k2_z / 2, z0 + k2_y / 2) :-     " << f(x0 + h / 2, y0 + k2_z / 2, z0 + k2_y / 2) << endl;
        double k3_y = h * g(x0 + h / 2, y0 + k2_z / 2, z0 + k2_y / 2);
        // cout << " k3_y :- " << setprecision(4) << k3_y << endl << endl;
        double k4_z = h * f(x0 + h, y0 + k3_z, z0 + k3_y);
        // cout << " k4_z :- " << setprecision(4) << k4_z << endl;
        double k4_y = h * g(x0 + h, y0 + k3_z, z0 + k3_y);
        // cout << " k4_y :- " << setprecision(4) << k4_y << endl << endl;
        // cout << "y=l :-     " << (k1_y + 2 * k2_y + 2 * k3_y + k4_y) / 6;
        z += (k1_y + 2 * k2_y + 2 * k3_y + k4_y) / 6;
        // cout << "z=k :-     " << (k1_z + 2 * k2_z + 2 * k3_z + k4_z) / 6;
        y += (k1_z + 2 * k2_z + 2 * k3_z + k4_z) / 6;
        x += h;
        cout << "When x = " << setprecision(4) << setw(8) << x << "  y = " << setw(8) << y << "  y' = " << setw(8) << z << endl;
    }
}

int main()
{
    double x0, y0, z0, h, xn;

    cout << "Enter the initial values of x0, y0, y'(0) = z0, step size (h), xn:" << endl;
    cin >> x0 >> y0 >> z0 >> h >> xn;

    rungeKutta(x0, y0, z0, h, xn);

    return 0;
}

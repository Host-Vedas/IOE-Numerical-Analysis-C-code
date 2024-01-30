#include <iostream>
using namespace std;
float func(float x)
{
    // define;
}
float simpson1_3(float a, float b, int h)
{
    float y_out = func(a) + func(b);
    int j = 0;
    float y_odd = 0, y_even = 0;
    for (int i = (a + h); i < b; i += h)
    {
        j++;
        if (j % 2 == 0)
        {
            y_even += func(i);
        }
        else
        {
            y_odd += func(i);
        }
    }
    return ((h / 3) * (y_out + 4 * y_odd + 2 * y_even));
}
int main()
{
    float a, b, h;
    cout << "Enter value of a , b and size i.e h" << endl;
    cin >> a >> b >> h;
    cout << "The required value of integration is " << simpson1_3(a, b, h);
    return 0;
}
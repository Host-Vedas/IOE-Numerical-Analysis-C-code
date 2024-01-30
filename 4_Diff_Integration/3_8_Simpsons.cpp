#include <iostream>
using namespace std;
float func(float x)
{
    // define;
}
float simpson3_8(float a, float b, int h)
{
    float y_out = func(a) + func(b);
    int j = 0;
    float y_3 = 0, y_non_3 = 0;
    for (int i = (a + h); i < b; i += h)
    {
        j++;
        if (j % 3 == 0)
        {
            y_3 += func(i);
        }
        else
        {
            y_non_3 += func(i);
        }
    }
    return ((3 * h / 8) * (y_out + 3 * y_non_3 + 2 * y_3));
}
int main()
{
    float a, b, h;
    cout << "Enter value of a , b and size i.e h" << endl;
    cin >> a >> b >> h;
    cout << "The required value of integration is " << simpson3_8(a, b, h);
    return 0;
}
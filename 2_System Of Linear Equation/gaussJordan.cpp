#include <iostream>
using namespace std;
const int maxSize = 100;

void gauss(float a[maxSize][maxSize + 1], int n)
{
    for (int i = 0; i < n; i++)
    {
        // pivot element
        float pivot = a[i][i];
        // work on row and devide that row by pivot, to make diagonal 1
        for (int j = i; j < n; j++)
        {
            a[i][j] /= pivot;
        }
        // work on other to make other zero except diagonal
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                float factor = a[k][i];
                for (int j = i; j < n; j++)
                {
                    a[k][j] -= factor * a[i][j];
                }
            }
        }
    }
}

int main()
{

    return 0;
}
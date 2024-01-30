#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;

void gaussianJordan(float matrix[MAX_SIZE][MAX_SIZE + 1], int n)
{
    for (int i = 0; i < n; i++)
    {
        // Pivot element
        float pivot = matrix[i][i];

        // Make the diagonal element 1
        for (int j = i; j < n + 1; j++)
        {
            matrix[i][j] /= pivot;
        }

        // Make other row's element zero
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                float factor = matrix[k][i];
                for (int j = i; j < n + 1; j++)
                    matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    float matrix[MAX_SIZE][MAX_SIZE + 1];

    // matrix[0][0] = 1;
    // matrix[0][1] = 1;
    // matrix[0][2] = 2;
    // matrix[1][0] = 1;
    // matrix[1][1] = -1;
    // matrix[1][2] = 0;

    cout << "Enter the augmented matrix coefficients:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
        {
            cin >> matrix[i][j];
        }
    gaussianJordan(matrix, n);

    cout << "\nSolution of the system of equations:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << matrix[i][n] << endl;
    }
    cout << "Matrix coefficiebts afer solution:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << matrix[i][j] << "    ";
        }
        cout << endl;
    }
    return 0;
}

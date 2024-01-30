#include <iostream>
#include <iomanip>
#include <math.h>
#define SIZE 10
using namespace std;
int main()
{
    float matrix[SIZE][SIZE], eigen_Vector[SIZE], new_eigen_vector[SIZE];
    float temp, lambda_new, lambda_old, error;
    int i, j, n, step = 1;
    /* Setting precision and writing floating point values in fixed-point notation. */
    cout << setprecision(3) << fixed;

    /* Inputs */
    /* Reading order of square matrix */
    cout << "Enter Order of Matrix: ";
    cin >> n;

    /* Reading tolerable error */
    cout << "Enter Tolerable Error: ";
    cin >> error;

    /* Reading Square Matrix of Order n */
    cout << "Enter Coefficient of Matrix: " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << "matrix[" << i << "]" << j << "]= ";
            cin >> matrix[i][j];
        }
    }

    /* Reading Intial Guess Vector */
    cout << "Enter Initial Guess Vector: " << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "eigen_Vector[" << i << "]= ";
        cin >> eigen_Vector[i];
    }

    /* Initializing Lambda_Old */
    lambda_old = 1;
/* Multiplication */

/* Setting label for repetition */
up:
    for (i = 1; i <= n; i++)
    {
        temp = 0.0;
        for (j = 1; j <= n; j++)
        {
            temp = temp + matrix[i][j] * eigen_Vector[j];
        }
        new_eigen_vector[i] = temp;
    }

    /* Replacing eigen_Vector by new_eigen_vector */
    for (i = 1; i <= n; i++)
    {
        eigen_Vector[i] = new_eigen_vector[i];
    }

    /* Finding largest value from eigen_Vector*/
    lambda_new = fabs(eigen_Vector[1]);
    for (i = 2; i <= n; i++)
    {
        if (fabs(eigen_Vector[i]) > lambda_new)
        {
            lambda_new = fabs(eigen_Vector[i]);
        }
    }

    /* Normalization */
    for (i = 1; i <= n; i++)
    {
        eigen_Vector[i] = eigen_Vector[i] / lambda_new;
    }

    /* Display */
    cout << endl
         << endl
         << "STEP-" << step << endl;
    cout << "Eigen Value = " << lambda_new << endl;
    cout << "Eigen Vector: " << endl;
    cout << "[";
    for (i = 1; i <= n; i++)
    {
        cout << eigen_Vector[i] << "\t";
    }
    cout << "\b\b\b]"; /* \b is for backspace */

    /* Checking Accuracy */
    if (fabs(lambda_new - lambda_old) > error)
    {
        lambda_old = lambda_new;
        step++;
        goto up;
    }

    return (0);
}


/// Exponential Equation:
/// Book(example 10.2)
/// Type(2): Y = a * x^b ;

#include<bits/stdc++.h>

using namespace std;

int n = 5;
double x[] = {1,2,3,4,5};
double y[] = {.5,2,4.5,8,12.5};
double a,b;

int main(void)
{
    double sum_x = 0;
    double sum_y = 0;
    double sum_lnx = 0;
    double sum_lny = 0;
    double sum_lnxSqr = 0;
    double sum_lnxlny = 0;

    cout << "\tx\t" << "y\t" << "ln(x)\t\t" << "ln(y)\t\t" << "[ln(x)]^2\t\t" << "[ln(x)][ln(y)]" << endl;

    for(int i = 0;i < n;i++)
    {
        double ln_x = log(x[i]);
        double ln_y = log(y[i]);
        double ln_xSqr = log(x[i])* log(x[i]);
        double ln_xy = log(x[i]) * log(y[i]);

        sum_x = sum_x + x[i];
        sum_y = sum_y + y[i];
        sum_lnx = sum_lnx + log (x[i]);
        sum_lny = sum_lny + log (y[i]);
        sum_lnxSqr = sum_lnxSqr + pow(log(x[i]),2);
        sum_lnxlny = sum_lnxlny + (log(x[i]) * log(y[i]));

        cout << "\t" << x[i] << "\t" << y[i] << "\t" << ln_x << "\t\t" << ln_y << "\t\t" << ln_xSqr << "\t\t\t"  << ln_xy  << endl;
    }

    cout << "\nSum:\t" << sum_x << "\t" << sum_y << "\t" << sum_lnx << "\t\t" << sum_lny << "\t\t" << sum_lnxSqr << "\t\t\t"  << sum_lnxlny  << endl;

    b = ((n * sum_lnxlny) - (sum_lnx * sum_lny)) / ((n * sum_lnxSqr) - (pow(sum_lnx,2)));
    double R = ((sum_lny - (b * sum_lnx)) / n);
    a = exp (R);

    cout << endl << "Equation : " << endl ;
    cout << endl << "Y = " << a << "x^" << b << endl  ;
}

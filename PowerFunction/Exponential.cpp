
/// Exponential Equation:
/// Book(example 10.3)
/// Type(1): T = b*e^(.25*t) + a;


#include<bits/stdc++.h>
#define f(t) exp (.25 * t)

using namespace std;

int n = 4;
double x[] = {1,2,3,4};
double y[] = {70,83,100,124};
double a,b;

int main(void)
{
    double sum_x = 0;
    double sum_y = 0;
    double sum_Fx = 0;
    double sum_yFx = 0;
    double sum_FxSqr = 0;

    cout << "\tx\t" << "y\t" << "f(x)\t\t" << "y*f(x)\t\t" << "[f(x)]^2" << endl;

    for(int i = 0;i < n;i++)
    {
        sum_x = sum_x + x[i];
        sum_y = sum_y + y[i];
        sum_Fx = sum_Fx + f(x[i]);
        sum_yFx = sum_yFx + (y[i] * f(x[i]));
        sum_FxSqr = sum_FxSqr + pow(f(x[i]),2);

        cout << "\t" << x[i] << "\t" << y[i] << "\t" << f(x[i]) << "\t\t" << y[i] * f(x[i]) << "\t\t"  << pow(f(x[i]),2) << endl;
    }


    cout << "\nSum:\t" << sum_x << "\t" << sum_y << "\t" << sum_Fx << "\t\t" << sum_yFx << "\t\t"  << sum_FxSqr << endl;

    b = ((n * sum_yFx)-(sum_Fx * sum_y)) / ((n * sum_FxSqr) - pow(sum_Fx,2));
    a = (sum_y - (b * sum_Fx)) / n ;

    cout << endl << "Equation : " << endl ;
    cout << endl << "Y = " << b << "e^(.25 * t) + " << a << endl;

    return 0;

}

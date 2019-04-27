/*
 5x1 - x2 + 2x3 = 12
 3x1 + 8x2 - 2x3 = -25
 x1 + x2 + 4x3 = 6
*/
#include <bits/stdc++.h>
#define E 0.001

using namespace std;

int main()
{
    float x1 = 0;
    float x2 = 0;
    float x3 = 0;

    int iteration = 1;
    cout << "Iteration :";
    cout << "\t";
    cout << "x1";
    cout << "\t";
    cout << "x2";
    cout << "\t";
    cout << "x3";
    cout << endl;
    cout << setprecision(2) << fixed;
    while (true)
    {
        float a = (12 + x2 - 2*x3)/5;
        float b = (-25-3*x1 + 2*x3)/8;
        float c = (6-x1-x2)/4;

        cout << iteration << "\t\t";
        cout << a;
        cout <<"\t";
        cout << b;
        cout <<"\t";
        cout << c;
        cout <<endl;


        if (fabs((x1 - a)/x1) < E) break;


        iteration++;
        x1 = a;
        x2 = b;
        x3 = c;

    }

}

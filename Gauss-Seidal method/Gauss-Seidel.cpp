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

    float errorCheck = 999;

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

        x1 = (12 + x2 - 2*x3)/5;
        x2 = (-25-3*x1 + 2*x3)/8;
        x3 = (6-x1-x2)/4;

        cout << iteration << "\t\t";
        cout << x1;
        cout <<"\t";
        cout << x2;
        cout <<"\t";
        cout << x3;
        cout <<endl;


        if (fabs((x1 - errorCheck)/x1) < E) break;

        errorCheck = x1;
        iteration++;


    }

}


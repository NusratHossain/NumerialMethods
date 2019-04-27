#include <bits/stdc++.h>
#define E 0.001

using namespace std;

int order;
vector <float> coefficients;
vector <float> coefficientsPrime;

float HR(float arg, vector <float> v)
{
    int len = v.size();
    float sum = v[0];
    for(int i = 1; i < len; i++)
    {
        sum = sum * arg  + v[i];
    }

    return sum;
}

void Derivative()
{
    coefficientsPrime.clear();
    int len;
    len = coefficients.size();

    for(int i = 0; i < len-1; i++)
    {
        coefficientsPrime.push_back(coefficients[i] * (order - i));
    }
}

void SD(float arg )
{
    float v = 0;
    vector <float> tempV;

    int len = coefficients.size();

    for(int i = 0; i < len; i++)
    {
        v = v * arg + coefficients[i];
        tempV.push_back(v);
    }

    coefficients.clear();

    coefficients = tempV;

    order--;
}

int main()
{
    float Arr[] = {1,-21,20,0};
    int length = sizeof(Arr)/sizeof(float);
    order = length - 1;

    for(int i = 0 ; i < length; i++)
    {
        coefficients.push_back(Arr[i]);

    }
    float x0;
    float x;
    float f;
    float fPrime;
    float errorCheck;
    x0 = 15;

    Derivative();

    while(order > 1)
    {
        do
        {
            f = HR(x0,coefficients);
            fPrime = HR(x0,coefficientsPrime);
            x = x0 - (f/fPrime);
            errorCheck = fabs((x - x0)/x);
            x0 = x;
        }while(errorCheck > E);

        cout << endl << "Root is : "  << x << endl;

        SD(x);
        Derivative();
    }
    cout << "Root is : " << (-1) * coefficients[1]/coefficients[0] << endl;
}

#include<bits/stdc++.h>

using namespace std;

int x[] = {5,7,11,13,21};
int y[] = {150,392,1452,2366,9702};
int n = 5;
int a = 6;
float p[100];

void DividedDifference()
{
    int j = 1;
    float func = y[0];
    float f1 = 1;
    float f2 = 0;

    do
    {
        for (int i = 0;i < n-1;i++)
        {
            p[i] = ((y[i+1]-y[i])/(x[i+j]-x[i]));
            y[i] = p[i];
        }

        f1 = 1;

        for(int i = 0;i < j;i++)
            {
                f1 = f1 * (a - x[i]);
            }
        f2 = f2 + (y[0] * f1);
        n--;
        j++;
    }

    while(n != 0);
    func = func + f2;
    printf("Result of f(%d) is %.3f\n\n", a , func);
}

int main()
{
    DividedDifference();

    return 0;
}

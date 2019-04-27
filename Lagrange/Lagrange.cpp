#include<bits/stdc++.h>

using namespace std;

int x[] = {5,6,9,11};
int y[] = {12,13,14,16};
int n = 4;
int a = 10;
float result = 0;

void Lagrange()
{
    for(int i = 0;i < n;i++)
    {
        float up = 1;
        float down = 1;
        for(int j = 0;j < n;j++)
        {
            if(i != j)
            {
                up = up * (a - x[j]);
                down = down * (x[i]-x[j]);
            }
        }

        result = result + (y[i]*(up/down)) ;
    }

    cout << endl << "Result for given value is: " << result << endl;
}

int main()
{
    Lagrange();

    return 0;
}



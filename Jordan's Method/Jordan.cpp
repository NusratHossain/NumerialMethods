#include<bits/stdc++.h>

using namespace std;

int numOfUnknown;
double arr[10][10];
double result[10];
double normal;

int main(void)
{
    int row;
    int col;
    int k;

    cout << "Number of Equation : " ;
    cin >> numOfUnknown ;

    cout << "Inputs : " << endl;
    for(int row = 1; row <= numOfUnknown; row++)
    {
        for(int col = 1; col <= numOfUnknown; col++)
        {
            cin >> arr[row][col] ;
        }
    }

    ///Jordan Method

    for(int row = 1; row <= numOfUnknown; row++)
    {
        for(int col = 1; col <= numOfUnknown; col++)
        {
            if(row != col)
            {
                normal = arr[col][row] / arr[row][row];

                for(int i = 1; i <= numOfUnknown; i++)
                {
                    arr[col][i] = arr[col][i] - (normal * arr[row][i]);
                }
            }
        }
    }

    cout << endl << "Solutions : " << endl ;
    for(int i = 1; i <= numOfUnknown; i++)
    {
        result[i] = arr[i][numOfUnknown+1] / arr[i][i];
        cout << "x" << i << " = " << result[i] << endl ;
    }

}

/*

2 1 3 1
4 4 7 1
2 5 9 3

*/










#include<iostream>
#include<math.h>
//#define f(x) (x*x*x) - 3*x + 2
//#define g(x) 3*x*x - 3
//#define f(x) x*x - 3*x + 2
//#define g(x) 2*x - 3
#define f(x) x*x - 4*x - 10
#define g(x) 2*x - 4

using namespace std;

int order;
double arr[20];

double NewtonRaphson()
{
    double x0,f0,g0;
	double x1;
	int iteration  = 0;
	double e = 0.0001;
	double absoluteValue;

	cout << "x0 : ";
	cin >> x0;

	cout << "Iteration: \tChanges of x: \t" << endl;

	do
	{
	    ++iteration;
	    cout << iteration << " \t\t";
	    cout << "x" << iteration-1 << " :" << x0;
		f0 = f(x0);
		g0 = g(x0);

		x1 = x0 - (f0/g0);
		absoluteValue = fabs((x1-x0)/x1);
		x0 = x1;
		cout << "\n" ;

	}while(absoluteValue > e);

	double root = x1;

    return root;

}

int main(void)
{
    for(int i = 0;i < 2; ++i)
    {
        arr[i] = NewtonRaphson();
        cout << "Root(" << i+1 << ") is : " << arr[i] << endl ;
    }

}






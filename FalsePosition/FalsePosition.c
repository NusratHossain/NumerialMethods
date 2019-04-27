#include <stdio.h>
#include <math.h>
#define f(x) (x*x) - 46*x - 45
//#define f(x) (x*x) - 4*x - 10

int main(void)
{
    double x0, x1, x2;
    double f0, f1, f2;
    double e = 0.01;
    double value;
    int noOfIteration = 0;
    char F0, F1, F2;

    x1 = 1.5;
    x2 = -1;

    int i = 0;
    for(i = 0; i < 2; i++)
    {
        f1 = f(x1);
        if(f1 < 0)
        {
            F1 = '-';
        }
        else
        {
            F1 = '+';
        }
        f2 = f(x2);
        if(f2 < 0)
        {
            F2 = '-';
        }
        else
        {
            F2 = '+';
        }

        if(f1 * f2 > 0)
        {
            printf("\nNo root in this interval.");
            break;
        }

        printf("Iteration:\tX1\t\tX2\t\tX0\t\tF1\t\tF2\t\tF0\n");
        do
        {
            noOfIteration++;
            x0 = x1 - ((f1*(x2-x1))/(f2-f1));
            f0 = f(x0);
            if(f0 < 0)
            {
                F0 = '-';
            }
            else
            {
                F0 = '+';
            }
            printf("  %d\t\t%f\t%f\t%f\t%c\t\t%c\t\t%c",noOfIteration,x1,x2,x0,F1,F2,F0);
            if(f0 == 0)
            {
                printf("\nRoot(%d) : %f",i+1,x0);
                break;
            }
            else
            {
                if(f1 * f0 < 0)
                {
                    x2 = x0;
                }
                else
                {
                    x1 = x0;
                }
            }
            value = (x2-x1)/x2;
            printf("\n");
        }
        while(fabs(value) > e);
        int root = (x1+x2)/2;

        printf("\nRoot(%d) : %f\n\n",i+1,x0);
        x1 = 41;
        x2 = 48;
    }


}

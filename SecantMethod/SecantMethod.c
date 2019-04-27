#include<stdio.h>
#include<math.h>

double HR(double arg,int a[],int length)
{
    double p = a[0];
    int i;
    for(i=1; i<length; ++i)
    {
        p = p*arg + a[i];
    }

    return p;
}

int main()
{
    double x1,x2,x3,f1,f2;
    double E = 0.001;
    double error;
    double root;
    int iteration=0;
    int coefs[] = {1,-21,20,0};
    int i;
    x1 = -0.5;
    x2 = 2.0;

    for(i = 0; i<3; ++i)
    {
        iteration = 0;

        f1 = HR(x1,coefs,4);
        f2 = HR(x2,coefs,4);
        printf("Iteration:\tx1\tx2\tx3\n");

        while(1)
        {
            ++iteration;
            x3 = ((f2*x1)-(f1*x2))/(f2-f1);
            printf("%d\t\t%.3f\t%.3f\t%.3f\n\n",iteration,x1,x2,x3);
            error = fabs((x3-x2)/x3);

            if(error > E)
            {
                x1 = x2;
                f1 = f2;
                x2 = x3;
                f2 = HR(x3,coefs,4);
            }
            else
            {
                root = x3;
                break;
            }
        }
        printf("\nRoot is : %.3f\n",root);
        x1 = 19;
        x2 = 21;
    }
}

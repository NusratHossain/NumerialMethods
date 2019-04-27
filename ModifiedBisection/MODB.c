#include <stdio.h>
#include <math.h>

#define delX 0.05
#define E 0.001


float HR(float arg, float coefs[], int len)
{
    float sum = coefs[0];
    int i;
    for(i = 1; i < len; i++)
    {
        sum = arg * sum + coefs[i];
    }

    return sum;
}




int main()
{
    float coefs[] = {1,-21,20,0};
    int len = sizeof(coefs)/sizeof(float);
    float x0;
    float x1;
    float x2;
    float f1;
    float f0;
    float f2;
    float errorCheck;

    float lowerLimit;
    float upperLimit;

    int rootCount = 0;

    lowerLimit = -1;
    upperLimit = 21;

    x1 = lowerLimit;
    x2 = x1 + delX;

    while(x2 < upperLimit)
    {
        f1 = HR(x1,coefs,len);
        f2 = HR(x2,coefs,len);
        int iteration = 0;



        if(f1 * f2 < 0)
        {
            printf("Iteration \t");
            printf("x1 \t");
            printf("x2 \t");
            printf("x0 \t");
            printf("f1 \t");
            printf("f2 \t");
            printf("f0 \n\n");


            while(1)
            {
                ++iteration;

                x0 = (x1 + x2)/2;
                f0 = HR(x0,coefs,len);

                printf("%d\t\t",iteration);
                printf("%0.2f\t",x1);
                printf("%0.2f\t",x2);
                printf("%0.2f\t",x0);
                printf("%0.2f\t",f1);
                printf("%0.2f\t",f2);
                printf("%0.2f\n",f0);

                if(f0 == 0)
                {
                    if(x0 == 0) x0 = fabs(x0);
                    rootCount++;
                    printf("\n Root %d is : %.2f\n\n",rootCount,x0);
                    break;
                }

                if(f1 * f0 < 0)
                {
                    x2 = x0;
                }
                else
                {
                    x1 = x0;
                    f1 = f0; ///?????????????????
                }

                errorCheck = fabs((x2 - x1)/x2);

                if(errorCheck < E)
                {
                    if(x0 == 0) fabs(x0);
                    rootCount++;
                    printf("\n Root %d is : %0.2f\n\n",rootCount,x0);
                    break;
                }

            }
        }

        x1 = x2;
        x2 = x1 + delX;
    }

}

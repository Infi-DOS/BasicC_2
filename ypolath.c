#include <stdio.h>

int main(void)
{
    int i, n, sum;

    printf("\nDose tin timi tou n");
    printf("\n n= ");
    scanf("%d", &n);


    for (sum = 0, i=0; i<n; ++i)
       {
            sum = sum+i;
            printf("\nS(%d) = %d",i,sum);
       }



    printf("\n");

    system("pause");
    return 0;
}

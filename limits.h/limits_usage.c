#include <stdio.h>
#include <limits.h>

int sum (int num1, int num2)
// Sum function returning sum if no overflow is present...
{
    if (num1 > INT_MAX - num2)
        return INT_MIN;

    else
        return num1 + num2;
}

int main()
{

    int num1 = 2147483627;
    int num2 = 20;
    // Two numbers with sum in limits of integer

    int result = sum(num1, num2);

    if (result == INT_MIN)
    {
        printf("Integer overflow occured... \n");
    }
    else
    {
        printf("Sum is %d \n", result);
    }
    return 0;
}

#include <stdio.h>
/**
* main: declare, initialize and add two integer variables.
* Return: 0 (Always) success.
*/
int main(void)
{
    // Declare and initialize two integer variables  
    int num1 = 10;
    int num2 = 20;

    // Calculate the sum of the two numbers
    int sum = num1 + num2;

    // Print the result
    printf("The sum of %d and %d is: %d\n", num1, num2, sum);

    // Return 0 to indicate successful execution
    return (0);
}

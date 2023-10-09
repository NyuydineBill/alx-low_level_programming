#include <stdlib.h>
#include <time.h>
<<<<<<< HEAD
#include <stdio.h>
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
=======
/* more headers goes there */

/* betty style doc for function main goes there */
/* This program generates a random number
and 
determines if it is positive, negative, or zero. */
>>>>>>> bb555ea32fe35dca92ed60293746a70adbc12b1d
int main(void)
{
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;
<<<<<<< HEAD
if (n > 0)
{
printf("%d is positive\n", n);
}
else if (n < 0)
{
printf("%d is negative\n", n);
}
else
{
printf("%d is zero\n", n);
=======
/* your code goes there */
if (n % 2 == 0 && n >= 1)
{
printf("%d is positive\n", n);
}
else if (n == 0)
{
printf("%d is zero\n", n);
}
else
{
printf("%d is negative\n", n);
>>>>>>> bb555ea32fe35dca92ed60293746a70adbc12b1d
}
return (0);
}

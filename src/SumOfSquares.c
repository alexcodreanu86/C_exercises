#include "SumOfSquares.h"
#include <stdio.h>

unsigned long int SumOfSquares_calculate(unsigned int number)
{
  /* unsigned long result = 0; */
  /* for (unsigned int i = 1; i <= number; i++) { */
  /*   result += (i * i); */
  /* } */
  /*  */
  /* return result; */
  return number * (number + 1) * ((2 * number) + 1) / 6;
}

unsigned long int SumOfSquares_SquareOfSum(unsigned int number)
{
  /* unsigned long result = 0; */
  /* for (unsigned int i = 1; i <= number; i++) { */
  /*   result += i; */
  /* } */
  /*  */
  /* return result * result; */

  return (number * number) * ((number + 1) * (number + 1)) / 4;
}

unsigned long int SumOfSquares_SquareSumDifference(unsigned int number)
{
  unsigned long squareSum = SumOfSquares_calculate(number);
  unsigned long sumSquare = SumOfSquares_SquareOfSum(number);


  return sumSquare - squareSum;
}

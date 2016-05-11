#include "AdjacentNumbers.h"

unsigned long AdjacentNumbers_GetLargest(char * digits, int length, int adjacentNumbers)
{
  unsigned long largestProduct = 0;
  for (int x = 0; (x + adjacentNumbers) <= length; x++) {
    unsigned long product = 1;
    for(int i = 0; i < adjacentNumbers; i++) {
      product *= (unsigned long) (digits[x + i] - '0');
    }

    if (product > largestProduct)
      largestProduct = product;
  }
  return largestProduct;
}

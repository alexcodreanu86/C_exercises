#include "DivisibleTriangularNumber.h"
#include "NumberOfFactors.h"
#include <stdbool.h>

unsigned long DivisibleTriangularNumber_withDivisorsOver(int number) {
  unsigned long long int triangularNumber = 28;

  for(unsigned long i = 8; true; i++) {
    int divisers = NumberOfFactors_Count(triangularNumber);
    if (divisers > number) {
      return triangularNumber;
    }
    triangularNumber += i;
  }
}

#include "NumberOfFactors.h"

int NumberOfFactors_Count(unsigned long number)
{
  unsigned long possibleDivisor = 2;
  int dividedNumberOfTimes = 0;
  int numberOfFactors = 1;
  unsigned long remainder = number;

  while(remainder % possibleDivisor == 0 )
  {
    ++dividedNumberOfTimes;
    remainder /= possibleDivisor;
  }

  numberOfFactors *= (dividedNumberOfTimes + 1);
  dividedNumberOfTimes = 0;
  possibleDivisor = 3;

  while(possibleDivisor <= remainder)
  {
    if (remainder % possibleDivisor == 0 )
    {
      ++dividedNumberOfTimes;
      remainder /= possibleDivisor;
    } else {
      if (dividedNumberOfTimes > 0) {
        numberOfFactors *= (dividedNumberOfTimes + 1);
        dividedNumberOfTimes = 0;
      }
      possibleDivisor += 2;
    }
  }

  numberOfFactors *= (dividedNumberOfTimes + 1);
  return numberOfFactors;
}

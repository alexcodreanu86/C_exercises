#include "LargeSum.h"
#include "stdio.h"

static char * result;
void LargeSum_Destroy()
{
  free(result);
}

int sumOfDigits(const char * [], int, int);
int sumOfDigits(const char * numbers[], int index, int numbersCount) {
  int sum = 0;
  for(int i = 0; i < numbersCount; i++)
    sum += (numbers[i][index] - '0');

  return sum;
}


char * LargeSum_result(const char * numbers[], int numbersCount, int numbersLength, int resultDigits)
{
  result = calloc((size_t) (resultDigits + 1), sizeof(char));
  char * tempResult =  calloc((size_t) (numbersLength + 2), sizeof(char));
  int rollover = 0;
  for (int i = numbersLength; i > 0; i--)
  {
    int digitsSum = sumOfDigits(numbers, i - 1, numbersCount) + rollover;
    int currentDigit = digitsSum % 10;
    rollover = digitsSum / 10;
    tempResult[i + 1] = (char) currentDigit + '0';
  }
  int lastIndexAdded = 2;
  while(rollover > 0) {
    int currentDigit = rollover % 10;
    rollover /= 10;
    lastIndexAdded--;
    tempResult[lastIndexAdded] = (char) currentDigit + '0';
  }

  for(int i = 0; i < resultDigits; i++) {
    result[i] = tempResult[i + lastIndexAdded];
  }

  free(tempResult);
  return result;
}

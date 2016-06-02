#include "LargestCollatzSequence.h"
#include "UnsignedLongVector.h"

unsigned long LCS_SequenceSize(unsigned long number)
{
  unsigned long currentState = number;
  unsigned long sequenceSize = 1;
  while(currentState > 1)
  {
    sequenceSize++;
    if (currentState % 2 == 0)
      currentState /= 2;
    else
      currentState = currentState * 3 + 1;
  }
  return sequenceSize;
}

unsigned long LCS_Bellow(unsigned long limit)
{
  unsigned long largestSequenceSize = 8;
  unsigned long numberWithLargestSequence = 3;
  for(unsigned long i = numberWithLargestSequence; i < limit; i++)
  {
    unsigned long currentSequenceSize = LCS_SequenceSize(i);
    if (currentSequenceSize > largestSequenceSize)
    {
      largestSequenceSize = currentSequenceSize;
      numberWithLargestSequence = i;
    }
  }
  return numberWithLargestSequence;
}

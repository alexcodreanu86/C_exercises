#include "SmallestMultiple.h"

void addFactorTo(struct Factors *, int);
void addFactorTo(struct Factors * container, int factor)
{
  container->count += 1;
  if (container->capacity < container->count)
  {
    container->capacity *= 2;
    container->factors= realloc(container->factors, (size_t) container->capacity * sizeof(int));
  }
  container->factors[container->count - 1] = factor;
}

void generateFactorsFor(struct Factors *, int);
void generateFactorsFor(struct Factors * container, int number)
{
  int possibleFactor = 2;

  while(possibleFactor <= number)
  {
    if (number % possibleFactor == 0){
      number /= possibleFactor;
      addFactorTo(container, possibleFactor);
    } else {
      possibleFactor++;
    }
  }
}

void SmallestMultiples_Destroy(struct Factors * container)
{
  free(container->factors);
  free(container);
}

struct Factors * SmallestMultiple_getAllFor(int number)
{
  struct Factors * container = (struct Factors *) calloc(1, sizeof(struct Factors));
  container->count = 0;
  container->capacity = 2;
  container->factors = calloc((size_t) container->capacity, sizeof (int));
  generateFactorsFor(container, number);
  return container;
}

int SmallestMultiple_for(int number)
{
  if (number < 2)
    return number;

  int result = 1;
  for (int i=1; i <= number; i++) {
    result *= i;
  }

  return result;
}

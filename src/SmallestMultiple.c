#include "SmallestMultiple.h"

void addFactorTo(struct Multiples *, int);
void addFactorTo(struct Multiples * container, int factor)
{
  container->count += 1;
  if (container->capacity < container->count)
  {
    container->capacity *= 2;
    container->factors= realloc(container->factors, (size_t) container->capacity * sizeof(int));
  }
  container->factors[container->count - 1] = factor;
}

void generateFactorsFor(struct Multiples *, int);
void generateFactorsFor(struct Multiples * container, int number)
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

void SmallestMultiples_Destroy(struct Multiples * container)
{
  free(container->factors);
  free(container);
}

struct Multiples * SmallestMultiple_getAllFor(int number)
{
  struct Multiples * container = (struct Multiples *) calloc(1, sizeof(struct Multiples));
  container->count = 0;
  container->capacity = 2;
  container->factors = calloc((size_t) container->capacity, sizeof (int));
  generateFactorsFor(container, number);
  return container;
}


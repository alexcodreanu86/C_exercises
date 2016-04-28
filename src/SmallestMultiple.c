#include "SmallestMultiple.h"

struct Factors * SmallestMultiple_CreateContainer() {
  struct Factors * factors = (struct Factors *) calloc(1, sizeof(struct Factors));
  factors->count = 0;
  factors->capacity = 2;
  struct HashMap ** container = (struct HashMap **) calloc((size_t) 2, sizeof(struct HashMap *));
  factors->container = container;
  return factors;
}

void SmallestMultiple_Destroy(struct Factors * self)
{
  for (int i = 0; i < self->count; i++ ) {
    HashMap_Destroy(self->container[i]);
  }
  free(self->container);
  free(self);
}

struct HashMap * getMultiplesFor(int number);
struct HashMap * getMultiplesFor(int number) {
  struct HashMap * factors = HashMap_Create();
  HashMap_AddKeyValue(factors, number, 1);
  return factors;
}

struct Factors * SmallestMultiple_AllMultiples(int number)
{
  struct Factors * factors = SmallestMultiple_CreateContainer();
  factors->count += (number -1);
  factors->container[0] = getMultiplesFor(2);
  factors->container[1] = getMultiplesFor(3);

  return factors;
}

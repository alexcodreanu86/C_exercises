#include "SmallestMultiple.h"

struct Multiples * SmallestMultiple_CreateContainer() {
  struct Multiples * multiples = (struct Multiples *) calloc(1, sizeof(struct Multiples));
  multiples->count = 0;
  multiples->capacity = 2;
  struct HashMap ** container = (struct HashMap **) calloc((size_t) 2, sizeof(struct HashMap *));
  multiples->container = container;
  return multiples;
}

void SmallestMultiple_Destroy(struct Multiples * self)
{
  for (int i = 0; i < self->count; i++ ) {
    HashMap_Destroy(self->container[i]);
  }
  free(self->container);
  free(self);
}

struct HashMap * getMultiplesFor(int number);
struct HashMap * getMultiplesFor(int number) {
  struct HashMap * multiples = HashMap_Create();
  HashMap_AddKeyValue(multiples, number, 1);
  return multiples;
}

struct Multiples * SmallestMultiple_AllMultiples(int number)
{
  struct Multiples * multiples = SmallestMultiple_CreateContainer();
  multiples->count += (number -1);
  multiples->container[0] = getMultiplesFor(2);
  multiples->container[1] = getMultiplesFor(3);

  return multiples;
}

#ifndef DEFINE_SMALLEST_MULTIPLES
#define DEFINE_SMALLEST_MULTIPLES
#include "HashMap.h"
#include "Vector.h"

#include <stdbool.h>

struct Multiples {
  int count;
  int capacity;
  struct HashMap ** container;
};

struct Multiples * SmallestMultiple_AllMultiples(int);
void SmallestMultiple_Destroy(struct Multiples *);
struct Multiples * SmallestMultiple_CreateContainer(void);
struct HashMap * SmallestMultiple_getAllFor(int);
bool SmallestMultiple_multiples(void);
int SmallestMultiple_for(int);

#endif

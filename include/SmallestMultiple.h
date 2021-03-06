#ifndef DEFINE_SMALLEST_MULTIPLES
#define DEFINE_SMALLEST_MULTIPLES
#include "HashMap.h"
#include "Vector.h"

#include <stdbool.h>

struct Factors {
  int count;
  int capacity;
  struct HashMap ** container;
};

struct Factors * SmallestMultiple_AllFactors(int);
void SmallestMultiple_Destroy(struct Factors *);
struct Factors * SmallestMultiple_CreateContainer(void);
struct HashMap * SmallestMultiple_GetFactorsFor(int);
int SmallestMultiple_ForNumbersUpTo(int);
struct HashMap * SmallestMultiple_FactorsWithHighestCount(struct Factors *);

#endif

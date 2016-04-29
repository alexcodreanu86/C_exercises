#include "SmallestMultiple.h"
#include <stdio.h>

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

void SmallestMultiple_ExpandFactors(struct Factors * factors);
void SmallestMultiple_ExpandFactors(struct Factors * factors) {
  factors->capacity *= 2;
  struct HashMap ** container = realloc(factors->container, (size_t) factors->capacity * sizeof(struct HashMap *));
  factors->container = container;
}

struct Factors * SmallestMultiple_AllFactors(int number)
{
  struct Factors * factors = SmallestMultiple_CreateContainer();
  for (int i = 2; i <= number; i++) {
    if (factors->count == factors->capacity) {
      SmallestMultiple_ExpandFactors(factors);
    }

    factors->container[factors->count] = SmallestMultiple_GetFactorsFor(i);
    factors->count += 1;
  }
  return factors;
}

struct HashMap * SmallestMultiple_GetFactorsFor(int number)
{
  struct HashMap * factors = HashMap_Create();
  int remainder = number;
  int possibleFactor = 2;
  while(possibleFactor <= remainder) {
    if (remainder % possibleFactor == 0) {
      remainder /= possibleFactor;
      if (HashMap_HasKey(factors, possibleFactor)) {
        int currentValue = HashMap_GetValue(factors, possibleFactor);
        HashMap_AddKeyValue(factors, possibleFactor, currentValue + 1);
      } else {
        HashMap_AddKeyValue(factors, possibleFactor, 1);
      }
    } else {
      possibleFactor++;
    }
  }
  return factors;
}

struct HashMap * SmallestMultiple_FactorsWithHighestCount(struct Factors * factors)
{
  struct HashMap * allCommonFactors = HashMap_Create();

  for (int i = 0; i < factors->count; i++) {
    struct HashMap * currentFactors = factors->container[i];
    struct Vector * keys = HashMap_GetKeys(currentFactors);

    for (int x = 0; x < Vector_Count(keys); x++) {
      int factor = Vector_ValueAt(keys, x);
      int factorValue = HashMap_GetValue(currentFactors, factor);


      if(!HashMap_HasKey(allCommonFactors, factor) || factorValue > HashMap_GetValue(allCommonFactors, factor)){
        HashMap_AddKeyValue(allCommonFactors, factor, factorValue);
      }
    }
  }

  return allCommonFactors;
}

int SmallestMultiple_ForNumbersUpTo(int number) {
  struct Factors * factors = SmallestMultiple_AllFactors(number);
  struct HashMap * allCommonFactors = SmallestMultiple_FactorsWithHighestCount(factors);
  struct Vector * factorNumbers = HashMap_GetKeys(allCommonFactors);
  int result = 1;
  for (int i = 0; i < Vector_Count(factorNumbers); i++) {
    int factor = Vector_ValueAt(factorNumbers, i);
    int factorCount = HashMap_GetValue(allCommonFactors, factor);

    for (int x = 0; x < factorCount; x++) {
      result *= factor;
    }
  }

  SmallestMultiple_Destroy(factors);
  HashMap_Destroy(allCommonFactors);

  return result;
}


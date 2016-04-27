#include <stdbool.h>

struct Factors {
  int count;
  int capacity;
  int * factors;
};

void SmallestMultiples_Destroy(struct Factors * container);
struct Factors * SmallestMultiple_getAllFor(int);
bool SmallestMultiple_multiples(void);
int SmallestMultiple_for(int);

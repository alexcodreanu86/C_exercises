#include <stdbool.h>

struct Multiples {
  int count;
  int capacity;
  int * factors;
};

void SmallestMultiples_Destroy(struct Multiples * container);
struct Multiples * SmallestMultiple_getAllFor(int);
bool SmallestMultiple_multiples(void);

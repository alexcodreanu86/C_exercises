#include "PythagoreanTriplets.h"

unsigned long PythagoreanTriplets_Product(int sum)
{

  unsigned int a = 2;
  unsigned int b = 3;
  unsigned int c = ((unsigned int) sum) - (a + b);

  while (a < b) {
    while(b < c) {
      if ((a * a) + (b * b)  == (c * c)) {
        return a * b * c;
      } else {
        b += 1;
        c = ((unsigned int) sum) - (a + b);
      }
    }

    if ((a * a) + (b * b)  == (c * c)) {
      return a * b * c;
    } else {
      a += 1;
      b = a + 1;
      c = ((unsigned int) sum) - (a + b);
    }

  }

  return a * c * b;
}

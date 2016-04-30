#include "NthPrime.h"
#include <stdbool.h>

bool isPrime(int number, int * primes, int numberOfElements);
bool isPrime(int number, int * primes, int numberOfElements) {
  bool primeStatus = true;
  for (int i = 0; i < numberOfElements; i++) {
    if (number % primes[i] == 0) {
      primeStatus = false;
      break;
    }
  }

  return primeStatus;
}

int NthPrime_Get(int number)
{
  int * primes = calloc((size_t) number, sizeof(int));;
  primes[0] = 2;
  int currentIndex = 1;
  int potentialPrime = 3;

  while (currentIndex < number) {
    if (isPrime(potentialPrime, primes, currentIndex)) {
      primes[currentIndex] = potentialPrime;
      currentIndex++;
    }
    potentialPrime++;
  }

  int value = primes[currentIndex - 1];
  free(primes);
  return value;
}

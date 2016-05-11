#include "SumOfPrimes.h"

bool isNumberPrime(int number, int * primes, int numberOfElements);
bool isNumberPrime(int number, int * primes, int numberOfElements) {
  bool primeStatus = true;
  for (int i = 0; i < numberOfElements; i++) {
    int currentPrime = primes[i];
    if (number % currentPrime == 0) {
      primeStatus = false;
      break;
    }
    if (number < (currentPrime * currentPrime))
      break;
  }

  return primeStatus;
}

unsigned long sumOfPrimes(int *, int);
unsigned long sumOfPrimes(int * primes, int length)
{
  unsigned long sum = 0;
  for (unsigned long i = 0; i < (unsigned long) length; i++){
    sum += (unsigned long) primes[i];
  }
  return sum;
}

unsigned long SumOfPrimes_SmallerThan(int limit)
{
  int * primes = calloc((size_t) limit, sizeof(int));;
  primes[0] = 2;
  int currentIndex = 1;
  int potentialPrime = 3;

  while (potentialPrime < limit) {
    if (isNumberPrime(potentialPrime, primes, currentIndex)) {
      primes[currentIndex] = potentialPrime;
      currentIndex++;
    }
    potentialPrime += 2;
  }

  unsigned long sum = sumOfPrimes(primes, currentIndex);
  free(primes);
  return sum;
}

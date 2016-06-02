#include "NthPrime.h"
#include <stdbool.h>
#include "Vector.h"

bool isPrime(int number, struct Vector * primes);
bool isPrime(int number, struct Vector * primes)
{
  int count = Vector_Count(primes);
  for (int i = 0; i < count; i++)
  {
    if (number % Vector_ValueAt(primes, i) == 0)
      return false;
  }

  return true;
}

int NthPrime_Get(int number)
{
  int potentialPrime = 3;

  struct Vector * primes = Vector_Create(number);
  Vector_Push(primes, 2);
  while (Vector_Count(primes) < number)
  {
    if (isPrime(potentialPrime, primes))
      Vector_Push(primes, potentialPrime);
    potentialPrime += 2;
  }

  int value = Vector_ValueAt(primes, Vector_Count(primes) - 1);
  Vector_Destroy(primes);
  return value;
}

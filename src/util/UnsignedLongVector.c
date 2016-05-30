#include "UnsignedLongVector.h"

struct ULVector {
  UL count;
  UL capacity;
  UL * container;
};

struct ULVector * ULVector_Create(UL capacity)
{
  struct ULVector * self = (struct ULVector *) calloc(1, sizeof(struct ULVector));
  self->count = 0;
  self->capacity = capacity;
  self->container = calloc((size_t) self->capacity, sizeof(UL));
  return self;
}

void ULVector_Destroy(struct ULVector * self)
{
  free(self->container);
  free(self);
}

bool ULVector_IsEmpty(struct ULVector * self)
{
  return self->count == 0;
}

void fillUpULEmptyPossitions(struct ULVector *, UL, UL);
void fillUpULEmptyPossitions(struct ULVector * self, UL oldCapacity, UL newCapacity)
{
  for(UL i = oldCapacity; i < newCapacity; i++) {
    self->container[i] = 0;
  }
}


void ULVector_Push(struct ULVector * self, UL value)
{
  if (self->capacity >= self->count) {
    UL oldCapacity = self->capacity;
    self->capacity *= 2;
    self->container = realloc(self->container, (size_t) self->capacity * sizeof(UL));
    fillUpULEmptyPossitions(self, oldCapacity, self->capacity);
  }

  self->container[self->count] = value;
  self->count += 1;
}

UL ULVector_Count(struct ULVector * self)
{
  return self->count;
}

UL ULVector_ValueAt(struct ULVector * self, UL index)
{
  return self->container[index];
}

void ULVector_SetValueAt(struct ULVector * self, UL index, UL value)
{
  self->container[index] = value;
}

long long ULVector_IndexOf(struct ULVector * self, UL value)
{
  long long index = INVALID_INDEX;
  long long count = (long long) self->count;

  for(long long i=0; i < count; i++)
  {
    if (self->container[i] == value)
    {
      index = i;
      break;
    }
  }

  return index;
}

long long ULVector_BinaryIndexOf(struct ULVector * self, UL value)
{
  long long index = INVALID_INDEX;
  long long upperBound = (long long) self->count - 1;
  long long lowerBound = 0;
  long long elementsLeft = 0;
  long long center = 0;
  UL centerElement = 0;
  do {
    centerElement = self->container[center];
    if (centerElement > value)
    {
      upperBound = center - 1;
    }
    else if (centerElement < value)
    {
      lowerBound = center + 1;
    }
    else
    {
      index = center;
      break;
    }

    elementsLeft = upperBound - lowerBound + 1;
    center = lowerBound + (elementsLeft / 2);
    if(elementsLeft % 2 == 0)
      center++;
  } while(upperBound - lowerBound > 1);

  centerElement = self->container[center];
  if (centerElement == value)
    index = center;

  return index;
}

void ULVector_SetCount(struct ULVector * self, UL count)
{
  self->count = count;
}

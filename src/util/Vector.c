#include <Vector.h>

struct Vector {
  int count;
  int capacity;
  int * container;
};

struct Vector * Vector_Create(int capacity)
{
  struct Vector * self = (struct Vector *) calloc(1, sizeof(struct Vector));
  self->count = 0;
  self->capacity = capacity;
  self->container = calloc((size_t) self->capacity, sizeof(int));
  return self;
}

void Vector_Destroy(struct Vector * self)
{
  free(self->container);
  free(self);
}

bool Vector_IsEmpty(struct Vector * self)
{
  return self->count == 0;
}

void Vector_Push(struct Vector * self, int value)
{
  if (self->capacity >= self->count) {
    self->capacity *= 2;
    self->container = realloc(self->container, (size_t) self->capacity * sizeof(int));
  }

  self->container[self->count] = value;
  self->count += 1;
}

int Vector_Count(struct Vector * self)
{
  return self->count;
}

int Vector_ValueAt(struct Vector * self, int index)
{
  return self->container[index];
}

void Vector_SetValueAt(struct Vector * self, int index, int value)
{
  self->container[index] = value;
}

int Vector_IndexOf(struct Vector * self, int value)
{
  int index = INVALID_INDEX;

  for(int i=0; i < self->count; i++)
  {
    if (self->container[i] == value)
    {
      index = i;
      break;
    }
  }

  return index;
}

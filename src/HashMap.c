#include "HashMap.h"

struct HashMap {
  int size;
};

void HashMap_Destroy(struct HashMap * hashMap)
{
  free(hashMap);
}

struct HashMap * HashMap_Create()
{
  struct HashMap * map = (struct HashMap *) calloc(1, sizeof(struct HashMap));
  return map;
}

bool HashMap_HasKey(struct HashMap * self, int key)
{
  self->size = key;
  return false;
}

void HashMap_AddKeyValue(int key, int value)
{
  key += value;
}

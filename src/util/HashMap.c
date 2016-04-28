#include "HashMap.h"

struct HashMap {
  int size;
  struct Vector * keys;
  struct Vector * values;
};

void HashMap_Destroy(struct HashMap * hashMap)
{
  Vector_Destroy(hashMap->keys);
  Vector_Destroy(hashMap->values);
  free(hashMap);
}

struct HashMap * HashMap_Create()
{
  struct HashMap * map = (struct HashMap *) calloc(1, sizeof(struct HashMap));
  map->keys = Vector_Create(2);
  map->values = Vector_Create(2);
  return map;
}

bool HashMap_HasKey(struct HashMap * self, int key)
{
  return Vector_IndexOf(self->keys, key) != INVALID_INDEX;
}

void HashMap_AddKeyValue(struct HashMap * self, int key, int value)
{
  int indexOfKey = Vector_IndexOf(self->keys, key);
  if (indexOfKey == INVALID_INDEX)
  {
    Vector_Push(self->keys, key);
    Vector_Push(self->values, value);
  } else {
    Vector_SetValueAt(self->keys, indexOfKey, key);
    Vector_SetValueAt(self->values, indexOfKey, value);
  }
}

int HashMap_GetValue(struct HashMap * self, int key)
{
  int indexOfKey = Vector_IndexOf(self->keys, key);
  return Vector_ValueAt(self->values, indexOfKey);
}

struct Vector * HashMap_GetKeys(struct HashMap * self)
{
  return self->keys;
}

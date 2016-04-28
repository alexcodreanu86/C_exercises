#ifndef DEFINE_HASH_MAP
#define DEFINE_HASH_MAP

#include <stdbool.h>

struct HashMap;

void HashMap_Destroy(struct HashMap *);
struct HashMap * HashMap_Create(void);
bool HashMap_HasKey(struct HashMap *, int);
void HashMap_AddKeyValue(struct HashMap *, int key, int value);
int HashMap_GetValue(struct HashMap *, int);

#endif

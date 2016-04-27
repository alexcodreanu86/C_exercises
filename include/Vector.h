#ifndef DEFINE_VECTOR
#define DEFINE_VECTOR
#include <stdbool.h>

struct Vector;

struct Vector * Vector_Create(void);
void Vector_Destroy(struct Vector *);
bool Vector_IsEmpty(struct Vector *);

#endif

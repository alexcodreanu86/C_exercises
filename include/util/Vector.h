#ifndef DEFINE_VECTOR
#define DEFINE_VECTOR
#include <stdbool.h>

struct Vector;
enum { INVALID_INDEX = -1 };

struct Vector * Vector_Create(int);
void Vector_Destroy(struct Vector *);
bool Vector_IsEmpty(struct Vector *);
int Vector_Count(struct Vector *);
int Vector_IndexOf(struct Vector *, int);
int Vector_ValueAt(struct Vector *, int);
void Vector_SetValueAt(struct Vector *, int index, int value);
void Vector_Push(struct Vector *, int);

#endif

#ifndef DEFINE_UNSIGNED_LONG_VECTOR
#define DEFINE_UNSIGNED_LONG_VECTOR
#include <stdbool.h>

typedef unsigned long UL;
struct ULVector;
enum { INVALID_INDEX = -1 };

struct ULVector * ULVector_Create(UL);
void ULVector_Destroy(struct ULVector *);
bool ULVector_IsEmpty(struct ULVector *);
UL ULVector_Count(struct ULVector *);
long long ULVector_IndexOf(struct ULVector *, UL);
UL ULVector_ValueAt(struct ULVector *, UL);
void ULVector_SetValueAt(struct ULVector *, UL index, UL value);
void ULVector_Push(struct ULVector *, UL);
long long ULVector_BinaryIndexOf(struct ULVector *, UL);
void ULVector_SetCount(struct ULVector *, UL);

#endif

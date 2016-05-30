#include "CppUTest/TestHarness.h"

extern "C"
{
#include "UnsignedLongVector.h"
}

TEST_GROUP(ULVector)
{
  ULVector * vector;
  void setup() {
    vector = ULVector_Create(2);
  }
  void teardown() {
    ULVector_Destroy(vector);
  }
};

TEST(ULVector, isEmptyWhenCreated)
{
  CHECK_TEXT(ULVector_IsEmpty(vector), "ULVector not empty");
}

TEST(ULVector, isNotEmptyAfterAddingValue)
{
  ULVector_Push(vector, 1);

  CHECK_FALSE_TEXT(ULVector_IsEmpty(vector), "Vector is empty after adding element");
}

TEST(ULVector, sizeReturnsZeroWhenCreated)
{
  CHECK_EQUAL(0, ULVector_Count(vector));
}

TEST(ULVector, returnsCorrectSizeAfterAddingElement)
{
  ULVector_Push(vector, 54);

  CHECK_EQUAL(1, ULVector_Count(vector));
}

TEST(ULVector, returnsElementAtIndex)
{
  ULVector_Push(vector, 54);

  CHECK_EQUAL(54, ULVector_ValueAt(vector, 0));
}

TEST(ULVector, canAddMultipleElements)
{
  ULVector_Push(vector, 1);
  ULVector_Push(vector, 2);
  ULVector_Push(vector, 3);

  CHECK_EQUAL(1, ULVector_ValueAt(vector, 0));
  CHECK_EQUAL(2, ULVector_ValueAt(vector, 1));
  CHECK_EQUAL(3, ULVector_ValueAt(vector, 2));
}

TEST(ULVector, fillsReallocatedCapacityWithZeros) {
  ULVector_Push(vector, 1);
  ULVector_Push(vector, 2);
  ULVector_Push(vector, 3);

  CHECK_EQUAL(0, ULVector_ValueAt(vector, 3));
}

TEST(ULVector, canSetTheValueAtAGivenIndex)
{
  ULVector_SetValueAt(vector, 1, 5);

  CHECK_EQUAL(5, ULVector_ValueAt(vector, 1));
}

TEST(ULVector, returnsInvalidIndexWhenDoesNotContainAValue)
{
  LONGS_EQUAL(INVALID_INDEX, ULVector_IndexOf(vector, 5));
}

TEST(ULVector, returnsIndexOfAGivenValue)
{
  ULVector_Push(vector, 7);
  ULVector_Push(vector, 19);

  LONGS_EQUAL(0, ULVector_IndexOf(vector, 7));
  LONGS_EQUAL(1, ULVector_IndexOf(vector, 19));
}

TEST(ULVector, binarySortReturnsIndexOfElement)
{
  ULVector_Push(vector, 7);
  ULVector_Push(vector, 19);
  ULVector_Push(vector, 23);
  ULVector_Push(vector, 32);
  ULVector_Push(vector, 45);

  LONGS_EQUAL(0, ULVector_BinaryIndexOf(vector, 7));
  LONGS_EQUAL(1, ULVector_BinaryIndexOf(vector, 19));
  LONGS_EQUAL(2, ULVector_BinaryIndexOf(vector, 23));
  LONGS_EQUAL(3, ULVector_BinaryIndexOf(vector, 32));
  LONGS_EQUAL(4, ULVector_BinaryIndexOf(vector, 45));
}

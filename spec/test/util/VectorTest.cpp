#include "CppUTest/TestHarness.h"

extern "C"
{
#include "Vector.h"
}

TEST_GROUP(Vector)
{
  Vector * vector;
  void setup() {
    vector = Vector_Create(2);
  }
  void teardown() {
    Vector_Destroy(vector);
  }
};

TEST(Vector, isEmptyWhenCreated)
{
  CHECK_TEXT(Vector_IsEmpty(vector), "Vector not empty");
}

TEST(Vector, isNotEmptyAfterAddingValue)
{
  Vector_Push(vector, 1);

  CHECK_FALSE_TEXT(Vector_IsEmpty(vector), "Vector is empty after adding element");
}

TEST(Vector, sizeReturnsZeroWhenCreated)
{
  CHECK_EQUAL(0, Vector_Count(vector));
}

TEST(Vector, returnsCorrectSizeAfterAddingElement)
{
  Vector_Push(vector, 54);

  CHECK_EQUAL(1, Vector_Count(vector));
}

TEST(Vector, returnsElementAtIndex)
{
  Vector_Push(vector, 54);

  CHECK_EQUAL(54, Vector_ValueAt(vector, 0));
}

TEST(Vector, canAddMultipleElements)
{
  Vector_Push(vector, 1);
  Vector_Push(vector, 2);
  Vector_Push(vector, 3);

  CHECK_EQUAL(1, Vector_ValueAt(vector, 0));
  CHECK_EQUAL(2, Vector_ValueAt(vector, 1));
  CHECK_EQUAL(3, Vector_ValueAt(vector, 2));
}

TEST(Vector, canSetTheValueAtAGivenIndex)
{
  Vector_SetValueAt(vector, 1, 5);

  CHECK_EQUAL(5, Vector_ValueAt(vector, 1));
}

TEST(Vector, returnsInvalidIndexWhenDoesNotContainAValue)
{
  CHECK_EQUAL(INVALID_INDEX, Vector_IndexOf(vector, 5));
}

TEST(Vector, returnsIndexOfAGivenValue)
{
  Vector_Push(vector, 7);
  Vector_Push(vector, 19);

  CHECK_EQUAL(0, Vector_IndexOf(vector, 7));
  CHECK_EQUAL(1, Vector_IndexOf(vector, 19));
}

#include "CppUTest/TestHarness.h"

extern "C"
{
#include "Vector.h"
}

TEST_GROUP(Vector)
{
  Vector * vector;
  void setup() {
    vector = Vector_Create();
  }
  void teardown() {
    Vector_Destroy(vector);
  }
};

TEST(Vector, isEmptyWhenCreated)
{
  CHECK_TEXT(Vector_IsEmpty(vector), "Vector not empty");
}


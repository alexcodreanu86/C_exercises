#include "CppUTest/TestHarness.h"

extern "C"
{
#include "SmallestMultiple.h"
}

TEST_GROUP(SmallestMultiple) {
  struct Factors * container;
  void setup() {
  }
  void teardown() {
    SmallestMultiple_Destroy(container);
  }
};

TEST(SmallestMultiple, returnsEmptyContainer)
{
  container = SmallestMultiple_CreateContainer();


  CHECK_EQUAL(0, container->count);
  CHECK_EQUAL(2, container->capacity);
}

TEST(SmallestMultiple, addsMultiplesOfNumbers) {
  container = SmallestMultiple_AllMultiples(3);
  CHECK_EQUAL(2, container->count);
}

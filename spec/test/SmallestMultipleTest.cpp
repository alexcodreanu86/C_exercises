#include "CppUTest/TestHarness.h"

extern "C"
{
#include "SmallestMultiple.h"
}

TEST_GROUP(SmallestMultiple) {
  void setup() {
  }
  void teardown() {
  }
};

TEST(SmallestMultiple, returnsEmptyContainer)
{
  struct Factors * container = SmallestMultiple_CreateContainer();


  CHECK_EQUAL(0, container->count);
  CHECK_EQUAL(2, container->capacity);

  SmallestMultiple_Destroy(container);
}

TEST(SmallestMultiple, returnsForTwo) {
  struct HashMap * factors = SmallestMultiple_GetFactorsFor(2);

  CHECK_EQUAL(1, HashMap_GetValue(factors, 2));

  HashMap_Destroy(factors);
}

TEST(SmallestMultiple, returnsFactorsForFour)
{
  struct HashMap * factors = SmallestMultiple_GetFactorsFor(4);

  CHECK_EQUAL(2, HashMap_GetValue(factors, 2));

  HashMap_Destroy(factors);
}

TEST(SmallestMultiple, returnsFactorsForSix)
{
  struct HashMap * factors = SmallestMultiple_GetFactorsFor(6);

  CHECK_EQUAL(1, HashMap_GetValue(factors, 2));
  CHECK_EQUAL(1, HashMap_GetValue(factors, 3));

  HashMap_Destroy(factors);
}

TEST(SmallestMultiple, returnsFactorsForAllNumbersUpToThree) {
  struct Factors * factors = SmallestMultiple_AllFactors(3);
  CHECK_EQUAL(1, HashMap_GetValue(factors->container[0], 2));
  CHECK_EQUAL(1, HashMap_GetValue(factors->container[1], 3));

  SmallestMultiple_Destroy(factors);
}

TEST(SmallestMultiple, returnsFactorsForAllNumbersUpToFour) {
  struct Factors * factors = SmallestMultiple_AllFactors(4);
  CHECK_EQUAL(3, factors->count);

  CHECK_EQUAL(2, HashMap_GetValue(factors->container[2], 2));

  SmallestMultiple_Destroy(factors);
}

TEST(SmallestMultiple, returnsTheSmallestMultipleWhenThereIsOnlyOneNumber)
{
  int smallestMultiple = SmallestMultiple_ForNumbersUpTo(2);

  CHECK_EQUAL(2, smallestMultiple);
}

TEST(SmallestMultiple, returnsMultipleWhenNumbersHaveNoFactorsInCommon)
{

  int smallestMultiple = SmallestMultiple_ForNumbersUpTo(3);

  CHECK_EQUAL(6, smallestMultiple);
}

IGNORE_TEST(SmallestMultiple, returnsMultipleWhenNumbersHaveCommonFactors){
  int smallestMultiple = SmallestMultiple_ForNumbersUpTo(4);

  CHECK_EQUAL(12, smallestMultiple);
}

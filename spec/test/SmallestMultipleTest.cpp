#include "CppUTest/TestHarness.h"

extern "C"
{
#include "SmallestMultiple.h"
}

TEST_GROUP(SmallestMultiple)
{
  Multiples * multiples;
  void setup() {}
  void teardown() {
    SmallestMultiples_Destroy(multiples);
  }
};

TEST(SmallestMultiple, returnsNoMultiplesForOne)
{
  multiples = SmallestMultiple_getAllFor(1);
  CHECK_EQUAL(0, multiples->count);
}

TEST(SmallestMultiple, returnsOneMultipleForTwo)
{
  multiples = SmallestMultiple_getAllFor(2);
  CHECK_EQUAL(1, multiples->count);
  CHECK_EQUAL(2, multiples->factors[0]);
}

TEST(SmallestMultiple, returnsMultiplesForFour)
{
  multiples = SmallestMultiple_getAllFor(4);

  CHECK_EQUAL(2, multiples->count);
  CHECK_EQUAL(2, multiples->factors[0]);
  CHECK_EQUAL(2, multiples->factors[1]);
}

TEST(SmallestMultiple, returnsMultiplesForEight)
{
  multiples = SmallestMultiple_getAllFor(8);

  CHECK_EQUAL(3, multiples->count);
  CHECK_EQUAL(2, multiples->factors[0]);
  CHECK_EQUAL(2, multiples->factors[1]);
  CHECK_EQUAL(2, multiples->factors[2]);
}

// TEST(SmallestMultiple, returnsSmallestMultipleForTwo)
// {
// }

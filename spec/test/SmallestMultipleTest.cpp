#include "CppUTest/TestHarness.h"

extern "C"
{
#include "SmallestMultiple.h"
}

TEST_GROUP(SmallestMultiple)
{
  Factors * multiples;
  void setup() {}
  void delete_multiples() {
    SmallestMultiples_Destroy(multiples);
  }
};

TEST(SmallestMultiple, returnsNoMultiplesForOne)
{
  multiples = SmallestMultiple_getAllFor(1);
  CHECK_EQUAL(0, multiples->count);
  delete_multiples();
}

TEST(SmallestMultiple, returnsOneMultipleForTwo)
{
  multiples = SmallestMultiple_getAllFor(2);
  CHECK_EQUAL(1, multiples->count);
  CHECK_EQUAL(2, multiples->factors[0]);
  delete_multiples();
}

TEST(SmallestMultiple, returnsMultiplesForFour)
{
  multiples = SmallestMultiple_getAllFor(4);

  CHECK_EQUAL(2, multiples->count);
  CHECK_EQUAL(2, multiples->factors[0]);
  CHECK_EQUAL(2, multiples->factors[1]);
  delete_multiples();
}

TEST(SmallestMultiple, returnsMultiplesForEight)
{
  multiples = SmallestMultiple_getAllFor(8);

  CHECK_EQUAL(3, multiples->count);
  CHECK_EQUAL(2, multiples->factors[0]);
  CHECK_EQUAL(2, multiples->factors[1]);
  CHECK_EQUAL(2, multiples->factors[2]);
  delete_multiples();
}

TEST(SmallestMultiple, returnsSmallestMultipleForTwo)
{
  int multiple = SmallestMultiple_for(2);

  CHECK_EQUAL(2, multiple);
}

TEST(SmallestMultiple, returnsSmallestMultipleForFour)
{
  int multiple = SmallestMultiple_for(3);

  CHECK_EQUAL(6, multiple);
}

// TEST(SmallestMultiple, returnsSmallestMultipleForSix)
// {
//   int multiple = SmallestMultiple_for(6);
//
//   CHECK_EQUAL(60, multiple);
// }

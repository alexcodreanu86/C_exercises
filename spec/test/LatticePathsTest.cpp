#include "CppUTest/TestHarness.h"

extern "C"
{
#include "LatticePaths.h"
}

TEST_GROUP(LatticePaths) {};

TEST(LatticePaths, returns6For2)
  UNSIGNED_LONGS_EQUAL(6, LatticePaths_for(2))

TEST(LatticePaths, returns20For3)
  UNSIGNED_LONGS_EQUAL(20, LatticePaths_for(3))

TEST(LatticePaths, returnsResultFor20)
  UNSIGNED_LONGS_EQUAL(137846528820, LatticePaths_for(20))

TEST(LatticePaths, combinatorialFor)
  UNSIGNED_LONGS_EQUAL(137846528820, LatticePaths_combinatorialFor(20))

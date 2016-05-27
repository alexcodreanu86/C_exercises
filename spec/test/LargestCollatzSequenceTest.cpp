#include "CppUTest/TestHarness.h"

extern "C"
{
#include "LargestCollatzSequence.h"
}

TEST_GROUP(LargestCollatzSequence) {};

TEST(LargestCollatzSequence, returns1For1)
{
  UNSIGNED_LONGS_EQUAL(1, LCS_SequenceSize(1));
}

TEST(LargestCollatzSequence, returns2For2)
{
  UNSIGNED_LONGS_EQUAL(2, LCS_SequenceSize(2));
}

TEST(LargestCollatzSequence, returns8For3)
{
  UNSIGNED_LONGS_EQUAL(8, LCS_SequenceSize(3));
}

TEST(LargestCollatzSequence, returns8For13)
{
  UNSIGNED_LONGS_EQUAL(8, LCS_SequenceSize(3));
}

TEST(LargestCollatzSequence, returns3ForNumbersSmallerThan4)
{
  UNSIGNED_LONGS_EQUAL(3, LCS_Bellow(4));
}

TEST(LargestCollatzSequence, returns7ForNumbersSmallerThan9)
{
  UNSIGNED_LONGS_EQUAL(7, LCS_Bellow(9));
}

TEST(LargestCollatzSequence, returnsResultFor1Million)
{
  UNSIGNED_LONGS_EQUAL(837799, LCS_Bellow(1000000));
}

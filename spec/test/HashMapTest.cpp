#include "CppUTest/TestHarness.h"

extern "C"
{
#include "HashMap.h"
}

TEST_GROUP(HashMap)
{
  HashMap * hashMap;
  void setup() {
    hashMap = HashMap_Create();
  }
  void teardown() {
    HashMap_Destroy(hashMap);
  }
};

TEST(HashMap, whenCreatedHasKeyReturnsFalse)
{
  CHECK_FALSE_TEXT(HashMap_HasKey(hashMap, 123), "HashMap not empty when created");
}

IGNORE_TEST(HashMap, hasKeyWhenAdded)
{
  HashMap_AddKeyValue(123, 3);

  CHECK_TEXT(HashMap_HasKey(hashMap, 123), "HashMap does not have added key");
}

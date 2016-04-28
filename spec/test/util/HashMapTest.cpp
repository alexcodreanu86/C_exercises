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

TEST(HashMap, hasKeyWhenAdded)
{
  HashMap_AddKeyValue(hashMap, 123, 3);

  CHECK_TEXT(HashMap_HasKey(hashMap, 123), "HashMap does not have added key");
}

TEST(HashMap, returnsTheValueOfTheKey)
{
  HashMap_AddKeyValue(hashMap, 123, 3);

  CHECK_EQUAL(3, HashMap_GetValue(hashMap, 123));
}

TEST(HashMap, suportsMultipleValues)
{
  HashMap_AddKeyValue(hashMap, 123, 3);
  HashMap_AddKeyValue(hashMap, 345, 4);

  CHECK_EQUAL(3, HashMap_GetValue(hashMap, 123));
  CHECK_EQUAL(4, HashMap_GetValue(hashMap, 345));
}


TEST(HashMap, overridesExistingValeu)
{
  HashMap_AddKeyValue(hashMap, 123, 3);
  HashMap_AddKeyValue(hashMap, 123, 5);

  CHECK_EQUAL(5, HashMap_GetValue(hashMap, 123));
}

TEST(HashMap, returnsKeysVector)
{
  HashMap_AddKeyValue(hashMap, 123, 3);
  HashMap_AddKeyValue(hashMap, 234, 5);

  Vector * keys = HashMap_GetKeys(hashMap);

  CHECK_EQUAL(123, Vector_ValueAt(keys, 0));
  CHECK_EQUAL(234, Vector_ValueAt(keys, 1));
}

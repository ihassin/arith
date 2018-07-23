#include <assert.h>
#include "unity.h"
#include "unity_fixture.h"

#include "arith.h"

TEST_GROUP(SubstractionCode);

TEST_SETUP(SubstractionCode)
{
}

TEST_TEAR_DOWN(SubstractionCode)
{
}

TEST(SubstractionCode, SameSize1)
{
    TEST_ASSERT_EQUAL_STRING("34", substract("12", "46"));
}

TEST(SubstractionCode, SameSize2)
{
    TEST_ASSERT_EQUAL_STRING("2", substract("2", "4"));
}

TEST(SubstractionCode, DiffSize1)
{
    TEST_ASSERT_EQUAL_STRING("454", substract("12", "466"));
}

TEST(SubstractionCode, DiffSize2)
{
    TEST_ASSERT_EQUAL_STRING("1230", substract("4", "1234"));
}

TEST(SubstractionCode, DiffSize3)
{
    TEST_ASSERT_EQUAL_STRING("1225", substract("9", "1234"));
}

TEST(SubstractionCode, Borrow1)
{
    TEST_ASSERT_EQUAL_STRING("449", substract("12", "461"));
}

TEST(SubstractionCode, Borrow2)
{
    TEST_ASSERT_EQUAL_STRING("2", substract("998", "1000"));
}

TEST(SubstractionCode, Zero1)
{
    TEST_ASSERT_EQUAL_STRING("0", substract("998", "998"));
}

TEST(SubstractionCode, Zero2)
{
    TEST_ASSERT_EQUAL_STRING("0", substract("9", "9"));
}

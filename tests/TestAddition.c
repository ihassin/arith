#include <assert.h>
#include "unity.h"
#include "unity_fixture.h"

#include "addition.h"

TEST_GROUP(AdditionCode);

TEST_SETUP(AdditionCode)
{
}

TEST_TEAR_DOWN(AdditionCode)
{
}

TEST(AdditionCode, Reverse)
{
    char reverse[] = "hello";
    TEST_ASSERT_EQUAL_STRING("olleh", strrev(reverse));
}

TEST(AdditionCode, SameSize2)
{
    TEST_ASSERT_EQUAL_STRING("46", add("12", "34"));
}

TEST(AdditionCode, SameSize3)
{
    TEST_ASSERT_EQUAL_STRING("578", add("123", "455"));
}

TEST(AdditionCode, DiffSize1)
{
    TEST_ASSERT_EQUAL_STRING("127", add("123", "4"));
}

TEST(AdditionCode, DiffSize2)
{
    TEST_ASSERT_EQUAL_STRING("127", add("4", "123"));
}

TEST(AdditionCode, CarryOver1)
{
    TEST_ASSERT_EQUAL_STRING("11", add("6", "5"));
}

TEST(AdditionCode, CarryOver2)
{
    TEST_ASSERT_EQUAL_STRING("11", add("5", "6"));
}

TEST(AdditionCode, CarryOver3)
{
    TEST_ASSERT_EQUAL_STRING("41", add("15", "26"));
}

TEST(AdditionCode, CarryOver4)
{
    TEST_ASSERT_EQUAL_STRING("1221", add("995", "226"));
}

TEST(AdditionCode, CarryOver5)
{
    TEST_ASSERT_EQUAL_STRING("1887", add("888", "999"));
}


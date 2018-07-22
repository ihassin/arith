#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(AdditionCode)
{
    RUN_TEST_CASE(AdditionCode, Reverse);

    RUN_TEST_CASE(AdditionCode, SameSize2);
    RUN_TEST_CASE(AdditionCode, SameSize3);

    RUN_TEST_CASE(AdditionCode, DiffSize1);
    RUN_TEST_CASE(AdditionCode, DiffSize2);

    RUN_TEST_CASE(AdditionCode, CarryOver1);
    RUN_TEST_CASE(AdditionCode, CarryOver2);
    RUN_TEST_CASE(AdditionCode, CarryOver3);
    RUN_TEST_CASE(AdditionCode, CarryOver4);
    RUN_TEST_CASE(AdditionCode, CarryOver5);
}

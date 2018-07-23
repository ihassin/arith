#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(SubstractionCode)
{
    RUN_TEST_CASE(SubstractionCode, SameSize1);
    RUN_TEST_CASE(SubstractionCode, SameSize2);
    RUN_TEST_CASE(SubstractionCode, SameSize3);
    RUN_TEST_CASE(SubstractionCode, DiffSize1);
    RUN_TEST_CASE(SubstractionCode, DiffSize2);
    RUN_TEST_CASE(SubstractionCode, DiffSize3);
    RUN_TEST_CASE(SubstractionCode, Borrow1);
    RUN_TEST_CASE(SubstractionCode, Borrow2);
    RUN_TEST_CASE(SubstractionCode, Zero1);
    RUN_TEST_CASE(SubstractionCode, Zero2);
}

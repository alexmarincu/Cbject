#include "CException.h"
#include "Interface.h"
#include "unity.h"
TEST_FILE("Interface.c")
/**
 * @brief
 */
void setUp(void) {
}
/**
 * @brief
 */
void tearDown(void) {
}
/**
 * @test Test Interface initialization
 */
void test_Interface_init(void) {
    Operations * operations;
    Interface * type = initInterface_(salloc_(Interface), 5, operations);
    TEST_ASSERT_EQUAL(5, toInterface_(type)->offset);
    TEST_ASSERT_EQUAL_PTR(operations, type->operations);
}

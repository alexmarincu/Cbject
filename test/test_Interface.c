#include "CException.h"
#include "unity.h"

#include "Interface.h"

TEST_FILE("Interface.c")
TEST_FILE("Type.c")

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
    Interface * interface = Interface_init(salloc_(Interface), 5, operations);
    TEST_ASSERT_EQUAL(5, toType_(interface)->offset);
    TEST_ASSERT_EQUAL_PTR(operations, interface->operations);
}

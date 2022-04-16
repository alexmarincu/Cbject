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
    Any * ops;
    Interface * interface = Interface_init(salloc_(Interface), 5, ops);
    TEST_ASSERT_EQUAL(5, toType_(interface)->offset);
    TEST_ASSERT_EQUAL_PTR(ops, interface->ops);
}

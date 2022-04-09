#include "CException.h"
#include "unity.h"

#include "Interface.h"

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
 * @brief Test Interface initialization
 */
void test_Interface_init(void) {
    Object * object;
    Any * operations;
    Interface * interface = Interface_init(salloc_(Interface), object, operations);
    TEST_ASSERT_EQUAL_PTR(object, interface->object);
    TEST_ASSERT_EQUAL_PTR(operations, interface->operations);
}

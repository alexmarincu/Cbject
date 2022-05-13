#include "CException.h"
#include "unity.h"

#include "Type.h"

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
 * @test Test Type initialization
 */
void test_Type_init(void) {
    Interface * interface;
    Type * type = initType_(salloc_(Type), 5, interface);
    TEST_ASSERT_EQUAL(5, toType_(type)->offset);
    TEST_ASSERT_EQUAL_PTR(interface, type->interface);
}

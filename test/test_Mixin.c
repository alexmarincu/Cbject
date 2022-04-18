#include "CException.h"
#include "unity.h"

#include "Mixin.h"

TEST_FILE("Mixin.c")
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
 * @test Test Mixin initialization
 */
void test_Mixin_init(void) {
    Interface * interface;
    Mixin * mixin = Mixin_init(salloc_(Mixin), 5, interface);
    TEST_ASSERT_EQUAL(5, toType_(mixin)->offset);
    TEST_ASSERT_EQUAL_PTR(interface, mixin->interface);
}

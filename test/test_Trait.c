#include "CException.h"
#include "unity.h"

#include "Trait.h"

TEST_FILE("Trait.c")
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
 * @test Test Trait initialization
 */
void test_Trait_init(void) {
    Interface * interface;
    Trait * trait = initTrait_(salloc_(Trait), 5, interface);
    TEST_ASSERT_EQUAL(5, toType_(trait)->offset);
    TEST_ASSERT_EQUAL_PTR(interface, trait->interface);
}

#include "CException.h"
#include "Interface.h"
#include "unity.h"
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
    TEST_ASSERT_EQUAL(5, ((Type *)interface)->offset);
    TEST_ASSERT_EQUAL_PTR(operations, ((Type *)interface)->operations);
}

#include "CException.h"
#include "Class.h"
#include "unity.h"
TEST_FILE("Class.c")
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
typedef int DontCare;
typedef DontCare Test;
typedef DontCare Test_Operations;
/**
 * @brief Dummy operations function to use in test
 * @return Test_Operations const * The reference to the Test_Operations
 */
static Test_Operations const * Test_Operations_(void) {
    static Test_Operations operations;
    return &operations;
}
static Class const * Test_Class_(void) {
    static Class cls;
    return &cls;
}
/**
 * @test Test class initialization
 * -# Allocate and initialize a Class
 * -# Check class name, object size, operations and super class
 */
void test_Class_init(void) {
    Class * cls = initClass_(salloc_(Class), Test, Test);
    TEST_ASSERT_EQUAL_STRING("Test", cls->name);
    TEST_ASSERT_EQUAL_size_t(sizeof(Test), cls->objectSize);
    TEST_ASSERT_EQUAL_PTR(Test_Operations_(), ((Type *)cls)->operations);
    TEST_ASSERT_EQUAL_PTR(Test_Class_(), cls->superClass);
}

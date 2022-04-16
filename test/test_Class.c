#include "CException.h"
#include "unity.h"

#include "Class.h"

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
typedef DontCare TestOperations;

/**
 * @brief Dummy operations function to use in test
 * @return TestOperations const * The reference to the TestOperations
 */
static TestOperations const * TestOperations_(void) {
    static TestOperations operations;
    return &operations;
}

static Class const * TestClass_(void) {
    static Class cls;
    return &cls;
}

/**
 * @test Test class initialization
 * -# Allocate and initialize a Class
 * -# Check class name, object size, operations and super class
 */
void test_Class_init(void) {
    Class * cls = initClass_(salloc_(Class), Test, TestClass_());
    TEST_ASSERT_EQUAL_STRING("Test", cls->name);
    TEST_ASSERT_EQUAL_size_t(sizeof(Test), cls->objectSize);
    TEST_ASSERT_EQUAL_PTR(TestOperations_(), toInterface_(cls)->operations);
    TEST_ASSERT_EQUAL_PTR(TestClass_(), cls->superClass);
}

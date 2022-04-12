#include "CException.h"
#include "unity.h"

#include "Class.h"

TEST_FILE("Class.c")

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
typedef DontCare TestOps;

/**
 * @brief Dummy ops function to use in test
 * @return TestOps const * The reference to the TestOps
 */
static TestOps const * TestOps_(void) {
    static TestOps ops;
    return &ops;
}

static Class const * TestClass_(void) {
    static Class cls;
    return &cls;
}

/**
 * @test Test class initialization
 * -# Allocate and initialize a Class
 * -# Check class name, object size, ops and super class
 */
void test_Class_init(void) {
    Class * cls = initClass_(salloc_(Class), Test, Test);
    TEST_ASSERT_EQUAL_STRING("Test", cls->name);
    TEST_ASSERT_EQUAL_size_t(sizeof(Test), cls->objectSize);
    TEST_ASSERT_EQUAL_PTR(TestOps_(), cls->ops);
    TEST_ASSERT_EQUAL_PTR(TestClass_(), cls->superClass);
}

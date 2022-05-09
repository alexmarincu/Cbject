#include "CException.h"
#include "unity.h"

#include "Class.h"

TEST_FILE("Class.c")
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

typedef int DontCare;
typedef DontCare Test;
typedef DontCare TestInterface;

/**
 * @brief Dummy interface function to use in test
 * @return TestInterface const * The reference to the TestInterface
 */
static TestInterface const * TestInterface_(void) {
    static TestInterface interface;
    return &interface;
}

static Class const * TestClass_(void) {
    static Class cls;
    return &cls;
}

/**
 * @test Test class initialization
 * -# Allocate and initialize a Class
 * -# Check class name, object size, interface and super class
 */
void test_Class_init(void) {
    Class * cls = initClass_(salloc_(Class), Test, Test);
    TEST_ASSERT_EQUAL_STRING("Test", cls->name);
    TEST_ASSERT_EQUAL_size_t(sizeof(Test), cls->objectSize);
    TEST_ASSERT_EQUAL_PTR(TestInterface_(), toTrait_(cls)->interface);
    TEST_ASSERT_EQUAL_PTR(TestClass_(), cls->superClass);
}

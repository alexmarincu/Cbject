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
typedef DontCare TestOperations;

/**
 * @brief Dummy operations function to use in test
 * @return TestOperations const * The reference to the TestOperations
 */
TestOperations const * TestOperations_(void) {
    static TestOperations operations;
    return &operations;
}

/**
 * @brief Test class initialization
 */
void test_Class_init(void) {
    Class * superClass;
    Class * class_ = initClass_(salloc_(Class), Test, superClass);
    TEST_ASSERT_EQUAL_STRING("Test", class_->name);
    TEST_ASSERT_EQUAL_size_t(sizeof(Test), class_->objectSize);
    TEST_ASSERT_EQUAL_PTR(TestOperations_(), class_->operations);
    TEST_ASSERT_EQUAL_PTR(superClass, class_->superClass);
}

#include "CException.h"
#include "unity.h"

#include "Class.h"

TEST_FILE("Class.c")

/**
 * @brief
 *
 */
void setUp(void) {
}

/**
 * @brief
 *
 */
void tearDown(void) {
}

/**
 * @brief Test class initialization
 *
 */
void test_Class_init(void) {
    Class * class_ = Class_init(salloc_(Class), "Test", 1, &class_, &class_);
    TEST_ASSERT_EQUAL_STRING("Test", class_->name);
    TEST_ASSERT_EQUAL_size_t(1, class_->objectSize);
    TEST_ASSERT_EQUAL_PTR(&class_, class_->operations);
    TEST_ASSERT_EQUAL_PTR(&class_, class_->superClass);
}

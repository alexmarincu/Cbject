#include "CException.h"
#include "Object.h"
#include "unity.h"
TEST_FILE("Object.c")
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
 * @test
 */
void test_Object_class(void) {
    Object_Class const * objectClass = class_(Object);
    TEST_ASSERT_EQUAL_size_t(sizeof(Object), class_(Object)->objectSize);
    TEST_ASSERT_NOT_NULL(class_(Object)->teardown);
    TEST_ASSERT_NOT_NULL(class_(Object)->copy);
    TEST_ASSERT_NOT_NULL(class_(Object)->equals);
    TEST_ASSERT_NOT_NULL(class_(Object)->hashCode);
}
/**
 * @test
 */
void test_Object_init(void) {
    Object * object = initObject_(Object, salloc_(Object));
    TEST_ASSERT_EQUAL_PTR(classOf_(object), class_(Object));
}
/**
 * @test
 */
void test_Object_equals(void) {
    Object * object = initObject_(Object, salloc_(Object));
    TEST_ASSERT_TRUE(equals_(object, object));
    Object * otherObject = initObject_(Object, salloc_(Object));
    TEST_ASSERT_FALSE(equals_(object, otherObject));
}
/**
 * @test
 */
void test_Object_hashCode(void) {
    Object * object = initObject_(Object, salloc_(Object));
    TEST_ASSERT_EQUAL_UINT64((uint64_t)object, hashCode_(object));
}
typedef struct {
    extends_(Object_Class);
} Test_Class;
Test_Class * Test_Class_(void) {
    static Test_Class class;
    return &class;
}
/**
 * @test
 */
void test_Object_isOfClass(void) {
    Object * object = initObject_(Object, salloc_(Object));
    typedef struct {
        extends_(Object_Class);
    } Test_Class;
    Test_Class testClass;
    TEST_ASSERT_TRUE(isOfClass_(object, Object));
    TEST_ASSERT_FALSE(isOfClass_(object, Test));
}
/**
 * @test
 */
void test_Object_copy(void) {
    Object * object = initObject_(Object, salloc_(Object));
    Object * copyObject = copy_(Object, object, salloc_(Object));
    TEST_ASSERT_EQUAL_MEMORY(object, copyObject, class_(Object)->objectSize);
}
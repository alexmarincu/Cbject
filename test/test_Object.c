#include "CException.h"
#include "Object.h"
#include "unity.h"
TEST_FILE("Object.c")
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
 * @test
 */
void test_Object_class(void) {
    Object_Class const * objectClass = class_(Object);
    TEST_ASSERT_EQUAL_STRING("Object", objectClass->name);
    TEST_ASSERT_EQUAL_size_t(sizeof(Object), objectClass->objectSize);
    TEST_ASSERT_EQUAL_PTR(Object_Operations_(), ((Object_Interface *)objectClass)->operations);
}
/**
 * @test
 */
void test_Object_init(void) {
    Object * object = Object_init(salloc_(Object), (Object_Interface *)class_(Object));
    TEST_ASSERT_EQUAL_PTR(rObjectOf_(object), object);
    TEST_ASSERT_EQUAL_PTR(classOf_(object), class_(Object));
}
/**
 * @test
 */
void test_Object_equals(void) {
    Object * object = Object_init(salloc_(Object), (Object_Interface *)class_(Object));
    TEST_ASSERT_TRUE(equals_(object, object));
    Object * otherObject = Object_init(salloc_(Object), (Object_Interface *)class_(Object));
    TEST_ASSERT_FALSE(equals_(object, otherObject));
}
/**
 * @test
 */
void test_Object_hashCode(void) {
    Object * object = Object_init(salloc_(Object), (Object_Interface *)class_(Object));
    TEST_ASSERT_EQUAL_UINT64((uint64_t)object, hashCode_(object));
}
/**
 * @test
 */
void test_Object_isOfClass(void) {
    Object * object = Object_init(salloc_(Object), (Object_Interface *)class_(Object));
    TEST_ASSERT_TRUE(isOfClass_(object, Object));
}
/**
 * @test
 */
void test_Object_copy(void) {
    Object * object = Object_init(salloc_(Object), (Object_Interface *)class_(Object));
    Object * copyObject = copy_(Object, object);
    TEST_ASSERT_EQUAL_MEMORY(object, copyObject, class_(Object)->objectSize);
    dealloc_(copyObject);
}
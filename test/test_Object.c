#include "CException.h"
#include "Object.h"
#include "unity.h"
TEST_FILE("Object.c")
TEST_FILE("Class.c")
TEST_FILE("Interface.c")
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
    Class const * objectClass = toClass_(Object_Class_());
    TEST_ASSERT_EQUAL_STRING("Object", objectClass->name);
    TEST_ASSERT_EQUAL_size_t(sizeof(Object), objectClass->objectSize);
    TEST_ASSERT_EQUAL_PTR(Object_Operations_(), toInterface_(objectClass)->operations);
}
/**
 * @test
 */
void test_Object_init(void) {
    Object * object = initObject_(salloc_(Object), Object);
    TEST_ASSERT_EQUAL_PTR(objectOf_(object), object);
    TEST_ASSERT_EQUAL_PTR(classOf_(object), Object_Class_());
}
/**
 * @test
 */
void test_Object_equals(void) {
    Object * object = initObject_(salloc_(Object), Object);
    TEST_ASSERT_TRUE(equals_(object, object));
    Object * otherObject = initObject_(salloc_(Object), Object);
    TEST_ASSERT_FALSE(equals_(object, otherObject));
}
/**
 * @test
 */
void test_Object_hashCode(void) {
    Object * object = initObject_(salloc_(Object), Object);
    TEST_ASSERT_EQUAL_UINT64((uint64_t)object, hashCode_(object));
}
/**
 * @test
 */
void test_Object_isOfClass(void) {
    Object * object = initObject_(salloc_(Object), Object);
    TEST_ASSERT_TRUE(isOfClass_(object, Object));
}
/**
 * @test
 */
void test_Object_copy(void) {
    Object * object = initObject_(salloc_(Object), Object);
    Object * copyObject = copy_(Object, object);
    TEST_ASSERT_EQUAL_MEMORY(object, copyObject, toClass_(Object_Class_())->objectSize);
    dealloc_(copyObject);
}
/**
 * @test
 */
void test_Object_cast(void) {
    Object * object = initObject_(salloc_(Object), Object);
    Object * castObject = to_(Object, object);
}
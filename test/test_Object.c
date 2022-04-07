#include "CException.h"
#include "unity.h"

#include "Object.h"

TEST_FILE("Object.c")
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
 * @brief
 *
 */
void test_Object_class(void) {
    Class const * objectClass = ObjectClass_();
    TEST_ASSERT_EQUAL_STRING("Object", objectClass->name);
    TEST_ASSERT_EQUAL_size_t(sizeof(Object), objectClass->objectSize);
    TEST_ASSERT_EQUAL_PTR(ObjectOperations_(), objectClass->operations);
}

/**
 * @brief
 *
 */
void test_Object_init(void) {
    Object * object = initObject_(salloc_(Object), ObjectClass_());
    TEST_ASSERT_EQUAL_PTR(classOf_(object), ObjectClass_());
}

/**
 * @brief
 *
 */
void test_Object_equals(void) {
    Object * object = initObject_(salloc_(Object), ObjectClass_());
    TEST_ASSERT_TRUE(equals_(object, object));

    Object * otherObject = initObject_(salloc_(Object), ObjectClass_());
    TEST_ASSERT_FALSE(equals_(object, otherObject));
}

/**
 * @brief
 *
 */
void test_Object_hashCode(void) {
    Object * object = initObject_(salloc_(Object), ObjectClass_());
    TEST_ASSERT_EQUAL_UINT64((uint64_t)object, hashCode_(object));
}

/**
 * @brief
 *
 */
void test_Object_isOfClass(void) {
    Object * object = initObject_(salloc_(Object), ObjectClass_());
    TEST_ASSERT_TRUE(isOfClass_(object, ObjectClass_()));
    TEST_ASSERT_FALSE(isOfClass_(object, NULL));
}

/**
 * @brief
 *
 */
void test_Object_copy(void) {
    Object * object = initObject_(salloc_(Object), ObjectClass_());
    Object * copyObject = copy_(Object, object);
    TEST_ASSERT_EQUAL_MEMORY(object, copyObject, ObjectClass_()->objectSize);
    delete_(copyObject);
}

/**
 * @brief
 *
 */
void test_Object_cast(void) {
    Object * object = initObject_(salloc_(Object), ObjectClass_());
    Object * castObject = cast_(Object, object);
}
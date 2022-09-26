#include "CException.h"
#include "Object.h"
#include "unity.h"
TEST_FILE("Object.c")
void setUp(void) {
}
void tearDown(void) {
}
/* tag::test[]
===== test_Object_class
====
Test setup of Object_Class

.Steps
. Get Object_Class instance
. Check if object size stored in class is equal to the actual object size
. Check that the function pointers in the class are initialized
====
end::test[] */
void test_Object_class(void) {
    Object_Class const * objectClass = class_(Object);
    TEST_ASSERT_EQUAL_size_t(sizeof(Object), class_(Object)->objectSize);
    TEST_ASSERT_NOT_NULL(class_(Object)->teardown);
    TEST_ASSERT_NOT_NULL(class_(Object)->copy);
    TEST_ASSERT_NOT_NULL(class_(Object)->equals);
    TEST_ASSERT_NOT_NULL(class_(Object)->hashCode);
}
/* tag::test[]
===== test_Object_init
====
Test initialization of Object

.Steps
. Allocate object on stack an initialize it
. Check if object class points to Object_Class instance
====
end::test[] */
void test_Object_init(void) {
    Object * object = initObject_(Object, salloc_(Object));
    TEST_ASSERT_EQUAL_PTR(classOf_(object), class_(Object));
}
/* tag::test[]
===== test_Object_equals
====
Test equals method

.Steps
. Allocate object on stack an initialize it
. Check if equals method return true when comparing object to self
. Allocate another object on stack an initialize it
. Check if equals method return false when comparing the two objects
====
end::test[] */
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
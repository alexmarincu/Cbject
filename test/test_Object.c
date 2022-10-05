#include "CException.h"
#include "Object.h"
#include "unity.h"
TEST_FILE("Object.c")
void setUp(void) {
}
void tearDown(void) {
}
/* tag::test[]
= test_Object_class
====
Test setup of ObjectClass

.Steps
. Get ObjectClass instance
. Check if object size stored in class is equal to the actual object size
. Check that the function pointers in the class are initialized
====
end::test[] */
void test_Object_class(void) {
    TEST_ASSERT_EQUAL_size_t(sizeof(Object), class_(Object)->objectSize);
    TEST_ASSERT_NOT_NULL(class_(Object)->teardown);
    TEST_ASSERT_NOT_NULL(class_(Object)->copy);
    TEST_ASSERT_NOT_NULL(class_(Object)->equals);
    TEST_ASSERT_NOT_NULL(class_(Object)->hashCode);
}
/* tag::test[]
= test_Object_init
====
Test initialization of Object

.Steps
. Allocate object on stack an initialize it
. Check if object class points to ObjectClass instance
====
end::test[] */
void test_Object_init(void) {
    Object * object = sallocInit_(Object);
    TEST_ASSERT_EQUAL_PTR(classOf_(object), class_(Object));
}
/* tag::test[]
= test_Object_equals
====
Test equals method

.Steps
. Allocate object on stack an initialize it
. Check if equals method returns true when comparing object to self
. Allocate another object on stack an initialize it
. Check if equals method returns false when comparing the two objects
====
end::test[] */
void test_Object_equals(void) {
    Object * object = sallocInit_(Object);
    TEST_ASSERT_TRUE(equals_(object, object));
    Object * otherObject = sallocInit_(Object);
    TEST_ASSERT_FALSE(equals_(object, otherObject));
}
/* tag::test[]
= test_Object_hashCode
====
Test hashCode method

.Steps
. Allocate object on stack an initialize it
. Check if hashCode method returns the address in memory of the object
====
end::test[] */
void test_Object_hashCode(void) {
    Object * object = sallocInit_(Object);
    TEST_ASSERT_EQUAL_UINT64((uint64_t)object, hashCode_(object));
}
/* tag::test[]
= test_Object_isOfClass
====
Test isOfClass method

.Preconditions
. Define a dummy TestClass which extends ObjectClass

.Steps
. Allocate object on stack an initialize it
. Check if isOfClass method returns true when checked against Object
. Check if isOfClass method returns false when checked against Test
====
end::test[] */
typedef struct {
    extends_(ObjectClass);
} TestClass;
TestClass * TestClass_instance(void) {
    static TestClass class;
    return &class;
}
void test_Object_isOfClass(void) {
    Object * object = sallocInit_(Object);
    TEST_ASSERT_TRUE(isOfClass_(object, Object));
    TEST_ASSERT_FALSE(isOfClass_(object, Test));
}
/* tag::test[]
= test_Object_copy
====
Test copy method

.Steps
. Allocate object on stack an initialize it
. Allocate another object on stack and copy the first object into it
. Check if the memory sections occupied by the two objects are equal
. Allocate another object on heap and copy the first object into it
. Check if the memory sections occupied by the two objects are equal
. Deallocate the object from the heap memory
====
end::test[] */
void test_Object_copy(void) {
    Object * object = sallocInit_(Object);
    Object * copyObjectInStack = sallocCopy_(Object, object);
    TEST_ASSERT_EQUAL_MEMORY(object, copyObjectInStack, objectSizeOf_(object));
    Object * copyObjectInHeap = allocCopy_(Object, object);
    TEST_ASSERT_EQUAL_MEMORY(object, copyObjectInHeap, objectSizeOf_(object));
    dealloc_(copyObjectInHeap);
}
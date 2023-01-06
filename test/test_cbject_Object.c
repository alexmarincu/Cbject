#include "CException.h"
#include "cbject.h"
#include "cbject_Object.h"
#include "unity.h"
#include <string.h>
TEST_FILE("cbject_Object.c")
void setUp(void) {
}
void tearDown(void) {
}
/* tag::test[]
= test_cbject_ObjectClass_getInstance
====
Test setup of ObjectClass

.Steps
. Get ObjectClass instance
. Check if object size stored in class is equal to the actual object size
. Check that the function pointers in the class are initialized
====
end::test[] */
void test_cbject_ObjectClass_getInstance(void) {
    TEST_ASSERT_EQUAL_STRING("Object", cbject_ObjectClass_getInstance()->name);
    TEST_ASSERT_EQUAL_size_t(sizeof(cbject_Object), cbject_ObjectClass_getInstance()->objectSize);
    TEST_ASSERT_NULL(cbject_ObjectClass_getInstance()->superClass);
    TEST_ASSERT_NOT_NULL(cbject_ObjectClass_getInstance()->teardown);
    TEST_ASSERT_NOT_NULL(cbject_ObjectClass_getInstance()->copy);
    TEST_ASSERT_NOT_NULL(cbject_ObjectClass_getInstance()->equals);
    TEST_ASSERT_NOT_NULL(cbject_ObjectClass_getInstance()->hashCode);
}
/* tag::test[]
= test_cbject_Object_init
====
Test initialization of cbject_Object

.Steps
. Allocate object on stack an initialize it
. Check if object class points to cbject_ObjectClass instance
====
end::test[] */
void test_cbject_Object_init(void) {
    cbject_Object * object = cbject_Object_init(cbject_salloc(cbject_Object));
    TEST_ASSERT_EQUAL_PTR(cbject_getClassOfObject(object), cbject_ObjectClass_getInstance());
}
/* tag::test[]
= test_cbject_Object_equals
====
Test equals method

.Steps
. Allocate object on stack an initialize it
. Check if equals method returns true when comparing object to self
. Allocate another object on stack an initialize it
. Check if equals method returns false when comparing the two objects
====
end::test[] */
void test_cbject_Object_equals(void) {
    cbject_Object * object = cbject_Object_init(cbject_salloc(cbject_Object));
    TEST_ASSERT_TRUE(cbject_equals(object, object));
    cbject_Object * otherObject = cbject_Object_init(cbject_salloc(cbject_Object));
    TEST_ASSERT_FALSE(cbject_equals(object, otherObject));
}
/* tag::test[]
= test_cbject_Object_hashCode
====
Test hashCode method

.Steps
. Allocate object on stack an initialize it
. Check if hashCode method returns the address in memory of the object
====
end::test[] */
void test_cbject_Object_hashCode(void) {
    cbject_Object * object = cbject_Object_init(cbject_salloc(cbject_Object));
    TEST_ASSERT_EQUAL_UINT64((uint64_t)object, cbject_hashCode(object));
}
/* tag::test[]
= test_cbject_Object_isOfClass
====
Test isOfClass method

.Preconditions
. Define a dummy TestClass which extends cbject_ObjectClass

.Steps
. Allocate object on stack an initialize it
. Check if isOfClass method returns true when checked against cbject_Object
. Check if isOfClass method returns false when checked against Test
====
end::test[] */
typedef struct {
    cbject_is(cbject_ObjectClass);
} TestClass;
TestClass * TestClass_getInstance(void) {
    static TestClass testClass;
    return &testClass;
}
void test_cbject_Object_isOfClass(void) {
    cbject_Object * object = cbject_Object_init(cbject_salloc(cbject_Object));
    TEST_ASSERT_TRUE(cbject_isOfClass(object, cbject_Object));
    TEST_ASSERT_FALSE(cbject_isOfClass(object, Test));
}
/* tag::test[]
= test_cbject_Object_copy
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
void test_cbject_Object_copy(void) {
    cbject_Object * object = cbject_Object_init(cbject_salloc(cbject_Object));
    cbject_Object * copyObjectInStack = cbject_Object_copy(object, cbject_salloc(cbject_Object));
    TEST_ASSERT_EQUAL_MEMORY(object, copyObjectInStack, cbject_getSizeOfObject(object));
    cbject_Object * copyObjectInHeap = cbject_Object_copy(object, cbject_alloc(cbject_Object));
    TEST_ASSERT_EQUAL_MEMORY(object, copyObjectInHeap, cbject_getSizeOfObject(object));
    cbject_dealloc(copyObjectInHeap);
}
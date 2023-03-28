#include "CException.h"
#include "cbject.h"
#include "unity.h"

TEST_FILE("cbject_Object.c")

void setUp(void) {
}
void tearDown(void) {
}

/*************************************************************************************************** tag::test[]
= test_cbject_ObjectClass
====
Test setup of ObjectClass

.Steps
. Get ObjectClass instance
. Check if object size stored in class is equal to the actual object size
. Check that the function pointers in the class are initialized
====
end::test[] ***************************************************************************************/
void test_cbject_ObjectClass_instance(void) {
    TEST_ASSERT_EQUAL_STRING("cbject_Object", cbject_ObjectClass_instance()->name);
    TEST_ASSERT_EQUAL_size_t(sizeof(cbject_Object), cbject_ObjectClass_instance()->instanceSize);
    TEST_ASSERT_NULL(cbject_ObjectClass_instance()->superClass);
}

/*************************************************************************************************** tag::test[]
= test_cbject_Object_init
====
Test initialization of cbject_Object

.Steps
. Allocate object on stack an initialize it
. Check if object class points to cbject_ObjectClass instance
====
end::test[] ***************************************************************************************/
void test_cbject_Object_init(void) {
    cbject_Object * object = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    TEST_ASSERT_EQUAL_PTR(cbject_Object_class(object), cbject_ObjectClass_instance());
}

/*************************************************************************************************** tag::test[]
= test_cbject_Object_equals
====
Test equals method

.Steps
. Allocate object on stack an initialize it
. Check if equals method returns true when comparing object to self
. Allocate another object on stack an initialize it
. Check if equals method returns false when comparing the two objects
====
end::test[] ***************************************************************************************/
void test_cbject_Object_equals(void) {
    cbject_Object * object = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    TEST_ASSERT_TRUE(cbject_utils_equals(object, object));
    cbject_Object * otherObject = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    TEST_ASSERT_FALSE(cbject_utils_equals(object, otherObject));
}

/*************************************************************************************************** tag::test[]
= test_cbject_Object_hashCode
====
Test hashCode method

.Steps
. Allocate object on stack an initialize it
. Check if hashCode method returns the address in memory of the object
====
end::test[] ***************************************************************************************/
void test_cbject_Object_hashCode(void) {
    cbject_Object * object = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    TEST_ASSERT_EQUAL_UINT64((uint64_t)object, cbject_utils_hashCode(object));
}

/*************************************************************************************************** tag::test[]
= test_cbject_Object_isOfClass
====
Test isOfType method

.Preconditions
. Define a dummy TestClass which extends cbject_ObjectClass

.Steps
. Allocate object on stack an initialize it
. Check if isOfType method returns true when checked against cbject_Object
. Check if isOfType method returns false when checked against Test
====
end::test[] ***************************************************************************************/
#define cbject_Class (Test, cbject_Object)
typedef struct Test Test;
typedef struct TestClass TestClass;
struct Test {
    cbject_Object object;
};
cbject_utils_noPool;
struct TestClass {
    cbject_ObjectClass klass;
};
cbject_ObjectClass * TestClass_instance(void) {
    static cbject_ObjectClass self;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&self);
    }
    return &self;
}
#undef cbject_Class
void test_cbject_Object_isOfClass(void) {
    cbject_Object * object = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    TEST_ASSERT_TRUE(cbject_utils_isOfType(object, cbject_Object));
    TEST_ASSERT_FALSE(cbject_utils_isOfType(object, Test));
}

/*************************************************************************************************** tag::test[]
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
end::test[] ***************************************************************************************/
void test_cbject_Object_copy(void) {
    cbject_Object * object = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * copyObjectInStack = cbject_utils_copy(object, cbject_utils_stackAlloc(cbject_Object));
    TEST_ASSERT_EQUAL_MEMORY(object, copyObjectInStack, cbject_Object_instanceSize(object));
    cbject_Object * copyObjectInHeap = cbject_utils_copy(object, cbject_utils_alloc(cbject_Object));
    TEST_ASSERT_EQUAL_MEMORY(object, copyObjectInHeap, cbject_Object_instanceSize(object));
    cbject_utils_release(copyObjectInHeap);
}
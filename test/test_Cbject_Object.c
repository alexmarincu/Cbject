#include "CException.h"
#include "Cbject_Object.h"
#include "Cbject_ShortNames.h"
#include "unity.h"
#include <string.h>
TEST_FILE("Cbject_Object.c")
void setUp(void) {
}
void tearDown(void) {
}
/* tag::test[]
= test_Cbject_ObjectClass_instance
====
Test setup of ObjectClass

.Steps
. Get ObjectClass instance
. Check if object size stored in class is equal to the actual object size
. Check that the function pointers in the class are initialized
====
end::test[] */
void test_Cbject_ObjectClass_instance(void) {
    TEST_ASSERT_EQUAL_PTR(Cbject_ObjectClass_instance(), x_class(x_Object));
    TEST_ASSERT_EQUAL_STRING("Object", x_class(x_Object)->name);
    TEST_ASSERT_EQUAL_size_t(sizeof(x_Object), x_class(x_Object)->objectSize);
    TEST_ASSERT_NULL(x_class(x_Object)->superClass);
    TEST_ASSERT_NOT_NULL(x_class(x_Object)->teardown);
    TEST_ASSERT_NOT_NULL(x_class(x_Object)->copy);
    TEST_ASSERT_NOT_NULL(x_class(x_Object)->equals);
    TEST_ASSERT_NOT_NULL(x_class(x_Object)->hashCode);
}
/* tag::test[]
= test_Cbject_Object_init
====
Test initialization of x_Object

.Steps
. Allocate object on stack an initialize it
. Check if object class points to x_ObjectClass instance
====
end::test[] */
void test_Cbject_Object_init(void) {
    x_Object * object = x_sallocInit(x_Object);
    TEST_ASSERT_EQUAL_PTR(x_classOf(object), x_class(x_Object));
}
/* tag::test[]
= test_Cbject_Object_equals
====
Test equals method

.Steps
. Allocate object on stack an initialize it
. Check if equals method returns true when comparing object to self
. Allocate another object on stack an initialize it
. Check if equals method returns false when comparing the two objects
====
end::test[] */
void test_Cbject_Object_equals(void) {
    x_Object * object = x_sallocInit(x_Object);
    TEST_ASSERT_TRUE(x_equals(object, object));
    x_Object * otherObject = x_sallocInit(x_Object);
    TEST_ASSERT_FALSE(x_equals(object, otherObject));
}
/* tag::test[]
= test_Cbject_Object_hashCode
====
Test hashCode method

.Steps
. Allocate object on stack an initialize it
. Check if hashCode method returns the address in memory of the object
====
end::test[] */
void test_Cbject_Object_hashCode(void) {
    x_Object * object = x_sallocInit(x_Object);
    TEST_ASSERT_EQUAL_UINT64((uint64_t)object, x_hashCode(object));
}
/* tag::test[]
= test_Cbject_Object_isOfClass
====
Test isOfClass method

.Preconditions
. Define a dummy TestClass which extends x_ObjectClass

.Steps
. Allocate object on stack an initialize it
. Check if isOfClass method returns true when checked against x_Object
. Check if isOfClass method returns false when checked against Test
====
end::test[] */
typedef struct {
    x_is(x_ObjectClass);
} TestClass;
TestClass * TestClass_instance(void) {
    static TestClass testClass;
    return &testClass;
}
void test_Cbject_Object_isOfClass(void) {
    x_Object * object = x_sallocInit(x_Object);
    TEST_ASSERT_TRUE(x_isOfClass(object, x_Object));
    TEST_ASSERT_FALSE(x_isOfClass(object, Test));
}
/* tag::test[]
= test_Cbject_Object_copy
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
void test_Cbject_Object_copy(void) {
    x_Object * object = x_sallocInit(x_Object);
    x_Object * copyObjectInStack = x_sallocCopy(x_Object, object);
    TEST_ASSERT_EQUAL_MEMORY(object, copyObjectInStack, x_objectSizeOf(object));
    x_Object * copyObjectInHeap = x_allocCopy(x_Object, object);
    TEST_ASSERT_EQUAL_MEMORY(object, copyObjectInHeap, x_objectSizeOf(object));
    x_dealloc(copyObjectInHeap);
}
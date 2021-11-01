#include "unity.h"

#include "Circle.h"
#include "Shape.h"

TEST_FILE("Object.c")
TEST_FILE("Circle.c")
TEST_FILE("Shape.c")

static void checkCircleInit(Circle const * const c);
static void checkCircleDataAccessors(Circle * const c);

void setUp(void) {}

void tearDown(void) {}

/* tag::testDoc[]
== Circle on heap
Test creation on heap and data accessors of Circle object

end::testDoc[] */
void test_Circle_Heap(void)
{
    Circle * c = Circle_createOnHeap((CircleParams){{4, 5}, 1});
    checkCircleInit(c);
    checkCircleDataAccessors(c);
    Circle_delete(c);
}

/* tag::testDoc[]
== Circle on static pool
Test retrieval from static pool and data accessors of Circle object

end::testDoc[] */
void test_Circle_StaticPool(void)
{
    Circle * c = Circle_getFromStaticPool((CircleParams){{4, 5}, 1});
    checkCircleInit(c);
    checkCircleDataAccessors(c);
}

/* tag::testDoc[]
== Circle on stack
Test creation on stack and data accessors of Circle object

end::testDoc[] */
void test_Circle_Stack(void)
{
    Circle * c = Circle_createOnStack((Circle *)&(CircleContainer){}, (CircleParams){{4, 5}, 1});
    checkCircleInit(c);
    checkCircleDataAccessors(c);
}

static void checkCircleInit(Circle const * const c)
{
    TEST_ASSERT_NOT_NULL(c);
    TEST_ASSERT_EQUAL_UINT8(4, Shape_origin(Cast(Shape, c)).x);
    TEST_ASSERT_EQUAL_UINT8(5, Shape_origin(Cast(Shape, c)).y);
    TEST_ASSERT_EQUAL_UINT8(1, Circle_radius(c));
}

static void checkCircleDataAccessors(Circle * const c)
{
    Shape_originSet(Cast(Shape, c), (Point){1, 2});
    TEST_ASSERT_EQUAL_UINT8(1, Shape_origin(Cast(Shape, c)).x);
    TEST_ASSERT_EQUAL_UINT8(2, Shape_origin(Cast(Shape, c)).y);
    Circle_radiusSet(c, 2);
    TEST_ASSERT_EQUAL_UINT8(2, Circle_radius(c));
}
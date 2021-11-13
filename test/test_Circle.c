#include "unity.h"

#include "Circle.h"
#include "Shape.h"

TEST_FILE("Object.c")
TEST_FILE("Circle.c")
TEST_FILE("Shape.c")

static void checkCircleInit(Circle const * const circle);
static void checkCircleDataAccessors(Circle * const circle);

void setUp(void) {}

void tearDown(void) {}

/* tag::testDescription[]
== Circle on heap
Test creation on heap and data accessors of Circle object

end::testDescription[] */
void test_Circle_Heap(void)
{
    Circle * circle = Create(Circle, &(CircleParams){{4, 5}, 1});
    checkCircleInit(circle);
    checkCircleDataAccessors(circle);
    Delete(circle, Circle);
}

/* tag::testDescription[]
== Circle on static pool
Test retrieval from static pool and data accessors of Circle object

end::testDescription[] */
void test_Circle_StaticPool(void)
{
    Circle * circle = Get(Circle, &(CircleParams){{4, 5}, 1});
    checkCircleInit(circle);
    checkCircleDataAccessors(circle);
}

/* tag::testDescription[]
== Circle on stack
Test creation on stack and data accessors of Circle object

end::testDescription[] */
void test_Circle_Stack(void)
{
    Circle * circle = StackCreate(Circle, &(CircleParams){{4, 5}, 1});
    checkCircleInit(circle);
    checkCircleDataAccessors(circle);
}

static void checkCircleInit(Circle const * const circle)
{
    TEST_ASSERT_NOT_NULL(circle);
    TEST_ASSERT_EQUAL_UINT8(4, Shape_origin(Cast(circle, Shape)).x);
    TEST_ASSERT_EQUAL_UINT8(5, Shape_origin(Cast(circle, Shape)).y);
    TEST_ASSERT_EQUAL_UINT8(1, Circle_radius(circle));
}

static void checkCircleDataAccessors(Circle * const circle)
{
    Shape_originSet(Cast(circle, Shape), (Point){1, 2});
    TEST_ASSERT_EQUAL_UINT8(1, Shape_origin(Cast(circle, Shape)).x);
    TEST_ASSERT_EQUAL_UINT8(2, Shape_origin(Cast(circle, Shape)).y);
    Circle_radiusSet(circle, 2);
    TEST_ASSERT_EQUAL_UINT8(2, Circle_radius(circle));
}
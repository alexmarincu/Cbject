#include "CException.h"
#include "unity.h"

#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"

TEST_FILE("Object.c")
TEST_FILE("Rectangle.c")
TEST_FILE("Shape.c")
TEST_FILE("Circle.c")

static void checkRectangleInit(Rectangle const * const rectangle);
static void checkRectangleDataAccessors(Rectangle * const rectangle);
static void checkMakeSquare(Rectangle * const rectangle);
static void checkCast(Rectangle * const rectangle);

void setUp(void) {}

void tearDown(void) {}

/* tag::testDescription[]
== Rectangle on heap
Test creation on heap and data accessors of Rectangle object

end::testDescription[] */
void test_Rectangle_Heap(void)
{
    Rectangle * rectangle = Create(Rectangle, &(RectangleParams){{4, 5}, 1, 2});
    checkRectangleInit(rectangle);
    checkRectangleDataAccessors(rectangle);
    checkMakeSquare(rectangle);
    checkCast(rectangle);
    Delete(rectangle, Rectangle);
}

/* tag::testDescription[]
== Rectangle on static pool
Test retrieval from static pool and data accessors of Rectangle object

end::testDescription[] */
void test_Rectangle_StaticPool(void)
{
    Rectangle * rectangle = Get(Rectangle, &(RectangleParams){{4, 5}, 1, 2});
    checkRectangleInit(rectangle);
    checkRectangleDataAccessors(rectangle);
}

/* tag::testDescription[]
== Rectangle on stack
Test creation on stack and data accessors of Rectangle object

end::testDescription[] */
void test_Rectangle_Stack(void)
{
    Rectangle * rectangle = StackCreate(Rectangle, &(RectangleParams){{4, 5}, 1, 2});
    checkRectangleInit(rectangle);
    checkRectangleDataAccessors(rectangle);
}

static void checkRectangleInit(Rectangle const * const rectangle)
{
    TEST_ASSERT_NOT_NULL(rectangle);
    TEST_ASSERT_EQUAL_UINT8(4, Shape_origin(Cast(rectangle, Shape)).x);
    TEST_ASSERT_EQUAL_UINT8(5, Shape_origin(Cast(rectangle, Shape)).y);
    TEST_ASSERT_EQUAL_UINT8(1, Rectangle_width(rectangle));
    TEST_ASSERT_EQUAL_UINT8(2, Rectangle_height(rectangle));
    TEST_ASSERT_EQUAL_UINT8(1 * 2, Shape_area(Cast(rectangle, Shape)));
}

static void checkRectangleDataAccessors(Rectangle * const rectangle)
{
    Shape_originSet(Cast(rectangle, Shape), (Point){1, 2});
    TEST_ASSERT_EQUAL_UINT8(1, Shape_origin(Cast(rectangle, Shape)).x);
    TEST_ASSERT_EQUAL_UINT8(2, Shape_origin(Cast(rectangle, Shape)).y);
    Rectangle_widthSet(rectangle, 2);
    Rectangle_heightSet(rectangle, 3);
    TEST_ASSERT_EQUAL_UINT8(2, Rectangle_width(rectangle));
    TEST_ASSERT_EQUAL_UINT8(3, Rectangle_height(rectangle));
    TEST_ASSERT_EQUAL_UINT8(2 * 3, Shape_area(Cast(rectangle, Shape)));
}

static void checkMakeSquare(Rectangle * const rectangle)
{
    Rectangle_makeSquare(rectangle, 5);
    TEST_ASSERT_EQUAL_UINT8(5, Rectangle_width(rectangle));
    TEST_ASSERT_EQUAL_UINT8(5, Rectangle_height(rectangle));
    TEST_ASSERT_EQUAL_UINT8(5 * 5, Shape_area(Cast(rectangle, Shape)));
}

static void checkCast(Rectangle * const rectangle)
{
    CEXCEPTION_T e;

    Try
    {
        Cast(NULL, Rectangle);
        TEST_FAIL_MESSAGE("Cast of NULL pointer did not assert");
    }
    Catch(e)
    {
        TEST_MESSAGE("Cast of NULL pointer did assert");
    }

    Try
    {
        Cast(rectangle, Circle);
        TEST_FAIL_MESSAGE("Cast to illegal class did not assert");
    }
    Catch(e)
    {
        TEST_MESSAGE("Cast to illegal class did assert");
    }

    Try
    {
        Cast(rectangle, Shape);
        TEST_MESSAGE("Cast to super class is working");
    }
    Catch(e)
    {
        TEST_FAIL_MESSAGE("Cast to super class is not working");
    }
}
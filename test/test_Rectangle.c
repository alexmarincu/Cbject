#include "unity.h"

#include "Rectangle.h"
#include "Shape.h"

TEST_FILE("Object.c")
TEST_FILE("Rectangle.c")
TEST_FILE("Shape.c")

static void checkRectangleInit(Rectangle const * const rectangle);
static void checkRectangleDataAccessors(Rectangle * const rectangle);
static void checkMakeSquare(Rectangle * const rectangle);

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
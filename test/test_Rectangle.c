#include "unity.h"

#include "Rectangle.h"
#include "Shape.h"

TEST_FILE("Cbject.c")
TEST_FILE("Rectangle.c")
TEST_FILE("Shape.c")

static void checkRectangleInit(Rectangle const * const r);
static void checkRectanglePropsAccessors(Rectangle const * const r);

void setUp(void) {}

void tearDown(void) {}

/*============================================================================= tag::testDoc[]
== Rectangle on heap
.Description
Test creation on heap and props accessors of Rectangle object

=============================================================================== end::testDoc[] */
void test_Rectangle_Heap(void)
{
    Rectangle * r = New(Rectangle, &((RectangleParams){.origin.x = 4, .origin.y = 5, .width = 1, .height = 2}));
    checkRectangleInit(r);
    checkRectanglePropsAccessors(r);
    free(r);
}

/*============================================================================= tag::testDoc[]
== Rectangle on static pool
.Description
Test retrieval from static pool and props accessors of Rectangle object

=============================================================================== end::testDoc[] */
void test_Rectangle_StaticPool(void)
{
    Rectangle * r = Get(Rectangle, &((RectangleParams){.origin.x = 4, .origin.y = 5, .width = 1, .height = 2}));
    checkRectangleInit(r);
    checkRectanglePropsAccessors(r);
}

static void checkRectangleInit(Rectangle const * const r)
{
    TEST_ASSERT_NOT_NULL(r);
    TEST_ASSERT_EQUAL_UINT8(4, Shape_origin(Rectangle_toShape(r)).x);
    TEST_ASSERT_EQUAL_UINT8(5, Shape_origin(Rectangle_toShape(r)).y);
    TEST_ASSERT_EQUAL_UINT8(1, Rectangle_width(r));
    TEST_ASSERT_EQUAL_UINT8(2, Rectangle_height(r));
}

static void checkRectanglePropsAccessors(Rectangle const * const r)
{
    Shape_originSet(r, (Point){1, 2});
    TEST_ASSERT_EQUAL_UINT8(1, Shape_origin(Rectangle_toShape(r)).x);
    TEST_ASSERT_EQUAL_UINT8(2, Shape_origin(Rectangle_toShape(r)).y);
    Rectangle_widthSet(r, 2);
    Rectangle_heightSet(r, 3);
    TEST_ASSERT_EQUAL_UINT8(2, Rectangle_width(r));
    TEST_ASSERT_EQUAL_UINT8(3, Rectangle_height(r));
}
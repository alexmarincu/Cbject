#include "Cbject.h"
#include "Rectangle.h"
#include "Shape.h"
#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_Rectanglexsss(void)
{
    Rectangle * r = New(Rectangle, &((RectangleParams){.origin.x = 4, .origin.y = 5, .width = 1, .height = 2}));
    TEST_ASSERT_NOT_NULL(r);
    TEST_ASSERT_EQUAL_UINT32(4, Shape_origin(Rectangle_toShape(r)).x);
    free(r);
}
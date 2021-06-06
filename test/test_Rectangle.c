#include "../src/Application/Rectangle.h"
#include "../src/Application/Shape.h"
#include "../src/Cbj/Cbject.h"
#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_Rectangle_NeedToImplement(void)
{
    Rectangle * r = New(Rectangle, &((RectangleParams){.origin.x = 4, .origin.y = 5, .width = 1, .height = 2}));
    TEST_ASSERT_NOT_NULL(r);
    TEST_ASSERT_EQUAL_UINT32(4, Shape_origin(Rectangle_toShape(r)).x);
    free(r);
    //TEST_IGNORE_MESSAGE("Need to Implement mainApp");
}
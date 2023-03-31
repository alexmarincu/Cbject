#include "CException.h"
#include "Rectangle.h"
#include "unity.h"

TEST_FILE("Rectangle.c")
TEST_FILE("Shape.c")
TEST_FILE("Drawable.c")
TEST_FILE("cbject_Object.c")

void setUp(void) {
}
void tearDown(void) {
}

void test_Rectangle_init(void) {
    Rectangle * rectangle = Rectangle_init(cbject_alloc(Rectangle), (Point){ 0, 1 }, 2, 3);
    TEST_ASSERT_EQUAL_UINT32(2, Rectangle_getWidth(rectangle));
    TEST_ASSERT_EQUAL_UINT32(3, Rectangle_getHeight(rectangle));
    TEST_ASSERT_EQUAL_UINT8(2 * 3, Shape_area((Shape *)rectangle));
    cbject_release(rectangle);
    Rectangle * rectangle2 = Rectangle_init(cbject_acquire(Rectangle), (Point){ 0, 1 }, 2, 3);
    TEST_ASSERT_EQUAL_UINT32(2, Rectangle_getWidth(rectangle2));
    TEST_ASSERT_EQUAL_UINT32(3, Rectangle_getHeight(rectangle2));
    TEST_ASSERT_EQUAL_UINT8(2 * 3, Shape_area((Shape *)rectangle2));
    cbject_release(rectangle2);
}

void test_Rectangle_setters(void) {
    Rectangle * rectangle = Rectangle_init(cbject_alloc(Rectangle), (Point){ 0, 1 }, 2, 3);
    Rectangle_setWidth(rectangle, 4);
    Rectangle_setHeight(rectangle, 5);
    TEST_ASSERT_EQUAL_UINT32(4, Rectangle_getWidth(rectangle));
    TEST_ASSERT_EQUAL_UINT32(5, Rectangle_getHeight(rectangle));
    TEST_ASSERT_EQUAL_UINT8(4 * 5, Shape_area((Shape *)rectangle));
    cbject_release(rectangle);
}

void test_Rectangle_makeSquare(void) {
    Rectangle * rectangle = Rectangle_init(cbject_alloc(Rectangle), (Point){ 0, 1 }, 2, 3);
    Rectangle_makeSquare(rectangle, 4);
    TEST_ASSERT_EQUAL_UINT32(4, Rectangle_getWidth(rectangle));
    TEST_ASSERT_EQUAL_UINT32(4, Rectangle_getHeight(rectangle));
    TEST_ASSERT_EQUAL_UINT8(4 * 4, Shape_area((Shape *)rectangle));
    cbject_release(rectangle);
}

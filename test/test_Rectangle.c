#include "CException.h"
#include "Rectangle.h"
#include "unity.h"
TEST_FILE("Rectangle.c")
TEST_FILE("Shape.c")
TEST_FILE("Drawable.c")
TEST_FILE("Object.c")
TEST_FILE("Trait.c")
void setUp(void) {
    initClass_(Shape);
    initClass_(Rectangle);
}
void tearDown(void) {
}
void test_Rectangle_init(void) {
    Rectangle * rectangle = allocInit_(Rectangle, (Point){ 0, 1 }, 2, 3);
    TEST_ASSERT_EQUAL_UINT32(2, Rectangle_getWidth(rectangle));
    TEST_ASSERT_EQUAL_UINT32(3, Rectangle_getHeight(rectangle));
    TEST_ASSERT_EQUAL_UINT8(2 * 3, Shape_area(to_(Shape, rectangle)));
    dealloc_(rectangle);
}
void test_Rectangle_setters(void) {
    Rectangle * rectangle = allocInit_(Rectangle, (Point){ 0, 1 }, 2, 3);
    Rectangle_setWidth(rectangle, 4);
    Rectangle_setHeight(rectangle, 5);
    TEST_ASSERT_EQUAL_UINT32(4, Rectangle_getWidth(rectangle));
    TEST_ASSERT_EQUAL_UINT32(5, Rectangle_getHeight(rectangle));
    TEST_ASSERT_EQUAL_UINT8(4 * 5, Shape_area(to_(Shape, rectangle)));
    dealloc_(rectangle);
}
void test_Rectangle_makeSquare(void) {
    Rectangle * rectangle = allocInit_(Rectangle, (Point){ 0, 1 }, 2, 3);
    Rectangle_makeSquare(rectangle, 4);
    TEST_ASSERT_EQUAL_UINT32(4, Rectangle_getWidth(rectangle));
    TEST_ASSERT_EQUAL_UINT32(4, Rectangle_getHeight(rectangle));
    TEST_ASSERT_EQUAL_UINT8(4 * 4, Shape_area(to_(Shape, rectangle)));
    dealloc_(rectangle);
}
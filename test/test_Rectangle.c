#include "CException.h"
#include "Rectangle.h"
#include "unity.h"
TEST_FILE("Rectangle.c")
TEST_FILE("Shape.c")
TEST_FILE("Drawable.c")
TEST_FILE("Object.c")
TEST_FILE("Trait.c")
void setUp(void) {
}
void tearDown(void) {
}
void test_Rectangle_init(void) {
    Rectangle * r = initObject_(Rectangle, alloc_(Rectangle), (Point){ 0, 1 }, 2, 3);
    TEST_ASSERT_EQUAL_UINT32(2, Rectangle_getWidth(r));
    TEST_ASSERT_EQUAL_UINT32(3, Rectangle_getHeight(r));
    TEST_ASSERT_EQUAL_UINT8(2 * 3, Shape_area(to_(Shape, r)));
    dealloc_(r);
}
void test_Rectangle_setters(void) {
    Rectangle * r = initObject_(Rectangle, alloc_(Rectangle), (Point){ 0, 1 }, 2, 3);
    Rectangle_setWidth(r, 4);
    Rectangle_setHeight(r, 5);
    TEST_ASSERT_EQUAL_UINT32(4, Rectangle_getWidth(r));
    TEST_ASSERT_EQUAL_UINT32(5, Rectangle_getHeight(r));
    TEST_ASSERT_EQUAL_UINT8(4 * 5, Shape_area(to_(Shape, r)));
    dealloc_(r);
}
void test_Rectangle_makeSquare(void) {
    Rectangle * r = initObject_(Rectangle, alloc_(Rectangle), (Point){ 0, 1 }, 2, 3);
    Rectangle_makeSquare(r, 4);
    TEST_ASSERT_EQUAL_UINT32(4, Rectangle_getWidth(r));
    TEST_ASSERT_EQUAL_UINT32(4, Rectangle_getHeight(r));
    TEST_ASSERT_EQUAL_UINT8(4 * 4, Shape_area(to_(Shape, r)));
    dealloc_(r);
}
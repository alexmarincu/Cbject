#include "CException.h"
#include "unity.h"

#include "Rectangle.h"

TEST_FILE("Rectangle.c")
TEST_FILE("Shape.c")
TEST_FILE("Drawable.c")
TEST_FILE("Object.c")
TEST_FILE("Class.c")
TEST_FILE("Interface.c")
TEST_FILE("Type.c")

/**
 * @brief
 */
void setUp(void) {
}

/**
 * @brief
 */
void tearDown(void) {
}

/**
 * @test
 */
void test_Rectangle_init(void) {
    Rectangle * r = Rectangle_init(alloc_(Rectangle), (Point){ 0, 1 }, 2, 3);
    TEST_ASSERT_EQUAL_UINT32(2, Rectangle_getWidth(r));
    TEST_ASSERT_EQUAL_UINT32(3, Rectangle_getHeight(r));
    TEST_ASSERT_EQUAL_UINT8(2 * 3, Shape_area(Rectangle_getShape(r)));
    dealloc_(r);
}

/**
 * @test
 */
void test_Rectangle_setters(void) {
    Rectangle * r = Rectangle_init(alloc_(Rectangle), (Point){ 0, 1 }, 2, 3);
    Rectangle_setWidth(r, 4);
    Rectangle_setHeight(r, 5);
    TEST_ASSERT_EQUAL_UINT32(4, Rectangle_getWidth(r));
    TEST_ASSERT_EQUAL_UINT32(5, Rectangle_getHeight(r));
    TEST_ASSERT_EQUAL_UINT8(4 * 5, Shape_area(Rectangle_getShape(r)));
    dealloc_(r);
}

/**
 * @test
 */
void test_Rectangle_makeSquare(void) {
    Rectangle * r = Rectangle_init(alloc_(Rectangle), (Point){ 0, 1 }, 2, 3);
    Rectangle_makeSquare(r, 4);
    TEST_ASSERT_EQUAL_UINT32(4, Rectangle_getWidth(r));
    TEST_ASSERT_EQUAL_UINT32(4, Rectangle_getHeight(r));
    TEST_ASSERT_EQUAL_UINT8(4 * 4, Shape_area(Rectangle_getShape(r)));
    dealloc_(r);
}
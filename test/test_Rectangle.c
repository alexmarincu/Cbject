#include "CException.h"
#include "unity.h"

#include "Rectangle.h"

TEST_FILE("Rectangle.c")
TEST_FILE("Shape.c")
TEST_FILE("Drawable.c")
TEST_FILE("Object.c")
TEST_FILE("Class.c")
TEST_FILE("Interface.c")

static void checkRectangleInit(Rectangle const * const rectangle);
static void checkRectangleDataAccessors(Rectangle * const rectangle);
static void checkMakeSquare(Rectangle * const rectangle);
static void checkCast(Rectangle * const rectangle);

/**
 * @brief
 *
 */
void setUp(void) {
}

/**
 * @brief
 *
 */
void tearDown(void) {
}

/**
 * @brief
 *
 */
void test_Rectangle_Heap(void) {
    Rectangle * r1 = Rectangle_init(new_(Rectangle), (Point){ 0, 0 }, 5, 7);
    Rectangle * r2 = copy_(Rectangle, r1);

    TEST_ASSERT_EQUAL_UINT8(5 * 7, Shape_area(Rectangle_getShape(r1)));
    TEST_ASSERT_EQUAL_UINT8(5 * 7, Shape_area(Rectangle_getShape(r2)));
    Drawable_draw(Rectangle_getDrawable(r1));
    delete_(r1);
    delete_(r2);
}

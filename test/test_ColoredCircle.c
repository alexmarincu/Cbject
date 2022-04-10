#include "CException.h"
#include "unity.h"

#include "ColoredCircle.h"

TEST_FILE("ColoredCircle.c")
TEST_FILE("Circle.c")
TEST_FILE("Shape.c")
TEST_FILE("Drawable.c")
TEST_FILE("Object.c")
TEST_FILE("Class.c")
TEST_FILE("Interface.c")

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
 * @brief
 */
void test_ColoredCircle_init(void) {
    ColoredCircle * c = init_(ColoredCircle, new_(ColoredCircle), (Point){ 0, 1 }, 2, Color_blue);
    Drawable_draw(&c->_xCircle._iDrawable);
    delete_(c);
}
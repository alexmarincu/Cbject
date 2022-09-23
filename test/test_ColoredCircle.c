#include "CException.h"
#include "ColoredCircle.h"
#include "unity.h"
TEST_FILE("ColoredCircle.c")
TEST_FILE("Circle.c")
TEST_FILE("Shape.c")
TEST_FILE("Drawable.c")
TEST_FILE("Object.c")
TEST_FILE("Module.c")
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
void test_ColoredCircle_init(void) {
    ColoredCircle * c = initObject_(ColoredCircle, alloc_(ColoredCircle), (Point){ 0, 1 }, 2, Color_blue);
    Drawable_draw(moduleOf_(c, Circle, Drawable));
    dealloc_(c);
}
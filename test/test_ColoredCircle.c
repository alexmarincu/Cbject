#include "CException.h"
#include "ColoredCircle.h"
#include "unity.h"
TEST_FILE("ColoredCircle.c")
TEST_FILE("Circle.c")
TEST_FILE("Shape.c")
TEST_FILE("Drawable.c")
TEST_FILE("Object.c")
TEST_FILE("Trait.c")
void setUp(void) {
}
void tearDown(void) {
}
void test_ColoredCircle_init(void) {
    ColoredCircle * coloredCircle = initObject_(ColoredCircle, alloc_(ColoredCircle), (Point){ 0, 1 }, 2, Color_blue);
    Drawable_draw(traitOf_(coloredCircle, Circle, Drawable));
    dealloc_(coloredCircle);
}
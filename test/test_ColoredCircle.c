#include "CException.h"
#include "ColoredCircle.h"
#include "unity.h"

TEST_FILE("ColoredCircle.c")
TEST_FILE("Circle.c")
TEST_FILE("Shape.c")
TEST_FILE("Drawable.c")
TEST_FILE("cbject_Object.c")

void setUp(void) {
}
void tearDown(void) {
}

void test_ColoredCircle_init(void) {
    ColoredCircle * coloredCircle = ColoredCircle_init(cbject_alloc(ColoredCircle), (Point){ 0, 1 }, 2, Color_blue);
    Drawable_draw((Drawable *)coloredCircle);
    cbject_release(coloredCircle);
}

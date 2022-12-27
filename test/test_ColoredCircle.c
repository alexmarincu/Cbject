#include "CException.h"
#include "ColoredCircle.h"
#include "unity.h"
TEST_FILE("ColoredCircle.c")
TEST_FILE("Circle.c")
TEST_FILE("Shape.c")
TEST_FILE("Drawable.c")
TEST_FILE("Cbject_Object.c")
TEST_FILE("Cbject_Trait.c")
void setUp(void) {
}
void tearDown(void) {
}
void test_ColoredCircle_init(void) {
    ColoredCircle * coloredCircle = x_allocInit(ColoredCircle, (Point){ 0, 1 }, 2, Color_blue);
    Drawable_draw(x_traitOf(Circle, Drawable, coloredCircle));
    x_dealloc(coloredCircle);
}
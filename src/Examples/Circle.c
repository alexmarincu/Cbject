#include "Circle.h"
#include <stdio.h>

#define cbject_Class (Circle, Drawable)
cbject_noPool;

Circle * Circle_init(
    Circle * const self,
    Point origin,
    uint32_t radius
) {
    Drawable_init((Drawable *)self, origin, 0);
    self->radius = radius;
    return self;
}

static float area(Shape const * const self) {
    Circle * circle = (Circle *)self;
    return circle->radius * circle->radius * 3.14;
}

static void draw(Drawable const * const self) {
    Circle * circle = (Circle *)self;
    float const radius = circle->radius;
    float const tolerance = radius / 2;
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            float eq = x * x + y * y - radius * radius;
            printf(((eq < tolerance) && (eq > -tolerance)) ? "*" : " ");
        }
        printf("\n");
    }
}

static cbject_Object * terminate(cbject_Object * self) {
    return cbject_invokeSuperMethod(cbject_Object, terminate, self);
}

Circle_Class * Circle_Class_instance(void) {
    static Circle_Class self;
    cbject_doOnce {
        cbject_Class_setup(&self);
        ((cbject_Object_Class *)&self)->terminate = terminate;
        ((Shape_Class *)&self)->area = area;
        ((Drawable_Class *)&self)->draw = draw;
    }
    return &self;
}

#undef cbject_Class

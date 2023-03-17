#include "Circle.h"
#include <stdio.h>

#define cbject_Class (Circle, Drawable)
cbject_allocPool(0);

Circle * Circle_init(
    Circle * const circle,
    Point origin,
    uint32_t radius
) {
    Drawable_init(
        &circle->drawable,
        origin,
        0
    );
    circle->radius = radius;
    return circle;
}

static float area(Shape const * const shape) {
    Circle * circle = (Circle *)shape;
    return circle->radius * circle->radius * 3.14;
}

static void draw(Drawable const * const drawable) {
    Circle * circle = (Circle *)drawable;
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

static cbject_Object * terminate(cbject_Object * object) {
    return cbject_invokeSuperMethod(cbject_Object, terminate, object);
}

CircleClass * CircleClass_instance(void) {
    static CircleClass klass;
    cbject_doOnce {
        cbject_Class_setup(&klass);
        klass.drawableClass.shapeClass.objectClass.terminate = terminate;
        klass.drawableClass.shapeClass.area = area;
        klass.drawableClass.draw = draw;
    }
    return &klass;
}

#undef cbject_Class

#include "Application.h"
#include "Circle.h"
#include "Greeting.h"
#include "Rectangle.h"
#include <stdio.h>

#define cbject_Class (Application, cbject_Singleton)

struct Application {
    cbject_Singleton super;
    Circle * circle;
    Rectangle * rectangle;
};

cbject_utils_noPool;

Application * Application_instance(void) {
    static Application self;
    cbject_utils_doOnce {
        cbject_Singleton_init((cbject_Singleton *)&self);
    }
    return &self;
}

static void greetingExample(Application * const self) {
    (void)(self);
    // Allocate and initialize a Greeting application
    Greeting * greeting = Greeting_init(cbject_utils_alloc(Greeting), "Hello Cbject!");
    // Call Greeting print function on the greeting application
    Greeting_print(greeting);
    // Free memory allocated for the Greeting application
    cbject_utils_release(greeting);
}

static void circleExample(Application * const self) {
    // Allocate and initialize a Circle object
    self->circle = Circle_init(cbject_utils_alloc(Circle), (Point){ 0, 1 }, 2);
    // Get circle radius
    uint32_t radius = self->circle->radius;
    (void)(radius);
    // Set circle radius
    self->circle->radius = 3;
    // Get circle area through Shape object polymorphic call
    float area = Shape_area((Shape *)self->circle);
    (void)(area);
    // Get circle shape origin
    Point origin = ((Shape *)self->circle)->origin;
    (void)(origin);
    // set circle shape origin
    ((Shape *)self->circle)->origin = (Point){ 4, 5 };
    // Draw circle through Drawable trait polymorphic call
    Drawable_draw((Drawable *)self->circle);
}

static void rectangleExample(Application * const self) {
    // Allocate and initialize a Rectangle object
    self->rectangle = Rectangle_init(cbject_utils_alloc(Rectangle), ((Point){ 0, 1 }), 2, 3);
    // Get rectangle width and height
    uint32_t width = Rectangle_getWidth(self->rectangle);
    (void)(width);
    uint32_t height = Rectangle_getHeight(self->rectangle);
    (void)(height);
    // Set rectangle with and height
    Rectangle_setWidth(self->rectangle, 4);
    Rectangle_setHeight(self->rectangle, 5);
    // Get rectangle area through Shape object polymorphic call
    float area = Shape_area((Shape *)self->rectangle);
    (void)(area);
    // Get rectangle shape origin
    Point origin = ((Shape *)self->rectangle)->origin;
    (void)(origin);
    // set rectangle shape origin
    ((Shape *)self->rectangle)->origin = (Point){ 6, 7 };
    // Draw rectangle through Drawable trait polymorphic call
    Drawable_draw((Drawable *)self->rectangle);
}

static void polymorphismExample(Application * const self) {
    // Prepare a list of shapes
    Shape * const shapes[] = {
        (Shape *)self->circle,
        (Shape *)self->rectangle,
    };
    // Loop through the list of shapes and call various polymorphic functions
    for (uint8_t i = 0; i < cbject_utils_Array_length(shapes); i++) {
        // Get area through Shape object polymorphic call
        float area = Shape_area(shapes[i]);
        (void)(area);
        // Get size of shape object
        size_t instanceSize = cbject_Object_instanceSize(shapes[i]);
        (void)(instanceSize);
        // Get hash code of shape object
        uint64_t hashCode = cbject_utils_hashCode(shapes[i]);
        (void)(hashCode);
        // Check class of chape object
        if (cbject_utils_isOfType(shapes[i], Circle)) {
            // Get circle radius
            uint32_t radius = ((Circle *)shapes[i])->radius;
            (void)(radius);
        } else if (cbject_utils_isOfType(shapes[i], Rectangle)) {
            // Get rectangle width and height
            uint32_t width = Rectangle_getWidth((Rectangle *)shapes[i]);
            (void)(width);
            uint32_t height = Rectangle_getHeight((Rectangle *)shapes[i]);
            (void)(height);
        }
    }
}

void Application_main(Application * const self) {
    greetingExample(self);
    circleExample(self);
    rectangleExample(self);
    polymorphismExample(self);
}

static cbject_Object * terminate(cbject_Object * const self) {
    Application * application = (Application *)self;
    cbject_utils_release(application->rectangle);
    cbject_utils_release(application->circle);
    return cbject_utils_invokeSuperMethod(cbject_Object, terminate, self);
}

ApplicationClass * ApplicationClass_instance(void) {
    static ApplicationClass self;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&self);
        ((cbject_ObjectClass *)&self)->terminate = terminate;
    }
    return &self;
}

#undef cbject_Class

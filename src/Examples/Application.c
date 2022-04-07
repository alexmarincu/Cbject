#include "Application.h"
#include "Circle.h"
#include "Greeting.h"
#include "Rectangle.h"
#include <stdio.h>

/**
 * @brief
 *
 */
struct Application {
    extends_(Object);
    Circle * circle;
    Rectangle * rectangle;
};

static void circleExample(Application * const this_);
static void greetingExample(Application * const this_);
static void rectangleExample(Application * const this_);
static void polymorphismExample(Application * const this_);

/**
 * @brief
 *
 * @param this_
 */
void Application_main(Application * const this_) {
    greetingExample(this_);
    circleExample(this_);
    rectangleExample(this_);
    polymorphismExample(this_);
}

/**
 * @brief
 *
 * @param this_
 */
static void greetingExample(Application * const this_) {
    Greeting * greeting = Greeting_init(new_(Greeting), "Hello Cbject!");
    Greeting_print(greeting);
    delete_(greeting);
}

/**
 * @brief
 *
 * @param this_
 */
static void circleExample(Application * const this_) {
    printf("\n= Circle example:\n");
    this_->circle = Circle_init(new_(Circle), (Point){ 0, 1 }, 1);
    printf("radius = %d\n", this_->circle->radius);
    printf("Set radius to 2\n");
    this_->circle->radius = 10;
    printf("radius = %d\n", this_->circle->radius);
    printf("area = %.2f\n", Shape_area(&this_->circle->_iShape));
    printf("origin.x = %d\n", this_->circle->_iShape.origin.x);
    printf("origin.y = %d\n", this_->circle->_iShape.origin.y);
    printf("Set origin to {2, 3}\n");
    this_->circle->_iShape.origin = (Point){ 2, 3 };
    printf("origin.x = %d\n", this_->circle->_iShape.origin.x);
    printf("origin.y = %d\n", this_->circle->_iShape.origin.y);
    Drawable_draw(&this_->circle->_iDrawable);
    Circle_rotate(this_->circle, 30);

    if (isOfClass_(this_->circle, CircleClass_())) {
        printf("is Circle\n");
    }

    printf("type name = %s\n", classNameOf_(this_->circle));
}

/**
 * @brief
 *
 * @param this_
 */
static void rectangleExample(Application * const this_) {
    printf("\n= rectangle example:\n");
    this_->rectangle = Rectangle_init(new_(Rectangle), (Point){ 12, 23 }, 34, 2);
    printf("width = %d\n", Rectangle_getWidth(this_->rectangle));
    printf("height = %d\n", Rectangle_getHeight(this_->rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_setWidth(this_->rectangle, 2);
    Rectangle_setHeight(this_->rectangle, 3);
    printf("width = %d\n", Rectangle_getWidth(this_->rectangle));
    printf("height = %d\n", Rectangle_getHeight(this_->rectangle));
    Rectangle * rectangle = Rectangle_init(new_(Rectangle), (Point){ 0, 0 }, 5, 10);
    printf("area = %.2f\n", Shape_area(Rectangle_getShape(rectangle)));
    Drawable_draw(Rectangle_getDrawable(rectangle));
    delete_(rectangle);
}

/**
 * @brief
 *
 * @param this_
 */
static void polymorphismExample(Application * const this_) {
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        &this_->circle->_iShape,
        Rectangle_getShape(this_->rectangle),
    };

    for (uint8_t i = 0; i < lengthOf_(shapes); i++) {
        printf("shapes[%d] area = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d] objectSize = %d\n", i, objectSizeOf_(interfaceObjectOf_(shapes[i])));
        printf("shapes[%d] hashCode = %d\n", i, hashCode_(interfaceObjectOf_(shapes[i])));
    }
}

/**
 * @brief
 *
 * @param this_
 * @param params
 */
Application * init(Application * const this_) {
    initObject_(this_, ApplicationClass_());
}

/**
 * @brief
 *
 * @param this_
 */
static void finalize(Application * const this_) {
    delete_(this_->rectangle);
    delete_(this_->circle);
}

/**
 * @brief Returns the same singleton object instead of a copy
 *
 * @param this_ The singleton Application object
 * @return Application*
 */
static Application * copy(Application * const this_) {
    return this_;
}

/**
 * @brief
 *
 * @param params
 * @return Application*
 */
Application * Application_(void) {
    static Application this_;

    doOnce_({
        init(&this_);
    });

    return &this_;
}

/**
 * @brief
 *
 * @return ApplicationOperations const*
 */
ApplicationOperations const * ApplicationOperations_(void) {
    static ApplicationOperations operations;

    doOnce_({
        operations.objectOperations = *ObjectOperations_();
        operations.objectOperations.finalize = (ObjectOperation_finalize)finalize;
        operations.objectOperations.copy = (ObjectOperation_copy)copy;
    });

    return &operations;
}

/**
 * @brief
 *
 * @return Class const*
 */
Class const * ApplicationClass_(void) {
    static Class class_;

    doOnce_({
        initClass_(&class_, Application, ObjectClass_());
    });

    return &class_;
}
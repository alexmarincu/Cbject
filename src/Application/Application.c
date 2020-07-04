#include "Application.h"
#include "../CObject/CObjectSuper.h"
#include "../Circle/Circle.h"
#include "../ColoredCircle/ColoredCircle.h"
#include "../Rectangle/Rectangle.h"
#include <stdio.h>

#undef class
#define class Application
#undef super_class
#define super_class CObject

singleton_class_members(
    mmCircle circle;
    mmRectangle rectangle;
    mmColoredCircle coloredCircle;);

singleton_class_init(
    bind_virtual_functions(););

static fun(Void, printBeginMessage);
static fun(Void, printEndMessage);
static fun(Void, circleExample);
static fun(Void, stackCircleExample);
static fun(Void, rectangleExample);
static fun(Void, stackRectangleExample);
static fun(Void, heapRectangleExample);
static fun(Void, coloredCircleExample);
static fun(Void, polimorphismExample);

fun(Void, start)
{
    Application_printBeginMessage(me);
    Application_circleExample(me);
    Application_stackCircleExample(me);
    Application_rectangleExample(me);
    Application_stackRectangleExample(me);
    Application_heapRectangleExample(me);
    Application_coloredCircleExample(me);
    Application_polimorphismExample(me);
    Application_printEndMessage(me);
}

static fun(Void, printBeginMessage) { printf("\nApplication started ->\n"); }
static fun(Void, printEndMessage) { printf("\nApplication ended <-\n"); }

static fun(Void, circleExample)
{
    printf("\n= Circle example:\n");

    me->circle = get_Circle(
        &((CircleInitParams){
            .origin.x = 0,
            .origin.y = 1,
            .radius = 1}));

    printf("circle.radius = %d\n", Circle_radius(me->circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(me->circle, 2);
    printf("circle.radius = %d\n", Circle_radius(me->circle));
    printf("circle.area() = %.2f\n", Shape_area((mShape) me->circle));
    printf("circle.origin.x = %d\n", Shape_origin((Shape) me->circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape) me->circle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((mShape) me->circle, (Point){2, 3});
    printf("circle.origin.x = %d\n", Shape_origin((Shape) me->circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape) me->circle).y);
    Shape_draw((mShape) me->circle, 5);
}

static fun(Void, stackCircleExample)
{
    printf("\n= StackCircle example:\n");

    mObject(Circle, stackCircle,
            &((CircleInitParams){
                .origin.x = 2,
                .origin.y = 3,
                .radius = 3}));

    printf("stackCircle.radius = %d\n", Circle_radius(stackCircle));
    printf("Set radius to 4\n");
    Circle_radiusSet(stackCircle, 4);
    printf("stackCircle.radius = %d\n", Circle_radius(stackCircle));
}

static fun(Void, rectangleExample)
{
    printf("\n= Rectangle example:\n");

    me->rectangle = get_Rectangle(
        &((RectangleInitParams){
            .origin.x = 4,
            .origin.y = 5,
            .width = 1,
            .height = 2}));

    printf("rectangle.width = %d\n", Rectangle_width(me->rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->rectangle, 2);
    Rectangle_heightSet(me->rectangle, 3);
    printf("rectangle.width = %d\n", Rectangle_width(me->rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->rectangle));
    printf("rectangle.area() = %.2f\n", Shape_area((mShape) me->rectangle));
    Shape_draw((mShape) me->rectangle, 6);
}

static fun(Void, stackRectangleExample)
{
    printf("\n= StackRectangle example:\n");

    mObject(Rectangle, stackRectangle,
            &((RectangleInitParams){
                .origin.x = 12,
                .origin.y = 23,
                .width = 34,
                .height = 2}));

    printf("stackRectangle.width = %d\n", Rectangle_width(stackRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(stackRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(stackRectangle, 2);
    Rectangle_heightSet(stackRectangle, 3);
    printf("stackRectangle.width = %d\n", Rectangle_width(stackRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(stackRectangle));
}

static fun(Void, heapRectangleExample)
{
    printf("\n= HeapRectangle example:\n");

    mRectangle heapRectangle = new_Rectangle(
        &((RectangleInitParams){
            .origin.x = 12,
            .origin.y = 23,
            .width = 34,
            .height = 2}));

    printf("heapRectangle.width = %d\n", Rectangle_width(heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(heapRectangle, 2);
    Rectangle_heightSet(heapRectangle, 3);
    printf("heapRectangle.width = %d\n", Rectangle_width(heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(heapRectangle));
    free(heapRectangle);
}

static fun(Void, coloredCircleExample)
{
    printf("\n= ColoredCircle example:\n");

    me->coloredCircle = get_ColoredCircle(
        &((ColoredCircleInitParams){
            .radius = 10,
            .color = Color_red}));

    printf("coloredCircle.radius = %d\n", Circle_radius((Circle) me->coloredCircle));
    printf("Set radius to 3\n");
    Circle_radiusSet((mCircle) me->coloredCircle, 3);
    printf("coloredCircle.radius = %d\n", Circle_radius((Circle) me->coloredCircle));
    printf("coloredCircle.area() = %.2f\n", Shape_area((mShape) me->coloredCircle));
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape) me->coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape) me->coloredCircle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((mShape) me->coloredCircle, (Point){2, 3});
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape) me->coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape) me->coloredCircle).y);
    Shape_draw((mShape) me->coloredCircle, 5);
}

static fun(Void, polimorphismExample)
{
    printf("\n= Polimorphism example:\n");

    mShape shapes[] = {
        (mShape) me->circle,
        (mShape) me->rectangle,
        (mShape) me->coloredCircle};

    for (mUInt8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].objectSize() = %d\n", i, CObject_objectSize((CObject) shapes[i]));
    }
}

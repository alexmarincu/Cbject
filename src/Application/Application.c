#include "Application.h"
#include "../Circle/Circle.h"
#include "../ColoredCircle/ColoredCircle.h"
#include "../Rectangle/Rectangle.h"
#include "../Shape/Shape.h"
#include <stdio.h>

#define class Application
#define superClass Cbject

objectMembers(
    Circle * circle,
    Rectangle * rectangle,
    Rectangle * heapRectangle,
    ColoredCircle * coloredCircle);

objectSetup({});
init({});
terminate({ delete_Rectangle(me->heapRectangle); });

privateFunctions(
    (void, printBeginMessage, ()),
    (void, printEndMessage, ()),
    (void, circleExample, ()),
    (void, stackCircleExample, ()),
    (void, rectangleExample, ()),
    (void, stackRectangleExample, ()),
    (void, heapRectangleExample, ()),
    (void, coloredCircleExample, ()),
    (void, polymorphismExample, ()));

function(void, start, ())
{
    Application_printBeginMessage(me);
    Application_circleExample(me);
    // Application_stackCircleExample(me);
    Application_rectangleExample(me);
    // Application_stackRectangleExample(me);
    // Application_heapRectangleExample(me);
    Application_coloredCircleExample(me);
    // Application_polymorphismExample(me);
    // Application_printEndMessage(me);
}

privateFunction(void, printBeginMessage, ()) { printf("\nApplication started ->\n"); }
privateFunction(void, printEndMessage, ()) { printf("\nApplication ended <-\n"); }

privateFunction(void, circleExample, ())
{
    printf("\n= Circle example:\n");
    printf("Circle_pi = %.2f\n", Circle_pi);
    Circle * circle = me->circle;

    circle = get_Circle(&((CircleParams){.origin.x = 0, .origin.y = 1, .radius = 1}));

    printf("circle.radius = %d\n", Circle_radius(circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(circle, 2);
    printf("circle.radius = %d\n", Circle_radius(circle));
    printf("circle.area = %.2f\n", Shape_area((Shape *) circle));
    printf("circle.origin.x = %d\n", Shape_origin((Shape *) circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) circle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) circle, (Point){2, 3});
    printf("circle.origin.x = %d\n", Shape_origin((Shape *) circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) circle).y);
    Shape_draw((Shape *) circle, 5);
    Circle_rotate(circle);
    printf("circle.class.type = %s\n", Cbject_type((Cbject *) circle));
}

privateFunction(void, stackCircleExample, ())
{
    printf("\n= StackCircle example:\n");

    stackCbject(Circle, stackCircle,
                &((CircleParams){
                    .origin.x = 2,
                    .origin.y = 3,
                    .radius = 3}));

    printf("stackCircle.radius = %d\n", Circle_radius(stackCircle));
    printf("Set radius to 4\n");
    Circle_radiusSet(stackCircle, 4);
    printf("stackCircle.radius = %d\n", Circle_radius(stackCircle));
}

privateFunction(void, rectangleExample, ())
{
    printf("\n= Rectangle example:\n");
    Rectangle * rectangle = me->rectangle;
    rectangle = get_Rectangle(
        &((RectangleParams){
            .origin.x = 4,
            .origin.y = 5,
            .width = 1,
            .height = 2}));

    printf("rectangle.width = %d\n", Rectangle_width(rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(rectangle, 2);
    Rectangle_heightSet(rectangle, 3);
    printf("rectangle.width = %d\n", Rectangle_width(rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(rectangle));
    printf("rectangle.area = %.2f\n", Shape_area((Shape *) rectangle));
    Shape_draw((Shape *) rectangle, 6);
    printf("rectangle.class.type = %s\n", Cbject_type((Cbject *) rectangle));
}

privateFunction(void, stackRectangleExample, ())
{
    printf("\n= StackRectangle example:\n");

    stackCbject(Rectangle, stackRectangle,
                &((RectangleParams){
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

privateFunction(void, heapRectangleExample, ())
{
    printf("\n= HeapRectangle example:\n");

    me->heapRectangle = new_Rectangle(
        &((RectangleParams){
            .origin.x = 12,
            .origin.y = 23,
            .width = 34,
            .height = 2}));

    printf("heapRectangle.width = %d\n", Rectangle_width(me->heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->heapRectangle, 2);
    Rectangle_heightSet(me->heapRectangle, 3);
    printf("heapRectangle.width = %d\n", Rectangle_width(me->heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->heapRectangle));
}

privateFunction(void, coloredCircleExample, ())
{
    printf("\n= ColoredCircle example:\n");
ColoredCircle * coloredCircle = me->coloredCircle;
    coloredCircle = get_ColoredCircle(
        &((ColoredCircleParams){
            .radius = 10,
            .color = Color_red}));

    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) coloredCircle));
    printf("Set radius to 3\n");
    Circle_radiusSet((Circle *) coloredCircle, 3);
    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) coloredCircle));
    printf("coloredCircle.area = %.2f\n", Shape_area((Shape *) coloredCircle));
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) coloredCircle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) coloredCircle, (Point){2, 3});
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) coloredCircle).y);
    Shape_draw((Shape *) coloredCircle, 5);
    Circle_rotate((Circle *) coloredCircle);
}

privateFunction(void, polymorphismExample, ())
{
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        (Shape *) me->circle,
        (Shape *) me->rectangle,
        (Shape *) me->coloredCircle};

    for (uint8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].size() = %d\n", i, Cbject_size((Cbject *) shapes[i]));
    }
}

#undef superClass
#undef class

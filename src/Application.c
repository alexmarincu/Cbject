#include "Application.h"
#include <stdio.h>

#define klass Application
#define superKlass Cbject

SingletonSetup({});
Init({});
Terminate({ Delete_Rectangle(me->m.heapRectangle); });

PrivateFunctions(_,
    (void, printBeginMessage, (0)),
    (void, printEndMessage, (0)),
    (void, circleExample, (0)),
    (void, stackCircleExample, (0)),
    (void, rectangleExample, (0)),
    (void, stackRectangleExample, (0)),
    (void, heapRectangleExample, (0)),
    (void, coloredCircleExample, (0)),
    (void, polymorphismExample, (0)));

Function(void, start, (0))
{
    Application_printBeginMessage(me);
    Application_circleExample(me);
    Application_stackCircleExample(me);
    Application_rectangleExample(me);
    Application_stackRectangleExample(me);
    Application_heapRectangleExample(me);
    Application_coloredCircleExample(me);
    Application_polymorphismExample(me);
    Application_printEndMessage(me);
}

PrivateFunction(void, printBeginMessage, (0)) { printf("\nApplication started ->\n"); }
PrivateFunction(void, printEndMessage, (0)) { printf("\nApplication ended <-\n"); }

PrivateFunction(void, circleExample, (0))
{
    printf("\n= Circle example:\n");
    printf("Circle_pi = %.2f\n", Circle_pi);
    me->m.circle = Get_Circle(&((CircleParams){.origin.x = 0, .origin.y = 1, .radius = 1}));
    printf("circle.radius = %d\n", Circle_radius(me->m.circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(me->m.circle, 2);
    printf("circle.radius = %d\n", Circle_radius(me->m.circle));
    printf("circle.area = %.2f\n", Shape_area((Shape *) me->m.circle));
    printf("circle.area = %.2f\n", superCircle_area(me->m.circle));
    printf("circle.origin.x = %d\n", Shape_origin((Shape *) me->m.circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) me->m.circle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) me->m.circle, (Point){2, 3});
    printf("circle.origin.x = %d\n", Shape_origin((Shape *) me->m.circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) me->m.circle).y);
    Shape_draw((Shape *) me->m.circle, 5);
    Circle_rotate(me->m.circle);
    printf("circle.klass.type = %s\n", Cbject_type((Cbject *) me->m.circle));
    printf("circle.klass.type = %s\n", (*((CbjectKlass **) me->m.circle))->type);
}

PrivateFunction(void, stackCircleExample, (0))
{
    printf("\n= StackCircle example:\n");

    NewOnStack(Circle, stackCircle,
        &((CircleParams){
            .origin.x = 2,
            .origin.y = 3,
            .radius = 3}));

    printf("stackCircle.radius = %d\n", Circle_radius(stackCircle));
    printf("Set radius to 4\n");
    Circle_radiusSet(stackCircle, 4);
    printf("stackCircle.radius = %d\n", Circle_radius(stackCircle));
}

PrivateFunction(void, rectangleExample, (0))
{
    printf("\n= Rectangle example:\n");
    me->m.rectangle = Get_Rectangle(
        &((RectangleParams){
            .origin.x = 4,
            .origin.y = 5,
            .width = 1,
            .height = 2}));

    printf("rectangle.width = %d\n", Rectangle_width(me->m.rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->m.rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->m.rectangle, 2);
    Rectangle_heightSet(me->m.rectangle, 3);
    printf("rectangle.width = %d\n", Rectangle_width(me->m.rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->m.rectangle));
    printf("rectangle.area = %.2f\n", Shape_area((Shape *) me->m.rectangle));
    Shape_draw((Shape *) me->m.rectangle, 6);
    printf("rectangle.klass.type = %s\n", Cbject_type((Cbject *) me->m.rectangle));
}

PrivateFunction(void, stackRectangleExample, (0))
{
    printf("\n= StackRectangle example:\n");

    NewOnStack(Rectangle, stackRectangle,
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

PrivateFunction(void, heapRectangleExample, (0))
{
    printf("\n= HeapRectangle example:\n");

    me->m.heapRectangle = New_Rectangle(
        &((RectangleParams){
            .origin.x = 12,
            .origin.y = 23,
            .width = 34,
            .height = 2}));

    printf("heapRectangle.width = %d\n", Rectangle_width(me->m.heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->m.heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->m.heapRectangle, 2);
    Rectangle_heightSet(me->m.heapRectangle, 3);
    printf("heapRectangle.width = %d\n", Rectangle_width(me->m.heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->m.heapRectangle));
}

PrivateFunction(void, coloredCircleExample, (0))
{
    printf("\n= ColoredCircle example:\n");
    me->m.coloredCircle = Get_ColoredCircle(
        &((ColoredCircleParams){
            .origin.x = 12,
            .origin.y = 23,
            .radius = 10,
            .color = Color_red}));

    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) me->m.coloredCircle));
    printf("Set radius to 3\n");
    Circle_radiusSet((Circle *) me->m.coloredCircle, 3);
    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) me->m.coloredCircle));
    printf("coloredCircle.area = %.2f\n", Shape_area((Shape *) me->m.coloredCircle));
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) me->m.coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) me->m.coloredCircle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) me->m.coloredCircle, (Point){2, 3});
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) me->m.coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) me->m.coloredCircle).y);
    Shape_draw((Shape *) me->m.coloredCircle, 5);
    Circle_rotate((Circle *) me->m.coloredCircle);
}

PrivateFunction(void, polymorphismExample, (0))
{
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        (Shape *) me->m.circle,
        (Shape *) me->m.rectangle,
        (Shape *) me->m.heapRectangle,
        (Shape *) me->m.coloredCircle};

    for (uint8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].size() = %d\n", i, Cbject_size((Cbject *) shapes[i]));
    }
}

#undef superKlass
#undef klass

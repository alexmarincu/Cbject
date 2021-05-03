#include "Application.h"
#include <stdio.h>

#define klass Application
#define superKlass Cbject

SingletonSetup({});
Init {}
Terminate { Delete_Rectangle(me->p.heapRectangle); }

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
    me->p.circle = Get_Circle(&((CircleParams){.origin.x = 0, .origin.y = 1, .radius = 1}));
    printf("circle.radius = %d\n", Circle_radius(me->p.circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(me->p.circle, 2);
    printf("circle.radius = %d\n", Circle_radius(me->p.circle));
    printf("circle.area = %.2f\n", Shape_area(Circle_toShape(me->p.circle)));
    printf("circle.area = %.2f\n", sCircle_area(me->p.circle));
    printf("circle.origin.x = %d\n", Shape_origin(Circle_toShape(me->p.circle)).x);
    printf("circle.origin.y = %d\n", Shape_origin(Circle_toShape(me->p.circle)).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) me->p.circle, (Point){2, 3});
    printf("circle.origin.x = %d\n", Shape_origin(Circle_toShape(me->p.circle)).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) me->p.circle).y);
    Shape_draw((Shape *) me->p.circle, 5);
    Circle_rotate(me->p.circle);
    printf("circle.klass.type = %s\n", Cbject_type((Cbject *) me->p.circle));
    printf("circle.klass.type = %s\n", (*((CbjectKlass **) me->p.circle))->type);
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
    me->p.rectangle = Get_Rectangle(
        &((RectangleParams){
            .origin.x = 4,
            .origin.y = 5,
            .width = 1,
            .height = 2}));

    printf("rectangle.width = %d\n", Rectangle_width(me->p.rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->p.rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->p.rectangle, 2);
    Rectangle_heightSet(me->p.rectangle, 3);
    printf("rectangle.width = %d\n", Rectangle_width(me->p.rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->p.rectangle));
    printf("rectangle.area = %.2f\n", Shape_area((Shape *) me->p.rectangle));
    Shape_draw((Shape *) me->p.rectangle, 6);
    printf("rectangle.klass.type = %s\n", Cbject_type((Cbject *) me->p.rectangle));
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

    me->p.heapRectangle = New_Rectangle(
        &((RectangleParams){
            .origin.x = 12,
            .origin.y = 23,
            .width = 34,
            .height = 2}));

    printf("heapRectangle.width = %d\n", Rectangle_width(me->p.heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->p.heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->p.heapRectangle, 2);
    Rectangle_heightSet(me->p.heapRectangle, 3);
    printf("heapRectangle.width = %d\n", Rectangle_width(me->p.heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->p.heapRectangle));
}

PrivateFunction(void, coloredCircleExample, (0))
{
    printf("\n= ColoredCircle example:\n");
    me->p.coloredCircle = Get_ColoredCircle(
        &((ColoredCircleParams){
            .origin.x = 12,
            .origin.y = 23,
            .radius = 10,
            .color = Color_red}));

    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) me->p.coloredCircle));
    printf("Set radius to 3\n");
    Circle_radiusSet((Circle *) me->p.coloredCircle, 3);
    printf("coloredCircle.radius = %d\n", Circle_radius(ColoredCircle_toCircle(me->p.coloredCircle)));
    printf("coloredCircle.area = %.2f\n", Shape_area((Shape *) me->p.coloredCircle));
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) me->p.coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) me->p.coloredCircle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) me->p.coloredCircle, (Point){2, 3});
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) me->p.coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) me->p.coloredCircle).y);
    Shape_draw((Shape *) me->p.coloredCircle, 5);
    Circle_rotate((Circle *) me->p.coloredCircle);
}

PrivateFunction(void, polymorphismExample, (0))
{
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        (Shape *) me->p.circle,
        (Shape *) me->p.rectangle,
        (Shape *) me->p.heapRectangle,
        (Shape *) me->p.coloredCircle};

    for (uint8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].size() = %d\n", i, Cbject_size((Cbject *) shapes[i]));
    }
}

#undef superKlass
#undef klass

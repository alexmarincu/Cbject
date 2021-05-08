#include "Application.h"
#include <stdio.h>

#define Type Application
#define Parent Cbject

ObjectSetup(BindFuns(0));
Init {}
Terminate { Delete_Rectangle(me->p.heapRectangle); }

PrivateFuns(_,
    (void, printBeginMessage, (0)),
    (void, printEndMessage, (0)),
    (void, circleExample, (0)),
    (void, stackCircleExample, (0)),
    (void, rectangleExample, (0)),
    (void, stackRectangleExample, (0)),
    (void, heapRectangleExample, (0)),
    (void, coloredCircleExample, (0)),
    (void, polymorphismExample, (0)));

Fun(void, start, (0))
{
    Application_circleExample(me);
    Application_stackCircleExample(me);
    Application_rectangleExample(me);
    Application_stackRectangleExample(me);
    Application_heapRectangleExample(me);
    Application_coloredCircleExample(me);
    Application_polymorphismExample(me);
}

PrivateFun(void, circleExample, (0))
{
    printf("\n= Circle example:\n");
    me->p.circle = Get_Circle(&((CircleParams){.origin.x = 0, .origin.y = 1, .radius = 1}));
    printf("radius = %d\n", Circle_radius(me->p.circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(me->p.circle, 2);
    printf("radius = %d\n", Circle_radius(me->p.circle));
    printf("area = %.2f\n", Shape_area(Circle_toShape(me->p.circle)));
    printf("origin.x = %d\n", Shape_origin(Circle_toShape(me->p.circle)).x);
    printf("origin.y = %d\n", Shape_origin(Circle_toShape(me->p.circle)).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) me->p.circle, (Point){2, 3});
    printf("origin.x = %d\n", Shape_origin(Circle_toShape(me->p.circle)).x);
    printf("origin.y = %d\n", Shape_origin((Shape *) me->p.circle).y);
    Shape_draw((Shape *) me->p.circle, 5);
    Circle_rotate(me->p.circle);
    printf("type = %s\n", Cbject_type((Cbject *) me->p.circle));
}

PrivateFun(void, stackCircleExample, (0))
{
    printf("\n= StackCircle example:\n");

    NewOnStack(Circle, stackCircle,
        &((CircleParams){
            .origin.x = 2,
            .origin.y = 3,
            .radius = 3}));

    printf("radius = %d\n", Circle_radius(stackCircle));
    printf("Set radius to 4\n");
    Circle_radiusSet(stackCircle, 4);
    printf("radius = %d\n", Circle_radius(stackCircle));
}

PrivateFun(void, rectangleExample, (0))
{
    printf("\n= Rectangle example:\n");

    me->p.rectangle =
        Get_Rectangle(
            &((RectangleParams){
                .origin.x = 4,
                .origin.y = 5,
                .width = 1,
                .height = 2}));

    printf("width = %d\n", Rectangle_width(me->p.rectangle));
    printf("height = %d\n", Rectangle_height(me->p.rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->p.rectangle, 2);
    Rectangle_heightSet(me->p.rectangle, 3);
    printf("width = %d\n", Rectangle_width(me->p.rectangle));
    printf("height = %d\n", Rectangle_height(me->p.rectangle));
    printf("area = %.2f\n", Shape_area((Shape *) me->p.rectangle));
    Shape_draw((Shape *) me->p.rectangle, 6);
    printf("type = %s\n", Cbject_type((Cbject *) me->p.rectangle));
}

PrivateFun(void, stackRectangleExample, (0))
{
    printf("\n= StackRectangle example:\n");

    NewOnStack(Rectangle, stackRectangle,
        &((RectangleParams){
            .origin.x = 12,
            .origin.y = 23,
            .width = 34,
            .height = 2}));

    printf("width = %d\n", Rectangle_width(stackRectangle));
    printf("height = %d\n", Rectangle_height(stackRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(stackRectangle, 2);
    Rectangle_heightSet(stackRectangle, 3);
    printf("width = %d\n", Rectangle_width(stackRectangle));
    printf("height = %d\n", Rectangle_height(stackRectangle));
}

PrivateFun(void, heapRectangleExample, (0))
{
    printf("\n= HeapRectangle example:\n");

    me->p.heapRectangle =
        New_Rectangle(
            &((RectangleParams){
                .origin.x = 12,
                .origin.y = 23,
                .width = 34,
                .height = 2}));

    printf("width = %d\n", Rectangle_width(me->p.heapRectangle));
    printf("height = %d\n", Rectangle_height(me->p.heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->p.heapRectangle, 2);
    Rectangle_heightSet(me->p.heapRectangle, 3);
    printf("width = %d\n", Rectangle_width(me->p.heapRectangle));
    printf("height = %d\n", Rectangle_height(me->p.heapRectangle));
}

PrivateFun(void, coloredCircleExample, (0))
{
    printf("\n= ColoredCircle example:\n");

    me->p.coloredCircle =
        Get_ColoredCircle(
            &((ColoredCircleParams){
                .origin.x = 12,
                .origin.y = 23,
                .radius = 10,
                .color = Color_red}));

    printf("radius = %d\n", Circle_radius((Circle *) me->p.coloredCircle));
    printf("Set radius to 3\n");
    Circle_radiusSet((Circle *) me->p.coloredCircle, 3);
    printf("radius = %d\n", Circle_radius(ColoredCircle_toCircle(me->p.coloredCircle)));
    printf("area = %.2f\n", Shape_area(Circle_toShape(ColoredCircle_toCircle(me->p.coloredCircle))));
    printf("origin.x = %d\n", Shape_origin((Shape *) me->p.coloredCircle).x);
    printf("origin.y = %d\n", Shape_origin((Shape *) me->p.coloredCircle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) me->p.coloredCircle, (Point){2, 3});
    printf("origin.x = %d\n", Shape_origin((Shape *) me->p.coloredCircle).x);
    printf("origin.y = %d\n", Shape_origin((Shape *) me->p.coloredCircle).y);
    Shape_draw((Shape *) me->p.coloredCircle, 5);
    Circle_rotate((Circle *) me->p.coloredCircle);
}

PrivateFun(void, polymorphismExample, (0))
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

#undef Parent
#undef Type

#include "Application.h"
#include <stdio.h>

#define Type Application
#define Parent Cbject

ObjectSetup(BindSuperFuns(0));
Init {}
Terminate {}

PrivateFuns(,
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
    Rectangle_delete(me->props.heapRectangle);
}

PrivateFun(void, circleExample, (0))
{
    printf("\n= Circle example:\n");
    me->props.circle = Circle_get(&(CircleParams){{0, 1}, 1});
    printf("radius = %d\n", Circle_radius(me->props.circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(me->props.circle, 2);
    printf("radius = %d\n", Circle_radius(me->props.circle));
    printf("area = %.2f\n", Shape_area(Circle_toShape(me->props.circle)));
    printf("origin.x = %d\n", Shape_origin(Circle_toShape(me->props.circle)).x);
    printf("origin.y = %d\n", Shape_origin(Circle_toShape(me->props.circle)).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) me->props.circle, (Point){2, 3});
    printf("origin.x = %d\n", Shape_origin(Circle_toShape(me->props.circle)).x);
    printf("origin.y = %d\n", Shape_origin((Shape *) me->props.circle).y);
    Shape_draw((Shape *) me->props.circle);
    Circle_rotate(me->props.circle);

    if (Cbject_isTypeOf(me->props.circle, Circle))
    {
        printf("is circle\n");
    }

    // printf("type name = %s\n", Cbject_type((Cbject *) me->props.circle)->name);
}

PrivateFun(void, stackCircleExample, (0))
{
    printf("\n= StackCircle example:\n");
    Circle * stackCircle = Circle_newOnStack((Circle *) &(CircleContainer){}, &(CircleParams){{2, 3}, 3});
    printf("radius = %d\n", Circle_radius(stackCircle));
    printf("Set radius to 4\n");
    Circle_radiusSet(stackCircle, 4);
    printf("radius = %d\n", Circle_radius(stackCircle));
}

PrivateFun(void, rectangleExample, (0))
{
    printf("\n= Rectangle example:\n");
    me->props.rectangle = Rectangle_get(&(RectangleParams){{4, 5}, 1, 2});
    printf("width = %d\n", Rectangle_width(me->props.rectangle));
    printf("height = %d\n", Rectangle_height(me->props.rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->props.rectangle, 2);
    Rectangle_heightSet(me->props.rectangle, 3);
    printf("width = %d\n", Rectangle_width(me->props.rectangle));
    printf("height = %d\n", Rectangle_height(me->props.rectangle));
    printf("area = %.2f\n", Shape_area((Shape *) me->props.rectangle));
    Shape_draw((Shape *) me->props.rectangle);
    // printf("type name = %s\n", Cbject_type((Cbject *) me->props.rectangle)->name);
}

PrivateFun(void, stackRectangleExample, (0))
{
    printf("\n= StackRectangle example:\n");
    Rectangle * stackRectangle = Rectangle_newOnStack((Rectangle *) &(RectangleContainer){}, &(RectangleParams){{12, 23}, 34, 2});
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
    me->props.heapRectangle = Rectangle_new(&(RectangleParams){{12, 23}, 34, 2});
    printf("width = %d\n", Rectangle_width(me->props.heapRectangle));
    printf("height = %d\n", Rectangle_height(me->props.heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->props.heapRectangle, 2);
    Rectangle_heightSet(me->props.heapRectangle, 3);
    printf("width = %d\n", Rectangle_width(me->props.heapRectangle));
    printf("height = %d\n", Rectangle_height(me->props.heapRectangle));
}

PrivateFun(void, coloredCircleExample, (0))
{
    printf("\n= ColoredCircle example:\n");
    me->props.coloredCircle = ColoredCircle_get(&(ColoredCircleParams){{12, 23}, 10, Color_red});
    printf("radius = %d\n", Circle_radius((Circle *) me->props.coloredCircle));
    printf("Set radius to 3\n");
    Circle_radiusSet((Circle *) me->props.coloredCircle, 3);
    printf("radius = %d\n", Circle_radius(ColoredCircle_toCircle(me->props.coloredCircle)));
    printf("area = %.2f\n", Shape_area(Circle_toShape(ColoredCircle_toCircle(me->props.coloredCircle))));
    printf("origin.x = %d\n", Shape_origin((Shape *) me->props.coloredCircle).x);
    printf("origin.y = %d\n", Shape_origin((Shape *) me->props.coloredCircle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) me->props.coloredCircle, (Point){2, 3});
    printf("origin.x = %d\n", Shape_origin((Shape *) me->props.coloredCircle).x);
    printf("origin.y = %d\n", Shape_origin((Shape *) me->props.coloredCircle).y);
    Shape_draw((Shape *) me->props.coloredCircle);
    Circle_rotate((Circle *) me->props.coloredCircle);
}

PrivateFun(void, polymorphismExample, (0))
{
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        Circle_toShape(me->props.circle),
        Rectangle_toShape(me->props.rectangle),
        Rectangle_toShape(me->props.heapRectangle),
        Circle_toShape(ColoredCircle_toCircle(me->props.coloredCircle))};

    for (uint8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].size() = %d\n", i, Cbject_size((Cbject *) shapes[i]));
    }
}

#undef Parent
#undef Type

#include "Application.h"
#include <stdio.h>

#define Type Application
#define Parent Cbject

ObjectSetup((0));
Init {}
Terminate {}

static Fun(void, printBeginMessage, (0));
static Fun(void, printEndMessage, (0));
static Fun(void, circleExample, (0));
static Fun(void, stackCircleExample, (0));
static Fun(void, rectangleExample, (0));
static Fun(void, stackRectangleExample, (0));
static Fun(void, heapRectangleExample, (0));
static Fun(void, coloredCircleExample, (0));
static Fun(void, polymorphismExample, (0));

Fun(void, start, (0))
{
    Application_circleExample(me);
    Application_stackCircleExample(me);
    Application_rectangleExample(me);
    Application_stackRectangleExample(me);
    Application_heapRectangleExample(me);
    Application_coloredCircleExample(me);
    Application_polymorphismExample(me);
    Rectangle_delete(me->d.heapRectangle);
}

static Fun(void, circleExample, (0))
{
    printf("\n= Circle example:\n");
    me->d.circle = Circle_getFromStaticPool((CircleParams){{0, 1}, 1});
    printf("radius = %d\n", Circle_radius(me->d.circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(me->d.circle, 2);
    printf("radius = %d\n", Circle_radius(me->d.circle));
    printf("area = %.2f\n", Shape_area(Cbject_cast(me->d.circle, Shape)));
    printf("origin.x = %d\n", Shape_origin(Cbject_cast(me->d.circle, Shape)).x);
    printf("origin.y = %d\n", Shape_origin(Cbject_cast(me->d.circle, Shape)).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet(Cbject_cast(me->d.circle, Shape), (Point){2, 3});
    printf("origin.x = %d\n", Shape_origin(Cbject_cast(me->d.circle, Shape)).x);
    printf("origin.y = %d\n", Shape_origin(Cbject_cast(me->d.circle, Shape)).y);
    Shape_draw(Cbject_cast(me->d.circle, Shape));
    Circle_rotate(me->d.circle);

    if (Cbject_isTypeOf(me->d.circle, Circle))
    {
        printf("is circle\n");
    }

    // printf("type name = %s\n", Cbject_type((Cbject *) me->d.circle)->name);
}

static Fun(void, stackCircleExample, (0))
{
    printf("\n= StackCircle example:\n");
    Circle * stackCircle = Circle_createOnStack((Circle *) &(CircleContainer){}, (CircleParams){{2, 3}, 3});
    printf("radius = %d\n", Circle_radius(stackCircle));
    printf("Set radius to 4\n");
    Circle_radiusSet(stackCircle, 4);
    printf("radius = %d\n", Circle_radius(stackCircle));
}

static Fun(void, rectangleExample, (0))
{
    printf("\n= Rectangle example:\n");
    me->d.rectangle = Rectangle_getFromStaticPool((RectangleParams){{4, 5}, 1, 2});
    printf("width = %d\n", Rectangle_width(me->d.rectangle));
    printf("height = %d\n", Rectangle_height(me->d.rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->d.rectangle, 2);
    Rectangle_heightSet(me->d.rectangle, 3);
    printf("width = %d\n", Rectangle_width(me->d.rectangle));
    printf("height = %d\n", Rectangle_height(me->d.rectangle));
    printf("area = %.2f\n", Shape_area(Cbject_cast(me->d.rectangle, Shape)));
    Shape_draw(Cbject_cast(me->d.rectangle, Shape));
    // printf("type name = %s\n", Cbject_type((Cbject *) me->d.rectangle)->name);
}

static Fun(void, stackRectangleExample, (0))
{
    printf("\n= StackRectangle example:\n");
    Rectangle * stackRectangle = Rectangle_createOnStack((Rectangle *) &(RectangleContainer){}, (RectangleParams){{12, 23}, 34, 2});
    printf("width = %d\n", Rectangle_width(stackRectangle));
    printf("height = %d\n", Rectangle_height(stackRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(stackRectangle, 2);
    Rectangle_heightSet(stackRectangle, 3);
    printf("width = %d\n", Rectangle_width(stackRectangle));
    printf("height = %d\n", Rectangle_height(stackRectangle));
}

static Fun(void, heapRectangleExample, (0))
{
    printf("\n= HeapRectangle example:\n");
    me->d.heapRectangle = Rectangle_createOnHeap((RectangleParams){{12, 23}, 34, 2});
    printf("width = %d\n", Rectangle_width(me->d.heapRectangle));
    printf("height = %d\n", Rectangle_height(me->d.heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->d.heapRectangle, 2);
    Rectangle_heightSet(me->d.heapRectangle, 3);
    printf("width = %d\n", Rectangle_width(me->d.heapRectangle));
    printf("height = %d\n", Rectangle_height(me->d.heapRectangle));
}

static Fun(void, coloredCircleExample, (0))
{
    printf("\n= ColoredCircle example:\n");
    me->d.coloredCircle = ColoredCircle_getFromStaticPool((ColoredCircleParams){{12, 23}, 10, Color_red});
    printf("radius = %d\n", Circle_radius(Cbject_cast(me->d.coloredCircle, Circle)));
    printf("Set radius to 3\n");
    Circle_radiusSet(Cbject_cast(me->d.coloredCircle, Circle), 3);
    printf("radius = %d\n", Circle_radius(Cbject_cast(me->d.coloredCircle, Circle)));
    printf("area = %.2f\n", Shape_area(Cbject_cast(me->d.coloredCircle, Shape)));
    printf("origin.x = %d\n", Shape_origin(Cbject_cast(me->d.coloredCircle, Shape)).x);
    printf("origin.y = %d\n", Shape_origin(Cbject_cast(me->d.coloredCircle, Shape)).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet(Cbject_cast(me->d.coloredCircle, Shape), (Point){2, 3});
    printf("origin.x = %d\n", Shape_origin(Cbject_cast(me->d.coloredCircle, Shape)).x);
    printf("origin.y = %d\n", Shape_origin(Cbject_cast(me->d.coloredCircle, Shape)).y);
    Shape_draw(Cbject_cast(me->d.coloredCircle, Shape));
    Circle_rotate(Cbject_cast(me->d.coloredCircle, Circle));
}

static Fun(void, polymorphismExample, (0))
{
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        Cbject_cast(me->d.circle, Shape),
        Cbject_cast(me->d.rectangle, Shape),
        Cbject_cast(me->d.heapRectangle, Shape),
        Cbject_cast(me->d.coloredCircle, Shape)};

    for (uint8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].size() = %d\n", i, Cbject_size((Cbject *) shapes[i]));
    }
}

#undef Parent
#undef Type

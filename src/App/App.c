#include "App.h"
#include "../Circle/Circle.h"
#include "../Rectangle/Rectangle.h"
#include <stdio.h>

Void App_start()
{
    CircleInitParams cp = {{2, 3}, 5};
    _Circle circle = Circle_get(&cp);
    _$(Circle, circleOnTheStack, &cp);
    _UInt32 newRadius = 3;
    Circle_radiusSet(circle, &newRadius);
    Circle_radiusSet(circleOnTheStack, &newRadius);
    Circle_radiusGet(circle, &newRadius);
    Circle_radiusGet(circleOnTheStack, &newRadius);
    RectangleInitParams rp = {{12, 23}, 34, 2};
    _Rectangle rectangle = Rectangle_get(&rp);
    _$(Rectangle, rectangleOnTheStack, &rp);
    _UInt32 newWidth = 30;
    Rectangle_widthSet(rectangle, &newWidth);
    Rectangle_widthSet(rectangleOnTheStack, &newWidth);
    Rectangle_widthGet(rectangle, &newWidth);
    Rectangle_widthGet(rectangleOnTheStack, &newWidth);
    Shape shapes[] = {(Shape) circle, (Shape) circleOnTheStack, (Shape) rectangle, (Shape) rectangleOnTheStack};
    printf("circle.isInitialized() = %d\n", CObject_isInitialized((CObject) circle));
    _Point origin;
    Shape_originGet((Shape) circle, &origin);
    printf("circle.origin.x = %d\n", origin.x);
    Point newOrigin = {3, 4};
    Shape_originSet((_Shape) circle, &newOrigin);
    printf("circle.origin.x = %d\n", origin.x);
    printf("circle.area() = %d\n", Shape_area((Shape) circle));
    printf("rectangle.area() = %d\n", Shape_area((Shape) rectangle));

    for (_UInt8 i = 0; i < 4; i++)
    {
        printf("shapes[%d].area() = %d\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].objectSize() = %d\n", i, CObject_objectSize((CObject) shapes[i]));
    }
}

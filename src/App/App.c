#include "App.h"
#include "../Circle/Circle.h"
#include "../ColoredCircle/ColoredCircle.h"
#include "../Rectangle/Rectangle.h"
#include <stdio.h>

Void App_start()
{
    mCircle circle = Circle_get(
        &((CircleInitParams){
            .origin.x = 2,
            .origin.y = 3,
            .radius = 5}));

    mUInt32 radius = Circle_radiusGet(circle);
    printf("circle.radius = %d\n", radius);
    UInt32 newRadius = 3;
    Circle_radiusSet(circle, newRadius);
    radius = Circle_radiusGet(circle);
    printf("circle.radius = %d\n", radius);

    mObject(Circle, stackCircle,
            &((CircleInitParams){
                .origin.x = 2,
                .origin.y = 3,
                .radius = 5}));

    radius = Circle_radiusGet(stackCircle);
    printf("stackCircle.radius = %d\n", radius);
    Circle_radiusSet(stackCircle, newRadius);
    radius = Circle_radiusGet(stackCircle);
    printf("stackCircle.radius = %d\n", radius);

    mRectangle rectangle = Rectangle_get(
        &((RectangleInitParams){
            .origin.x = 12,
            .origin.y = 23,
            .width = 34,
            .height = 2}));

    mUInt32 width = Rectangle_widthGet(rectangle);
    printf("rectangle.width = %d\n", width);
    UInt32 newWidth = 30;
    Rectangle_widthSet(rectangle, newWidth);
    width = Rectangle_widthGet(rectangle);
    printf("rectangle.width = %d\n", width);

    mObject(Rectangle, stackRectangle,
            &((RectangleInitParams){
                .origin.x = 12,
                .origin.y = 23,
                .width = 34,
                .height = 2}));

    width = Rectangle_widthGet(stackRectangle);
    printf("stackRectangle.width = %d\n", width);
    Rectangle_widthSet(stackRectangle, newWidth);
    width = Rectangle_widthGet(stackRectangle);
    printf("stackRectangle.width = %d\n", width);

    mRectangle heapRectangle = Rectangle_new(
        &((RectangleInitParams){
            .origin.x = 12,
            .origin.y = 23,
            .width = 34,
            .height = 2}));

    width = Rectangle_widthGet(heapRectangle);
    printf("heapRectangle.width = %d\n", width);
    Rectangle_widthSet(heapRectangle, newWidth);
    width = Rectangle_widthGet(heapRectangle);
    printf("heapRectangle.width = %d\n", width);
    free(heapRectangle);

    mColoredCircle coloredCircle = ColoredCircle_get(
        &((ColoredCircleInitParams){
            .radius = 10,
            .color = Color_red}));

    radius = Circle_radiusGet((Circle) coloredCircle);
    printf("coloredCircle.radius = %d\n", radius);
    Circle_radiusSet((mCircle) coloredCircle, newRadius);
    radius = Circle_radiusGet((Circle) coloredCircle);
    printf("coloredCircle.radius = %d\n", radius);

    Shape shapes[] = {
        (Shape) circle,
        (Shape) stackCircle,
        (Shape) rectangle,
        (Shape) stackRectangle,
        (Shape) coloredCircle};

    mPoint origin = Shape_originGet((Shape) circle);
    printf("circle.origin.x = %d\n", origin.x);
    Point newOrigin = {3, 4};
    Shape_originSet((mShape) circle, newOrigin);
    origin = Shape_originGet((Shape) circle);
    printf("circle.origin.x = %d\n", origin.x);

    origin = Shape_originGet((Shape) coloredCircle);
    printf("coloredCircle.origin.x = %d\n", origin.x);
    Shape_originSet((mShape) coloredCircle, newOrigin);
    origin = Shape_originGet((Shape) coloredCircle);
    printf("coloredCircle.origin.x = %d\n", origin.x);

    printf("circle.area() = %.2f\n", Shape_area((Shape) circle));
    printf("coloredCircle.area() = %.2f\n", Shape_area((Shape) coloredCircle));
    printf("rectangle.area() = %.2f\n", Shape_area((Shape) rectangle));

    for (mUInt8 i = 0; i < 4; i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].objectSize() = %d\n", i, CObject_objectSize((CObject) shapes[i]));
    }

    Shape_draw((Shape) circle, 5);
    Shape_draw((Shape) rectangle, 6);
    Shape_draw((Shape) coloredCircle, 5);
}

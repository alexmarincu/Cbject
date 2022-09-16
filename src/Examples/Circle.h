#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Cbject/Cbject.h"
#include "Drawable.h"
#include "Shape.h"
/**
 * @brief Circle
 */
typedef struct {
    extends_(Object);
    implements_(Shape);
    implements_(Drawable);
    uint32_t radius;
} Circle;
/**
 * @brief Circle_Class
 */
typedef struct {
    extends_(Object_Class);
    implements_(Shape_Interface);
    implements_(Drawable_Interface);
} Circle_Class;
/**
 * @brief Get Circle_Class
 * @return Class const*
 */
Circle_Class const * Circle_Class_(void);
/**
 * @brief Circle_Operations
 */
typedef struct {
    extends_(Object_Operations);
    implements_(Shape_Operations);
    implements_(Drawable_Operations);
} Circle_Operations;
/**
 * @brief Get Circle_Operations
 * @return Circle_Operations const*
 */
Circle_Operations const * Circle_Operations_(void);
/**
 * @brief Init Circle object
 * @param me
 * @param origin
 * @param radius
 * @return Circle*
 */
Circle * Circle_init(Circle * me, Point origin, uint32_t radius);
#endif // CIRCLE_H

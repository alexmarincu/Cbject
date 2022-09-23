#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Cbject/Cbject.h"
#include "Drawable.h"
#include "Shape.h"
/**
 * @brief Rectangle_Class
 */
typedef struct {
    extends_(Object_Class);
    implements_(Shape_Interface);
    implements_(Drawable_Interface);
} Rectangle_Class;
/**
 * @brief Get Rectangle_Class
 * @return Rectangle_Class const*
 */
Rectangle_Class const * Rectangle_Class_(void);
typedef struct Rectangle Rectangle;
/**
 * @brief
 * @param me
 * @param origin
 * @param width
 * @param height
 * @return Rectangle*
 */
Rectangle * Rectangle_init(
    Rectangle * me,
    Point origin,
    uint32_t width,
    uint32_t height
);
/**
 * @brief
 * @param me
 * @return uint32_t
 */
uint32_t Rectangle_getWidth(Rectangle const * const me);
/**
 * @brief
 * @param me
 * @param width
 */
void Rectangle_setWidth(Rectangle * const me, uint32_t const width);
/**
 * @brief
 * @param me
 * @return uint32_t
 */
uint32_t Rectangle_getHeight(Rectangle const * const me);
/**
 * @brief
 * @param me
 * @param height
 */
void Rectangle_setHeight(Rectangle * const me, uint32_t const height);
/**
 * @brief
 * @param me
 * @param edgeSize
 */
void Rectangle_makeSquare(Rectangle * const me, uint32_t const edgeSize);
#endif // RECTANGLE_H

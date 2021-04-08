#ifndef OBJECT_H
#define OBJECT_H
#include "../CObjectUtilities.h"

typedef struct Object Object;
enum{ObjectClass_sizes = sizeof(struct{void * _;})};
typedef struct ObjectParams
{
} ObjectParams;

void Object_init(Object * const me, ObjectParams const * const params);
void Object_terminate(Object * const me);
uint8 Object_size(Object const * const me);
char const * Object_type(Object const * const me);

#endif // OBJECT_H

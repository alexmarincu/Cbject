#ifndef OBJECT_H
#define OBJECT_H
#include "../CObjectUtilities.h"
// #include <stddef.h>

typedef union Object Object;
typedef struct ObjectClass
{
    char const * type;

    struct
    {
        uint8 (*size)(Object const * const me);
    } vf;
} ObjectClass;


typedef union ObjectShell 
{
    char d[sizeof(struct{ObjectClass * c;})];
    maxAlign a;
} ObjectShell;

enum{ObjectClass_sizes = sizeof(ObjectShell)};
typedef struct ObjectParams
{
} ObjectParams;

ObjectClass const * const ObjectClass_instance();
void Object_init(Object * const me, ObjectParams const * const params);
void Object_terminate(Object * const me);
uint8 Object_size(Object const * const me);
char const * Object_type(Object const * const me);
void Object_classSet(Object * const me, ObjectClass const * const c);

#endif // OBJECT_H

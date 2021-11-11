#ifndef OBJECT_H
#define OBJECT_H
#include "Cbject.h"

#define Object_isTypeOf(me, class) \
    (Object_type((Object *)(me)) == (ObjectType *)class##Type_instance())

typedef struct ObjectType ObjectType;
typedef struct Object Object;
typedef char ObjectParams;

typedef struct ObjectVirtFuns
{
    uint8 (*size)(Object const * const me);
} ObjectVirtFuns;

typedef union ObjectTypeContainer
{
    Cbject_Settings_maxAlign align;
    char container[sizeof(
        struct
        {
            Cbject_Settings_maxAlign align;
            char const * name;
            ObjectType * superType;
            ObjectVirtFuns virtFuns;
        })];
} ObjectTypeContainer;

typedef union ObjectContainer
{
    Cbject_Settings_maxAlign align;
    char container[sizeof(
        struct
        {
            Cbject_Settings_maxAlign align;
            ObjectType * type;
        })];
} ObjectContainer;

ObjectType const * const ObjectType_instance();
void Object_init(Object * const me, ObjectParams const params);
void Object_terminate(Object * const me);
uint8 Object_size(Object const * const me);
ObjectType const * Object_type(Object * const me);

#endif // OBJECT_H

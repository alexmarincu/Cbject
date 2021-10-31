#ifndef OBJECT_H
#define OBJECT_H
#include "Cbject.h"

#define Object_isTypeOf(me, typeName) \
    (Object_type((Object *)(me)) == (ObjectType *)typeName##Type_instance())

#define Cast(typeName, me) \
    Object_to##typeName((Object *)me)

typedef struct ObjectType ObjectType;
typedef struct Object Object;
typedef char ObjectParams;

typedef struct ObjectVirtFuns
{
    uint8 (*size)(Object const * const me);
} ObjectVirtFuns;

typedef union ObjectTypeContainer
{
    Cbject_Settings_maxAlign a;
    char c[sizeof(struct
        {
            Cbject_Settings_maxAlign a;
            char const * name;
            ObjectType * st;
            ObjectVirtFuns vf;
        })];
} ObjectTypeContainer;

typedef union ObjectContainer
{
    Cbject_Settings_maxAlign a;
    char c[sizeof(struct
        {
            Cbject_Settings_maxAlign a;
            ObjectType * t;
        })];
} ObjectContainer;

ObjectType const * const ObjectType_instance();
void Object_init(Object * const me, ObjectParams const p);
void Object_terminate(Object * const me);
uint8 Object_size(Object const * const me);
ObjectType const * Object_type(Object * const me);

#endif // OBJECT_H

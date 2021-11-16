#ifndef OBJECT_H
#define OBJECT_H
#include "Cbject.h"

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

ObjectType const * ObjectType_instance();
void Object_init(Object * const me, ObjectParams const * const params);
void Object_terminate(Object * const me);
uint8 Object_size(Object const * const me);
ObjectType const * Object_type(Object * const me);
char const * Object_typeName(Object const * const me);
Object * Object_toObject(Object * const me);
bool Object_isTypeOf(Object const * const me, ObjectType const * const targetType);

#endif // OBJECT_H

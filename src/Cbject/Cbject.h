#ifndef CBJECT_H
#define CBJECT_H

/* tag::overview[]
== Cbject

[plantuml, target=CbjectDiagram, format=png]
....
hide circle
class ObjectType {
    max_align align - alignment enforcer
    ..
    char * name - type name
    ..
    ObjectVirtFuns virtFuns - struct containing pointers to functions
}

class Object {
    max_align align - alignment enforcer
    ..
    ObjectType type - pointer to the type struct
}

class CustomClass {
    Object super - embedded super class
    ..
    CustomClassData data - struct containing the object fields
}

Object::type -> ObjectType::align
CustomClass -[hidden]u-> Object
....

end::overview[] */

#include "Cbject_Assert.h"
#include "Cbject_Keywords.h"
#include "Cbject_PrimitiveTypes.h"
#include "Cbject_Settings.h"
#include "Object.h"

#define Assert(condition) \
    Cbject_Assert(condition)

#define StaticAssert(condition, identifier) \
    Cbject_Assert_Static(condition, identifier)

#define Cast(me, class) \
    Object_to##class((Object *)me)

#define Get(class, ...) \
    class##_get(__VA_ARGS__)

#define Create(class, ...) \
    class##_create(__VA_ARGS__)

#define Delete(me, class) \
    class##_delete(me)

#define StackCreate(class, ...) \
    class##_stackCreate((class *)&(class##Container){}, __VA_ARGS__)

#define Size(me) \
    Object_size((Object *)me)

#define TypeName(me) \
    Object_typeName((Object *)me)

#define IsTypeOf(me, class) \
    Object_isTypeOf((Object *)me, (ObjectType *)class##Type_instance())

#endif // CBJECT_H

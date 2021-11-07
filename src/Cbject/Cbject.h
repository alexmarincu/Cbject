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

#include "Cbject_Keywords.h"
#include "Cbject_PrimitiveTypes.h"
#include "Cbject_Settings.h"
#include "Cbject_StaticAssert.h"
#include "Object.h"
#include <assert.h>

#endif // CBJECT_H

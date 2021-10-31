#ifndef CBJECT_H
#define CBJECT_H

/* tag::overview[]
== Cbject

[plantuml, target=CbjectDiagram, format=png]
....
hide circle
class ObjectType {
    max_align a - alignment enforcer
    ..
    char * name - type name
    ..
    ObjectVirtFuns vf - struct containing pointers to functions
}

class Object {
    max_align a - alignment enforcer
    ..
    ObjectType t - pointer to the type struct
}

class CustomClass {
    Object s - embedded super class
    ..
    CustomClassData d - struct containing the object fields
}

Object::type -> ObjectType::a
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

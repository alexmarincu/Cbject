/* tag::overview[]
== Cbject
[plantuml, target=ClassObject, format=png]
.Object model with class
....
hide circle
together {
class Object {
    Object_Interface * interface;
}
class Object_Class {
    Object_Interface super;
    size_t objectSize;
    Class const * superClass;
}
}
together {
class Object_Interface {
    size_t offset;
    Operations const * operations;
}
class Object_Operations {
    Object * (*teardown)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
}
}
Object -r-> Object_Class
Object_Class -u-|> Object_Interface
Object_Interface -r-> Object_Operations
....

[plantuml, target=InterfaceObject, format=png]
.Object model with interface
....
hide circle
together {
class Object {
    Object_Interface * interface;
}
class Object_Interface {
    size_t offset;
    Operations const * operations;
}
}
Object -r-> Object_Interface
....

[plantuml, target=CustomClassObject, format=png]
.Object model of a custom object with class
....
hide circle
class Shape {
    Object super;
    Point origin;
}
together {
class Object {
    Object_Interface * interface;
}
class Shape_Class {
    Object_Class super;
}
}
class Object_Class {
    Type super;
    size_t objectSize;
    Class const * superClass;
}
together {
class Object_Interface {
    size_t offset;
    Operations const * operations;
}
class Shape_Operations {
    Object_Operations super;
    float (*area)(Shape const * const me);
}
}
class Object_Operations {
    Object * (*teardown)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other)
}
Shape -u-|> Object
Object -r-> Shape_Class
Shape_Class -u-|> Object_Class
Object_Class -u-|> Object_Interface
Object_Interface -r-> Shape_Operations
Shape_Operations -u-|> Object_Operations
....
end::overview[] */
#ifndef CBJECT_H
#define CBJECT_H
#include "Assert.h"
#include "Object.h"
#include "Trait.h"
#endif // CBJECT_H

/* tag::overview[]
== Cbject
[plantuml, target=CbjectDiagram, format=png]
....
together {
object Object {
    ..
    Type * type;
}
object Object_Interface {
    ..
    Interface super;
}
object Object_Class {
    ..
    Class super;
}
}
together {
object Interface {
    ..
    Type super;
}
object Class {
    ..
    Type super;
    char const * name;
    size_t objectSize;
    Class const * superClass;
}
}
together {
object Type {
    ..
    size_t offset;
    Operations const * operations;
}
object Object_Operations {
    ..
    Object * (*deinit)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
}
}
Object -l-> Object_Interface
Object -r-> Object_Class
Object_Interface *-u- Interface
Object_Class *-u- Class
Class *-u- Type
Interface *-u- Type
Type -r-> Object_Operations
....
end::overview[] */
#ifndef CBJECT_H
#define CBJECT_H
#include "Assert.h"
#include "Class.h"
#include "Interface.h"
#include "Object.h"
#endif // CBJECT_H

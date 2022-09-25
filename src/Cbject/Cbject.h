/* tag::overview[]
Cbject makes it easier to write object oriented code in C.

=== Features
* Classes
* Traits
* Polymorphism

=== Usage
.How to add it to a project
====
Include the following header file:

[source,c]
----
#include "Cbject.h"
----
====

.How to create an object
====
[source,c]
----
Object * object = initObject_(Object, alloc_(Object));
printf("%d\n", hashCode_(object));
dealloc_(object);
----
====

=== Object model
[plantuml, target=diag-building-blocks, format=png]
.Building blocks
----
object Object {
    Object_Class const * class;
}
object Object_Class {
    size_t objectSize;
    Object_Class const * superClass;
    Object * (*teardown)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
}
Object -r-> Object_Class
object Trait {
    size_t offset;
    size_t interfaceOffset;
}
object Trait_Interface {
    size_t offset;
}
----

[plantuml, target=diag-rectangle-class-example, format=png]
.Rectangle class example
----
object Rectangle {
    Shape super;
    Drawable mDrawable;
    uint32_t width;
    uint32_t height;
}
object Shape {
    Object super;
    Point origin;
}
object Drawable {
    Trait super;
}
object Drawable_Interface {
    Trait_Interface super;
    void (*draw)(Drawable const * const me);
}
object Trait {
    size_t offset;
    size_t interfaceOffset;
}
object Rectangle_Class {
    Shape_Class super;
    Drawable_Interface mDrawable_Interface;
}
object Trait_Interface {
    size_t offset;
}
object Object {
    Object_Class const * class;
}
object Shape_Class {
    Object_Class super;
    float (*area)(Shape const * const me);
}
object Object_Class {
    size_t objectSize;
    Object_Class const * superClass;
    Object * (*teardown)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
}
Rectangle -u-|> Shape
Rectangle *-r- Drawable
Rectangle_Class *-r- Drawable_Interface
Drawable -u-|> Trait
Drawable_Interface -u-|> Trait_Interface
Rectangle_Class -u-|> Shape_Class
Shape -u-|> Object
Object -r-> Rectangle_Class
Shape_Class -u-|> Object_Class
----
end::overview[] */
#ifndef CBJECT_H
#define CBJECT_H
#include "Assert.h"
#include "Object.h"
#include "Trait.h"
#endif // CBJECT_H

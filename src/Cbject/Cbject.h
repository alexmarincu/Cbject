/* tag::overview[]
Cbject makes it easier to write object oriented code in C.

=== Features
* Classes
* Objects
* Traits
* Interfaces
* Inheritance
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
!include ../src/Cbject/Object.h!Object
!include ../src/Cbject/Object.h!Object_Class
!include ../src/Cbject/Trait.h!Trait
!include ../src/Cbject/Trait.h!Trait_Interface
Object -r-> Object_Class
----

[plantuml, target=diag-rectangle-class-example, format=png]
.Rectangle class example
----
!include ../src/Examples/Rectangle.c!Rectangle
!include ../src/Examples/Shape.h!Shape
!include ../src/Examples/Drawable.h!Drawable
!include ../src/Examples/Drawable.h!Drawable_Interface
!include ../src/Cbject/Trait.h!Trait
!include ../src/Examples/Rectangle.h!Rectangle_Class
!include ../src/Cbject/Trait.h!Trait_Interface
!include ../src/Cbject/Object.h!Object
!include ../src/Examples/Shape.h!Shape_Class
!include ../src/Cbject/Object.h!Object_Class
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

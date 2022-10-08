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

----
#include "Cbject.h"
----
====

.How to create an object
====
----
Object * object = allocInit_(Object);
printf("%d\n", hashCode_(object));
dealloc_(object);
----
====

=== Object model
[plantuml, target=diag-building-blocks, format=png]
.Building blocks
----
!include ../src/Cbject/Object.h!Object
!include ../src/Cbject/Object.h!ObjectClass
!include ../src/Cbject/Trait.h!Trait
!include ../src/Cbject/Trait.h!TraitInterface
Object -r-> ObjectClass
----

[plantuml, target=diag-rectangle-class-example, format=png]
.Rectangle class example
----
!include ../src/Examples/Rectangle.c!Rectangle
!include ../src/Examples/Shape.h!Shape
!include ../src/Examples/Drawable.h!Drawable
!include ../src/Examples/Drawable.h!DrawableInterface
!include ../src/Cbject/Trait.h!Trait
!include ../src/Examples/Rectangle.h!RectangleClass
!include ../src/Cbject/Trait.h!TraitInterface
!include ../src/Cbject/Object.h!Object
!include ../src/Examples/Shape.h!ShapeClass
!include ../src/Cbject/Object.h!ObjectClass
Rectangle -u-|> Shape
Rectangle *-r- Drawable
RectangleClass *-r- DrawableInterface
Drawable -u-|> Trait
DrawableInterface -u-|> TraitInterface
RectangleClass -u-|> ShapeClass
Shape -u-|> Object
Object -r-> RectangleClass
ShapeClass -u-|> ObjectClass
----
end::overview[] */
#ifndef CBJECT_H
#define CBJECT_H
#include "Object.h"
#include "Trait.h"
#endif // CBJECT_H

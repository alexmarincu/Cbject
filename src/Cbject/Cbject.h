/* tag::overview[]
Cbject makes it easier to write object oriented code in C.

=== Features
* Objects
* Classes
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
Cbject_Object * object = Cbject_allocInit(Cbject_Object);
printf("%d\n", Cbject_hashCode(object));
Cbject_dealloc(object);
----
====

=== Cbject_Object model
[plantuml, target=diag-building-blocks, format=png]
.Building blocks
----
!include ../src/Cbject/Cbject_Object.h!Cbject_Object
!include ../src/Cbject/Cbject_Object.h!Cbject_ObjectClass
!include ../src/Cbject/Cbject_Trait.h!Cbject_Trait
!include ../src/Cbject/Cbject_Trait.h!Cbject_TraitInterface
Cbject_Object -r-> Cbject_ObjectClass
----

[plantuml, target=diag-rectangle-class-example, format=png]
.Rectangle class example
----
!include ../src/Examples/Rectangle.c!Rectangle
!include ../src/Examples/Shape.h!Shape
!include ../src/Examples/Drawable.h!Drawable
!include ../src/Examples/Drawable.h!DrawableInterface
!include ../src/Cbject/Cbject_Trait.h!Cbject_Trait
!include ../src/Examples/Rectangle.h!RectangleClass
!include ../src/Cbject/Cbject_Trait.h!Cbject_TraitInterface
!include ../src/Cbject/Cbject_Object.h!Cbject_Object
!include ../src/Examples/Shape.h!ShapeClass
!include ../src/Cbject/Cbject_Object.h!Cbject_ObjectClass
Rectangle -u-|> Shape
Rectangle *-r- Drawable
RectangleClass *-r- DrawableInterface
Drawable -u-|> Cbject_Trait
DrawableInterface -u-|> Cbject_TraitInterface
RectangleClass -u-|> ShapeClass
Shape -u-|> Cbject_Object
Cbject_Object -r-> RectangleClass
ShapeClass -u-|> Cbject_ObjectClass
----
end::overview[] */
#ifndef CBJECT_H
#define CBJECT_H
#include "Cbject_Object.h"
#include "Cbject_Settings.h"
#include "Cbject_Trait.h"
#endif // CBJECT_H

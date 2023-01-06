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
#include "cbject.h"
----
====

.How to create an object
====
----
cbject_Object * object = cbject_allocInit(cbject_Object);
printf("%d\n", cbject_hashCode(object));
cbject_Object_dealloc(object);
----
====

=== cbject_Object model
[plantuml, target=diag-building-blocks, format=png]
.Building blocks
----
!include ../src/cbject/cbject_Object.h!cbject_Object
!include ../src/cbject/cbject_Object.h!cbject_ObjectClass
!include ../src/cbject/cbject_Trait.h!cbject_Trait
!include ../src/cbject/cbject_Trait.h!cbject_TraitInterface
cbject_Object -r-> cbject_ObjectClass
----

[plantuml, target=diag-rectangle-class-example, format=png]
.Rectangle class example
----
!include ../src/Examples/Rectangle.c!Rectangle
!include ../src/Examples/Shape.h!Shape
!include ../src/Examples/Drawable.h!Drawable
!include ../src/Examples/Drawable.h!DrawableInterface
!include ../src/cbject/cbject_Trait.h!cbject_Trait
!include ../src/Examples/Rectangle.h!RectangleClass
!include ../src/cbject/cbject_Trait.h!cbject_TraitInterface
!include ../src/cbject/cbject_Object.h!cbject_Object
!include ../src/Examples/Shape.h!ShapeClass
!include ../src/cbject/cbject_Object.h!cbject_ObjectClass
Rectangle -u-|> Shape
Rectangle *-r- Drawable
RectangleClass *-r- DrawableInterface
Drawable -u-|> cbject_Trait
DrawableInterface -u-|> cbject_TraitInterface
RectangleClass -u-|> ShapeClass
Shape -u-|> cbject_Object
cbject_Object -r-> RectangleClass
ShapeClass -u-|> cbject_ObjectClass
----
end::overview[] */
#ifndef CBJECT_H
#define CBJECT_H
#include "cbject_Object.h"
#include "cbject_Trait.h"
#include "cbject_settings.h"
/* tag::macro[]
= cbject_typedefClass()
====
----
cbject_typedefClass(className)
----
Syntactic sugar to define types for a class

.Params
* className - Name of the class
====
end::macro[] */
#define cbject_typedefClass(className) \
    cbject_utils_typedefClass(className)
/* tag::macro[]
= cbject_typedefInterface()
====
----
cbject_typedefInterface(interfaceName)
----
Syntactic sugar to define types for an interface

.Params
* interfaceName - Name of the interface
====
end::macro[] */
#define cbject_typedefInterface(interfaceName) \
    cbject_utils_typedefInterface(interfaceName)
/* tag::macro[]
= cbject_is()
====
----
cbject_is(typeName)
----
Syntactic sugar to extend a type

.Remark
Should be used as the first member in the structure

.Params
* typeName - Name of the type
====
end::macro[] */
#define cbject_is(typeName) \
    typeName s_##typeName
/* tag::macro[]
= cbject_has()
====
----
cbject_has(typeName)
----
Syntactic sugar to compose a type with the provided typeName

.Remark
Should be used after cbject_is() macro

.Params
* typeName - Name of the type
====
end::macro[] */
#define cbject_has(typeName) \
    typeName ss_##typeName
/* tag::macro[]
= cbject_alloc()
====
----
cbject_alloc(className)
----
Syntactic sugar to allocate an object in heap memory

.Params
* className - Name of class

.Return
Reference of the allocated object
====
end::macro[] */
#define cbject_alloc(className) \
    ((className *)cbject_ObjectClass_alloc((cbject_ObjectClass *)className##Class_getInstance()))
/* tag::macro[]
= cbject_salloc()
====
----
cbject_salloc(className)
----
Syntactic sugar to allocate object on the stack

.Params
* className - Name of class

.Return
Reference of the allocated memory
====
end::macro[] */
#define cbject_salloc(className) \
    (&(className){ .objectClass = className##Class_getInstance() })
/* tag::macro[]
= cbject_setUpClass()
====
----
cbject_setUpClass(className, superClassName, objectClass)
----
Class setup (initialize super, set the object size and super class)

.Params
* className - Name of the class
* superClassName - Name of the super class
* objectClass - Class instance
====
end::macro[] */
#define cbject_setUpClass(className, superClassName, objectClass)                     \
    *((superClassName##Class *)(objectClass)) = *superClassName##Class_getInstance(); \
    ((cbject_ObjectClass *)(objectClass))->name = #className;                         \
    ((cbject_ObjectClass *)(objectClass))->objectSize = sizeof(className);            \
    ((cbject_ObjectClass *)(objectClass))->superClass =                               \
        (cbject_ObjectClass *)superClassName##Class_getInstance()
/* tag::macro[]
= cbject_bindClassMethod()
====
----
cbject_bindClassMethod(className, methodName, objectClass)
----
Bind a method of a class

.Params
* className - Name of the class
* methodName - Name of the method
* objectClass - Class instance
====
end::macro[] */
#define cbject_bindClassMethod(className, methodName, objectClass) \
    ((className##Class *)(objectClass))->methodName = methodName
/* tag::macro[]
= cbject_setUpInterfaceOf()
====
----
cbject_setUpInterfaceOf(className, interfaceName, objectClass)
----
Interface setup in class (initialize super, set the trait offset in container object)

.Params
* className - Name of the class
* interfaceName - Name of the interface
* objectClass - Class instance
====
end::macro[] */
#define cbject_setUpInterfaceOf(className, interfaceName, objectClass)                               \
    *((interfaceName##Interface *)&(objectClass)->ss_##interfaceName##Interface) =                   \
        *interfaceName##Interface_getInstance();                                                     \
    ((cbject_TraitInterface *)&(objectClass)->ss_##interfaceName##Interface)->name = #interfaceName; \
    ((cbject_TraitInterface *)&(objectClass)->ss_##interfaceName##Interface)->traitOffset =          \
        offsetof(className, ss_##interfaceName)
/* tag::macro[]
= cbject_bindInterfaceMethodOf()
====
----
cbject_bindInterfaceMethodOf(className, interfaceName, methodName, objectClass)
----
Bind a method of an interface

.Params
* className - Name of the class
* interfaceName - Name of the interface
* methodName - Name of the method
* objectClass - Class instance
====
end::macro[] */
#define cbject_bindInterfaceMethodOf(className, interfaceName, methodName, objectClass) \
    (                                                                                   \
        (interfaceName##Interface *)&((className##Class *)(objectClass))                \
            ->ss_##interfaceName##Interface                                             \
    )                                                                                   \
        ->methodName = methodName
/* tag::macro[]
= cbject_dealloc()
====
----
cbject_dealloc(object)
----
Syntactic sugar to free memory allocated for an object

.Params
* object - cbject_Object reference

.Return
NULL
====
end::macro[] */
#define cbject_dealloc(object) \
    ((void *)cbject_Object_dealloc((cbject_Object *)object))
/* tag::macro[]
= cbject_setUpTraitOf()
====
----
cbject_setUpTraitOf(className, interfaceName, ...)
----
cbject_Trait setup (initialize, set the trait offset and interface offset)

.Params
* className - Name of the class
* interfaceName - Name of the interface
* ...
** object - cbject_Object reference
** ... - Init params
====
end::macro[] */
#define cbject_setUpTraitOf(className, interfaceName, ...)                                                      \
    cbject_initTrait(                                                                                           \
        interfaceName,                                                                                          \
        &cbject_utils_VaArgs_first(__VA_ARGS__)->ss_##interfaceName cbject_utils_VaArgs_rest(__VA_ARGS__)       \
    );                                                                                                          \
    cbject_utils_cast(cbject_Trait, &cbject_utils_VaArgs_first(__VA_ARGS__)->ss_##interfaceName)->object =      \
        (cbject_Object *)cbject_utils_VaArgs_first(__VA_ARGS__);                                                \
    cbject_utils_cast(cbject_Trait, &cbject_utils_VaArgs_first(__VA_ARGS__)->ss_##interfaceName)->interface =   \
        (void *)&className##Class_getInstance()->ss_##interfaceName##Interface;                                 \
/* tag::macro[]                                                                                                 \
= cbject_teardown()                                                                                             \
====                                                                                                            \
----                                                                                                            \
cbject_teardown(object)                                                                                         \
----                                                                                                            \
Syntactic sugar to teardown an object.                                                                          \
                                                                                                              \ \
.Params                                                                                                         \
* object - cbject_Object reference                                                                              \
                                                                                                              \ \
.Return                                                                                                         \
NULL                                                                                                            \
====                                                                                                            \
end::macro[] */
#define cbject_teardown(object) \
    ((void *)cbject_Object_teardown((cbject_Object *)(object)))
/* tag::macro[]
= cbject_equals()
====
----
cbject_equals(object, otherObject)
----
Syntactic sugar to compare two objects

.Params
* object - cbject_Object reference
* otherObject - Reference for the compared object

.Return
* true - If the objects are equal
* false - If the objects are different
====
end::macro[] */
#define cbject_equals(object, otherObject) \
    cbject_Object_equals((cbject_Object *)(object), (cbject_Object *)(otherObject))
/* tag::macro[]
= cbject_hashCode()
====
----
cbject_hashCode(object)
----
Syntactic sugar to get hash code of object

.Params
* object - cbject_Object reference

.Return
cbject_Object hash code
====
end::macro[] */
#define cbject_hashCode(object) \
    cbject_Object_hashCode((cbject_Object *)(object))
/* tag::macro[]
= cbject_isOfClass()
====
----
cbject_isOfClass(object, className)
----
Syntactic sugar to check if an object is of a given class

.Params
* object - cbject_Object reference
* className - Class name

.Return
* true - If the object is of the provided class
* false - If the object is of a different class
====
end::macro[] */
#define cbject_isOfClass(object, className)                  \
    cbject_Object_isOfClass(                                 \
        (cbject_Object *)(object),                           \
        (cbject_ObjectClass *)className##Class_getInstance() \
    )
/* tag::macro[]
= cbject_setUpInterface()
====
----
cbject_setUpInterface(interfaceName, traitInterface)
----
Interface setup (initialize super)

.Params
* interfaceName - Name of the interface
* traitInterface - Interface instance
====
end::macro[] */
#define cbject_setUpInterface(interfaceName, superInterfaceName, traitInterface)                       \
    *((superInterfaceName##Interface *)traitInterface) = *superInterfaceName##Interface_getInstance(); \
    ((cbject_TraitInterface *)traitInterface)->name = #interfaceName
/* tag::macro[]
= cbject_bindInterfaceMethod()
====
----
cbject_bindInterfaceMethod(interfaceName, methodName, traitInterface)
----
Bind a method of an interface

.Params
* interfaceName - Name of the interface
* superInterfaceName - Name of the super interface
* methodName - Name of the method
* traitInterface - Interface instance
====
end::macro[] */
#define cbject_bindInterfaceMethod(interfaceName, methodName, traitInterface) \
    ((interfaceName##Interface *)traitInterface)->methodName = methodName
/* tag::macro[]
= cbject_initTrait()
====
----
cbject_initTrait(interfaceName, ...)
----
Syntactic sugar for trait initialization

.Params
* interfaceName - Name of the interface
* ...
** trait - cbject_Trait reference
** ... - Init params

.Return
Initialized trait
====
end::macro[] */
#define cbject_initTrait(interfaceName, ...)                      \
    interfaceName##_init(                                         \
        ((interfaceName *)cbject_utils_VaArgs_first(__VA_ARGS__)) \
            cbject_utils_VaArgs_rest(__VA_ARGS__)                 \
    )
/* tag::macro[]
= cbject_lengthOfArray()
====
----
cbject_lengthOfArray(array)
----
Get length of an array

.Params
* array - Array for which to get the length
====
end::macro[] */
#define cbject_lengthOfArray(array) \
    (sizeof(array) / sizeof(array[0]))
/* tag::macro[]
= cbject_assertStatic()
====
----
cbject_assertStatic(expression, identifier)
----
Compile time assert

.Params
* expression - Expression to assert
* identifier - An identifier to describe the assertion
====
end::macro[] */
#define cbject_assertStatic(expression, identifier) \
    typedef char identifier[(!!(expression)) * 2 - 1]
/* tag::macro[]
= cbject_doOnce
====
----
cbject_doOnce
----
Run a block of code only once

.Usage
----
cbject_doOnce {
    functionCall();
    anotherFunctionCall();
}
----

.Remark
Not thread safe
====
end::macro[] */
#define cbject_doOnce           \
    static bool isDone = false; \
    for (; isDone == false; isDone = true)
#endif // CBJECT_H

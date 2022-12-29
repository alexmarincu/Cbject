/* tag::overview[]
TODO
end::overview[] */
#ifndef CBJECT_UTILS_H
#define CBJECT_UTILS_H
#include <assert.h>
#if Cbject_useShortNames == true
    #include "Cbject_ShortNames.h"
#endif
/* tag::macro[]
= Cbject_typedefClass()
====
----
#define Cbject_typedefClass(className)
----
Syntactic sugar to define types for a class

.Params
* className - Name of the class
====
end::macro[] */
#define Cbject_typedefClass(className)                \
    typedef struct className##Class className##Class; \
    typedef struct className className
/* tag::macro[]
= Cbject_setUpClass()
====
----
#define Cbject_setUpClass(className, superClassName, objectClass)
----
Class setup (initialize super, set the object size and super class)

.Params
* className - Name of the class
* superClassName - Name of the super class
* objectClass - Class instance
====
end::macro[] */
#define Cbject_setUpClass(className, superClassName, objectClass)                       \
    *Cbject_castTo(superClassName##Class, objectClass) = *Cbject_class(superClassName); \
    Cbject_castTo(Cbject_ObjectClass, objectClass)->name = #className;                  \
    Cbject_castTo(Cbject_ObjectClass, objectClass)->objectSize = sizeof(className);     \
    Cbject_castTo(Cbject_ObjectClass, objectClass)->superClass = Cbject_castTo(Cbject_ObjectClass, Cbject_class(superClassName))
/* tag::macro[]
= Cbject_bindClassMethod()
====
----
#define Cbject_bindClassMethod(className, methodName, objectClass)
----
Bind a method of a class

.Params
* className - Name of the class
* methodName - Name of the method
* objectClass - Class instance
====
end::macro[] */
#define Cbject_bindClassMethod(className, methodName, objectClass) \
    Cbject_castTo(className##Class, objectClass)->methodName = methodName
/* tag::macro[]
= Cbject_setUpInterfaceOf()
====
----
#define Cbject_setUpInterfaceOf(className, interfaceName, objectClass)
----
Interface setup in class (initialize super, set the trait offset in container object)

.Params
* className - Name of the class
* interfaceName - Name of the interface
* objectClass - Class instance
====
end::macro[] */
#define Cbject_setUpInterfaceOf(className, interfaceName, objectClass)                                                          \
    *Cbject_castTo(interfaceName##Interface, &(objectClass)->ss_##interfaceName##Interface) = *Cbject_interface(interfaceName); \
    Cbject_castTo(Cbject_TraitInterface, &(objectClass)->ss_##interfaceName##Interface)->name = #interfaceName;                 \
    Cbject_castTo(Cbject_TraitInterface, &(objectClass)->ss_##interfaceName##Interface)->traitOffset = offsetof(className, ss_##interfaceName)
/* tag::macro[]
= Cbject_bindInterfaceMethodOf()
====
----
#define Cbject_bindInterfaceMethodOf(className, interfaceName, methodName, objectClass)
----
Bind a method of an interface

.Params
* className - Name of the class
* interfaceName - Name of the interface
* methodName - Name of the method
* objectClass - Class instance
====
end::macro[] */
#define Cbject_bindInterfaceMethodOf(className, interfaceName, methodName, objectClass) \
    Cbject_castTo(interfaceName##Interface, &Cbject_castTo(className##Class, objectClass)->ss_##interfaceName##Interface)->methodName = methodName
/* tag::macro[]
= Cbject_alloc()
====
----
#define Cbject_alloc(className)
----
Syntactic sugar to allocate an object in heap memory

.Params
* className - Name of class

.Return
Reference of the allocated object
====
end::macro[] */
#define Cbject_alloc(className) \
    Cbject_castTo(className, Cbject_Object_alloc(Cbject_castTo(Cbject_ObjectClass, Cbject_class(className))))
/* tag::macro[]
= Cbject_dealloc()
====
----
#define Cbject_dealloc(object)
----
Syntactic sugar to free memory allocated for an object

.Params
* object - Cbject_Object reference

.Return
NULL
====
end::macro[] */
#define Cbject_dealloc(object) \
    Cbject_castTo(Cbject_Any, Cbject_Object_dealloc(Cbject_castTo(Cbject_Object, object)))
/* tag::macro[]
= Cbject_init()
====
----
#define Cbject_init(className, ...)
----
Syntactic sugar for object initialization

.Params
* className - Name of the class
* ...
** object - Cbject_Object reference
** ... - Init params

.Return
Initialized object
====
end::macro[] */
#define Cbject_init(className, ...) \
    className##_init(Cbject_castTo(className, Cbject_VaArgs_first(__VA_ARGS__)) Cbject_VaArgs_rest(__VA_ARGS__))
/* tag::macro[]
= Cbject_setUpObject()
====
----
#define Cbject_setUpObject(className, superClassName, ...)
----
Cbject_Object setup (initialize, set the object class)

.Params
* className - Name of the class
* superClassName - Name of the super class
* ...
** object - Cbject_Object reference
** ... - Init params
====
end::macro[] */
#define Cbject_setUpObject(className, superClassName, ...) \
    Cbject_init(superClassName, __VA_ARGS__);              \
    Cbject_classOf(Cbject_VaArgs_first(__VA_ARGS__)) = Cbject_castTo(Cbject_ObjectClass, Cbject_class(className))
/* tag::macro[]
= Cbject_setUpTraitOf()
====
----
#define Cbject_setUpTraitOf(className, interfaceName, ...)
----
Cbject_Trait setup (initialize, set the trait offset and interface offset)

.Params
* className - Name of the class
* interfaceName - Name of the interface
* ...
** object - Cbject_Object reference
** ... - Init params
====
end::macro[] */
#define Cbject_setUpTraitOf(className, interfaceName, ...)                                                                  \
    Cbject_initTrait(interfaceName, &Cbject_VaArgs_first(__VA_ARGS__)->ss_##interfaceName Cbject_VaArgs_rest(__VA_ARGS__)); \
    Cbject_offsetOf(&Cbject_VaArgs_first(__VA_ARGS__)->ss_##interfaceName) = offsetof(className, ss_##interfaceName);       \
    Cbject_interfaceOffsetOf(&Cbject_VaArgs_first(__VA_ARGS__)->ss_##interfaceName) = offsetof(className##Class, ss_##interfaceName##Interface)
/* tag::macro[]
= Cbject_allocInit()
====
----
#define Cbject_allocInit(...)
----
Syntactic sugar to allocate and init an object in heap memory

.Params
* ...
** className - Name of class
** ... - Init params

.Return
Reference of the allocated and initialized object
====
end::macro[] */
#define Cbject_allocInit(...) \
    Cbject_allocInit_h0(Cbject_VaArgs_first(__VA_ARGS__), Cbject_alloc(Cbject_VaArgs_first(__VA_ARGS__)) Cbject_VaArgs_rest(__VA_ARGS__))
#define Cbject_allocInit_h0(className, ...) \
    Cbject_init(className, Cbject_VaArgs_first(__VA_ARGS__) Cbject_VaArgs_rest(__VA_ARGS__))
/* tag::macro[]
= Cbject_sallocInit()
====
----
#define Cbject_sallocInit(...)
----
Syntactic sugar to allocate and init an object in stack memory

.Params
* ...
** className - Name of class
** ... - Init params

.Return
Reference of the allocated and initialized object
====
end::macro[] */
#define Cbject_sallocInit(...) \
    Cbject_sallocInit_h0(Cbject_VaArgs_first(__VA_ARGS__), Cbject_salloc(Cbject_VaArgs_first(__VA_ARGS__)) Cbject_VaArgs_rest(__VA_ARGS__))
#define Cbject_sallocInit_h0(className, ...) \
    Cbject_init(className, Cbject_VaArgs_first(__VA_ARGS__) Cbject_VaArgs_rest(__VA_ARGS__))
/* tag::macro[]
= Cbject_teardown()
====
----
#define Cbject_teardown(object)
----
Syntactic sugar to teardown an object.

.Params
* object - Cbject_Object reference

.Return
NULL
====
end::macro[] */
#define Cbject_teardown(object) \
    Cbject_castTo(Cbject_Any, Cbject_Object_teardown(Cbject_castTo(Cbject_Object, object)))
/* tag::macro[]
= Cbject_copy()
====
----
#define Cbject_copy(className, object, copyObject)
----
Syntactic sugar to make a copy of an object.

.Params
* className - Name of class
* object - Cbject_Object reference
* copyObject - Reference of a new allocated object in which to copy the original one

.Return
Pointer to a new object (copy of the original one)
====
end::macro[] */
#define Cbject_copy(className, object, copyObject) \
    Cbject_castTo(className, Cbject_Object_copy(Cbject_castTo(Cbject_Object, object), Cbject_castTo(Cbject_Object, copyObject)))
/* tag::macro[]
= Cbject_allocCopy()
====
----
#define Cbject_allocCopy(className, object)
----
Syntactic sugar to copy object in new object allocated in heap memory

.Params
* className - Name of class
* object - Cbject_Object reference

.Return
Reference of the allocated object (copy of the original one)
====
end::macro[] */
#define Cbject_allocCopy(className, object) \
    Cbject_copy(className, object, Cbject_alloc(className))
/* tag::macro[]
= Cbject_sallocCopy()
====
----
#define Cbject_sallocCopy(className, object)
----
Syntactic sugar to copy object in new object allocated in stack memory

.Params
* className - Name of class
* object - Cbject_Object reference

.Return
Reference of the allocated object (copy of the original one)
====
end::macro[] */
#define Cbject_sallocCopy(className, object) \
    Cbject_copy(className, object, Cbject_salloc(className))
/* tag::macro[]
= Cbject_equals()
====
----
#define Cbject_equals(object, otherObject)
----
Syntactic sugar to compare two objects

.Params
* object - Cbject_Object reference
* otherObject - Reference for the compared object

.Return
* true - If the objects are equal
* false - If the objects are different
====
end::macro[] */
#define Cbject_equals(object, otherObject) \
    Cbject_Object_equals(Cbject_castTo(Cbject_Object, object), Cbject_castTo(Cbject_Object, otherObject))
/* tag::macro[]
= Cbject_hashCode()
====
----
#define Cbject_hashCode(object)
----
Syntactic sugar to get hash code of object

.Params
* object - Cbject_Object reference

.Return
Cbject_Object hash code
====
end::macro[] */
#define Cbject_hashCode(object) \
    Cbject_Object_hashCode(Cbject_castTo(Cbject_Object, object))
/* tag::macro[]
= Cbject_isOfClass()
====
----
#define Cbject_isOfClass(object, className)
----
Syntactic sugar to check if an object is of a given class

.Params
* object - Cbject_Object reference
* className - Class name

.Return
* true - If the object is of the provided class
* false - If the object is of a different class
====
end::macro[] */
#define Cbject_isOfClass(object, className) \
    Cbject_Object_isOfClass(Cbject_castTo(Cbject_Object, object), Cbject_castTo(Cbject_ObjectClass, Cbject_class(className)))
/* tag::macro[]
= Cbject_typedefInterface()
====
----
#define Cbject_typedefInterface(interfaceName)
----
Syntactic sugar to define types for an interface

.Params
* interfaceName - Name of the interface
====
end::macro[] */
#define Cbject_typedefInterface(interfaceName)                        \
    typedef struct interfaceName##Interface interfaceName##Interface; \
    typedef struct interfaceName interfaceName
/* tag::macro[]
= Cbject_setUpInterface()
====
----
#define Cbject_setUpInterface(interfaceName, traitInterface)
----
Interface setup (initialize super)

.Params
* interfaceName - Name of the interface
* traitInterface - Interface instance
====
end::macro[] */
#define Cbject_setUpInterface(interfaceName, superInterfaceName, traitInterface)                           \
    *Cbject_castTo(superInterfaceName##Interface, traitInterface) = *Cbject_interface(superInterfaceName); \
    Cbject_castTo(Cbject_TraitInterface, traitInterface)->name = #interfaceName
/* tag::macro[]
= Cbject_bindInterfaceMethod()
====
----
#define Cbject_bindInterfaceMethod(interfaceName, methodName, traitInterface)
----
Bind a method of an interface

.Params
* interfaceName - Name of the interface
* superInterfaceName - Name of the super interface
* methodName - Name of the method
* traitInterface - Interface instance
====
end::macro[] */
#define Cbject_bindInterfaceMethod(interfaceName, methodName, traitInterface) \
    Cbject_castTo(interfaceName##Interface, traitInterface)->methodName = methodName
/* tag::macro[]
= Cbject_initTrait()
====
----
#define Cbject_initTrait(interfaceName, ...)
----
Syntactic sugar for trait initialization

.Params
* interfaceName - Name of the interface
* ...
** trait - Cbject_Trait reference
** ... - Init params

.Return
Initialized trait
====
end::macro[] */
#define Cbject_initTrait(interfaceName, ...) \
    interfaceName##_init(Cbject_castTo(interfaceName, Cbject_VaArgs_first(__VA_ARGS__)) Cbject_VaArgs_rest(__VA_ARGS__))
/* tag::type[]
= Cbject_Any
====
----
typedef void Cbject_Any;
----
Typedef for Cbject_Any

.Remark
To be used with pointers to anything
====
end::type[] */
typedef void Cbject_Any;
/* tag::macro[]
= Cbject_doOnce
====
----
#define Cbject_doOnce
----
Run a block of code only once

.Usage
----
Cbject_doOnce {
    functionCall();
    anotherFunctionCall();
}
----

.Remark
Not thread safe
====
end::macro[] */
#define Cbject_doOnce           \
    static bool isDone = false; \
    for (; isDone == false; isDone = true)
/* tag::macro[]
= Cbject_assertStatic()
====
----
#define Cbject_assertStatic(expression, identifier)
----
Compile time assert

.Params
* expression - Expression to assert
* identifier - An identifier to describe the assertion
====
end::macro[] */
#define Cbject_assertStatic(expression, identifier) \
    typedef char identifier[(!!(expression)) * 2 - 1]
/* tag::macro[]
= Cbject_castTo()
====
----
#define Cbject_castTo(typeName, instance)
----
Cast an instance to the provided typeName

.Params
* typeName - Name of the type (class or interface)
* instance - Instance to cast

.Return
Instance cast to the provided typeName
====
end::macro[] */
#define Cbject_castTo(typeName, instance) \
    ((typeName *)(instance))
/* tag::macro[]
= Cbject_lengthOf()
====
----
#define Cbject_lengthOf(array)
----
Get length of an array

.Params
* array - Array for which to get the length
====
end::macro[] */
#define Cbject_lengthOf(array) \
    (sizeof(array) / sizeof(array[0]))
/* tag::macro[]
= Cbject_salloc()
====
----
#define Cbject_salloc(typeName)
----
Syntactic sugar to allocate memory on the stack

.Params
* typeName - Name of type

.Return
Reference of the allocated memory
====
end::macro[] */
#define Cbject_salloc(typeName) \
    (&(typeName){ 0 })
/* tag::macro[]
= Cbject_ignore()
====
----
#define Cbject_ignore(var)
----
Syntactic sugar to ignore unused variables

.Params
* var - Variable to be ignored
====
end::macro[] */
#define Cbject_ignore(var) \
    (void)var
/* tag::macro[]
= Cbject_is()
====
----
#define Cbject_is(typeName)
----
Syntactic sugar to extend a type

.Remark
Should be used as the first member in the structure

.Params
* typeName - Name of the type
====
end::macro[] */
#define Cbject_is(typeName) \
    typeName s_##typeName
/* tag::macro[]
= Cbject_has()
====
----
#define Cbject_has(typeName)
----
Syntactic sugar to compose a type with the provided typeName

.Remark
Should be used after Cbject_is() macro

.Params
* typeName - Name of the type
====
end::macro[] */
#define Cbject_has(typeName) \
    typeName ss_##typeName
/* tag::macro[]
= Cbject_class()
====
----
#define Cbject_class(className)
----
Syntactic sugar to get class reference

.Params
* className - Name of the class

.Return
Class reference
====
end::macro[] */
#define Cbject_class(className) \
    className##Class_instance()
/* tag::macro[]
= Cbject_singleton()
====
----
#define Cbject_singleton(className)
----
Syntactic sugar to get a singleton reference

.Params
* className - Name of the class

.Return
Singleton reference
====
end::macro[] */
#define Cbject_singleton(className) \
    className##_instance()
/* tag::macro[]
= Cbject_classOf()
====
----
#define Cbject_classOf(object)
----
Get the class of an object

.Params
* object - Cbject_Object reference

.Return
Class reference
====
end::macro[] */
#define Cbject_classOf(object) \
    Cbject_castTo(Cbject_Object, object)->objectClass
/* tag::macro[]
= Cbject_objectSizeOf()
====
----
#define Cbject_objectSizeOf(object)
----
Get the size in memory of an object

.Params
* object - Cbject_Object reference

.Return
Cbject_Object size
====
end::macro[] */
#define Cbject_objectSizeOf(object) \
    Cbject_classOf(object)->objectSize
/* tag::macro[]
= Cbject_traitOf()
====
----
#define Cbject_traitOf(className, interfaceName, object)
----
Get trait of an object

.Params
* className - Name of the class
* interfaceName - Name of the interface
* object - Cbject_Object reference

.Return
Cbject_Trait reference
====
end::macro[] */
#define Cbject_traitOf(className, interfaceName, object) \
    Cbject_castTo(interfaceName, (Cbject_castTo(Cbject_Any, object) + Cbject_castTo(Cbject_TraitInterface, &Cbject_castTo(className##Class, Cbject_classOf(object))->ss_##interfaceName##Interface)->traitOffset))
/* tag::macro[]
= Cbject_callObjectMethod()
====
----
#define Cbject_callObjectMethod(className, methodName, ...)
----
Call a method through an object

.Params
* className - Name of the class
* methodName - Name of the method
* ...
** object - Cbject_Object reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define Cbject_callObjectMethod(className, methodName, ...) \
    Cbject_castTo(className##Class, Cbject_classOf(Cbject_VaArgs_first(__VA_ARGS__)))->methodName(__VA_ARGS__)
/* tag::macro[]
= Cbject_callClassMethod()
====
----
#define Cbject_callClassMethod(className, superClassName, methodName, ...)
----
Call a method through a class

.Params
* className - Name of the class
* superClassName - Name of the super class
* methodName - Name of the method
* ...
** object - Cbject_Object reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define Cbject_callClassMethod(className, superClassName, methodName, ...) \
    Cbject_castTo(superClassName##Class, Cbject_class(className))->methodName(__VA_ARGS__)
/* tag::macro[]
= Cbject_offsetOf()
====
----
#define Cbject_offsetOf(trait)
----
Get offset of a trait in container object

.Params
* trait - Cbject_Trait reference

.Return
Offset of trait in container object
====
end::macro[] */
#define Cbject_offsetOf(trait) \
    Cbject_castTo(Cbject_Trait, trait)->offset
/* tag::macro[]
= Cbject_interfaceOffsetOf()
====
----
#define Cbject_interfaceOffsetOf(trait)
----
Get the interface offset in container class

.Params
* trait - Cbject_Trait reference

.Return
Offset of interface in container class
====
end::macro[] */
#define Cbject_interfaceOffsetOf(trait) \
    Cbject_castTo(Cbject_Trait, trait)->interfaceOffset
/* tag::macro[]
= Cbject_objectOf()
====
----
#define Cbject_objectOf(trait)
----
Get container object from a trait

.Params
* trait - Cbject_Trait reference

.Return
Reference of the container object
====
end::macro[] */
#define Cbject_objectOf(trait) \
    Cbject_castTo(Cbject_Object, Cbject_castTo(Cbject_Any, trait) - Cbject_offsetOf(trait))
/* tag::macro[]
= Cbject_interfaceOf()
====
----
#define Cbject_interfaceOf(trait)
----
Get the interface of a trait

.Params
* trait - Cbject_Trait reference

.Return
Interface reference
====
end::macro[] */
#define Cbject_interfaceOf(trait) \
    Cbject_castTo(Cbject_TraitInterface, Cbject_castTo(Cbject_Any, Cbject_classOf(Cbject_objectOf(trait))) + Cbject_interfaceOffsetOf(trait))
/* tag::macro[]
= Cbject_interface()
====
----
#define Cbject_interface(interfaceName)
----
Syntactic sugar to get interface reference

.Params
* interfaceName - Name of the interface

.Return
Interface reference
====
end::macro[] */
#define Cbject_interface(interfaceName) \
    interfaceName##Interface_instance()
/* tag::macro[]
= Cbject_callTraitMethod()
====
----
#define Cbject_callTraitMethod(interfaceName, methodName, ...)
----
Call a method through a trait

.Params
* interfaceName - Name of the interface
* methodName - Name of the method
* ...
** trait - Cbject_Trait reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define Cbject_callTraitMethod(interfaceName, methodName, ...) \
    Cbject_castTo(interfaceName##Interface, Cbject_interfaceOf(Cbject_VaArgs_first(__VA_ARGS__)))->methodName(__VA_ARGS__)
/* tag::macro[]
= Cbject_callInterfaceMethod()
====
----
#define Cbject_callInterfaceMethod(className, interfaceName, methodName, ...)
----
Call a method through an interface

.Params
* className - Name of the class
* interfaceName - Name of the interface
* methodName - Name of the method
* ...
** trait - Cbject_Trait reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define Cbject_callInterfaceMethod(className, interfaceName, methodName, ...) \
    Cbject_castTo(interfaceName##Interface, &Cbject_castTo(className##Class, Cbject_class(className))->ss_##interfaceName##Interface)->methodName(__VA_ARGS__)
/* tag::macro[]
= Cbject_VaArgs_first()
====
----
#define Cbject_VaArgs_first(...)
----
Get first argument from __VA_ARGS__

.Params
* ... - __VA_ARGS__
====
end::macro[] */
#define Cbject_VaArgs_first(...) \
    Cbject_VaArgs_first_h0(__VA_ARGS__, discard)
#define Cbject_VaArgs_first_h0(first, ...) \
    first
/* tag::macro[]
= Cbject_VaArgs_rest()
====
----
#define Cbject_VaArgs_rest(...)
----
Get list of arguments from __VA_ARGS__ except the first

.Remark
* Comma is added before the list
* Supports max 99 arguments

.Params
* ... - __VA_ARGS__
====
end::macro[] */
#define Cbject_VaArgs_rest(...) \
    Cbject_VaArgs_rest_h0(Cbject_VaArgs_case(__VA_ARGS__), __VA_ARGS__)
#define Cbject_VaArgs_rest_h0(case, ...) \
    Cbject_VaArgs_rest_h1(case, __VA_ARGS__)
#define Cbject_VaArgs_rest_h1(case, ...) \
    Cbject_VaArgs_rest_case_##case (__VA_ARGS__)
#define Cbject_VaArgs_rest_case_one(first)
#define Cbject_VaArgs_rest_case_more(first, ...) \
    , __VA_ARGS__
#define Cbject_VaArgs_case(...)                                            \
    Cbject_VaArgs_get99th(                                                 \
        __VA_ARGS__, more, more, more, more, more, more, more, more, more, \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, one, discard       \
    )
#define Cbject_VaArgs_get99th(                        \
    a01, a02, a03, a04, a05, a06, a07, a08, a09, a10, \
    a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, \
    a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, \
    a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, \
    a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, \
    a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, \
    a61, a62, a63, a64, a65, a66, a67, a68, a69, a70, \
    a71, a72, a73, a74, a75, a76, a77, a78, a79, a80, \
    a81, a82, a83, a84, a85, a86, a87, a88, a89, a90, \
    a91, a92, a93, a94, a95, a96, a97, a98, a99, ...  \
)                                                     \
    a99
#endif // CBJECT_UTILS_H

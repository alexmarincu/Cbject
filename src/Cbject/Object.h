#ifndef OBJECT_H
#define OBJECT_H
#include "Class.h"

defineClass_(Object);

/**
 * @brief ObjectInterface
 */
struct ObjectInterface {
    Object * (*deinit)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
};

/**
 * @brief ObjectClass
 */
struct ObjectClass {
    super_(Class);
};

/**
 * @brief Object
 */
struct Object {
    Type const * type;
};

/**
 * @brief ObjectInterface
 * @return ObjectInterface const*
 */
ObjectInterface const * ObjectInterface_(void);

/**
 * @brief ObjectClass
 * @return ObjectClass const*
 */
ObjectClass const * ObjectClass_(void);

/**
 * @brief Initialize an object
 * @param me The object
 * @param cls The class
 * @return Object* The initialized object
 */
Object * Object_init(Object * const me, Type const * const type);

/**
 * @brief Initialize an object
 * @param me
 * @param className
 */
#define initObject_(me, className) Object_init(toObject_(me), toType_(className##Class_()))

/**
 * @brief Override an object
 * @param me
 * @param className
 */
#define overrideObject_(me, className) initObject_(me, className)

/**
 * @brief Override a mixin object
 * @param me
 * @param className
 * @param mixinClassName
 * @param mixinName
 */
#define overrideMixinObject_(me, className, mixinClassName, mixinName) \
    Object_init(toObject_(mixinObjectOf_(mixinClassName, mixinName, me)), toType_(&to_(mixinClassName##Class, className##Class_())->m##mixinName##Mixin))

/**
 * @brief Initialize a mixin object
 * @param me
 * @param className
 * @param mixinName
 */
#define initMixinObject_(me, className, mixinName) \
    overrideMixinObject_(me, className, className, mixinName)

/**
 * @brief Initialize a derived object
 * @param className The object class
 * @param ... (me The object to initialize, ... The init arguments)
 */
#define init_(className, ...) \
    className##_init(to_(className, VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))

/**
 * @brief Get type of an object
 */
#define typeOf_(me) toObject_(me)->type

/**
 * @brief Get object offset from object or mixin
 */
#define objectOffsetOf_(me) typeOf_(me)->offset

/**
 * @brief Get parent object from object or mixin
 */
#define objectOf_(me) toObject_(toAny_(me) - objectOffsetOf_(me))

/**
 * @brief Get child object from object or mixin
 */
#define mixinObjectOf_(className, mixinName, me) \
    to_(mixinName, toAny_(me) + toType_(&to_(className##Class, classOf_(me))->m##mixinName##Mixin)->offset)

/**
 * @brief Get class of an object
 */
#define classOf_(me) toClass_(typeOf_(me))

/**
 * @brief Get mixin of an object
 */
#define mixinOf_(me) toMixin_(typeOf_(me))

/**
 * @brief Get interface of an object
 */
#define interfaceOf_(me) mixinOf_(me)->interface

/**
 * @brief Get the class name of an object
 */
#define classNameOf_(me) classOf_(me)->name

/**
 * @brief Get the superClass of an object
 */
#define superClassOf_(me) classOf_(me)->superClass

/**
 * @brief Get the size in memory of an object
 */
#define objectSizeOf_(me) classOf_(me)->objectSize

/**
 * @brief Call an object operation
 * @param typeName The type name
 * @param operationName The operation name
 * @param ... (me The object, ... The operation arguments)
 */
#define call_(typeName, operationName, ...) \
    to_(typeName##Interface, interfaceOf_(VaArgs_first_(__VA_ARGS__)))->operationName(__VA_ARGS__)

/**
 * @brief Call a super object operation
 * @param superClassName The superClass name
 * @param operationName The operation name
 * @param ... (me The object, ... The operation arguments)
 */
#define superCall_(superClassName, operationName, ...) \
    to_(superClassName##Interface, toMixin_(superClassName##Class_())->interface)->operationName(__VA_ARGS__)

/**
 * @brief Call a super mixin object operation
 * @param superClassName The superClass name
 * @param mixinName The mixin name
 * @param operationName The operation name
 * @param ... (me The object, ... The operation arguments)
 */
#define superMixinCall_(superClassName, mixinName, operationName, ...) \
    to_(superClassName##Interface, toMixin_(superClassName##Class_())->interface)->m##mixinName##Interface.operationName(__VA_ARGS__)

/**
 * @brief
 * @param me
 * @param cls
 * @return true
 * @return false
 */
bool Object_isOfClass(Object const * const me, Class const * const cls);

/**
 * @brief
 */
#define isOfClass_(me, className) Object_isOfClass(toObject_(me), toClass_(className##Class_()))

/**
 * @brief
 * @param cls
 * @return Object*
 */
Object * Object_alloc(Class const * const cls);

/**
 * @brief
 */
#define alloc_(className) to_(className, Object_alloc(toClass_(className##Class_())))

/**
 * @brief
 * @param me
 */
Object * Object_dealloc(Object * const me);

/**
 * @brief
 */
#define dealloc_(me) Object_dealloc(toObject_(me))

/**
 * @brief
 * @param me
 */
Object * Object_deinit(Object * me);

/**
 * @brief
 */
#define deinit_(me) toAny_(Object_deinit(toObject_(me)))

/**
 * @brief
 * @param me
 * @return Object*
 */
Object * Object_copy(Object const * const me);

/**
 * @brief
 */
#define copy_(className, me) to_(className, Object_copy(toObject_(me)))

/**
 * @brief
 * @param me
 * @param other
 * @return true
 * @return false
 */
bool Object_equals(Object const * const me, Object const * const other);

/**
 * @brief
 */
#define equals_(me, other) Object_equals(toObject_(me), toObject_(other))

/**
 * @brief
 * @param me
 * @return uint64_t
 */
uint64_t Object_hashCode(Object const * const me);

/**
 * @brief
 */
#define hashCode_(me) Object_hashCode(toObject_(me))

/**
 * @brief Cast to (Object *)
 */
#define toObject_(me) to_(Object, (me))

#define inheritInterface_(interface, superClassName) \
    *to_(superClassName##Interface, interface) = *superClassName##Interface_()

#define overrideMixinOperation_(interface, className, mixinName, operationName) \
    to_(className##Interface, interface)->m##mixinName##Interface.operationName = operationName

#define overrideOperation_(interface, superClassName, operationName) \
    to_(superClassName##Interface, interface)->operationName = operationName

#endif // OBJECT_H

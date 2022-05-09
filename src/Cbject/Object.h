#ifndef OBJECT_H
#define OBJECT_H
#include "Class.h"

/**
 * @brief ObjectClass
 */
typedef struct {
    extends_(Class);
} ObjectClass;

/**
 * @brief ObjectTrait
 */
typedef struct {
    extends_(Trait);
} ObjectTrait;

/**
 * @brief Object
 */
typedef struct {
    Type const * type;
} Object;

/**
 * @brief ObjectInterface
 */
typedef struct {
    Object * (*deinit)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
} ObjectInterface;

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
 * @param me Object reference
 * @param type Type reference (Class or Trait)
 * @return Object* Initialized object
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
 * @brief Override a trait object
 * @param me
 * @param className
 * @param traitContainerClassName
 * @param traitName
 */
#define overrideObjectIn_(me, className, traitContainerClassName, traitName)                    \
    Object_init(                                                                                \
        toObject_(objectIn_(me, traitContainerClassName, traitName)),                           \
        toType_(&to_(traitContainerClassName##Class, className##Class_())->m##traitName##Trait) \
    )

/**
 * @brief Initialize a trait object
 * @param me
 * @param className
 * @param traitName
 */
#define initObjectIn_(me, className, traitName)                                   \
    Object_init(                                                                  \
        toObject_(objectIn_(me, className, traitName)),                           \
        toType_(&to_(className##Class, className##Class_())->m##traitName##Trait) \
    )

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
 * @brief Get object offset from object or trait
 */
#define objectOffsetOf_(me) typeOf_(me)->offset

/**
 * @brief Get parent object from object or trait
 */
#define objectOf_(me) toObject_(toAny_(me) - objectOffsetOf_(me))

/**
 * @brief Get child object from object or trait
 */
#define objectIn_(me, className, traitName) \
    to_(traitName, toAny_(me) + toType_(&to_(className##Class, classOf_(me))->m##traitName##Trait)->offset)

/**
 * @brief Get class of an object
 */
#define classOf_(me) toClass_(typeOf_(me))

/**
 * @brief Get trait of an object
 */
#define traitOf_(me) toTrait_(typeOf_(me))

/**
 * @brief Get interface of an object
 */
#define interfaceOf_(me) traitOf_(me)->interface

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
    to_(superClassName##Interface, toTrait_(superClassName##Class_())->interface)->operationName(__VA_ARGS__)

/**
 * @brief Call a super trait object operation
 * @param superClassName The superClass name
 * @param traitName The trait name
 * @param operationName The operation name
 * @param ... (me The object, ... The operation arguments)
 */
#define superTraitCall_(superClassName, traitName, operationName, ...) \
    to_(superClassName##Interface, toTrait_(superClassName##Class_())->interface)->m##traitName##Interface.operationName(__VA_ARGS__)

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

#define inheritInterface_(me, superClassName) \
    *to_(superClassName##Interface, me) = *superClassName##Interface_()

#define overrideOperationIn_(me, className, traitName, operationName) \
    to_(className##Interface, me)->m##traitName##Interface.operationName = operationName

#define overrideOperation_(me, superClassName, operationName) \
    to_(superClassName##Interface, me)->operationName = operationName

#endif // OBJECT_H

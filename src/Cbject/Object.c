#include "Object.h"
#include "Assert.h"
#include <stdlib.h>
#include <string.h>
static Object * deinit(Object * me);
static Object * copy(Object const * const me);
static bool equals(Object const * const me, Object const * const other);
static uint64_t hashCode(Object const * const me);
Object_Class * Object_Class_init(
    Object_Class * const me,
    Operations const * const operations,
    char const * const name,
    size_t const objectSize,
    Object_Class const * const superClass
) {
    Object_Interface_init(to_(Object_Interface, me), 0, operations);
    me->name = name;
    me->objectSize = objectSize;
    me->superClass = superClass;
    return me;
}
Object_Class const * Object_Class_(void) {
    static Object_Class class;
    doOnce_ {
        Object_Class_init(
            to_(Object_Class, &class),
            to_(Operations, Object_Operations_()),
            "Object",
            sizeof(Object),
            NULL
        );
    }
    return &class;
}
Object_Interface * Object_Interface_init(
    Object_Interface * const me,
    size_t offset,
    Operations const * operations
) {
    me->offset = offset;
    me->operations = operations;
    return me;
}
Object_Operations const * Object_Operations_(void) {
    static Object_Operations const operations = {
        .deinit = deinit,
        .copy = copy,
        .equals = equals,
        .hashCode = hashCode
    };
    return &operations;
}
Object * Object_alloc(Object_Class const * const class) {
    Object * object = to_(Object, calloc(1, class->objectSize));
    assert_(object);
    return object;
}
Object * Object_dealloc(Object * const me) {
    deinit_(me);
    free(me);
    return NULL;
}
Object * Object_init(Object * const me, Object_Interface const * const interface) {
    me->interface = interface;
    return me;
}
Object * Object_deinit(Object * me) {
    return call_(Object, deinit, me);
}
static Object * deinit(Object * me) {
    (void)me;
    return NULL;
}
Object * Object_copy(Object const * const me) {
    return call_(Object, copy, me);
}
static Object * copy(Object const * const me) {
    Object * object = Object_alloc(classOf_(me));
    assert_(object);
    object = memcpy(object, me, objectSizeOf_(me));
    return object;
}
bool Object_equals(Object const * const me, Object const * const other) {
    return call_(Object, equals, me, other);
}
static bool equals(Object const * const me, Object const * const other) {
    return me == other;
}
uint64_t Object_hashCode(Object const * const me) {
    return call_(Object, hashCode, me);
}
static uint64_t hashCode(Object const * const me) {
    return (uint64_t)me;
}
bool Object_isOfClass(Object const * const me, Object_Class const * const targetClass) {
    bool isOfClass = true;
    Object_Class const * class = classOf_(me);
    if (targetClass != to_(Object_Class, class_(Object))) {
        while ((isOfClass == true) && (class != targetClass)) {
            class = class->superClass;
            if (class == NULL) {
                isOfClass = false;
            }
        }
    }
    return isOfClass;
}
void Object_setClass(Object * const me, Object_Class const * const class) {
    me->interface = to_(Object_Interface, class);
}

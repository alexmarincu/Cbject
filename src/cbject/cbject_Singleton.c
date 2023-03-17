#include "cbject_Singleton.h"

#define cbject_Class (cbject_Singleton, cbject_Object)

cbject_Singleton * cbject_Singleton_init(cbject_Singleton * const singleton) {
    cbject_Object_init((cbject_Object *)singleton);
    return singleton;
}

static cbject_Object * alloc(cbject_ObjectClass * const objectClass) {
    assert("Singleton cannot be allocated" && false);
    (void)objectClass;
    return NULL;
}

static cbject_Object * copy(cbject_Object const * const object, cbject_Object * const copyObject) {
    assert("Singleton cannot be copied" && false);
    (void)(object);
    (void)(copyObject);
    return NULL;
}

static void * dealloc(cbject_Object * const object) {
    assert("Singleton cannot be deallocated" && false);
    (void)object;
    return NULL;
}

cbject_SingletonClass const * cbject_SingletonClass_instance(void) {
    static cbject_SingletonClass klass;
    cbject_utils_doOnce {
        klass.objectClass = *cbject_ObjectClass_instance();
        klass.objectClass.name = "cbject_Singleton";
        klass.objectClass.instanceSize = sizeof(cbject_Singleton);
        klass.objectClass.superClass = cbject_ObjectClass_instance();
        klass.objectClass.alloc = alloc;
        klass.objectClass.copy = copy;
        klass.objectClass.dealloc = dealloc;
    }
    return &klass;
}

#undef cbject_Class
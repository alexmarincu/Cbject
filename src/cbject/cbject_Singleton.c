#include "cbject_Singleton.h"
#if (cbject_config_useSingleton == true)
#include "cbject_utils.h"

#define cbject_Class (cbject_Singleton, cbject_Object)
#if (cbject_config_useStaticPool == true)
cbject_utils_allocPool(0);
#endif

cbject_Singleton * cbject_Singleton_init(cbject_Singleton * const singleton) {
    cbject_utils_init(singleton);
    return singleton;
}

#if (cbject_config_useHeap == true)
static cbject_Object * alloc(cbject_ObjectClass * const objectClass) {
    assert("Singleton cannot be allocated" && false);
    (void)objectClass;
    return NULL;
}

static void * dealloc(cbject_Object * const object) {
    assert("Singleton cannot be deallocated" && false);
    (void)object;
    return NULL;
}
#endif // (cbject_config_useHeap == true)

static cbject_Object * copy(cbject_Object const * const object, cbject_Object * const copyObject) {
    assert("Singleton cannot be copied" && false);
    (void)(object);
    (void)(copyObject);
    return NULL;
}

cbject_SingletonClass * cbject_SingletonClass_instance(void) {
    static cbject_SingletonClass klass;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&klass);
#if (cbject_config_useHeap == true)
        klass.objectClass.alloc = alloc;
        klass.objectClass.dealloc = dealloc;
#endif
        klass.objectClass.copy = copy;
    }
    return &klass;
}

#undef cbject_Class
#endif // (cbject_config_useSingleton == true)
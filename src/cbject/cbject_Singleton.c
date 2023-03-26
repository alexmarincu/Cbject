#include "cbject_Singleton.h"
#if (cbject_config_useSingleton == true)
#include "cbject_utils.h"

#define cbject_Class (cbject_Singleton, cbject_Object)
#if (cbject_config_useStaticPool == true)
cbject_utils_nullPool;
#endif

cbject_Singleton * cbject_Singleton_init(cbject_Singleton * const self) {
    cbject_utils_init(self);
    return self;
}

#if (cbject_config_useHeap == true)
static cbject_Object * alloc(cbject_ObjectClass * const self) {
    assert("Singleton cannot be allocated" && false);
    (void)self;
    return NULL;
}
#endif // (cbject_config_useHeap == true)

static cbject_Object * copy(cbject_Object const * const self, cbject_Object * const object) {
    assert("Singleton cannot be copied" && false);
    (void)(self);
    (void)(object);
    return NULL;
}

cbject_SingletonClass * cbject_SingletonClass_instance(void) {
    static cbject_SingletonClass self;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&self);
#if (cbject_config_useHeap == true)
        ((cbject_ObjectClass *)&self)->alloc = alloc;
#endif
        ((cbject_ObjectClass *)&self)->copy = copy;
    }
    return &self;
}

#undef cbject_Class
#endif // (cbject_config_useSingleton == true)
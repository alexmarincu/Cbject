#include "cbject_Singleton.h"
#if (cbject_config_useSingleton == true)
#include "cbject_internal.h"

#define cbject_Class (cbject_Singleton, cbject_Object)
#if (cbject_config_useStaticPool == true)
cbject_noPool;
#endif

cbject_Singleton * cbject_Singleton_init(cbject_Singleton * const self) {
    cbject_init(self);
    return self;
}

#if (cbject_config_useHeap == true)
static cbject_Object * alloc(cbject_Object_Class * const self) {
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

cbject_Singleton_Class * cbject_Singleton_Class_instance(void) {
    static cbject_Singleton_Class self;
    cbject_doOnce {
        cbject_Object_Class_setup(&self);
#if (cbject_config_useHeap == true)
        ((cbject_Object_Class *)&self)->alloc = alloc;
#endif
        ((cbject_Object_Class *)&self)->copy = copy;
    }
    return &self;
}

#undef cbject_Class
#endif // (cbject_config_useSingleton == true)
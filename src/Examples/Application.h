#ifndef APPLICATION_H
#define APPLICATION_H
#include "../cbject/cbject.h"
cbject_typedefClass(Application);
struct ApplicationClass {
    cbject_is(cbject_ObjectClass);
};
ApplicationClass const * ApplicationClass_getInstance(void);
Application * Application_getInstance(void);
void Application_main(Application * const application);
#endif // APPLICATION_H

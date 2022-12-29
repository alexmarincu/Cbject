#ifndef APPLICATION_H
#define APPLICATION_H
#include "../Cbject/Cbject.h"
x_typedefClass(Application);
struct ApplicationClass {
    x_is(x_ObjectClass);
};
ApplicationClass const * ApplicationClass_instance(void);
Application * Application_instance(void);
void Application_main(Application * const application);
#endif // APPLICATION_H

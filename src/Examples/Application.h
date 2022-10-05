#ifndef APPLICATION_H
#define APPLICATION_H
#include "../Cbject/Cbject.h"
typedefClass_(Application);
struct ApplicationClass {
    extends_(ObjectClass);
};
ApplicationClass const * ApplicationClass_instance(void);
Application * Application_instance(void);
void Application_main(Application * const application);
#endif // APPLICATION_H

#ifndef APPLICATION_H
#define APPLICATION_H
#include "../cbject/cbject.h"

typedef struct Application Application;
typedef struct ApplicationClass ApplicationClass;

struct ApplicationClass {
    cbject_SingletonClass super;
};

Application * Application_instance(void);
void Application_main(Application * const self);
ApplicationClass * ApplicationClass_instance(void);

#endif // APPLICATION_H

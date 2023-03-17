#ifndef APPLICATION_H
#define APPLICATION_H
#include "../cbject/cbject.h"

typedef struct Application Application;
typedef struct ApplicationClass ApplicationClass;

struct ApplicationClass {
    cbject_SingletonClass singletonClass;
};

Application * Application_instance(void);
void Application_main(Application * const application);
ApplicationClass * ApplicationClass_instance(void);

#endif // APPLICATION_H

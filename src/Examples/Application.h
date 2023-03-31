#ifndef APPLICATION_H
#define APPLICATION_H
#include "../cbject/cbject.h"

typedef struct Application Application;
typedef struct Application_Class Application_Class;

struct Application_Class {
    cbject_Singleton_Class super;
};

Application * Application_instance(void);
void Application_main(Application * const self);
Application_Class * Application_Class_instance(void);

#endif // APPLICATION_H

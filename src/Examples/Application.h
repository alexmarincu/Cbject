#ifndef APPLICATION_H
#define APPLICATION_H
#include "../Cbject/Cbject.h"
typedef struct Application Application;
typedef struct Application_Class Application_Class;
struct Application_Class {
    extends_(Object_Class);
};
Application_Class const * Application_Class_(void);
Application * Application_(void);
void Application_main(Application * const me);
#endif // APPLICATION_H

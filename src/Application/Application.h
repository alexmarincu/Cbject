#ifndef APPLICATION_H
#define APPLICATION_H
#include "../Cbject/Cbject.h"

#define class Application
#define superClass Cbject

SingletonInitParams();
Function(void, start, ());

#undef superClass
#undef class
#endif // APPLICATION_H

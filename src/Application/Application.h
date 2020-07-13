#ifndef APPLICATION_H
#define APPLICATION_H
#include "../CObject/CObject.h"

#undef Class
#define Class Application

singleton_class_init_params();

fun(Void, start, ());

#endif // APPLICATION_H

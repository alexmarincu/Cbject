#ifndef CBJECTSETTER_H
#define CBJECTSETTER_H
#include "CbjectSetterFunctionPrototype.h"

#define CbjectSetter(klassName, type, memberName) \
    CbjectSetterFunctionPrototype(klassName, type, memberName)

#endif // CBJECTSETTER_H

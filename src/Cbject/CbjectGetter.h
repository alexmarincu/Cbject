#ifndef CBJECTGETTER_H
#define CBJECTGETTER_H
#include "CbjectGetterFunctionPrototype.h"

#define CbjectGetter(klassName, type, memberName) \
    CbjectGetterFunctionPrototype(klassName, type, memberName)

#endif // CBJECTGETTER_H

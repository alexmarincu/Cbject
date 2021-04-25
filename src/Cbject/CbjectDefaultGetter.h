#ifndef CBJECTDEFAULTGETTER_H
#define CBJECTDEFAULTGETTER_H
#include "CbjectDefaultGetterImpl.h"

#define CbjectDefaultGetter(klassName, type, memberName) \
    CbjectDefaultGetterImpl(klassName, type, memberName)

#endif // CBJECTDEFAULTGETTER_H

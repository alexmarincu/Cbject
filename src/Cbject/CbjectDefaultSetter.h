#ifndef CBJECTDEFAULTSETTER_H
#define CBJECTDEFAULTSETTER_H
#include "CbjectDefaultSetterImpl.h"

#define CbjectDefaultSetter(klassName, type, memberName) \
    CbjectDefaultSetterImpl(klassName, type, memberName)

#endif // CBJECTDEFAULTSETTER_H

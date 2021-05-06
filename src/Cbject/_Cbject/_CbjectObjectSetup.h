#ifndef _CBJECTSINGLETONSETUP_H
#define _CBJECTSINGLETONSETUP_H
#include "_CbjectInstanceImpl.h"
#include "_CbjectClassInstanceFunPrototype.h"
#include "_CbjectClassInstanceImpl.h"
#include "_CbjectClassTypeDefinition.h"
#include "_CbjectSizeImpl.h"
#include "_CbjectTypeDefinition.h"
#include "_CbjectUtilities.h"

#define _CbjectObjectSetup(cbjectTypeName, parentName, bindFuns) \
    _CbjectTypeDefinition(cbjectTypeName, parentName);              \
    _CbjectClassTypeDefinition(cbjectTypeName, parentName, 0);      \
    _CbjectClassInstanceFunPrototype(cbjectTypeName);              \
    _CbjectInstanceImpl(cbjectTypeName);                                \
    _CbjectSizeImpl(cbjectTypeName);                                    \
    _CbjectClassInstanceImpl(cbjectTypeName, parentName, _CbjectUtilities_stripParentheses(bindFuns))

#endif // _CBJECTSINGLETONSETUP_H

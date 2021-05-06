#ifndef _CBJECTABSTRACTCLASSSETUP_H
#define _CBJECTABSTRACTCLASSSETUP_H
#include "_CbjectCastToSubImpl.h"
#include "_CbjectCastToSuperImpl.h"
#include "_CbjectClassInstanceImpl.h"
#include "_CbjectSizeImpl.h"
#include "_CbjectTypeDefinition.h"
#include "_CbjectUtilities.h"
#include "_CbjectVirtualFunCalls.h"

#define _CbjectAbstractClassSetup(cbjectTypeName, parentName, virtualFunCalls, bindFuns)               \
    _CbjectTypeDefinition(cbjectTypeName, parentName);                                                 \
    _CbjectSizeImpl(cbjectTypeName);                                                                   \
    _CbjectClassInstanceImpl(cbjectTypeName, parentName, _CbjectUtilities_stripParentheses(bindFuns)); \
    _CbjectCastToSuperImpl(cbjectTypeName, parentName);                                                \
    _CbjectCastToSubImpl(cbjectTypeName, parentName);                                                  \
    _CbjectVirtualFunCalls(_CbjectUtilities_stripParentheses(virtualFunCalls))

#endif // _CBJECTABSTRACTCLASSSETUP_H

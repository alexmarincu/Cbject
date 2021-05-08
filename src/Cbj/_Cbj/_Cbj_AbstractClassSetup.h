#ifndef _CBJ_ABSTRACTCLASSSETUP_H
#define _CBJ_ABSTRACTCLASSSETUP_H
#include "_Cbj_CastToSubImpl.h"
#include "_Cbj_CastToSuperImpl.h"
#include "_Cbj_ClassInstanceImpl.h"
#include "_Cbj_SizeImpl.h"
#include "_Cbj_TypeDef.h"
#include "_Cbj_Utils.h"
#include "_Cbj_VirtFunCalls.h"

#define _Cbj_AbstractClassSetup(typeName, Cbj_ParentName, virtFunCalls, bindFuns)            \
    _Cbj_TypeDef(typeName, Cbj_ParentName);                                                  \
    _Cbj_SizeImpl(typeName);                                                             \
    _Cbj_ClassInstanceImpl(typeName, Cbj_ParentName, _Cbj_Utils_stripParentheses(bindFuns)); \
    _Cbj_CastToSuperImpl(typeName, Cbj_ParentName);                                          \
    _Cbj_CastToSubImpl(typeName, Cbj_ParentName);                                            \
    _Cbj_VirtFunCalls(_Cbj_Utils_stripParentheses(virtFunCalls))

#endif // _CBJ_ABSTRACTCLASSSETUP_H

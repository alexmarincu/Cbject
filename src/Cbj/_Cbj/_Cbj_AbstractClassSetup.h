#ifndef _CBJ_ABSTRACTCLASSSETUP_H
#define _CBJ_ABSTRACTCLASSSETUP_H
#include "_Cbj_CastToSubImpl.h"
#include "_Cbj_CastToSuperImpl.h"
#include "_Cbj_SizeImpl.h"
#include "_Cbj_TypeDef.h"
#include "_Cbj_TypeInstanceImpl.h"
#include "_Cbj_Utils.h"
#include "_Cbj_VirtFunCalls.h"

#define _Cbj_AbstractClassSetup(cbjType, parent, virtFunCalls, bindFuns)           \
    _Cbj_TypeDef(cbjType, parent);                                                 \
    _Cbj_SizeImpl(cbjType);                                                        \
    _Cbj_TypeInstanceImpl(cbjType, parent, _Cbj_Utils_stripParentheses(bindFuns)); \
    _Cbj_CastToSuperImpl(cbjType, parent);                                         \
    _Cbj_CastToSubImpl(cbjType, parent);                                           \
    _Cbj_VirtFunCalls(_Cbj_Utils_stripParentheses(virtFunCalls))

#endif // _CBJ_ABSTRACTCLASSSETUP_H

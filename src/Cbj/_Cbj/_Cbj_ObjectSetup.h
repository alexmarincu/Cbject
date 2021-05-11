#ifndef _CBJ_OBJECTSETUP_H
#define _CBJ_OBJECTSETUP_H
#include "_Cbj_ObjectInstanceImpl.h"
#include "_Cbj_SizeImpl.h"
#include "_Cbj_TypeDef.h"
#include "_Cbj_TypeInstanceFunPrototype.h"
#include "_Cbj_TypeInstanceImpl.h"
#include "_Cbj_TypeTypeDef.h"
#include "_Cbj_Utils.h"

#define _Cbj_ObjectSetup(cbjType, parent, bindFuns) \
    _Cbj_TypeDef(cbjType, parent);                  \
    _Cbj_TypeTypeDef(cbjType, parent, 0);           \
    _Cbj_TypeInstanceFunPrototype(cbjType);         \
    _Cbj_ObjectInstanceImpl(cbjType);               \
    _Cbj_SizeImpl(cbjType);                         \
    _Cbj_TypeInstanceImpl(cbjType, parent, _Cbj_Utils_stripParentheses(bindFuns))

#endif // _CBJ_OBJECTSETUP_H

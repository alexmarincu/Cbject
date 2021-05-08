#ifndef _CBJ_OBJECTSETUP_H
#define _CBJ_OBJECTSETUP_H
#include "_Cbj_ClassInstanceFunPrototype.h"
#include "_Cbj_ClassInstanceImpl.h"
#include "_Cbj_ClassTypeDef.h"
#include "_Cbj_ObjectInstanceImpl.h"
#include "_Cbj_SizeImpl.h"
#include "_Cbj_TypeDef.h"
#include "_Cbj_Utils.h"

#define _Cbj_ObjectSetup(cbjType, parent, bindFuns) \
    _Cbj_TypeDef(cbjType, parent);                  \
    _Cbj_ClassTypeDef(cbjType, parent, 0);          \
    _Cbj_ClassInstanceFunPrototype(cbjType);        \
    _Cbj_ObjectInstanceImpl(cbjType);               \
    _Cbj_SizeImpl(cbjType);                         \
    _Cbj_ClassInstanceImpl(cbjType, parent, _Cbj_Utils_stripParentheses(bindFuns))

#endif // _CBJ_OBJECTSETUP_H

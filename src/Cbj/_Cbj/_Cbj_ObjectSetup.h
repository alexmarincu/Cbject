#ifndef _CBJ_OBJECTSETUP_H
#define _CBJ_OBJECTSETUP_H
#include "_Cbj_ClassInstanceFunPrototype.h"
#include "_Cbj_ClassInstanceImpl.h"
#include "_Cbj_ClassTypeDef.h"
#include "_Cbj_ObjectInstanceImpl.h"
#include "_Cbj_SizeImpl.h"
#include "_Cbj_TypeDef.h"
#include "_Cbj_Utils.h"

#define _Cbj_ObjectSetup(typeName, Cbj_ParentName, bindFuns) \
    _Cbj_TypeDef(typeName, Cbj_ParentName);                  \
    _Cbj_ClassTypeDef(typeName, Cbj_ParentName, 0);          \
    _Cbj_ClassInstanceFunPrototype(typeName);            \
    _Cbj_ObjectInstanceImpl(typeName);                   \
    _Cbj_SizeImpl(typeName);                             \
    _Cbj_ClassInstanceImpl(typeName, Cbj_ParentName, _Cbj_Utils_stripParentheses(bindFuns))

#endif // _CBJ_OBJECTSETUP_H

#ifndef _CBJ_OBJECTSETUP_H
#define _CBJ_OBJECTSETUP_H
#include "_Cbj_ObjectInstanceImpl.h"
#include "_Cbj_SizeImpl.h"
#include "_Cbj_TypeDef.h"
#include "_Cbj_TypeInstanceFunPrototype.h"
#include "_Cbj_TypeInstanceImpl.h"
#include "_Cbj_TypeTypeDef.h"
#include "_Cbj_Utils.h"

#define _Cbj_ObjectSetup(m_cbjType, mParent, mBindSuperFuns) \
    _Cbj_TypeTypeDef(m_cbjType, mParent, withoutVirtFuns);           \
    _Cbj_TypeDef(m_cbjType, mParent);                  \
    _Cbj_TypeInstanceFunPrototype(m_cbjType);         \
    _Cbj_ObjectInstanceImpl(m_cbjType);               \
    _Cbj_SizeImpl(m_cbjType);                         \
    _Cbj_TypeInstanceImpl(m_cbjType, mParent, _Cbj_Utils_stripParentheses(mBindSuperFuns))

#endif // _CBJ_OBJECTSETUP_H

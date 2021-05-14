#ifndef _CBJ_ABSTRACTCLASSSETUP_H
#define _CBJ_ABSTRACTCLASSSETUP_H
#include "_Cbj_CastToSubImpl.h"
#include "_Cbj_CastToSuperImpl.h"
#include "_Cbj_CbjectTypeVirtFunsGetImpl.h"
#include "_Cbj_SizeImpl.h"
#include "_Cbj_TypeDef.h"
#include "_Cbj_TypeInstanceImpl.h"
#include "_Cbj_TypeTypeDef.h"
#include "_Cbj_Utils.h"
#include "_Cbj_VirtFunCalls.h"

#define _Cbj_AbstractClassSetup(m_cbjType, mParent, mVirtFunCalls, mBindSuperFuns)          \
    _Cbj_TypeTypeDef(m_cbjType, mParent, withVirtFuns);                               \
    _Cbj_TypeDef(m_cbjType, mParent);                                                 \
    _Cbj_SizeImpl(m_cbjType);                                                         \
    _Cbj_TypeInstanceImpl(m_cbjType, mParent, _Cbj_Utils_stripParentheses(mBindSuperFuns)); \
    _Cbj_CastToSuperImpl(m_cbjType, mParent);                                         \
    _Cbj_CastToSubImpl(m_cbjType, mParent);                                           \
    _Cbj_CbjectTypeVirtFunsGetImpl(m_cbjType);                                        \
    _Cbj_VirtFunCalls(_Cbj_Utils_stripParentheses(mVirtFunCalls))

#endif // _CBJ_ABSTRACTCLASSSETUP_H

#ifndef _CBJ_ABSTRACTCLASS_H
#define _CBJ_ABSTRACTCLASS_H
#include "_Cbj_CastToSubFunPrototype.h"
#include "_Cbj_CastToSuperFunPrototype.h"
#include "_Cbj_CbjectTypeVirtFunsGetFunPrototype.h"
#include "_Cbj_ContainerTypeDef.h"
#include "_Cbj_InitFunPrototype.h"
#include "_Cbj_ParamsTypeDef.h"
#include "_Cbj_PropsTypeDef.h"
#include "_Cbj_TerminateFunPrototype.h"
#include "_Cbj_TypeContainerTypeDef.h"
#include "_Cbj_TypeDecl.h"
#include "_Cbj_TypeInstanceFunPrototype.h"
#include "_Cbj_TypeTypeDecl.h"
#include "_Cbj_Utils.h"
#include "_Cbj_VirtFunsTypeDef.h"

#define _Cbj_AbstractClass(m_cbjType, mParent, mParams, mProps, mVirtFuns)      \
    _Cbj_TypeTypeDecl(m_cbjType);                                            \
    _Cbj_TypeDecl(m_cbjType);                                                \
    _Cbj_ParamsTypeDef(m_cbjType, _Cbj_Utils_stripParentheses(mParams));      \
    _Cbj_PropsTypeDef(m_cbjType, _Cbj_Utils_stripParentheses(mProps));        \
    _Cbj_VirtFunsTypeDef(m_cbjType, _Cbj_Utils_stripParentheses(mVirtFuns)); \
    _Cbj_TypeContainerTypeDef(m_cbjType, mParent, withVirtFuns);                 \
    _Cbj_ContainerTypeDef(m_cbjType, mParent);                                \
    _Cbj_InitFunPrototype(m_cbjType);                                        \
    _Cbj_TerminateFunPrototype(m_cbjType);                                   \
    _Cbj_TypeInstanceFunPrototype(m_cbjType);                                \
    Funs(_Cbj_Utils_stripParentheses(mVirtFuns));                          \
    _Cbj_CastToSuperFunPrototype(m_cbjType, mParent);                         \
    _Cbj_CastToSubFunPrototype(m_cbjType, mParent);                           \
    _Cbj_CbjectTypeVirtFunsGetFunPrototype(m_cbjType)

#endif // _CBJ_ABSTRACTCLASS_H

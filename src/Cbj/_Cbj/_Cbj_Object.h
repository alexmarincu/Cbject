#ifndef _CBJ_OBJECT_H
#define _CBJ_OBJECT_H
#include "_Cbj_ContainerTypeDef.h"
#include "_Cbj_InitFunPrototype.h"
#include "_Cbj_ObjectInstanceFunPrototype.h"
#include "_Cbj_ParamsTypeDef.h"
#include "_Cbj_PropsTypeDef.h"
#include "_Cbj_TerminateFunPrototype.h"
#include "_Cbj_TypeDecl.h"
#include "_Cbj_TypeTypeDecl.h"
#include "_Cbj_Utils.h"

#define _Cbj_Object(m_cbjType, mParent, mProps)                         \
    _Cbj_TypeTypeDecl(m_cbjType);                                     \
    _Cbj_TypeDecl(m_cbjType);                                         \
    _Cbj_ParamsTypeDef(m_cbjType, 0);                                 \
    _Cbj_PropsTypeDef(m_cbjType, _Cbj_Utils_stripParentheses(mProps)); \
    _Cbj_ContainerTypeDef(m_cbjType, mParent);                         \
    _Cbj_InitFunPrototype(m_cbjType);                                 \
    _Cbj_TerminateFunPrototype(m_cbjType);                            \
    _Cbj_ObjectInstanceFunPrototype(m_cbjType)

#endif // _CBJ_OBJECT_H

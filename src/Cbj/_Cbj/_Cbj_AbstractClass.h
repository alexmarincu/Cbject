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

#define _Cbj_AbstractClass(cbjType, parent, params, props, virtFuns)      \
    _Cbj_TypeTypeDecl(cbjType);                                            \
    _Cbj_TypeDecl(cbjType);                                                \
    _Cbj_ParamsTypeDef(cbjType, _Cbj_Utils_stripParentheses(params));      \
    _Cbj_PropsTypeDef(cbjType, _Cbj_Utils_stripParentheses(props));        \
    _Cbj_VirtFunsTypeDef(cbjType, _Cbj_Utils_stripParentheses(virtFuns)); \
    _Cbj_TypeContainerTypeDef(cbjType, parent, withVirtFuns);                 \
    _Cbj_ContainerTypeDef(cbjType, parent);                                \
    _Cbj_InitFunPrototype(cbjType);                                        \
    _Cbj_TerminateFunPrototype(cbjType);                                   \
    _Cbj_TypeInstanceFunPrototype(cbjType);                                \
    Funs(_Cbj_Utils_stripParentheses(virtFuns));                          \
    _Cbj_CastToSuperFunPrototype(cbjType, parent);                         \
    _Cbj_CastToSubFunPrototype(cbjType, parent);                           \
    _Cbj_CbjectTypeVirtFunsGetFunPrototype(cbjType)

#endif // _CBJ_ABSTRACTCLASS_H

#ifndef ___CBJ_ABSTRACTCLASS_H
#define ___CBJ_ABSTRACTCLASS_H
#include "___Cbj_CastToSuperFunPrototype.h"
#include "___Cbj_CbjectTypeVirtFunsGetFunPrototype.h"
#include "___Cbj_ContainerTypeDef.h"
#include "___Cbj_InitFunPrototype.h"
#include "___Cbj_ParamsTypeDef.h"
#include "___Cbj_PropsTypeDef.h"
#include "___Cbj_TerminateFunPrototype.h"
#include "___Cbj_TypeContainerTypeDef.h"
#include "___Cbj_TypeDecl.h"
#include "___Cbj_TypeInstanceFunPrototype.h"
#include "___Cbj_TypeTypeDecl.h"
#include "___Cbj_Utils.h"
#include "___Cbj_VirtFunsTypeDef.h"

#define ___Cbj_AbstractClass(cbjType, parent, params, props, virtFuns)        \
    ___Cbj_TypeTypeDecl(cbjType);                                             \
    ___Cbj_TypeDecl(cbjType);                                                 \
    ___Cbj_ParamsTypeDef(cbjType, ___Cbj_Utils_stripParentheses(params));     \
    ___Cbj_PropsTypeDef(cbjType, ___Cbj_Utils_stripParentheses(props));       \
    ___Cbj_VirtFunsTypeDef(cbjType, ___Cbj_Utils_stripParentheses(virtFuns)); \
    ___Cbj_TypeContainerTypeDef(cbjType, parent, withVirtFuns);               \
    ___Cbj_ContainerTypeDef(cbjType, parent);                                 \
    ___Cbj_InitFunPrototype(cbjType);                                         \
    ___Cbj_TerminateFunPrototype(cbjType);                                    \
    ___Cbj_TypeInstanceFunPrototype(cbjType);                                 \
    Funs(___Cbj_Utils_stripParentheses(virtFuns));                            \
    ___Cbj_CastToSuperFunPrototype(cbjType, parent);                          \
    ___Cbj_CbjectTypeVirtFunsGetFunPrototype(cbjType)

#endif // ___CBJ_ABSTRACTCLASS_H

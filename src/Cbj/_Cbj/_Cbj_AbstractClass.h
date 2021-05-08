#ifndef _CBJ_ABSTRACTCLASS_H
#define _CBJ_ABSTRACTCLASS_H
#include "_Cbj_CastToSubFunPrototype.h"
#include "_Cbj_CastToSuperFunPrototype.h"
#include "_Cbj_ClassInstanceFunPrototype.h"
#include "_Cbj_ClassTypeDef.h"
#include "_Cbj_ContainerTypeDef.h"
#include "_Cbj_InitFunPrototype.h"
#include "_Cbj_ParamsTypeDef.h"
#include "_Cbj_PropsTypeDef.h"
#include "_Cbj_TerminateFunPrototype.h"
#include "_Cbj_TypeDecl.h"
#include "_Cbj_VirtFunsTypeDef.h"

#define _Cbj_AbstractClass(typeName, Cbj_ParentName, params, props, virtFuns)           \
    _Cbj_PropsTypeDef(typeName, _Cbj_Utils_stripParentheses(props));             \
    _Cbj_ParamsTypeDef(typeName, _Cbj_Utils_stripParentheses(params));    \
    _Cbj_TypeDecl(typeName);                                                    \
    _Cbj_ContainerTypeDef(typeName, Cbj_ParentName);                                \
    _Cbj_InitFunPrototype(typeName);                                                   \
    _Cbj_TerminateFunPrototype(typeName);                                              \
    _Cbj_VirtFunsTypeDef(typeName, _Cbj_Utils_stripParentheses(virtFuns)); \
    _Cbj_ClassTypeDef(typeName, Cbj_ParentName, vf);                                \
    _Cbj_ClassInstanceFunPrototype(typeName);                                          \
    Funs(_Cbj_Utils_stripParentheses(virtFuns));                                      \
    _Cbj_CastToSuperFunPrototype(typeName, Cbj_ParentName);                                \
    _Cbj_CastToSubFunPrototype(typeName, Cbj_ParentName)

#endif // _CBJ_ABSTRACTCLASS_H

#ifndef _CBJ_OBJECT_H
#define _CBJ_OBJECT_H
#include "_Cbj_ContainerTypeDef.h"
#include "_Cbj_InitFunPrototype.h"
#include "_Cbj_ObjectInstanceFunPrototype.h"
#include "_Cbj_ParamsTypeDef.h"
#include "_Cbj_PropsTypeDef.h"
#include "_Cbj_TerminateFunPrototype.h"
#include "_Cbj_TypeDecl.h"
#include "_Cbj_Utils.h"

#define _Cbj_Object(typeName, Cbj_ParentName, props)                     \
    _Cbj_PropsTypeDef(typeName, _Cbj_Utils_stripParentheses(props)); \
    _Cbj_ParamsTypeDef(typeName, 0);                                 \
    _Cbj_TypeDecl(typeName);                                         \
    _Cbj_ContainerTypeDef(typeName, Cbj_ParentName);                     \
    _Cbj_InitFunPrototype(typeName);                                 \
    _Cbj_TerminateFunPrototype(typeName);                            \
    _Cbj_ObjectInstanceFunPrototype(typeName)

#endif // _CBJ_OBJECT_H

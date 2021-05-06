#ifndef _CBJECTABSTRACTKLASS_H
#define _CBJECTABSTRACTKLASS_H
#include "_CbjectCastToSubFunPrototype.h"
#include "_CbjectCastToSuperFunPrototype.h"
#include "_CbjectContainerTypeDefinition.h"
#include "_CbjectInitFunPrototype.h"
#include "_CbjectClassInstanceFunPrototype.h"
#include "_CbjectClassTypeDefinition.h"
#include "_CbjectParamsTypeDefinition.h"
#include "_CbjectPropsTypeDef.h"
#include "_CbjectTerminateFunPrototype.h"
#include "_CbjectTypeDeclaration.h"
#include "_CbjectVirtualFunsTypeDef.h"

#define _CbjectAbstractClass(cbjectTypeName, parentName, params, props, virtualFuns)              \
    _CbjectPropsTypeDef(cbjectTypeName, _CbjectUtilities_stripParentheses(props));             \
    _CbjectParamsTypeDefinition(cbjectTypeName, _CbjectUtilities_stripParentheses(params));                     \
    _CbjectTypeDeclaration(cbjectTypeName);                                                                     \
    _CbjectContainerTypeDefinition(cbjectTypeName, parentName);                                             \
    _CbjectInitFunPrototype(cbjectTypeName);                                                                    \
    _CbjectTerminateFunPrototype(cbjectTypeName);                                                               \
    _CbjectVirtualFunsTypeDef(cbjectTypeName, _CbjectUtilities_stripParentheses(virtualFuns)); \
    _CbjectClassTypeDefinition(cbjectTypeName, parentName, vf);                                             \
    _CbjectClassInstanceFunPrototype(cbjectTypeName);                                                      \
    OverrideFuns(_CbjectUtilities_stripParentheses(virtualFuns));                                   \
    Funs(_CbjectUtilities_stripParentheses(virtualFuns));                                        \
    _CbjectCastToSuperFunPrototype(cbjectTypeName, parentName);                                             \
    _CbjectCastToSubFunPrototype(cbjectTypeName, parentName)

#endif // _CBJECTABSTRACTKLASS_H

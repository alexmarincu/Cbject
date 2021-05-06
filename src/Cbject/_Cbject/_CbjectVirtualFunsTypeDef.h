#ifndef _CBJECTVIRTUALFUNSTYPEDEF_H
#define _CBJECTVIRTUALFUNSTYPEDEF_H
#include "_CbjectVirtualFunPtr.h"

#define _CbjectVirtualFunsTypeDef_stripParenthesesAndApplyVirtualFunPtr(funPrototype) \
    _CbjectVirtualFunPtr funPrototype;

#define _CbjectVirtualFunsTypeDef_0(cbjectTypeName, ...) \
    typedef char cbjectTypeName##VirtualFuns

#define _CbjectVirtualFunsTypeDef__(cbjectTypeName, ...)                                                            \
    typedef struct cbjectTypeName##VirtualFuns                                                                      \
    {                                                                                                          \
        _CbjectUtilities_forEach(_CbjectVirtualFunsTypeDef_stripParenthesesAndApplyVirtualFunPtr, __VA_ARGS__) \
    } cbjectTypeName##VirtualFuns

#define _CbjectVirtualFunsTypeDef_case(cbjectTypeName, case, ...) \
    _CbjectVirtualFunsTypeDef_##case (cbjectTypeName, __VA_ARGS__)

#define _CbjectVirtualFunsTypeDef(cbjectTypeName, ...) \
    _CbjectVirtualFunsTypeDef_case(cbjectTypeName, __VA_ARGS__)

#endif // _CBJECTVIRTUALFUNSTYPEDEF_H

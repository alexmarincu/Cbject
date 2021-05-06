#ifndef _CBJECTPROPSTYPEDEF_H
#define _CBJECTPROPSTYPEDEF_H

#define _CbjectPropsTypeDef_0(cbjectTypeName, ...) \
    typedef char cbjectTypeName##Props

#define _CbjectPropsTypeDef__(cbjectTypeName, ...)                                \
    typedef struct cbjectTypeName##Props                                          \
    {                                                                        \
        _CbjectUtilities_forEach(_CbjectUtilities_addSemicolon, __VA_ARGS__) \
    } cbjectTypeName##Props

#define _CbjectPropsTypeDef_case(cbjectTypeName, case, ...) \
    _CbjectPropsTypeDef_##case (cbjectTypeName, __VA_ARGS__)

#define _CbjectPropsTypeDef(cbjectTypeName, ...) \
    _CbjectPropsTypeDef_case(cbjectTypeName, __VA_ARGS__)

#endif // _CBJECTPROPSTYPEDEF_H

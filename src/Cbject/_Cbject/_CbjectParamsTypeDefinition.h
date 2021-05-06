#ifndef _CBJECTPARAMSTYPEDEFINITION_H
#define _CBJECTPARAMSTYPEDEFINITION_H

#define _CbjectParamsTypeDefinition_0(cbjectTypeName, ...) \
    typedef char cbjectTypeName##Params

#define _CbjectParamsTypeDefinition__(cbjectTypeName, ...)                        \
    typedef struct cbjectTypeName##Params                                         \
    {                                                                        \
        _CbjectUtilities_forEach(_CbjectUtilities_addSemicolon, __VA_ARGS__) \
    } cbjectTypeName##Params

#define _CbjectParamsTypeDefinition_case(cbjectTypeName, case, ...) \
    _CbjectParamsTypeDefinition_##case (cbjectTypeName, __VA_ARGS__)

#define _CbjectParamsTypeDefinition(cbjectTypeName, ...) \
    _CbjectParamsTypeDefinition_case(cbjectTypeName, __VA_ARGS__)

#endif // _CBJECTPARAMSTYPEDEFINITION_H

#ifndef _CBJECTPARAMSTYPEDEFINITION_H
#define _CBJECTPARAMSTYPEDEFINITION_H

#define _CbjectParamsTypeDefinition_0(klassName, ...) \
    typedef char klassName##Params

#define _CbjectParamsTypeDefinition__(klassName, ...)                        \
    typedef struct klassName##Params                                         \
    {                                                                        \
        _CbjectUtilities_forEach(_CbjectUtilities_addSemicolon, __VA_ARGS__) \
    } klassName##Params

#define _CbjectParamsTypeDefinition_case(klassName, case, ...) \
    _CbjectParamsTypeDefinition_##case (klassName, __VA_ARGS__)

#define _CbjectParamsTypeDefinition(klassName, ...) \
    _CbjectParamsTypeDefinition_case(klassName, __VA_ARGS__)

#endif // _CBJECTPARAMSTYPEDEFINITION_H

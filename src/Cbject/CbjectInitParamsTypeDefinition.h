#ifndef CBJECTKLASSINITPARAMSTYPEDEFINITION_H
#define CBJECTKLASSINITPARAMSTYPEDEFINITION_H

#define CbjectInitParamsTypeDefinition0(klassName, ...) \
    typedef char klassName##InitParams

#define CbjectInitParamsTypeDefinition_(klassName, ...)               \
    typedef struct klassName##InitParams                                   \
    {                                                                      \
        CbjectUtilities_forEach(CbjectUtilities_addSemicolon, __VA_ARGS__) \
    } klassName##InitParams

#define CbjectInitParamsTypeDefinition_case(klassName, case, ...) \
    CbjectInitParamsTypeDefinition##case (klassName, __VA_ARGS__)

#define CbjectInitParamsTypeDefinition(klassName, ...) \
    CbjectInitParamsTypeDefinition_case(klassName, __VA_ARGS__)

#endif // CBJECTKLASSINITPARAMSTYPEDEFINITION_H

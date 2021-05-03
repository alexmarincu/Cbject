#ifndef _CBJECTDATATYPEDEFINITION_H
#define _CBJECTDATATYPEDEFINITION_H

#define _CbjectDataTypeDefinition(klassName, ...)                            \
    typedef struct klassName                                                 \
    {                                                                        \
        _CbjectUtilities_forEach(_CbjectUtilities_addSemicolon, __VA_ARGS__) \
    } klassName

#endif // _CBJECTDATATYPEDEFINITION_H

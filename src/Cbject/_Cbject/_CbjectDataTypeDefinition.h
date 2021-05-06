#ifndef _CBJECTDATATYPEDEFINITION_H
#define _CBJECTDATATYPEDEFINITION_H

#define _CbjectDataTypeDefinition(cbjectTypeName, ...)                            \
    typedef struct cbjectTypeName                                                 \
    {                                                                        \
        _CbjectUtilities_forEach(_CbjectUtilities_addSemicolon, __VA_ARGS__) \
    } cbjectTypeName

#endif // _CBJECTDATATYPEDEFINITION_H

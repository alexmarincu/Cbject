#ifndef _CBJECTTYPEDEFINITION_H
#define _CBJECTTYPEDEFINITION_H

#define _CbjectTypeDefinition(cbjectTypeName, parentName) \
    struct cbjectTypeName                                     \
    {                                                    \
        _##parentName s;                             \
        cbjectTypeName##Props p;                         \
    }

#endif // _CBJECTTYPEDEFINITION_H

#ifndef _CBJECTTYPEDEFINITION_H
#define _CBJECTTYPEDEFINITION_H

#define _CbjectTypeDefinition(klassName, superKlassName) \
    struct klassName                                     \
    {                                                    \
        _##superKlassName s;                             \
        klassName##Properties p;                         \
    }

#endif // _CBJECTTYPEDEFINITION_H

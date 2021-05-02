#ifndef _CBJECTKLASSTYPEDEFINITION_H
#define _CBJECTKLASSTYPEDEFINITION_H

#define _CbjectKlassTypeDefinition(klassName, superKlassName) \
    typedef struct klassName##Klass                           \
    {                                                         \
        superKlassName##Klass s;                          \
        klassName##KlassVirtualFunctions vf;                  \
    } klassName##Klass

#endif // _CBJECTKLASSTYPEDEFINITION_H

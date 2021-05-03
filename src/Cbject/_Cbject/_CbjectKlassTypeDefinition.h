#ifndef _CBJECTKLASSTYPEDEFINITION_H
#define _CBJECTKLASSTYPEDEFINITION_H

#define _CbjectKlassTypeDefinition_0(klassName, superKlassName) \
    typedef struct klassName##Klass                             \
    {                                                           \
        superKlassName##Klass s;                                \
    } klassName##Klass

#define _CbjectKlassTypeDefinition_vf(klassName, superKlassName) \
    typedef struct klassName##Klass                              \
    {                                                            \
        superKlassName##Klass s;                                 \
        klassName##KlassVirtualFunctions vf;                     \
    } klassName##Klass

#define _CbjectKlassTypeDefinition(klassName, superKlassName, case) \
    _CbjectKlassTypeDefinition_##case (klassName, superKlassName)

#endif // _CBJECTKLASSTYPEDEFINITION_H

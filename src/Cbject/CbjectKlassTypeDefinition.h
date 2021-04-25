#ifndef CBJECTKLASSTYPEDEFINITION_H
#define CBJECTKLASSTYPEDEFINITION_H

#define CbjectKlassTypeDefinition(klassName, superKlassName) \
    typedef struct klassName##Klass                          \
    {                                                        \
        superKlassName##Klass super;                         \
        klassName##KlassVirtualFunctions vf;                 \
    } klassName##Klass

#endif // CBJECTKLASSTYPEDEFINITION_H

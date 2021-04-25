#ifndef CBJECTKLASSSHELLTYPEDEFINITION_H
#define CBJECTKLASSSHELLTYPEDEFINITION_H

#define CbjectShellTypeDefinition(klassName, superKlassName) \
    typedef union klassName##Shell                                \
    {                                                             \
        char d[sizeof(struct { superKlassName##Shell super; klassName##Properties m; })];                               \
        CbjectSettings_maxAlign a;                                               \
    } klassName##Shell

#endif // CBJECTKLASSSHELLTYPEDEFINITION_H

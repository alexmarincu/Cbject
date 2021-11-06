#ifndef CBJECT_CLASSSTRUCT_H
#define CBJECT_CLASSSTRUCT_H

#define Cbject_ClassStruct_Decl(typeName) \
    typedef struct typeName typeName

#define Cbject_ClassStruct_Def(typeName, superTypeName) \
    struct typeName                                     \
    {                                                   \
        superTypeName##Container super;                 \
        typeName##Data data;                            \
    }

#endif // CBJECT_CLASSSTRUCT_H

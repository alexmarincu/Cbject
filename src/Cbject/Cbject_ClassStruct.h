#ifndef CBJECT_CLASSSTRUCT_H
#define CBJECT_CLASSSTRUCT_H

/*
Cbject_ClassStruct_Decl
*/
#define Cbject_ClassStruct_Decl(className) \
    typedef struct className className

/*
Cbject_ClassStruct_Def
*/
#define Cbject_ClassStruct_Def(className, superClassName) \
    struct className                                      \
    {                                                     \
        superClassName##Container super;                  \
        className##Data data;                             \
    }

#endif // CBJECT_CLASSSTRUCT_H

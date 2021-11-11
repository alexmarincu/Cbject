#ifndef CBJECT_CLASSSTRUCT_H
#define CBJECT_CLASSSTRUCT_H

/*
Cbject_ClassStruct_Decl
*/
#define Cbject_ClassStruct_Decl(class) \
    typedef struct class class

/*
Cbject_ClassStruct_Def
*/
#define Cbject_ClassStruct_Def(class, superClass) \
    struct class                                  \
    {                                             \
        superClass##Container super;              \
        class##Data data;                         \
    }

#endif // CBJECT_CLASSSTRUCT_H

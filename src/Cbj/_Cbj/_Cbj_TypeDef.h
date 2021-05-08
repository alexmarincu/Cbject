#ifndef _CBJ_TYPEDEF_H
#define _CBJ_TYPEDEF_H

#define _Cbj_TypeDef(typeName, Cbj_ParentName) \
    struct typeName                                     \
    {                                                    \
        _##Cbj_ParentName s;                             \
        typeName##Props p;                         \
    }

#endif // _CBJ_TYPEDEF_H

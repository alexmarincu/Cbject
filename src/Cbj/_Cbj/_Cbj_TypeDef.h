#ifndef _CBJ_TYPEDEF_H
#define _CBJ_TYPEDEF_H

#define _Cbj_TypeDef(cbjType, parent) \
    struct cbjType                    \
    {                                 \
        _##parent s;                  \
        cbjType##Props p;             \
    }

#endif // _CBJ_TYPEDEF_H

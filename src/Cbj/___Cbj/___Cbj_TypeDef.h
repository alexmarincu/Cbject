#ifndef ___CBJ_TYPEDEF_H
#define ___CBJ_TYPEDEF_H

#define ___Cbj_TypeDef(cbjType, parent) \
    struct cbjType                      \
    {                                   \
        ___##parent super;              \
        cbjType##Props props;           \
    }

#endif // ___CBJ_TYPEDEF_H

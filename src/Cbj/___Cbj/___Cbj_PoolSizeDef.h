#ifndef ___CBJ_POOLSIZEDEF_H
#define ___CBJ_POOLSIZEDEF_H

#define ___Cbj_PoolSizeDef(cbjType, poolSize) \
    enum                                      \
    {                                         \
        cbjType##_poolSize = poolSize         \
    }

#endif // ___CBJ_POOLSIZEDEF_H

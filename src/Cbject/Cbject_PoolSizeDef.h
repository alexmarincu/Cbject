#ifndef CBJECT_POOLSIZEDEF_H
#define CBJECT_POOLSIZEDEF_H

#define Cbject_PoolSizeDef(cbjType, poolSize) \
    enum                                      \
    {                                         \
        cbjType##_poolSize = poolSize         \
    }

#endif // CBJECT_POOLSIZEDEF_H

#ifndef CBJECT_POOLSIZEDEF_H
#define CBJECT_POOLSIZEDEF_H

#define Cbject_PoolSizeDef(className, poolSize) \
    enum                                        \
    {                                           \
        className##_poolSize = poolSize         \
    }

#endif // CBJECT_POOLSIZEDEF_H

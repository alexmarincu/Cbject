#ifndef CBJECT_POOLSIZEDEF_H
#define CBJECT_POOLSIZEDEF_H

/*
Cbject_PoolSizeDef
*/
#define Cbject_PoolSizeDef_x0(class, poolSize) \
    enum                                       \
    {                                          \
        class##_poolSize = poolSize            \
    }

#define Cbject_PoolSizeDef(class, poolSize) \
    Cbject_PoolSizeDef_x0(class, poolSize)

#endif // CBJECT_POOLSIZEDEF_H

#ifndef CBJECT_POOLSIZEDEF_H
#define CBJECT_POOLSIZEDEF_H

#define Cbject_PoolSizeDef(typeName, poolSize) \
    enum                                       \
    {                                          \
        typeName##_poolSize = poolSize         \
    }

#endif // CBJECT_POOLSIZEDEF_H

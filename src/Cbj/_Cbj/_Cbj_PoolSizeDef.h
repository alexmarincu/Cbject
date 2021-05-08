#ifndef _CBJ_POOLSIZEDEF_H
#define _CBJ_POOLSIZEDEF_H

#define _Cbj_PoolSizeDef(typeName, poolSize) \
    enum                                     \
    {                                        \
        typeName##_poolSize = poolSize       \
    }

#endif // _CBJ_POOLSIZEDEF_H

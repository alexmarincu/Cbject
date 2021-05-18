#ifndef _CBJ_POOLSIZEDEF_H
#define _CBJ_POOLSIZEDEF_H

#define _Cbj_PoolSizeDef(cbjType, poolSize) \
    enum                                    \
    {                                       \
        cbjType##_poolSize = poolSize       \
    }

#endif // _CBJ_POOLSIZEDEF_H

#ifndef _CBJ_POOLSIZEDEF_H
#define _CBJ_POOLSIZEDEF_H

#define _Cbj_PoolSizeDef(m_cbjType, poolSize) \
    enum                                    \
    {                                       \
        m_cbjType##_poolSize = poolSize       \
    }

#endif // _CBJ_POOLSIZEDEF_H

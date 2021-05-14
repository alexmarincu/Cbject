#ifndef _CBJ_GETOBJECTFUNPROTOTYPE_H
#define _CBJ_GETOBJECTFUNPROTOTYPE_H

#define _Cbj_GetObjectFunPrototype(m_cbjType) \
    m_cbjType * Get_##m_cbjType(m_cbjType##Params const * const params)

#endif // _CBJ_GETOBJECTFUNPROTOTYPE_H

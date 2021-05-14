#ifndef _CBJ_NEWOBJECTFUNPROTOTYPE_H
#define _CBJ_NEWOBJECTFUNPROTOTYPE_H

#define _Cbj_NewObjectFunPrototype(m_cbjType) \
    m_cbjType * New_##m_cbjType(m_cbjType##Params const * const params)
#endif // _CBJ_NEWOBJECTFUNPROTOTYPE_H

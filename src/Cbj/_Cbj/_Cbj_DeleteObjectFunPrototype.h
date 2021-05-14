#ifndef _CBJ_DELETEOBJECTFUNPROTOTYPE_H
#define _CBJ_DELETEOBJECTFUNPROTOTYPE_H

#define _Cbj_DeleteObjectFunPrototype(m_cbjType) \
    m_cbjType * Delete_##m_cbjType(m_cbjType * me)

#endif // _CBJ_DELETEOBJECTFUNPROTOTYPE_H

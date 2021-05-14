#ifndef _CBJ_GETFUNPROTOTYPE_H
#define _CBJ_GETFUNPROTOTYPE_H

#define _Cbj_GetFunPrototype(m_cbjType, propType, propName) \
    propType m_cbjType##_##propName(m_cbjType const * const me)

#endif // _CBJ_GETFUNPROTOTYPE_H

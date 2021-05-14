#ifndef _CBJ_SETFUNPROTOTYPE_H
#define _CBJ_SETFUNPROTOTYPE_H

#define _Cbj_SetFunPrototype(m_cbjType, propType, propName) \
    void m_cbjType##_##propName##Set(m_cbjType * const me, propType const propName)

#endif // _CBJ_SETFUNPROTOTYPE_H

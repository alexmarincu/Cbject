#ifndef _CBJ_ONINITFUNPROTOTYPE_H
#define _CBJ_ONINITFUNPROTOTYPE_H

#define _Cbj_OnInitFunPrototype(m_cbjType, mParent) \
    static void _##m_cbjType##_onInit(m_cbjType * const me, m_cbjType##Params const * const params, mParent##Params * const s_params)

#endif // _CBJ_ONINITFUNPROTOTYPE_H

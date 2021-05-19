#ifndef ___CBJ_ONINITFUNPROTOTYPE_H
#define ___CBJ_ONINITFUNPROTOTYPE_H

#define ___Cbj_OnInitFunPrototype(cbjType, parent) \
    static void ___##cbjType##_onInit(cbjType * const me, cbjType##Params const * const params, parent##Params * const s_params)

#endif // ___CBJ_ONINITFUNPROTOTYPE_H

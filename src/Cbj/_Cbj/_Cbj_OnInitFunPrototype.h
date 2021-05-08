#ifndef _CBJ_ONINITFUNPROTOTYPE_H
#define _CBJ_ONINITFUNPROTOTYPE_H

#define _Cbj_OnInitFunPrototype(cbjType, parent) \
    static void _##cbjType##_onInit(cbjType * const me, cbjType##Params const * const params, parent##Params * const s_params)

#endif // _CBJ_ONINITFUNPROTOTYPE_H

#ifndef _CBJ_ONINITFUNPROTOTYPE_H
#define _CBJ_ONINITFUNPROTOTYPE_H

#define _Cbj_OnInitFunPrototype(typeName, Cbj_ParentName) \
    static void _##typeName##_onInit(typeName * const me, typeName##Params const * const params, Cbj_ParentName##Params * const s_params)

#endif // _CBJ_ONINITFUNPROTOTYPE_H

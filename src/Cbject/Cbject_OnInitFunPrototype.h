#ifndef CBJECT_ONINITFUNPROTOTYPE_H
#define CBJECT_ONINITFUNPROTOTYPE_H

#define Cbject_OnInitFunPrototype(cbjType, parent) \
    static void cbjType##_onInit(cbjType * const me, cbjType##Params const * const params, parent##Params * const super_params)

#endif // CBJECT_ONINITFUNPROTOTYPE_H

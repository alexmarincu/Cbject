#ifndef CBJECT_ONINITFUNPROTOTYPE_H
#define CBJECT_ONINITFUNPROTOTYPE_H

#define Cbject_OnInitFunPrototype(typeName, parent) \
    static void typeName##_onInit(typeName * const me, typeName##Params const * const params, parent##Params * const super_params)

#endif // CBJECT_ONINITFUNPROTOTYPE_H

#ifndef CBJECT_ONINITFUNPROTOTYPE_H
#define CBJECT_ONINITFUNPROTOTYPE_H

#define Cbject_OnInitFunPrototype(typeName, parent) \
    static void typeName##_onInit(typeName * const me, typeName##Params const params, parent##Params * const s_params)

#endif // CBJECT_ONINITFUNPROTOTYPE_H

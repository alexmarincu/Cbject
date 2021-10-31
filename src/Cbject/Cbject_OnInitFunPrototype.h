#ifndef CBJECT_ONINITFUNPROTOTYPE_H
#define CBJECT_ONINITFUNPROTOTYPE_H

#define Cbject_OnInitFunPrototype(typeName, parent) \
    static void typeName##_onInit(typeName * const me, typeName##Params const p, parent##Params * const sp)

#endif // CBJECT_ONINITFUNPROTOTYPE_H

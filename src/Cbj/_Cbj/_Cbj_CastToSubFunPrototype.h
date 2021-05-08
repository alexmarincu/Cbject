#ifndef _CBJ_CASTTOSUBFUNPROTOTYPE_H
#define _CBJ_CASTTOSUBFUNPROTOTYPE_H

#define _Cbj_CastToSubFunPrototype(typeName, Cbj_ParentName) \
    typeName * const Cbj_ParentName##_to##typeName(Cbj_ParentName const * const me)

#endif // _CBJ_CASTTOSUBFUNPROTOTYPE_H

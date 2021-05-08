#ifndef _CBJ_CASTTOSUPERFUNPROTOTYPE_H
#define _CBJ_CASTTOSUPERFUNPROTOTYPE_H

#define _Cbj_CastToSuperFunPrototype(typeName, Cbj_ParentName) \
    Cbj_ParentName * const typeName##_to##Cbj_ParentName(typeName const * const me)

#endif // _CBJ_CASTTOSUPERFUNPROTOTYPE_H

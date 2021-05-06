#ifndef _CBJECTCASTTOSUPERFUNPROTOTYPE_H
#define _CBJECTCASTTOSUPERFUNPROTOTYPE_H

#define _CbjectCastToSuperFunPrototype(cbjectTypeName, parentName) \
    parentName * const cbjectTypeName##_to##parentName(cbjectTypeName const * const me)

#endif // _CBJECTCASTTOSUPERFUNPROTOTYPE_H

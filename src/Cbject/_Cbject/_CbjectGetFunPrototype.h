#ifndef _CBJECTGETFUNPROTOTYPE_H
#define _CBJECTGETFUNPROTOTYPE_H

#define _CbjectGetFunPrototype(cbjectTypeName, type, memberName) \
    type cbjectTypeName##_##memberName(cbjectTypeName const * const me)

#endif // _CBJECTGETFUNPROTOTYPE_H

#ifndef _CBJECTCASTTOSUBFUNPROTOTYPE_H
#define _CBJECTCASTTOSUBFUNPROTOTYPE_H

#define _CbjectCastToSubFunPrototype(cbjectTypeName, parentName) \
    cbjectTypeName * const parentName##_to##cbjectTypeName(parentName const * const me)

#endif // _CBJECTCASTTOSUBFUNPROTOTYPE_H

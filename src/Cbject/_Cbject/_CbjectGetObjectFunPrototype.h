#ifndef _CBJECTGETOBJECTFUNPROTOTYPE_H
#define _CBJECTGETOBJECTFUNPROTOTYPE_H

#define _CbjectGetObjectFunPrototype(cbjectTypeName) \
    cbjectTypeName * Get_##cbjectTypeName(cbjectTypeName##Params const * const params)

#endif // _CBJECTGETOBJECTFUNPROTOTYPE_H

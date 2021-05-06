#ifndef _CBJECTONINITFUNPROTOTYPE_H
#define _CBJECTONINITFUNPROTOTYPE_H

#define _CbjectOnInitFunPrototype(cbjectTypeName, parentName) \
    static void _##cbjectTypeName##_onInit(cbjectTypeName * const me, cbjectTypeName##Params const * const params, parentName##Params * const s_params)

#endif // _CBJECTONINITFUNPROTOTYPE_H

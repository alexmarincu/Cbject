#ifndef _CBJECTONINITFUNPROTOTYPE_H
#define _CBJECTONINITFUNPROTOTYPE_H

#define _CbjectOnInitFunPrototype(klassName, superKlassName) \
    static void _##klassName##_onInit(klassName * const me, klassName##Params const * const params, superKlassName##Params * const s_params)

#endif // _CBJECTONINITFUNPROTOTYPE_H

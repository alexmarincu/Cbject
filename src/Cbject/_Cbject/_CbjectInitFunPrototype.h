#ifndef _CBJECTINITFUNPROTOTYPE_H
#define _CBJECTINITFUNPROTOTYPE_H

#define _CbjectInitFunPrototype(klassName, superKlassName) \
    static void _##klassName##_init(klassName * const me, klassName##Params const * const params, superKlassName##Params * const s_params)

#endif // _CBJECTINITFUNPROTOTYPE_H

#ifndef _CBJECTCASTTOSUBFUNPROTOTYPE_H
#define _CBJECTCASTTOSUBFUNPROTOTYPE_H

#define _CbjectCastToSubFunPrototype(klassName, superKlassName) \
    klassName * const superKlassName##_to##klassName(superKlassName const * const me)

#endif // _CBJECTCASTTOSUBFUNPROTOTYPE_H

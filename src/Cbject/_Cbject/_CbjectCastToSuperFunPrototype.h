#ifndef _CBJECTCASTTOSUPERFUNPROTOTYPE_H
#define _CBJECTCASTTOSUPERFUNPROTOTYPE_H

#define _CbjectCastToSuperFunPrototype(klassName, superKlassName) \
    superKlassName * const klassName##_to##superKlassName(klassName const * const me)

#endif // _CBJECTCASTTOSUPERFUNPROTOTYPE_H

#ifndef _CBJECTTERMINATEFUNPROTOTYPE_H
#define _CBJECTTERMINATEFUNPROTOTYPE_H

#define _CbjectTerminateFunPrototype(klassName) \
    static void _##klassName##_terminate(klassName * const me)

#endif // _CBJECTTERMINATEFUNPROTOTYPE_H

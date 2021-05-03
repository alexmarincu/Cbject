#ifndef _CBJECTONTERMINATEFUNPROTOTYPE_H
#define _CBJECTONTERMINATEFUNPROTOTYPE_H

#define _CbjectOnTerminateFunPrototype(klassName) \
    static void _##klassName##_onTerminate(klassName * const me)

#endif // _CBJECTONTERMINATEFUNPROTOTYPE_H

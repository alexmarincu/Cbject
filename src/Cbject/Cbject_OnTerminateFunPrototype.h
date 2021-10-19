#ifndef CBJECT_ONTERMINATEFUNPROTOTYPE_H
#define CBJECT_ONTERMINATEFUNPROTOTYPE_H

#define Cbject_OnTerminateFunPrototype(cbjType) \
    static void ___##cbjType##_onTerminate(cbjType * const me)

#endif // CBJECT_ONTERMINATEFUNPROTOTYPE_H

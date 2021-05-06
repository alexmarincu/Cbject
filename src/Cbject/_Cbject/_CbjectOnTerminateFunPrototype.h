#ifndef _CBJECTONTERMINATEFUNPROTOTYPE_H
#define _CBJECTONTERMINATEFUNPROTOTYPE_H

#define _CbjectOnTerminateFunPrototype(cbjectTypeName) \
    static void _##cbjectTypeName##_onTerminate(cbjectTypeName * const me)

#endif // _CBJECTONTERMINATEFUNPROTOTYPE_H

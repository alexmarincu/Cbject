#ifndef ___CBJ_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H
#define ___CBJ_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H

#define ___Cbj_CbjectTypeVirtFunsGetFunPrototype(cbjType) \
    cbjType##VirtFuns * cbjType##Type_virtFuns(cbjType##Type * meType)

#endif // ___CBJ_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H

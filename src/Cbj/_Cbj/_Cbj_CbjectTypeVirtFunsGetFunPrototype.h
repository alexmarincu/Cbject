#ifndef _CBJ_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H
#define _CBJ_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H

#define _Cbj_CbjectTypeVirtFunsGetFunPrototype(cbjType) \
    cbjType##VirtFuns * cbjType##Type_virtFuns(cbjType##Type * meType)

#endif // _CBJ_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H

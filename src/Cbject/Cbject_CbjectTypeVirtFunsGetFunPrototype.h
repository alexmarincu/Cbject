#ifndef CBJECT_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H
#define CBJECT_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H

#define Cbject_CbjectTypeVirtFunsGetFunPrototype(cbjType) \
    cbjType##VirtFuns * cbjType##Type_virtFuns(cbjType##Type * meType)

#endif // CBJECT_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H

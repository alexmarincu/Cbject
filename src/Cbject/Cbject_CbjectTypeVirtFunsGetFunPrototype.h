#ifndef CBJECT_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H
#define CBJECT_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H

#define Cbject_CbjectTypeVirtFunsGetFunPrototype(typeName) \
    typeName##VirtFuns * typeName##Type_virtFuns(typeName##Type * meType)

#endif // CBJECT_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H

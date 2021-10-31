#ifndef CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
#define CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H
#include "Cbject_CbjectTypeVirtFunsGetFunPrototype.h"

#define Cbject_CbjectTypeVirtFunsGetImpl(typeName)     \
    Cbject_CbjectTypeVirtFunsGetFunPrototype(typeName) \
    {                                                  \
        typeName##VirtFuns * virtFuns = NULL;          \
                                                       \
        typedef struct ObjectTypeT                     \
        {                                              \
            Cbject_Settings_maxAlign a;                \
            char const * name;                         \
            ObjectType * st;                           \
            ObjectVirtFuns vf;                         \
        } ObjectTypeT;                                 \
                                                       \
        if (((ObjectTypeT *)meType)->name == NULL)     \
        {                                              \
            virtFuns = &meType->vf;                    \
        }                                              \
                                                       \
        return virtFuns;                               \
    }

#endif // CBJECT_CBJECTTYPEVIRTFUNSGETIMPL_H

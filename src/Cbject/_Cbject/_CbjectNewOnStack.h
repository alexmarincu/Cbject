#ifndef _CBJECTNEWONSTACK_H
#define _CBJECTNEWONSTACK_H

#define _CbjectNewOnStack(klassName, varName, ...)                 \
    klassName * const varName = (klassName *) &((_##klassName){}); \
    klassName##_ctor((klassName *) varName, __VA_ARGS__)

#endif // _CBJECTNEWONSTACK_H

#ifndef _CBJECTNEWONSTACK_H
#define _CBJECTNEWONSTACK_H

#define _CbjectNewOnStack(cbjectTypeName, varName, ...)                 \
    cbjectTypeName * const varName = (cbjectTypeName *) &((_##cbjectTypeName){}); \
    cbjectTypeName##_init((cbjectTypeName *) varName, __VA_ARGS__)

#endif // _CBJECTNEWONSTACK_H

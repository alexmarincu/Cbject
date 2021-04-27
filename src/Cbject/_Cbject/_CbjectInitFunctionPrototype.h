#ifndef _CBJECTINITFUNCTIONPROTOTYPE_H
#define _CBJECTINITFUNCTIONPROTOTYPE_H

#define _CbjectInitFunctionPrototype(klassName) \
    void klassName##_init(klassName * const me, klassName##Params const * const params)

#endif // _CBJECTINITFUNCTIONPROTOTYPE_H

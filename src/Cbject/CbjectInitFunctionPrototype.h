#ifndef CBJECTINITFUNCTIONPROTOTYPE_H
#define CBJECTINITFUNCTIONPROTOTYPE_H

#define CbjectInitFunctionPrototype(klassName) \
    void klassName##_init(klassName * const me, klassName##InitParams const * const params)

#endif // CBJECTINITFUNCTIONPROTOTYPE_H

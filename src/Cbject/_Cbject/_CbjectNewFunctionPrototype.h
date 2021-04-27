#ifndef _CBJECTNEWFUNCTIONPROTOTYPE_H
#define _CBJECTNEWFUNCTIONPROTOTYPE_H

#define _CbjectNewFunctionPrototype(klassName) \
    klassName * New_##klassName(klassName##Params const * const params)
#endif // _CBJECTNEWFUNCTIONPROTOTYPE_H

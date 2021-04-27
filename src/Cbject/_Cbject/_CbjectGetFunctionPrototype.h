#ifndef _CBJECTGETFUNCTIONPROTOTYPE_H
#define _CBJECTGETFUNCTIONPROTOTYPE_H

#define _CbjectGetFunctionPrototype(klassName) \
    klassName * Get_##klassName(klassName##Params const * const params)

#endif // _CBJECTGETFUNCTIONPROTOTYPE_H

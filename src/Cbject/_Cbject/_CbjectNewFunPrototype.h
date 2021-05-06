#ifndef _CBJECTNEWFUNCTIONPROTOTYPE_H
#define _CBJECTNEWFUNCTIONPROTOTYPE_H

#define _CbjectNewFunPrototype(cbjectTypeName) \
    cbjectTypeName * New_##cbjectTypeName(cbjectTypeName##Params const * const params)
#endif // _CBJECTNEWFUNCTIONPROTOTYPE_H

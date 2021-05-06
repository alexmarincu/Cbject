#ifndef _CBJECTDELETEFUNCTIONPROTOTYPE_H
#define _CBJECTDELETEFUNCTIONPROTOTYPE_H

#define _CbjectDeleteFunPrototype(cbjectTypeName) \
    cbjectTypeName * Delete_##cbjectTypeName(cbjectTypeName * me)

#endif // _CBJECTDELETEFUNCTIONPROTOTYPE_H

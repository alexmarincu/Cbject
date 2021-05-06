#ifndef _CBJECTSETTERFUNCTIONPROTOTYPE_H
#define _CBJECTSETTERFUNCTIONPROTOTYPE_H

#define _CbjectSetFunPrototype(cbjectTypeName, type, memberName) \
    void cbjectTypeName##_##memberName##Set(cbjectTypeName * const me, type const memberName)

#endif // _CBJECTSETTERFUNCTIONPROTOTYPE_H

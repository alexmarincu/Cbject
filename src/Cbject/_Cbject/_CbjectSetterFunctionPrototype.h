#ifndef _CBJECTSETTERFUNCTIONPROTOTYPE_H
#define _CBJECTSETTERFUNCTIONPROTOTYPE_H

#define _CbjectSetterFunctionPrototype(klassName, type, memberName) \
    void klassName##_##memberName##Set(klassName * const me, type const memberName)

#endif // _CBJECTSETTERFUNCTIONPROTOTYPE_H

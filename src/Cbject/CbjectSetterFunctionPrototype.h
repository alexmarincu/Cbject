#ifndef CBJECTSETTERFUNCTIONPROTOTYPE_H
#define CBJECTSETTERFUNCTIONPROTOTYPE_H

#define CbjectSetterFunctionPrototype(klassName, type, memberName) \
    void klassName##_##memberName##Set(klassName * const me, type const memberName)

#endif // CBJECTSETTERFUNCTIONPROTOTYPE_H

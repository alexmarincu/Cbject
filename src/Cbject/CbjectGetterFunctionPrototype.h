#ifndef CBJECTGETTERFUNCTIONPROTOTYPE_H
#define CBJECTGETTERFUNCTIONPROTOTYPE_H

#define CbjectGetterFunctionPrototype(klassName, type, memberName) \
    type klassName##_##memberName(klassName const * const me)

#endif // CBJECTGETTERFUNCTIONPROTOTYPE_H

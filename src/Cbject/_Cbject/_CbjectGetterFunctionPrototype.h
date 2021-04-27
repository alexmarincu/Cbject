#ifndef _CBJECTGETTERFUNCTIONPROTOTYPE_H
#define _CBJECTGETTERFUNCTIONPROTOTYPE_H

#define _CbjectGetterFunctionPrototype(klassName, type, memberName) \
    type klassName##_##memberName(klassName const * const me)

#endif // _CBJECTGETTERFUNCTIONPROTOTYPE_H

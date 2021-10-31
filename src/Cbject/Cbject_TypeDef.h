#ifndef CBJECT_TYPEDEF_H
#define CBJECT_TYPEDEF_H

#define Cbject_TypeDef(typeName, parent) \
    struct typeName                      \
    {                                    \
        parent##Container s;             \
        typeName##Data d;                \
    }

#endif // CBJECT_TYPEDEF_H

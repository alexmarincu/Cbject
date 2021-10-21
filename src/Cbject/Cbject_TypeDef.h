#ifndef CBJECT_TYPEDEF_H
#define CBJECT_TYPEDEF_H

#define Cbject_TypeDef(cbjType, parent) \
    struct cbjType                      \
    {                                   \
        parent##Container super;        \
        cbjType##Props props;           \
    }

#endif // CBJECT_TYPEDEF_H

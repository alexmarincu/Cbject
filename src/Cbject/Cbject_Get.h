#ifndef CBJECT_GET_H
#define CBJECT_GET_H

#define Cbject_Get(cbjType, ...) \
    ___##cbjType##_get(__VA_ARGS__)

#endif // CBJECT_GET_H

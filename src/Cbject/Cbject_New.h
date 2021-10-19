#ifndef CBJECT_NEW_H
#define CBJECT_NEW_H

#define Cbject_New(cbjType, ...) \
    ___##cbjType##_new(__VA_ARGS__)

#endif // CBJECT_NEW_H

#ifndef CBJECT_PUBLICCONSTDECL_H
#define CBJECT_PUBLICCONSTDECL_H

#define Cbject_PublicConstDecl(className, constType, constName) \
    extern constType const className##_##constName

#endif // CBJECT_PUBLICCONSTDECL_H

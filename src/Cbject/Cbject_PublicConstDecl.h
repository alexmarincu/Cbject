#ifndef CBJECT_PUBLICCONSTDECL_H
#define CBJECT_PUBLICCONSTDECL_H

#define Cbject_PublicConstDecl(cbjType, constType, constName) \
    extern constType const cbjType##_##constName

#endif // CBJECT_PUBLICCONSTDECL_H

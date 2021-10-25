#ifndef CBJECT_PUBLICCONSTDECL_H
#define CBJECT_PUBLICCONSTDECL_H

#define Cbject_PublicConstDecl(typeName, constType, constName) \
    extern constType const typeName##_##constName

#endif // CBJECT_PUBLICCONSTDECL_H

#ifndef _CBJECTPUBLICCONSTDECL_H
#define _CBJECTPUBLICCONSTDECL_H

#define _CbjectPublicConstDecl(cbjectTypeName, type, constName) \
    extern type const cbjectTypeName##_##constName

#endif // _CBJECTPUBLICCONSTDECL_H

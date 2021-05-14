#ifndef _CBJ_PROPSTYPEDEF_H
#define _CBJ_PROPSTYPEDEF_H
#include "_Cbj_Utils.h"

#define _Cbj_PropsTypeDef_0(m_cbjType, ...) \
    typedef char m_cbjType##Props

#define _Cbj_PropsTypeDef__(m_cbjType, ...)                        \
    typedef struct m_cbjType##Props                                \
    {                                                            \
        _Cbj_Utils_forEach(_Cbj_Utils_addSemicolon, __VA_ARGS__) \
    } m_cbjType##Props

#define _Cbj_PropsTypeDef_case(m_cbjType, mCase, ...) \
    _Cbj_PropsTypeDef_##mCase (m_cbjType, __VA_ARGS__)

#define _Cbj_PropsTypeDef(m_cbjType, ...) \
    _Cbj_PropsTypeDef_case(m_cbjType, __VA_ARGS__)

#endif // _CBJ_PROPSTYPEDEF_H

#ifndef _CBJ_PARAMSTYPEDEF_H
#define _CBJ_PARAMSTYPEDEF_H
#include "_Cbj_Utils.h"

#define _Cbj_ParamsTypeDef_0(m_cbjType, ...) \
    typedef char m_cbjType##Params

#define _Cbj_ParamsTypeDef__(m_cbjType, ...)                       \
    typedef struct m_cbjType##Params                               \
    {                                                            \
        _Cbj_Utils_forEach(_Cbj_Utils_addSemicolon, __VA_ARGS__) \
    } m_cbjType##Params

#define _Cbj_ParamsTypeDef_case(m_cbjType, mCase, ...) \
    _Cbj_ParamsTypeDef_##mCase (m_cbjType, __VA_ARGS__)

#define _Cbj_ParamsTypeDef(m_cbjType, ...) \
    _Cbj_ParamsTypeDef_case(m_cbjType, __VA_ARGS__)

#endif // _CBJ_PARAMSTYPEDEF_H

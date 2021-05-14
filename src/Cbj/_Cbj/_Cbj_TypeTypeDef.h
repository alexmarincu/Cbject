#ifndef _CBJ_TYPETYPEDEF_H
#define _CBJ_TYPETYPEDEF_H

#define _Cbj_TypeTypeDef_withoutVirtFuns(m_cbjType, mParent) \
    struct m_cbjType##Type                                   \
    {                                                       \
        _##mParent##Type s;                                 \
    }

#define _Cbj_TypeTypeDef_withVirtFuns(m_cbjType, mParent) \
    struct m_cbjType##Type                                \
    {                                                    \
        _##mParent##Type s;                              \
        m_cbjType##VirtFuns virtFuns;                     \
    }

#define _Cbj_TypeTypeDef(m_cbjType, mParent, mCase) \
    _Cbj_TypeTypeDef_##mCase(m_cbjType, mParent)

#endif // _CBJ_TYPETYPEDEF_H

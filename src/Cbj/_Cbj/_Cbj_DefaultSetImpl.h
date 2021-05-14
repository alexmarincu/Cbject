#ifndef _CBJ_DEFAULTSETIMPL_H
#define _CBJ_DEFAULTSETIMPL_H

#define _Cbj_DefaultSetImpl(m_cbjType, propType, propName) \
    Set(propType, propName) { me->props.propName = propName; }

#endif // _CBJ_DEFAULTSETIMPL_H

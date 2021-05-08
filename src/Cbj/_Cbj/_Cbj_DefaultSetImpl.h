#ifndef _CBJ_DEFAULTSETIMPL_H
#define _CBJ_DEFAULTSETIMPL_H

#define _Cbj_DefaultSetImpl(cbjType, propType, propName) \
    Set(propType, propName) { me->p.propName = propName; }

#endif // _CBJ_DEFAULTSETIMPL_H

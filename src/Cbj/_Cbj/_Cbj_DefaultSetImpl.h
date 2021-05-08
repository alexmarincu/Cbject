#ifndef _CBJ_DEFAULTSETIMPL_H
#define _CBJ_DEFAULTSETIMPL_H

#define _Cbj_DefaultSetImpl(typeName, type, propName) \
    Set(type, propName) { me->p.propName = propName; }

#endif // _CBJ_DEFAULTSETIMPL_H

#ifndef _CBJECTDEFAULTSETTERIMPL_H
#define _CBJECTDEFAULTSETTERIMPL_H

#define _CbjectDefaultSetImpl(cbjectTypeName, type, memberName) \
    Set(type, memberName) { me->p.memberName = memberName; }

#endif // _CBJECTDEFAULTSETTERIMPL_H

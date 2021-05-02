#ifndef _CBJECTDEFAULTSETTERIMPL_H
#define _CBJECTDEFAULTSETTERIMPL_H

#define _CbjectDefaultSetterImpl(klassName, type, memberName) \
    Setter(type, memberName) { me->p.memberName = memberName; }

#endif // _CBJECTDEFAULTSETTERIMPL_H

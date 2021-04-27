#ifndef _CBJECTDEFAULTSETTERIMPL_H
#define _CBJECTDEFAULTSETTERIMPL_H

#define _CbjectDefaultSetterImpl(klassName, type, memberName) \
    Setter(type, memberName) { me->m.memberName = memberName; }

#endif // _CBJECTDEFAULTSETTERIMPL_H

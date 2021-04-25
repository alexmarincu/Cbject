#ifndef CBJECTDEFAULTSETTERIMPL_H
#define CBJECTDEFAULTSETTERIMPL_H

#define CbjectDefaultSetterImpl(klassName, type, memberName) \
    Setter(type, memberName) { me->m.memberName = memberName; }

#endif // CBJECTDEFAULTSETTERIMPL_H

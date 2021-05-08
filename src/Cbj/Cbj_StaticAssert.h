#ifndef CBJ_STATICASSERT_H
#define CBJ_STATICASSERT_H

#define Cbj_StaticAssert(condition, identifier) typedef char identifier[(!!(condition)) * 2 - 1]

#endif // CBJ_STATICASSERT_H

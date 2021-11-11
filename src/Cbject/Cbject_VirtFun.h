#ifndef CBJECT_VIRTFUN_H
#define CBJECT_VIRTFUN_H
#include "Cbject_Utils.h"
#include "Cbject_VirtFun.h"

/*
Cbject_VirtFun_Ptr
*/
#define Cbject_VirtFun_Ptr_caseNA(class, funReturnType, funName, ...) \
    funReturnType (*funName)(class * const me)

#define Cbject_VirtFun_Ptr_caseParams(class, funReturnType, funName, ...) \
    funReturnType (*funName)(class * const me, __VA_ARGS__)

#define Cbject_VirtFun_Ptr_x1(class, funReturnType, funName, paramsCase, ...) \
    Cbject_VirtFun_Ptr_case##paramsCase(class, funReturnType, funName, __VA_ARGS__)

#define Cbject_VirtFun_Ptr_x0(class, funReturnType, funName, ...) \
    Cbject_VirtFun_Ptr_x1(class, funReturnType, funName, __VA_ARGS__)

#define Cbject_VirtFun_Ptr(funReturnType, funName, funParamsPack) \
    Cbject_VirtFun_Ptr_x0(Type, funReturnType, funName, Cbject_Utils_unpack(funParamsPack))

/*
Cbject_VirtFun_Call
*/
#define Cbject_VirtFun_Call_caseNA(class, funName, ...) \
    typedef struct ObjectT                              \
    {                                                   \
        Cbject_Settings_maxAlign align;                 \
        ObjectType * type;                              \
    } ObjectT;                                          \
                                                        \
    return ((class##Type *)((ObjectT *)me)->type)->virtFuns.funName(me)

#define Cbject_VirtFun_Call_caseParams(class, funName, ...) \
    typedef struct ObjectT                                  \
    {                                                       \
        Cbject_Settings_maxAlign align;                     \
        ObjectType * type;                                  \
    } ObjectT;                                              \
                                                            \
    return ((class##Type *)((ObjectT *)me)->type)->virtFuns.funName(me, __VA_ARGS__)

#define Cbject_VirtFun_Call_x1(class, funName, paramsCase, ...) \
    Cbject_VirtFun_Call_case##paramsCase(class, funName, __VA_ARGS__)

#define Cbject_VirtFun_Call_x0(class, funName, ...) \
    Cbject_VirtFun_Call_x1(class, funName, __VA_ARGS__)

#define Cbject_VirtFun_Call(class, funName, funCallParamsPack) \
    Cbject_VirtFun_Call_x0(class, funName, Cbject_Utils_unpack(funCallParamsPack))

/*
Cbject_VirtFun_Impl
*/
#define Cbject_VirtFun_Impl(class, funReturnType, funName, funParamsPack, funCallParamsPack) \
    Fun(funReturnType, funName, funParamsPack) { Cbject_VirtFun_Call(class, funName, funCallParamsPack); }

#endif // CBJECT_VIRTFUN_H

#ifndef CbjectUTILITIES_H
#define CbjectUTILITIES_H
#include "CbjectSettings.h"
#include "Primitives.h"
#include <assert.h>

#define ct_assert(condition, identifier) typedef char identifier[(!!(condition)) * 2 - 1]

#define CbjectUtilities_prependComma(...) , ##__VA_ARGS__
#define CbjectUtilities_vaArgs(...) CbjectUtilities_prependComma(__VA_ARGS__)

#define CbjectUtilities_stripParentheses__(...) __VA_ARGS__
// #define CbjectUtilities_stripParentheses_(x) x
// #define CbjectUtilities_stripParentheses(arguments) \
//     CbjectUtilities_stripParentheses_(CbjectUtilities_stripParentheses__ arguments)
#define CbjectUtilities_stripParentheses(arguments) \
    CbjectUtilities_stripParentheses__ arguments

#define CbjectUtilities_feN
#define CbjectUtilities_fe0(macro)
#define CbjectUtilities_fe1(macro, x) macro(x)
#define CbjectUtilities_fe2(macro, x, ...) macro(x) CbjectUtilities_fe1(macro, __VA_ARGS__)
#define CbjectUtilities_fe3(macro, x, ...) macro(x) CbjectUtilities_fe2(macro, __VA_ARGS__)
#define CbjectUtilities_fe4(macro, x, ...) macro(x) CbjectUtilities_fe3(macro, __VA_ARGS__)
#define CbjectUtilities_fe5(macro, x, ...) macro(x) CbjectUtilities_fe4(macro, __VA_ARGS__)
#define CbjectUtilities_fe6(macro, x, ...) macro(x) CbjectUtilities_fe5(macro, __VA_ARGS__)
#define CbjectUtilities_fe7(macro, x, ...) macro(x) CbjectUtilities_fe6(macro, __VA_ARGS__)
#define CbjectUtilities_fe8(macro, x, ...) macro(x) CbjectUtilities_fe7(macro, __VA_ARGS__)
#define CbjectUtilities_fe9(macro, x, ...) macro(x) CbjectUtilities_fe8(macro, __VA_ARGS__)
#define CbjectUtilities_fe10(macro, x, ...) macro(x) CbjectUtilities_fe9(macro, __VA_ARGS__)
#define CbjectUtilities_fe11(macro, x, ...) macro(x) CbjectUtilities_fe10(macro, __VA_ARGS__)
#define CbjectUtilities_fe12(macro, x, ...) macro(x) CbjectUtilities_fe11(macro, __VA_ARGS__)
#define CbjectUtilities_fe13(macro, x, ...) macro(x) CbjectUtilities_fe12(macro, __VA_ARGS__)
#define CbjectUtilities_fe14(macro, x, ...) macro(x) CbjectUtilities_fe13(macro, __VA_ARGS__)
#define CbjectUtilities_fe15(macro, x, ...) macro(x) CbjectUtilities_fe14(macro, __VA_ARGS__)
#define CbjectUtilities_fe16(macro, x, ...) macro(x) CbjectUtilities_fe15(macro, __VA_ARGS__)
#define CbjectUtilities_fe17(macro, x, ...) macro(x) CbjectUtilities_fe16(macro, __VA_ARGS__)
#define CbjectUtilities_fe18(macro, x, ...) macro(x) CbjectUtilities_fe17(macro, __VA_ARGS__)
#define CbjectUtilities_fe19(macro, x, ...) macro(x) CbjectUtilities_fe18(macro, __VA_ARGS__)
#define CbjectUtilities_fe20(macro, x, ...) macro(x) CbjectUtilities_fe19(macro, __VA_ARGS__)
#define CbjectUtilities_fe21(macro, x, ...) macro(x) CbjectUtilities_fe20(macro, __VA_ARGS__)
#define CbjectUtilities_fe22(macro, x, ...) macro(x) CbjectUtilities_fe21(macro, __VA_ARGS__)
#define CbjectUtilities_fe23(macro, x, ...) macro(x) CbjectUtilities_fe22(macro, __VA_ARGS__)
#define CbjectUtilities_fe24(macro, x, ...) macro(x) CbjectUtilities_fe23(macro, __VA_ARGS__)
#define CbjectUtilities_fe25(macro, x, ...) macro(x) CbjectUtilities_fe24(macro, __VA_ARGS__)
#define CbjectUtilities_fe26(macro, x, ...) macro(x) CbjectUtilities_fe25(macro, __VA_ARGS__)
#define CbjectUtilities_fe27(macro, x, ...) macro(x) CbjectUtilities_fe26(macro, __VA_ARGS__)
#define CbjectUtilities_fe28(macro, x, ...) macro(x) CbjectUtilities_fe27(macro, __VA_ARGS__)
#define CbjectUtilities_fe29(macro, x, ...) macro(x) CbjectUtilities_fe28(macro, __VA_ARGS__)
#define CbjectUtilities_fe30(macro, x, ...) macro(x) CbjectUtilities_fe29(macro, __VA_ARGS__)
#define CbjectUtilities_getArgN(                                          \
    arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10,    \
    arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, \
    arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, \
    argN, ...) argN
#define CbjectUtilities_forEach(macro, ...)                                                                                                                                                                                         \
    CbjectUtilities_getArgN(                                                                                                                                                                                                        \
        CbjectUtilities_feN, ##__VA_ARGS__,                                                                                                                                                                                         \
        CbjectUtilities_fe30, CbjectUtilities_fe29, CbjectUtilities_fe28, CbjectUtilities_fe27, CbjectUtilities_fe26, CbjectUtilities_fe25, CbjectUtilities_fe24, CbjectUtilities_fe23, CbjectUtilities_fe22, CbjectUtilities_fe21, \
        CbjectUtilities_fe20, CbjectUtilities_fe19, CbjectUtilities_fe18, CbjectUtilities_fe17, CbjectUtilities_fe16, CbjectUtilities_fe15, CbjectUtilities_fe14, CbjectUtilities_fe13, CbjectUtilities_fe12, CbjectUtilities_fe11, \
        CbjectUtilities_fe10, CbjectUtilities_fe9, CbjectUtilities_fe8, CbjectUtilities_fe7, CbjectUtilities_fe6, CbjectUtilities_fe5, CbjectUtilities_fe4, CbjectUtilities_fe3, CbjectUtilities_fe2, CbjectUtilities_fe1, CbjectUtilities_fe0)(macro, ##__VA_ARGS__)

#define CbjectUtilities_addSemicolon(x) x;

#endif // CbjectUTILITIES_H

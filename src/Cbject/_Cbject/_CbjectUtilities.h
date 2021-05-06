#ifndef _CBJECTUTILITIES_H
#define _CBJECTUTILITIES_H
#include "../CbjectSettings.h"
#include "../Primitives.h"
#include <assert.h>

#define ct_assert(condition, identifier) typedef char identifier[(!!(condition)) * 2 - 1]

#define _CbjectUtilities_prependComma(...) , ##__VA_ARGS__
#define _CbjectUtilities_vaArgs(...) _CbjectUtilities_prependComma(__VA_ARGS__)

#define _CbjectUtilities_stripParentheses__(...) __VA_ARGS__
#define _CbjectUtilities_stripParentheses_(x) x
#define _CbjectUtilities_stripParentheses(args) \
    _CbjectUtilities_stripParentheses_(_CbjectUtilities_stripParentheses__ args)
// #define _CbjectUtilities_stripParentheses(args) \
//     _CbjectUtilities_stripParentheses__ args

#define _CbjectUtilities_feN
#define _CbjectUtilities_fe0(macro)
#define _CbjectUtilities_fe1(macro, x) macro(x)
#define _CbjectUtilities_fe2(macro, x, ...) macro(x) _CbjectUtilities_fe1(macro, __VA_ARGS__)
#define _CbjectUtilities_fe3(macro, x, ...) macro(x) _CbjectUtilities_fe2(macro, __VA_ARGS__)
#define _CbjectUtilities_fe4(macro, x, ...) macro(x) _CbjectUtilities_fe3(macro, __VA_ARGS__)
#define _CbjectUtilities_fe5(macro, x, ...) macro(x) _CbjectUtilities_fe4(macro, __VA_ARGS__)
#define _CbjectUtilities_fe6(macro, x, ...) macro(x) _CbjectUtilities_fe5(macro, __VA_ARGS__)
#define _CbjectUtilities_fe7(macro, x, ...) macro(x) _CbjectUtilities_fe6(macro, __VA_ARGS__)
#define _CbjectUtilities_fe8(macro, x, ...) macro(x) _CbjectUtilities_fe7(macro, __VA_ARGS__)
#define _CbjectUtilities_fe9(macro, x, ...) macro(x) _CbjectUtilities_fe8(macro, __VA_ARGS__)
#define _CbjectUtilities_fe10(macro, x, ...) macro(x) _CbjectUtilities_fe9(macro, __VA_ARGS__)
#define _CbjectUtilities_fe11(macro, x, ...) macro(x) _CbjectUtilities_fe10(macro, __VA_ARGS__)
#define _CbjectUtilities_fe12(macro, x, ...) macro(x) _CbjectUtilities_fe11(macro, __VA_ARGS__)
#define _CbjectUtilities_fe13(macro, x, ...) macro(x) _CbjectUtilities_fe12(macro, __VA_ARGS__)
#define _CbjectUtilities_fe14(macro, x, ...) macro(x) _CbjectUtilities_fe13(macro, __VA_ARGS__)
#define _CbjectUtilities_fe15(macro, x, ...) macro(x) _CbjectUtilities_fe14(macro, __VA_ARGS__)
#define _CbjectUtilities_fe16(macro, x, ...) macro(x) _CbjectUtilities_fe15(macro, __VA_ARGS__)
#define _CbjectUtilities_fe17(macro, x, ...) macro(x) _CbjectUtilities_fe16(macro, __VA_ARGS__)
#define _CbjectUtilities_fe18(macro, x, ...) macro(x) _CbjectUtilities_fe17(macro, __VA_ARGS__)
#define _CbjectUtilities_fe19(macro, x, ...) macro(x) _CbjectUtilities_fe18(macro, __VA_ARGS__)
#define _CbjectUtilities_fe20(macro, x, ...) macro(x) _CbjectUtilities_fe19(macro, __VA_ARGS__)
#define _CbjectUtilities_fe21(macro, x, ...) macro(x) _CbjectUtilities_fe20(macro, __VA_ARGS__)
#define _CbjectUtilities_fe22(macro, x, ...) macro(x) _CbjectUtilities_fe21(macro, __VA_ARGS__)
#define _CbjectUtilities_fe23(macro, x, ...) macro(x) _CbjectUtilities_fe22(macro, __VA_ARGS__)
#define _CbjectUtilities_fe24(macro, x, ...) macro(x) _CbjectUtilities_fe23(macro, __VA_ARGS__)
#define _CbjectUtilities_fe25(macro, x, ...) macro(x) _CbjectUtilities_fe24(macro, __VA_ARGS__)
#define _CbjectUtilities_fe26(macro, x, ...) macro(x) _CbjectUtilities_fe25(macro, __VA_ARGS__)
#define _CbjectUtilities_fe27(macro, x, ...) macro(x) _CbjectUtilities_fe26(macro, __VA_ARGS__)
#define _CbjectUtilities_fe28(macro, x, ...) macro(x) _CbjectUtilities_fe27(macro, __VA_ARGS__)
#define _CbjectUtilities_fe29(macro, x, ...) macro(x) _CbjectUtilities_fe28(macro, __VA_ARGS__)
#define _CbjectUtilities_fe30(macro, x, ...) macro(x) _CbjectUtilities_fe29(macro, __VA_ARGS__)
#define _CbjectUtilities_getArgN(                                         \
    arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10,    \
    arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, \
    arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, \
    argN, ...) argN
#define _CbjectUtilities_forEach(macro, ...)                                                                                                                                                                                                  \
    _CbjectUtilities_getArgN(                                                                                                                                                                                                                 \
        _CbjectUtilities_feN, ##__VA_ARGS__,                                                                                                                                                                                                  \
        _CbjectUtilities_fe30, _CbjectUtilities_fe29, _CbjectUtilities_fe28, _CbjectUtilities_fe27, _CbjectUtilities_fe26, _CbjectUtilities_fe25, _CbjectUtilities_fe24, _CbjectUtilities_fe23, _CbjectUtilities_fe22, _CbjectUtilities_fe21, \
        _CbjectUtilities_fe20, _CbjectUtilities_fe19, _CbjectUtilities_fe18, _CbjectUtilities_fe17, _CbjectUtilities_fe16, _CbjectUtilities_fe15, _CbjectUtilities_fe14, _CbjectUtilities_fe13, _CbjectUtilities_fe12, _CbjectUtilities_fe11, \
        _CbjectUtilities_fe10, _CbjectUtilities_fe9, _CbjectUtilities_fe8, _CbjectUtilities_fe7, _CbjectUtilities_fe6, _CbjectUtilities_fe5, _CbjectUtilities_fe4, _CbjectUtilities_fe3, _CbjectUtilities_fe2, _CbjectUtilities_fe1, _CbjectUtilities_fe0)(macro, ##__VA_ARGS__)

#define _CbjectUtilities_addSemicolon(x) x;

#endif // _CBJECTUTILITIES_H

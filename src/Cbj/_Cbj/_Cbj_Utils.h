#ifndef _CBJ_UTILS_H
#define _CBJ_UTILS_H

#define _Cbj_Utils_stripParentheses__(...) __VA_ARGS__

#define _Cbj_Utils_stripParentheses_(x) x

#define _Cbj_Utils_stripParentheses(mArgs) \
    _Cbj_Utils_stripParentheses_(_Cbj_Utils_stripParentheses__ mArgs)

#define _Cbj_Utils_fe1(macro, x) macro(x)
#define _Cbj_Utils_fe2(macro, x, ...) macro(x) _Cbj_Utils_fe1(macro, __VA_ARGS__)
#define _Cbj_Utils_fe3(macro, x, ...) macro(x) _Cbj_Utils_fe2(macro, __VA_ARGS__)
#define _Cbj_Utils_fe4(macro, x, ...) macro(x) _Cbj_Utils_fe3(macro, __VA_ARGS__)
#define _Cbj_Utils_fe5(macro, x, ...) macro(x) _Cbj_Utils_fe4(macro, __VA_ARGS__)
#define _Cbj_Utils_fe6(macro, x, ...) macro(x) _Cbj_Utils_fe5(macro, __VA_ARGS__)
#define _Cbj_Utils_fe7(macro, x, ...) macro(x) _Cbj_Utils_fe6(macro, __VA_ARGS__)
#define _Cbj_Utils_fe8(macro, x, ...) macro(x) _Cbj_Utils_fe7(macro, __VA_ARGS__)
#define _Cbj_Utils_fe9(macro, x, ...) macro(x) _Cbj_Utils_fe8(macro, __VA_ARGS__)
#define _Cbj_Utils_fe10(macro, x, ...) macro(x) _Cbj_Utils_fe9(macro, __VA_ARGS__)
#define _Cbj_Utils_fe11(macro, x, ...) macro(x) _Cbj_Utils_fe10(macro, __VA_ARGS__)
#define _Cbj_Utils_fe12(macro, x, ...) macro(x) _Cbj_Utils_fe11(macro, __VA_ARGS__)
#define _Cbj_Utils_fe13(macro, x, ...) macro(x) _Cbj_Utils_fe12(macro, __VA_ARGS__)
#define _Cbj_Utils_fe14(macro, x, ...) macro(x) _Cbj_Utils_fe13(macro, __VA_ARGS__)
#define _Cbj_Utils_fe15(macro, x, ...) macro(x) _Cbj_Utils_fe14(macro, __VA_ARGS__)
#define _Cbj_Utils_fe16(macro, x, ...) macro(x) _Cbj_Utils_fe15(macro, __VA_ARGS__)
#define _Cbj_Utils_fe17(macro, x, ...) macro(x) _Cbj_Utils_fe16(macro, __VA_ARGS__)
#define _Cbj_Utils_fe18(macro, x, ...) macro(x) _Cbj_Utils_fe17(macro, __VA_ARGS__)
#define _Cbj_Utils_fe19(macro, x, ...) macro(x) _Cbj_Utils_fe18(macro, __VA_ARGS__)
#define _Cbj_Utils_fe20(macro, x, ...) macro(x) _Cbj_Utils_fe19(macro, __VA_ARGS__)
#define _Cbj_Utils_fe21(macro, x, ...) macro(x) _Cbj_Utils_fe20(macro, __VA_ARGS__)
#define _Cbj_Utils_fe22(macro, x, ...) macro(x) _Cbj_Utils_fe21(macro, __VA_ARGS__)
#define _Cbj_Utils_fe23(macro, x, ...) macro(x) _Cbj_Utils_fe22(macro, __VA_ARGS__)
#define _Cbj_Utils_fe24(macro, x, ...) macro(x) _Cbj_Utils_fe23(macro, __VA_ARGS__)
#define _Cbj_Utils_fe25(macro, x, ...) macro(x) _Cbj_Utils_fe24(macro, __VA_ARGS__)
#define _Cbj_Utils_fe26(macro, x, ...) macro(x) _Cbj_Utils_fe25(macro, __VA_ARGS__)
#define _Cbj_Utils_fe27(macro, x, ...) macro(x) _Cbj_Utils_fe26(macro, __VA_ARGS__)
#define _Cbj_Utils_fe28(macro, x, ...) macro(x) _Cbj_Utils_fe27(macro, __VA_ARGS__)
#define _Cbj_Utils_fe29(macro, x, ...) macro(x) _Cbj_Utils_fe28(macro, __VA_ARGS__)
#define _Cbj_Utils_fe30(macro, x, ...) macro(x) _Cbj_Utils_fe29(macro, __VA_ARGS__)

#define _Cbj_Utils_getArgN(                                               \
    arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10,          \
    arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, \
    arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, \
    argN, ...) argN

#define _Cbj_Utils_forEach(macro, ...)                                                       \
    _Cbj_Utils_getArgN(                                                                      \
        __VA_ARGS__,                                                                         \
        _Cbj_Utils_fe30, _Cbj_Utils_fe29, _Cbj_Utils_fe28, _Cbj_Utils_fe27, _Cbj_Utils_fe26, \
        _Cbj_Utils_fe25, _Cbj_Utils_fe24, _Cbj_Utils_fe23, _Cbj_Utils_fe22, _Cbj_Utils_fe21, \
        _Cbj_Utils_fe20, _Cbj_Utils_fe19, _Cbj_Utils_fe18, _Cbj_Utils_fe17, _Cbj_Utils_fe16, \
        _Cbj_Utils_fe15, _Cbj_Utils_fe14, _Cbj_Utils_fe13, _Cbj_Utils_fe12, _Cbj_Utils_fe11, \
        _Cbj_Utils_fe10, _Cbj_Utils_fe9, _Cbj_Utils_fe8, _Cbj_Utils_fe7, _Cbj_Utils_fe6,     \
        _Cbj_Utils_fe5, _Cbj_Utils_fe4, _Cbj_Utils_fe3, _Cbj_Utils_fe2, _Cbj_Utils_fe1)(macro, __VA_ARGS__)

#define _Cbj_Utils_addSemicolon(x) x;

#endif // _CBJ_UTILS_H

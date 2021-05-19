#ifndef ___CBJ_UTILS_H
#define ___CBJ_UTILS_H

#define ___Cbj_Utils_stripParentheses__(...) __VA_ARGS__

#define ___Cbj_Utils_stripParentheses_(x) x

#define ___Cbj_Utils_stripParentheses(args) \
    ___Cbj_Utils_stripParentheses_(___Cbj_Utils_stripParentheses__ args)

#define ___Cbj_Utils_fe1(macro, x) macro(x)
#define ___Cbj_Utils_fe2(macro, x, ...) macro(x) ___Cbj_Utils_fe1(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe3(macro, x, ...) macro(x) ___Cbj_Utils_fe2(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe4(macro, x, ...) macro(x) ___Cbj_Utils_fe3(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe5(macro, x, ...) macro(x) ___Cbj_Utils_fe4(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe6(macro, x, ...) macro(x) ___Cbj_Utils_fe5(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe7(macro, x, ...) macro(x) ___Cbj_Utils_fe6(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe8(macro, x, ...) macro(x) ___Cbj_Utils_fe7(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe9(macro, x, ...) macro(x) ___Cbj_Utils_fe8(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe10(macro, x, ...) macro(x) ___Cbj_Utils_fe9(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe11(macro, x, ...) macro(x) ___Cbj_Utils_fe10(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe12(macro, x, ...) macro(x) ___Cbj_Utils_fe11(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe13(macro, x, ...) macro(x) ___Cbj_Utils_fe12(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe14(macro, x, ...) macro(x) ___Cbj_Utils_fe13(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe15(macro, x, ...) macro(x) ___Cbj_Utils_fe14(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe16(macro, x, ...) macro(x) ___Cbj_Utils_fe15(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe17(macro, x, ...) macro(x) ___Cbj_Utils_fe16(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe18(macro, x, ...) macro(x) ___Cbj_Utils_fe17(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe19(macro, x, ...) macro(x) ___Cbj_Utils_fe18(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe20(macro, x, ...) macro(x) ___Cbj_Utils_fe19(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe21(macro, x, ...) macro(x) ___Cbj_Utils_fe20(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe22(macro, x, ...) macro(x) ___Cbj_Utils_fe21(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe23(macro, x, ...) macro(x) ___Cbj_Utils_fe22(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe24(macro, x, ...) macro(x) ___Cbj_Utils_fe23(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe25(macro, x, ...) macro(x) ___Cbj_Utils_fe24(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe26(macro, x, ...) macro(x) ___Cbj_Utils_fe25(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe27(macro, x, ...) macro(x) ___Cbj_Utils_fe26(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe28(macro, x, ...) macro(x) ___Cbj_Utils_fe27(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe29(macro, x, ...) macro(x) ___Cbj_Utils_fe28(macro, __VA_ARGS__)
#define ___Cbj_Utils_fe30(macro, x, ...) macro(x) ___Cbj_Utils_fe29(macro, __VA_ARGS__)

#define ___Cbj_Utils_getArgN(                                             \
    arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10,          \
    arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, \
    arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, \
    argN, ...) argN

#define ___Cbj_Utils_forEach(macro, ...)                                                               \
    ___Cbj_Utils_getArgN(                                                                              \
        __VA_ARGS__,                                                                                   \
        ___Cbj_Utils_fe30, ___Cbj_Utils_fe29, ___Cbj_Utils_fe28, ___Cbj_Utils_fe27, ___Cbj_Utils_fe26, \
        ___Cbj_Utils_fe25, ___Cbj_Utils_fe24, ___Cbj_Utils_fe23, ___Cbj_Utils_fe22, ___Cbj_Utils_fe21, \
        ___Cbj_Utils_fe20, ___Cbj_Utils_fe19, ___Cbj_Utils_fe18, ___Cbj_Utils_fe17, ___Cbj_Utils_fe16, \
        ___Cbj_Utils_fe15, ___Cbj_Utils_fe14, ___Cbj_Utils_fe13, ___Cbj_Utils_fe12, ___Cbj_Utils_fe11, \
        ___Cbj_Utils_fe10, ___Cbj_Utils_fe9, ___Cbj_Utils_fe8, ___Cbj_Utils_fe7, ___Cbj_Utils_fe6,     \
        ___Cbj_Utils_fe5, ___Cbj_Utils_fe4, ___Cbj_Utils_fe3, ___Cbj_Utils_fe2, ___Cbj_Utils_fe1)(macro, __VA_ARGS__)

#define ___Cbj_Utils_addSemicolon(x) x;

#endif // ___CBJ_UTILS_H

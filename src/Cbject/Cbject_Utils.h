#ifndef CBJECT_UTILS_H
#define CBJECT_UTILS_H

#define Cbject_Utils_stripParentheses__(...) __VA_ARGS__

#define Cbject_Utils_stripParentheses_(x) x

#define Cbject_Utils_stripParentheses(params) \
    Cbject_Utils_stripParentheses_(Cbject_Utils_stripParentheses__ params)

#define Cbject_Utils_fe1(macro, x) macro(x)
#define Cbject_Utils_fe2(macro, x, ...) macro(x) Cbject_Utils_fe1(macro, __VA_ARGS__)
#define Cbject_Utils_fe3(macro, x, ...) macro(x) Cbject_Utils_fe2(macro, __VA_ARGS__)
#define Cbject_Utils_fe4(macro, x, ...) macro(x) Cbject_Utils_fe3(macro, __VA_ARGS__)
#define Cbject_Utils_fe5(macro, x, ...) macro(x) Cbject_Utils_fe4(macro, __VA_ARGS__)
#define Cbject_Utils_fe6(macro, x, ...) macro(x) Cbject_Utils_fe5(macro, __VA_ARGS__)
#define Cbject_Utils_fe7(macro, x, ...) macro(x) Cbject_Utils_fe6(macro, __VA_ARGS__)
#define Cbject_Utils_fe8(macro, x, ...) macro(x) Cbject_Utils_fe7(macro, __VA_ARGS__)
#define Cbject_Utils_fe9(macro, x, ...) macro(x) Cbject_Utils_fe8(macro, __VA_ARGS__)
#define Cbject_Utils_fe10(macro, x, ...) macro(x) Cbject_Utils_fe9(macro, __VA_ARGS__)
#define Cbject_Utils_fe11(macro, x, ...) macro(x) Cbject_Utils_fe10(macro, __VA_ARGS__)
#define Cbject_Utils_fe12(macro, x, ...) macro(x) Cbject_Utils_fe11(macro, __VA_ARGS__)
#define Cbject_Utils_fe13(macro, x, ...) macro(x) Cbject_Utils_fe12(macro, __VA_ARGS__)
#define Cbject_Utils_fe14(macro, x, ...) macro(x) Cbject_Utils_fe13(macro, __VA_ARGS__)
#define Cbject_Utils_fe15(macro, x, ...) macro(x) Cbject_Utils_fe14(macro, __VA_ARGS__)
#define Cbject_Utils_fe16(macro, x, ...) macro(x) Cbject_Utils_fe15(macro, __VA_ARGS__)
#define Cbject_Utils_fe17(macro, x, ...) macro(x) Cbject_Utils_fe16(macro, __VA_ARGS__)
#define Cbject_Utils_fe18(macro, x, ...) macro(x) Cbject_Utils_fe17(macro, __VA_ARGS__)
#define Cbject_Utils_fe19(macro, x, ...) macro(x) Cbject_Utils_fe18(macro, __VA_ARGS__)
#define Cbject_Utils_fe20(macro, x, ...) macro(x) Cbject_Utils_fe19(macro, __VA_ARGS__)
#define Cbject_Utils_fe21(macro, x, ...) macro(x) Cbject_Utils_fe20(macro, __VA_ARGS__)
#define Cbject_Utils_fe22(macro, x, ...) macro(x) Cbject_Utils_fe21(macro, __VA_ARGS__)
#define Cbject_Utils_fe23(macro, x, ...) macro(x) Cbject_Utils_fe22(macro, __VA_ARGS__)
#define Cbject_Utils_fe24(macro, x, ...) macro(x) Cbject_Utils_fe23(macro, __VA_ARGS__)
#define Cbject_Utils_fe25(macro, x, ...) macro(x) Cbject_Utils_fe24(macro, __VA_ARGS__)
#define Cbject_Utils_fe26(macro, x, ...) macro(x) Cbject_Utils_fe25(macro, __VA_ARGS__)
#define Cbject_Utils_fe27(macro, x, ...) macro(x) Cbject_Utils_fe26(macro, __VA_ARGS__)
#define Cbject_Utils_fe28(macro, x, ...) macro(x) Cbject_Utils_fe27(macro, __VA_ARGS__)
#define Cbject_Utils_fe29(macro, x, ...) macro(x) Cbject_Utils_fe28(macro, __VA_ARGS__)
#define Cbject_Utils_fe30(macro, x, ...) macro(x) Cbject_Utils_fe29(macro, __VA_ARGS__)

#define Cbject_Utils_getArgN(                                             \
    arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10,          \
    arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, \
    arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, \
    argN, ...) argN

#define Cbject_Utils_forEach(macro, ...)                                                               \
    Cbject_Utils_getArgN(                                                                              \
        __VA_ARGS__,                                                                                   \
        Cbject_Utils_fe30, Cbject_Utils_fe29, Cbject_Utils_fe28, Cbject_Utils_fe27, Cbject_Utils_fe26, \
        Cbject_Utils_fe25, Cbject_Utils_fe24, Cbject_Utils_fe23, Cbject_Utils_fe22, Cbject_Utils_fe21, \
        Cbject_Utils_fe20, Cbject_Utils_fe19, Cbject_Utils_fe18, Cbject_Utils_fe17, Cbject_Utils_fe16, \
        Cbject_Utils_fe15, Cbject_Utils_fe14, Cbject_Utils_fe13, Cbject_Utils_fe12, Cbject_Utils_fe11, \
        Cbject_Utils_fe10, Cbject_Utils_fe9, Cbject_Utils_fe8, Cbject_Utils_fe7, Cbject_Utils_fe6,     \
        Cbject_Utils_fe5, Cbject_Utils_fe4, Cbject_Utils_fe3, Cbject_Utils_fe2, Cbject_Utils_fe1)(macro, __VA_ARGS__)

#define Cbject_Utils_addSemicolon(x) x;

#endif // CBJECT_UTILS_H

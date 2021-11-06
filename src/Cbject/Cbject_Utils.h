#ifndef CBJECT_UTILS_H
#define CBJECT_UTILS_H

#define Cbject_Utils_unpack_args(...) __VA_ARGS__

#define Cbject_Utils_unpack_x1(x) x

#define Cbject_Utils_unpack(args) \
    Cbject_Utils_unpack_x1(Cbject_Utils_unpack_args args)

#define Cbject_Utils_forEach0(macro, x) macro(x)
#define Cbject_Utils_forEach1(macro, x, ...) macro(x) Cbject_Utils_forEach0(macro, __VA_ARGS__)
#define Cbject_Utils_forEach2(macro, x, ...) macro(x) Cbject_Utils_forEach1(macro, __VA_ARGS__)
#define Cbject_Utils_forEach3(macro, x, ...) macro(x) Cbject_Utils_forEach2(macro, __VA_ARGS__)
#define Cbject_Utils_forEach4(macro, x, ...) macro(x) Cbject_Utils_forEach3(macro, __VA_ARGS__)
#define Cbject_Utils_forEach5(macro, x, ...) macro(x) Cbject_Utils_forEach4(macro, __VA_ARGS__)
#define Cbject_Utils_forEach6(macro, x, ...) macro(x) Cbject_Utils_forEach5(macro, __VA_ARGS__)
#define Cbject_Utils_forEach7(macro, x, ...) macro(x) Cbject_Utils_forEach6(macro, __VA_ARGS__)
#define Cbject_Utils_forEach8(macro, x, ...) macro(x) Cbject_Utils_forEach7(macro, __VA_ARGS__)
#define Cbject_Utils_forEach9(macro, x, ...) macro(x) Cbject_Utils_forEach8(macro, __VA_ARGS__)
#define Cbject_Utils_forEach10(macro, x, ...) macro(x) Cbject_Utils_forEach9(macro, __VA_ARGS__)
#define Cbject_Utils_forEach11(macro, x, ...) macro(x) Cbject_Utils_forEach10(macro, __VA_ARGS__)
#define Cbject_Utils_forEach12(macro, x, ...) macro(x) Cbject_Utils_forEach11(macro, __VA_ARGS__)
#define Cbject_Utils_forEach13(macro, x, ...) macro(x) Cbject_Utils_forEach12(macro, __VA_ARGS__)
#define Cbject_Utils_forEach14(macro, x, ...) macro(x) Cbject_Utils_forEach13(macro, __VA_ARGS__)
#define Cbject_Utils_forEach15(macro, x, ...) macro(x) Cbject_Utils_forEach14(macro, __VA_ARGS__)
#define Cbject_Utils_forEach16(macro, x, ...) macro(x) Cbject_Utils_forEach15(macro, __VA_ARGS__)
#define Cbject_Utils_forEach17(macro, x, ...) macro(x) Cbject_Utils_forEach16(macro, __VA_ARGS__)
#define Cbject_Utils_forEach18(macro, x, ...) macro(x) Cbject_Utils_forEach17(macro, __VA_ARGS__)
#define Cbject_Utils_forEach19(macro, x, ...) macro(x) Cbject_Utils_forEach18(macro, __VA_ARGS__)
#define Cbject_Utils_forEach20(macro, x, ...) macro(x) Cbject_Utils_forEach19(macro, __VA_ARGS__)
#define Cbject_Utils_forEach21(macro, x, ...) macro(x) Cbject_Utils_forEach20(macro, __VA_ARGS__)
#define Cbject_Utils_forEach22(macro, x, ...) macro(x) Cbject_Utils_forEach21(macro, __VA_ARGS__)
#define Cbject_Utils_forEach23(macro, x, ...) macro(x) Cbject_Utils_forEach22(macro, __VA_ARGS__)
#define Cbject_Utils_forEach24(macro, x, ...) macro(x) Cbject_Utils_forEach23(macro, __VA_ARGS__)
#define Cbject_Utils_forEach25(macro, x, ...) macro(x) Cbject_Utils_forEach24(macro, __VA_ARGS__)
#define Cbject_Utils_forEach26(macro, x, ...) macro(x) Cbject_Utils_forEach25(macro, __VA_ARGS__)
#define Cbject_Utils_forEach27(macro, x, ...) macro(x) Cbject_Utils_forEach26(macro, __VA_ARGS__)
#define Cbject_Utils_forEach28(macro, x, ...) macro(x) Cbject_Utils_forEach27(macro, __VA_ARGS__)
#define Cbject_Utils_forEach29(macro, x, ...) macro(x) Cbject_Utils_forEach28(macro, __VA_ARGS__)
#define Cbject_Utils_forEach30(macro, x, ...) macro(x) Cbject_Utils_forEach29(macro, __VA_ARGS__)
#define Cbject_Utils_forEach31(macro, x, ...) macro(x) Cbject_Utils_forEach30(macro, __VA_ARGS__)
#define Cbject_Utils_forEach32(macro, x, ...) macro(x) Cbject_Utils_forEach31(macro, __VA_ARGS__)
#define Cbject_Utils_forEach33(macro, x, ...) macro(x) Cbject_Utils_forEach32(macro, __VA_ARGS__)
#define Cbject_Utils_forEach34(macro, x, ...) macro(x) Cbject_Utils_forEach33(macro, __VA_ARGS__)
#define Cbject_Utils_forEach35(macro, x, ...) macro(x) Cbject_Utils_forEach34(macro, __VA_ARGS__)
#define Cbject_Utils_forEach36(macro, x, ...) macro(x) Cbject_Utils_forEach35(macro, __VA_ARGS__)
#define Cbject_Utils_forEach37(macro, x, ...) macro(x) Cbject_Utils_forEach36(macro, __VA_ARGS__)
#define Cbject_Utils_forEach38(macro, x, ...) macro(x) Cbject_Utils_forEach37(macro, __VA_ARGS__)
#define Cbject_Utils_forEach39(macro, x, ...) macro(x) Cbject_Utils_forEach38(macro, __VA_ARGS__)
#define Cbject_Utils_forEach40(macro, x, ...) macro(x) Cbject_Utils_forEach39(macro, __VA_ARGS__)
#define Cbject_Utils_forEach41(macro, x, ...) macro(x) Cbject_Utils_forEach40(macro, __VA_ARGS__)
#define Cbject_Utils_forEach42(macro, x, ...) macro(x) Cbject_Utils_forEach41(macro, __VA_ARGS__)
#define Cbject_Utils_forEach43(macro, x, ...) macro(x) Cbject_Utils_forEach42(macro, __VA_ARGS__)
#define Cbject_Utils_forEach44(macro, x, ...) macro(x) Cbject_Utils_forEach43(macro, __VA_ARGS__)
#define Cbject_Utils_forEach45(macro, x, ...) macro(x) Cbject_Utils_forEach44(macro, __VA_ARGS__)
#define Cbject_Utils_forEach46(macro, x, ...) macro(x) Cbject_Utils_forEach45(macro, __VA_ARGS__)
#define Cbject_Utils_forEach47(macro, x, ...) macro(x) Cbject_Utils_forEach46(macro, __VA_ARGS__)
#define Cbject_Utils_forEach48(macro, x, ...) macro(x) Cbject_Utils_forEach47(macro, __VA_ARGS__)
#define Cbject_Utils_forEach49(macro, x, ...) macro(x) Cbject_Utils_forEach48(macro, __VA_ARGS__)
#define Cbject_Utils_forEach50(macro, x, ...) macro(x) Cbject_Utils_forEach49(macro, __VA_ARGS__)
#define Cbject_Utils_forEach51(macro, x, ...) macro(x) Cbject_Utils_forEach50(macro, __VA_ARGS__)
#define Cbject_Utils_forEach52(macro, x, ...) macro(x) Cbject_Utils_forEach51(macro, __VA_ARGS__)
#define Cbject_Utils_forEach53(macro, x, ...) macro(x) Cbject_Utils_forEach52(macro, __VA_ARGS__)
#define Cbject_Utils_forEach54(macro, x, ...) macro(x) Cbject_Utils_forEach53(macro, __VA_ARGS__)
#define Cbject_Utils_forEach55(macro, x, ...) macro(x) Cbject_Utils_forEach54(macro, __VA_ARGS__)
#define Cbject_Utils_forEach56(macro, x, ...) macro(x) Cbject_Utils_forEach55(macro, __VA_ARGS__)
#define Cbject_Utils_forEach57(macro, x, ...) macro(x) Cbject_Utils_forEach56(macro, __VA_ARGS__)
#define Cbject_Utils_forEach58(macro, x, ...) macro(x) Cbject_Utils_forEach57(macro, __VA_ARGS__)
#define Cbject_Utils_forEach59(macro, x, ...) macro(x) Cbject_Utils_forEach58(macro, __VA_ARGS__)
#define Cbject_Utils_forEach60(macro, x, ...) macro(x) Cbject_Utils_forEach59(macro, __VA_ARGS__)
#define Cbject_Utils_forEach61(macro, x, ...) macro(x) Cbject_Utils_forEach60(macro, __VA_ARGS__)
#define Cbject_Utils_forEach62(macro, x, ...) macro(x) Cbject_Utils_forEach61(macro, __VA_ARGS__)
#define Cbject_Utils_forEach63(macro, x, ...) macro(x) Cbject_Utils_forEach62(macro, __VA_ARGS__)
#define Cbject_Utils_forEach64(macro, x, ...) macro(x) Cbject_Utils_forEach63(macro, __VA_ARGS__)
#define Cbject_Utils_forEach65(macro, x, ...) macro(x) Cbject_Utils_forEach64(macro, __VA_ARGS__)
#define Cbject_Utils_forEach66(macro, x, ...) macro(x) Cbject_Utils_forEach65(macro, __VA_ARGS__)
#define Cbject_Utils_forEach67(macro, x, ...) macro(x) Cbject_Utils_forEach66(macro, __VA_ARGS__)
#define Cbject_Utils_forEach68(macro, x, ...) macro(x) Cbject_Utils_forEach67(macro, __VA_ARGS__)
#define Cbject_Utils_forEach69(macro, x, ...) macro(x) Cbject_Utils_forEach68(macro, __VA_ARGS__)
#define Cbject_Utils_forEach70(macro, x, ...) macro(x) Cbject_Utils_forEach69(macro, __VA_ARGS__)
#define Cbject_Utils_forEach71(macro, x, ...) macro(x) Cbject_Utils_forEach70(macro, __VA_ARGS__)
#define Cbject_Utils_forEach72(macro, x, ...) macro(x) Cbject_Utils_forEach71(macro, __VA_ARGS__)
#define Cbject_Utils_forEach73(macro, x, ...) macro(x) Cbject_Utils_forEach72(macro, __VA_ARGS__)
#define Cbject_Utils_forEach74(macro, x, ...) macro(x) Cbject_Utils_forEach73(macro, __VA_ARGS__)
#define Cbject_Utils_forEach75(macro, x, ...) macro(x) Cbject_Utils_forEach74(macro, __VA_ARGS__)
#define Cbject_Utils_forEach76(macro, x, ...) macro(x) Cbject_Utils_forEach75(macro, __VA_ARGS__)
#define Cbject_Utils_forEach77(macro, x, ...) macro(x) Cbject_Utils_forEach76(macro, __VA_ARGS__)
#define Cbject_Utils_forEach78(macro, x, ...) macro(x) Cbject_Utils_forEach77(macro, __VA_ARGS__)
#define Cbject_Utils_forEach79(macro, x, ...) macro(x) Cbject_Utils_forEach78(macro, __VA_ARGS__)
#define Cbject_Utils_forEach80(macro, x, ...) macro(x) Cbject_Utils_forEach79(macro, __VA_ARGS__)
#define Cbject_Utils_forEach81(macro, x, ...) macro(x) Cbject_Utils_forEach80(macro, __VA_ARGS__)
#define Cbject_Utils_forEach82(macro, x, ...) macro(x) Cbject_Utils_forEach81(macro, __VA_ARGS__)
#define Cbject_Utils_forEach83(macro, x, ...) macro(x) Cbject_Utils_forEach82(macro, __VA_ARGS__)
#define Cbject_Utils_forEach84(macro, x, ...) macro(x) Cbject_Utils_forEach83(macro, __VA_ARGS__)
#define Cbject_Utils_forEach85(macro, x, ...) macro(x) Cbject_Utils_forEach84(macro, __VA_ARGS__)
#define Cbject_Utils_forEach86(macro, x, ...) macro(x) Cbject_Utils_forEach85(macro, __VA_ARGS__)
#define Cbject_Utils_forEach87(macro, x, ...) macro(x) Cbject_Utils_forEach86(macro, __VA_ARGS__)
#define Cbject_Utils_forEach88(macro, x, ...) macro(x) Cbject_Utils_forEach87(macro, __VA_ARGS__)
#define Cbject_Utils_forEach89(macro, x, ...) macro(x) Cbject_Utils_forEach88(macro, __VA_ARGS__)
#define Cbject_Utils_forEach90(macro, x, ...) macro(x) Cbject_Utils_forEach89(macro, __VA_ARGS__)
#define Cbject_Utils_forEach91(macro, x, ...) macro(x) Cbject_Utils_forEach90(macro, __VA_ARGS__)
#define Cbject_Utils_forEach92(macro, x, ...) macro(x) Cbject_Utils_forEach91(macro, __VA_ARGS__)
#define Cbject_Utils_forEach93(macro, x, ...) macro(x) Cbject_Utils_forEach92(macro, __VA_ARGS__)
#define Cbject_Utils_forEach94(macro, x, ...) macro(x) Cbject_Utils_forEach93(macro, __VA_ARGS__)
#define Cbject_Utils_forEach95(macro, x, ...) macro(x) Cbject_Utils_forEach94(macro, __VA_ARGS__)
#define Cbject_Utils_forEach96(macro, x, ...) macro(x) Cbject_Utils_forEach95(macro, __VA_ARGS__)
#define Cbject_Utils_forEach97(macro, x, ...) macro(x) Cbject_Utils_forEach96(macro, __VA_ARGS__)
#define Cbject_Utils_forEach98(macro, x, ...) macro(x) Cbject_Utils_forEach97(macro, __VA_ARGS__)
#define Cbject_Utils_forEach99(macro, x, ...) macro(x) Cbject_Utils_forEach98(macro, __VA_ARGS__)

#define Cbject_Utils_getArgN( \
    arg0,                     \
    arg1,                     \
    arg2,                     \
    arg3,                     \
    arg4,                     \
    arg5,                     \
    arg6,                     \
    arg7,                     \
    arg8,                     \
    arg9,                     \
    arg10,                    \
    arg11,                    \
    arg12,                    \
    arg13,                    \
    arg14,                    \
    arg15,                    \
    arg16,                    \
    arg17,                    \
    arg18,                    \
    arg19,                    \
    arg20,                    \
    arg21,                    \
    arg22,                    \
    arg23,                    \
    arg24,                    \
    arg25,                    \
    arg26,                    \
    arg27,                    \
    arg28,                    \
    arg29,                    \
    arg30,                    \
    arg31,                    \
    arg32,                    \
    arg33,                    \
    arg34,                    \
    arg35,                    \
    arg36,                    \
    arg37,                    \
    arg38,                    \
    arg39,                    \
    arg40,                    \
    arg41,                    \
    arg42,                    \
    arg43,                    \
    arg44,                    \
    arg45,                    \
    arg46,                    \
    arg47,                    \
    arg48,                    \
    arg49,                    \
    arg50,                    \
    arg51,                    \
    arg52,                    \
    arg53,                    \
    arg54,                    \
    arg55,                    \
    arg56,                    \
    arg57,                    \
    arg58,                    \
    arg59,                    \
    arg60,                    \
    arg61,                    \
    arg62,                    \
    arg63,                    \
    arg64,                    \
    arg65,                    \
    arg66,                    \
    arg67,                    \
    arg68,                    \
    arg69,                    \
    arg70,                    \
    arg71,                    \
    arg72,                    \
    arg73,                    \
    arg74,                    \
    arg75,                    \
    arg76,                    \
    arg77,                    \
    arg78,                    \
    arg79,                    \
    arg80,                    \
    arg81,                    \
    arg82,                    \
    arg83,                    \
    arg84,                    \
    arg85,                    \
    arg86,                    \
    arg87,                    \
    arg88,                    \
    arg89,                    \
    arg90,                    \
    arg91,                    \
    arg92,                    \
    arg93,                    \
    arg94,                    \
    arg95,                    \
    arg96,                    \
    arg97,                    \
    arg98,                    \
    arg99,                    \
    argN, ...) argN

#define Cbject_Utils_forEach(macro, ...) \
    Cbject_Utils_getArgN(                \
        __VA_ARGS__,                     \
        Cbject_Utils_forEach99,          \
        Cbject_Utils_forEach98,          \
        Cbject_Utils_forEach97,          \
        Cbject_Utils_forEach96,          \
        Cbject_Utils_forEach95,          \
        Cbject_Utils_forEach94,          \
        Cbject_Utils_forEach93,          \
        Cbject_Utils_forEach92,          \
        Cbject_Utils_forEach91,          \
        Cbject_Utils_forEach90,          \
        Cbject_Utils_forEach89,          \
        Cbject_Utils_forEach88,          \
        Cbject_Utils_forEach87,          \
        Cbject_Utils_forEach86,          \
        Cbject_Utils_forEach85,          \
        Cbject_Utils_forEach84,          \
        Cbject_Utils_forEach83,          \
        Cbject_Utils_forEach82,          \
        Cbject_Utils_forEach81,          \
        Cbject_Utils_forEach80,          \
        Cbject_Utils_forEach79,          \
        Cbject_Utils_forEach78,          \
        Cbject_Utils_forEach77,          \
        Cbject_Utils_forEach76,          \
        Cbject_Utils_forEach75,          \
        Cbject_Utils_forEach74,          \
        Cbject_Utils_forEach73,          \
        Cbject_Utils_forEach72,          \
        Cbject_Utils_forEach71,          \
        Cbject_Utils_forEach70,          \
        Cbject_Utils_forEach69,          \
        Cbject_Utils_forEach68,          \
        Cbject_Utils_forEach67,          \
        Cbject_Utils_forEach66,          \
        Cbject_Utils_forEach65,          \
        Cbject_Utils_forEach64,          \
        Cbject_Utils_forEach63,          \
        Cbject_Utils_forEach62,          \
        Cbject_Utils_forEach61,          \
        Cbject_Utils_forEach60,          \
        Cbject_Utils_forEach59,          \
        Cbject_Utils_forEach58,          \
        Cbject_Utils_forEach57,          \
        Cbject_Utils_forEach56,          \
        Cbject_Utils_forEach55,          \
        Cbject_Utils_forEach54,          \
        Cbject_Utils_forEach53,          \
        Cbject_Utils_forEach52,          \
        Cbject_Utils_forEach51,          \
        Cbject_Utils_forEach50,          \
        Cbject_Utils_forEach49,          \
        Cbject_Utils_forEach48,          \
        Cbject_Utils_forEach47,          \
        Cbject_Utils_forEach46,          \
        Cbject_Utils_forEach45,          \
        Cbject_Utils_forEach44,          \
        Cbject_Utils_forEach43,          \
        Cbject_Utils_forEach42,          \
        Cbject_Utils_forEach41,          \
        Cbject_Utils_forEach40,          \
        Cbject_Utils_forEach39,          \
        Cbject_Utils_forEach38,          \
        Cbject_Utils_forEach37,          \
        Cbject_Utils_forEach36,          \
        Cbject_Utils_forEach35,          \
        Cbject_Utils_forEach34,          \
        Cbject_Utils_forEach33,          \
        Cbject_Utils_forEach32,          \
        Cbject_Utils_forEach31,          \
        Cbject_Utils_forEach30,          \
        Cbject_Utils_forEach29,          \
        Cbject_Utils_forEach28,          \
        Cbject_Utils_forEach27,          \
        Cbject_Utils_forEach26,          \
        Cbject_Utils_forEach25,          \
        Cbject_Utils_forEach24,          \
        Cbject_Utils_forEach23,          \
        Cbject_Utils_forEach22,          \
        Cbject_Utils_forEach21,          \
        Cbject_Utils_forEach20,          \
        Cbject_Utils_forEach19,          \
        Cbject_Utils_forEach18,          \
        Cbject_Utils_forEach17,          \
        Cbject_Utils_forEach16,          \
        Cbject_Utils_forEach15,          \
        Cbject_Utils_forEach14,          \
        Cbject_Utils_forEach13,          \
        Cbject_Utils_forEach12,          \
        Cbject_Utils_forEach11,          \
        Cbject_Utils_forEach10,          \
        Cbject_Utils_forEach9,           \
        Cbject_Utils_forEach8,           \
        Cbject_Utils_forEach7,           \
        Cbject_Utils_forEach6,           \
        Cbject_Utils_forEach5,           \
        Cbject_Utils_forEach4,           \
        Cbject_Utils_forEach3,           \
        Cbject_Utils_forEach2,           \
        Cbject_Utils_forEach1,           \
        Cbject_Utils_forEach0)(macro, __VA_ARGS__)

#define Cbject_Utils_addSemicolon(x) x;

#endif // CBJECT_UTILS_H

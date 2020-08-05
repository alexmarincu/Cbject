#ifndef COBJECTUTILITIES_H
#define COBJECTUTILITIES_H
#include "CObjectSettings.h"
#include "Primitives.h"
#include <assert.h>

#define ct_assert(condition, message) typedef char ct_assert_##message[(!!(condition)) * 2 - 1]

#define z_va_args_(...) , ##__VA_ARGS__
#define z_va_args(...) z_va_args_(__VA_ARGS__)

#define z_strip_parentheses__(...) __VA_ARGS__
#define z_strip_parentheses_(x) x
#define z_strip_parentheses(arguments) z_strip_parentheses_(z_strip_parentheses__ arguments)

#define z_fe_1(macro, x) macro(x)
#define z_fe_2(macro, x, ...) macro(x) z_fe_1(macro, __VA_ARGS__)
#define z_fe_3(macro, x, ...) macro(x) z_fe_2(macro, __VA_ARGS__)
#define z_fe_4(macro, x, ...) macro(x) z_fe_3(macro, __VA_ARGS__)
#define z_fe_5(macro, x, ...) macro(x) z_fe_4(macro, __VA_ARGS__)
#define z_fe_6(macro, x, ...) macro(x) z_fe_5(macro, __VA_ARGS__)
#define z_fe_7(macro, x, ...) macro(x) z_fe_6(macro, __VA_ARGS__)
#define z_fe_8(macro, x, ...) macro(x) z_fe_7(macro, __VA_ARGS__)
#define z_fe_9(macro, x, ...) macro(x) z_fe_8(macro, __VA_ARGS__)
#define z_fe_10(macro, x, ...) macro(x) z_fe_9(macro, __VA_ARGS__)
#define z_fe_11(macro, x, ...) macro(x) z_fe_10(macro, __VA_ARGS__)
#define z_fe_12(macro, x, ...) macro(x) z_fe_11(macro, __VA_ARGS__)
#define z_fe_13(macro, x, ...) macro(x) z_fe_12(macro, __VA_ARGS__)
#define z_fe_14(macro, x, ...) macro(x) z_fe_13(macro, __VA_ARGS__)
#define z_fe_15(macro, x, ...) macro(x) z_fe_14(macro, __VA_ARGS__)
#define z_fe_16(macro, x, ...) macro(x) z_fe_15(macro, __VA_ARGS__)
#define z_fe_17(macro, x, ...) macro(x) z_fe_16(macro, __VA_ARGS__)
#define z_fe_18(macro, x, ...) macro(x) z_fe_17(macro, __VA_ARGS__)
#define z_fe_19(macro, x, ...) macro(x) z_fe_18(macro, __VA_ARGS__)
#define z_fe_20(macro, x, ...) macro(x) z_fe_19(macro, __VA_ARGS__)
#define z_fe_21(macro, x, ...) macro(x) z_fe_20(macro, __VA_ARGS__)
#define z_fe_22(macro, x, ...) macro(x) z_fe_21(macro, __VA_ARGS__)
#define z_fe_23(macro, x, ...) macro(x) z_fe_22(macro, __VA_ARGS__)
#define z_fe_24(macro, x, ...) macro(x) z_fe_23(macro, __VA_ARGS__)
#define z_fe_25(macro, x, ...) macro(x) z_fe_24(macro, __VA_ARGS__)
#define z_fe_26(macro, x, ...) macro(x) z_fe_25(macro, __VA_ARGS__)
#define z_fe_27(macro, x, ...) macro(x) z_fe_26(macro, __VA_ARGS__)
#define z_fe_28(macro, x, ...) macro(x) z_fe_27(macro, __VA_ARGS__)
#define z_fe_29(macro, x, ...) macro(x) z_fe_28(macro, __VA_ARGS__)
#define z_fe_30(macro, x, ...) macro(x) z_fe_29(macro, __VA_ARGS__)
#define z_get_arg_n(                                                      \
    arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10,          \
    arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, \
    arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, \
    argN, ...) argN
#define z_for_each(macro, ...)                                                                    \
    z_get_arg_n(                                                                                  \
        __VA_ARGS__,                                                                              \
        z_fe_30, z_fe_29, z_fe_28, z_fe_27, z_fe_26, z_fe_25, z_fe_24, z_fe_23, z_fe_22, z_fe_21, \
        z_fe_20, z_fe_19, z_fe_18, z_fe_17, z_fe_16, z_fe_15, z_fe_14, z_fe_13, z_fe_12, z_fe_11, \
        z_fe_10, z_fe_9, z_fe_8, z_fe_7, z_fe_6, z_fe_5, z_fe_4, z_fe_3, z_fe_2, z_fe_1)(macro, __VA_ARGS__)

#define z_add_semicolon(x) x;

#define z_params(className, ...)                                                             \
    typedef struct className className;                                                      \
                                                                                             \
    typedef struct className##Params                                                         \
    {                                                                                        \
        z_for_each(z_add_semicolon, __VA_ARGS__)                                             \
    } className##Params;                                                                     \
                                                                                             \
    UInt8 className##Class_size();                                                           \
    Void className##_init(className * const this_, className##Params const * const params_); \
    Void className##_terminate(className * const this_)

#define z_get_object_decl(className) className * get_##className(className##Params const * const params_)
#define z_new_object_decl(className) className * new_##className(className##Params const * const params_)
#define z_delete_object_decl(className) className * delete_##className(className * this_)

#define z_abstract_class_params_(className, ...) z_params(className, __VA_ARGS__)
#define z_abstract_class_params(className, ...) z_abstract_class_params_(className, __VA_ARGS__)
#define abstract_class_params(...) z_abstract_class_params(Class_, __VA_ARGS__)

#define z_singleton_class_params_(className, ...) \
    z_params(className, __VA_ARGS__);             \
    className * className##_instance()
#define z_singleton_class_params(className, ...) z_singleton_class_params_(className, __VA_ARGS__)
#define singleton_class_params(...) z_singleton_class_params(Class_, __VA_ARGS__)

#if CObject_useStaticPool == true
    #if CObject_useHeap == true
        #define z_class_params_(className, ...) \
            z_params(className, __VA_ARGS__);   \
            z_get_object_decl(className);       \
            z_new_object_decl(className);       \
            z_delete_object_decl(className)
    #else
        #define z_class_params_(className, ...) \
            z_params(className, __VA_ARGS__);   \
            z_get_object_decl(className)
    #endif
#else
    #if CObject_useHeap == true
        #define z_class_params_(className, ...) \
            z_params(className, __VA_ARGS__);   \
            z_new_object_decl(className)        \
                z_delete_object_decl(className)
    #else
        #define z_class_params_(className, ...) z_params(className, __VA_ARGS__)
    #endif
#endif
#define z_class_params(className, ...) z_class_params_(className, __VA_ARGS__)
#define class_params(...) z_class_params(Class_, __VA_ARGS__)

#if CObject_useStaticPool == true
    #define z_class_pool_size_(className, poolSize) \
        enum                                        \
        {                                           \
            className##_poolSize = poolSize         \
        }
    #define z_class_pool_size(className, poolSize) z_class_pool_size_(className, poolSize)
    #define class_pool_size(poolSize) z_class_pool_size(Class_, poolSize)
#endif

#define z_class(className, superClassName) \
    typedef struct className##Class        \
    {                                      \
        superClassName##Class super;       \
    } className##Class;                    \
                                           \
    className##Class const * const className##Class_instance()

#define z_members(className, superClassName, ...) \
    struct className                              \
    {                                             \
        superClassName super;                     \
        z_for_each(z_add_semicolon, __VA_ARGS__)  \
    }

#define z_class_members_(className, superClassName, ...) \
    z_members(className, superClassName, __VA_ARGS__);   \
    z_class(className, superClassName)
#define z_class_members(className, superClassName, ...) z_class_members_(className, superClassName, __VA_ARGS__)
#define class_members(...) z_class_members(Class_, super_Class_, __VA_ARGS__)

#define z_constant_(className, type, ...) type const className##_##__VA_ARGS__
#define z_constant(className, type, ...) z_constant_(className, type, __VA_ARGS__)
#define constant(type, ...) z_constant(Class_, type, __VA_ARGS__)
#define z_strip_parentheses_and_apply_constant(constSignature) constant constSignature;
#define constants(...) z_for_each(z_strip_parentheses_and_apply_constant, __VA_ARGS__)

#define z_public_constant_(className, type, constName) extern type const className##_##constName
#define z_public_constant(className, type, constName) z_public_constant_(className, type, constName)
#define public_constant(type, constName) z_public_constant(Class_, type, constName)
#define z_strip_parentheses_and_apply_public_constant(constSignature) public_constant constSignature;
#define public_constants(...) z_for_each(z_strip_parentheses_and_apply_public_constant, __VA_ARGS__)

#define z_private_constant_(className, type, ...) static type const className##_##__VA_ARGS__
#define z_private_constant(className, type, ...) z_private_constant_(className, type, __VA_ARGS__)
#define private_constant(type, ...) z_private_constant(Class_, type, __VA_ARGS__)
#define z_strip_parentheses_and_apply_private_constant(constSignature) private_constant constSignature;
#define private_constants(className, ...) z_for_each(z_strip_parentheses_and_apply_private_constant, __VA_ARGS__)

#define z_virtual_class_members_(className, superClassName, ...) z_members(className, superClassName, __VA_ARGS__)
#define z_virtual_class_members(className, superClassName, ...) z_virtual_class_members_(className, superClassName, __VA_ARGS__)
#define virtual_class_members(...) z_virtual_class_members(Class_, super_Class_, __VA_ARGS__)

#define z_data_class_(className, ...)            \
    typedef struct className                     \
    {                                            \
        z_for_each(z_add_semicolon, __VA_ARGS__) \
    } className
#define z_data_class(className, ...) z_data_class_(className, __VA_ARGS__)
#define data_class(...) z_data_class(Class_, __VA_ARGS__)

#define z_prepend_class_name_and_add_comma__(className, valueName) className##_##valueName,
#define z_prepend_class_name_and_add_comma_(className, valueName) z_prepend_class_name_and_add_comma__(className, valueName)
#define z_prepend_class_name_and_add_comma(valueName) z_prepend_class_name_and_add_comma_(Class_, valueName)

#define z_enum_class_(className, ...)                               \
    typedef enum className                                          \
    {                                                               \
        z_for_each(z_prepend_class_name_and_add_comma, __VA_ARGS__) \
    } className
#define z_enum_class(className, ...) z_enum_class_(className, __VA_ARGS__)
#define enum_class(...) z_enum_class(Class_, __VA_ARGS__)

#define z_fun_(className, type, functionName, arguments) \
    type className##_##functionName(className * const this_ z_va_args(z_strip_parentheses(arguments)))
#define z_fun(className, type, functionName, arguments) z_fun_(className, type, functionName, arguments)
#define fun(type, functionName, arguments) z_fun(Class_, type, functionName, arguments)
#define z_strip_parentheses_and_apply_fun(funSignature) fun funSignature;
#define functions(...) z_for_each(z_strip_parentheses_and_apply_fun, __VA_ARGS__)

#define z_private_fun_(className, type, functionName, arguments) \
    static type className##_##functionName(className * const this_ z_va_args(z_strip_parentheses(arguments)))
#define z_private_fun(className, type, functionName, arguments) z_private_fun_(className, type, functionName, arguments)
#define private_fun(type, functionName, arguments) z_private_fun(Class_, type, functionName, arguments)
#define z_strip_parentheses_and_apply_private_fun(funSignature) private_fun funSignature;
#define private_functions(...) z_for_each(z_strip_parentheses_and_apply_private_fun, __VA_ARGS__)

#define z_virtual_fun_pt__(className, type, functionName, arguments) \
    type (*functionName)(className * const this_ z_va_args(z_strip_parentheses(arguments)))
#define z_virtual_fun_pt_(className, type, functionName, arguments) z_virtual_fun_pt__(className, type, functionName, arguments)
#define z_virtual_fun_pt(type, functionName, arguments) z_virtual_fun_pt_(Class_, type, functionName, arguments)
#define z_strip_parentheses_and_apply_virtual_fun_pt(funSignature) z_virtual_fun_pt funSignature;

#define z_virtual_call(className, functionName, params) \
    return ((className##Class *) ((Obj *) this_)->class_)->virtFun.functionName(this_ z_va_args(z_strip_parentheses(params)))

#define z_super_fun__(className, type, functionName, arguments) \
    type super_##className##_##functionName(className * const this_ z_va_args(z_strip_parentheses(arguments)))
#define z_super_fun_(className, type, functionName, arguments) z_super_fun__(className, type, functionName, arguments)
#define z_super_fun(type, functionName, arguments) z_super_fun_(Class_, type, functionName, arguments)
#define z_strip_parentheses_and_apply_super_fun(funSignature) z_super_fun funSignature;

#define z_virtual_fun_(className, type, functionName, arguments, params)                                  \
    z_fun_(className, type, functionName, arguments) { z_virtual_call(className, functionName, params); } \
    z_super_fun__(className, type, functionName, arguments)
#define z_virtual_fun(className, type, functionName, arguments, params) z_virtual_fun_(className, type, functionName, arguments, params)
#define virtual_fun(type, functionName, arguments, params) z_virtual_fun(Class_, type, functionName, arguments, params)

#define z_virtual_functions_(className, superClassName, ...)                      \
    typedef struct className##Class                                               \
    {                                                                             \
        superClassName##Class super;                                              \
                                                                                  \
        struct                                                                    \
        {                                                                         \
            z_for_each(z_strip_parentheses_and_apply_virtual_fun_pt, __VA_ARGS__) \
        } virtFun;                                                                \
    } className##Class;                                                           \
                                                                                  \
    className##Class const * const className##Class_instance();                   \
    z_for_each(z_strip_parentheses_and_apply_super_fun, __VA_ARGS__)
#define z_virtual_functions(className, superClassName, ...) z_virtual_functions_(className, superClassName, __VA_ARGS__)
#define virtual_functions(...) z_virtual_functions(Class_, super_Class_, __VA_ARGS__)

#define Object(className, varName, ...)                       \
    Byte const varName##Stack[className##Class_size()];       \
    className * const varName = (className *) varName##Stack; \
    className##_init((className *) varName, __VA_ARGS__)

#define z_set_get_(className, type, memberName)                                         \
    Void className##_##memberName##Set(className * const this_, type const memberName); \
    type className##_##memberName(className const * const this_)
#define z_set_get(className, type, memberName) z_set_get_(className, type, memberName)
#define set_get(type, memberName) z_set_get(Class_, type, memberName)
#define z_strip_parentheses_and_apply_set_get(memberSignature) set_get memberSignature;
#define setters_getters(...) z_for_each(z_strip_parentheses_and_apply_set_get, __VA_ARGS__)

#define z_default_set_(className, type, memberName) \
    Void className##_##memberName##Set(className * const this_, type const memberName) { this_->memberName = memberName; }
#define z_default_set(className, type, memberName) z_default_set_(className, type, memberName)
#define default_set(type, memberName) z_default_set(Class_, type, memberName)

#define z_default_get_(className, type, memberName) \
    type className##_##memberName(className const * const this_) { return this_->memberName; }
#define z_default_get(className, type, memberName) z_default_get_(className, type, memberName)
#define default_get(type, memberName) z_default_get(Class_, type, memberName)

#define z_default_set_get_(className, type, memberName)                                                                    \
    Void className##_##memberName##Set(className * const this_, type const memberName) { this_->memberName = memberName; } \
    type className##_##memberName(className const * const this_) { return this_->memberName; }
#define z_default_set_get(className, type, memberName) z_default_set_get_(className, type, memberName)
#define default_set_get(type, memberName) z_default_set_get(Class_, type, memberName)
#define z_strip_parentheses_and_apply_default_set_get(memberSignature) default_set_get memberSignature
#define default_setters_getters(...) z_for_each(z_strip_parentheses_and_apply_default_set_get, __VA_ARGS__)

#define z_override_fun_(className, type, superClassName, functionName, arguments) \
    type super_##className##_##functionName(className * const this_ z_va_args(z_strip_parentheses(arguments)))
#define z_override_fun(className, type, superClassName, functionName, arguments) z_override_fun_(className, type, superClassName, functionName, arguments)
#define override_fun(type, superClassName, functionName, arguments) z_override_fun(Class_, type, superClassName, functionName, arguments)
#define z_strip_parentheses_and_apply_override_fun(funSignature) override_fun funSignature;
#define override_functions(...) z_for_each(z_strip_parentheses_and_apply_override_fun, __VA_ARGS__)

#define z_init_(className, superClassName, ...)                                             \
    Void className##_init(className * const this_, className##Params const * const params_) \
    {                                                                                       \
        if (#superClassName == "Obj") { Obj_init((Obj *) this_); }                          \
                                                                                            \
        do                                                                                  \
            __VA_ARGS__                                                                     \
        while (0);                                                                          \
                                                                                            \
        ((Obj *) this_)->class_ = (ObjClass *) className##Class_instance();                 \
    }
#define z_init(className, superClassName, ...) z_init_(className, superClassName, __VA_ARGS__)
#define init(...) z_init(Class_, super_Class_, __VA_ARGS__)

#define z_terminate_(className, ...)                    \
    Void className##_terminate(className * const this_) \
    {                                                   \
        do                                              \
            __VA_ARGS__                                 \
        while (0);                                      \
    }
#define z_terminate(className, ...) z_terminate_(className, __VA_ARGS__)
#define terminate(...) z_terminate(Class_, __VA_ARGS__)

#define z_class_instance_impl(className, superClassName, ...)                                                   \
    className##Class const * const className##Class_instance()                                                  \
    {                                                                                                           \
        static className##Class class_;                                                                         \
                                                                                                                \
        if (((ObjClass *) &class_)->type == null)                                                               \
        {                                                                                                       \
            static char const * const type = #className;                                                        \
            *((superClassName##Class *) &class_) = *superClassName##Class##_instance();                         \
            ((ObjClass *) &class_)->virtFun.objectSize = (UInt8(*)(Obj const * const this_)) override_Obj_size; \
                                                                                                                \
            do                                                                                                  \
                __VA_ARGS__                                                                                     \
            while (0);                                                                                          \
                                                                                                                \
            ((ObjClass *) &class_)->type = type;                                                                \
        }                                                                                                       \
                                                                                                                \
        return &class_;                                                                                         \
    }

#define z_get_object_impl(className)                                     \
    className * get_##className(className##Params const * const params_) \
    {                                                                    \
        static className pool[className##_poolSize];                     \
        static UInt64 count = 0;                                         \
        className * this_ = null;                                        \
                                                                         \
        if (count < className##_poolSize)                                \
        {                                                                \
            this_ = &pool[count];                                        \
            className##_init(this_, params_);                            \
            count++;                                                     \
        }                                                                \
                                                                         \
        return this_;                                                    \
    }

#define z_new_object_impl(className)                                     \
    className * new_##className(className##Params const * const params_) \
    {                                                                    \
        className * this_ = (className *) malloc(sizeof(className));     \
        assert((this_ != null) && "Heap memory allocation failed");      \
        className##_init(this_, params_);                                \
        return this_;                                                    \
    }

#define z_delete_object_impl(className)               \
    className * delete_##className(className * this_) \
    {                                                 \
        className##_terminate(this_);                 \
        free(this_);                                  \
    }

#define z_abstract_class_setup_(className, superClassName, ...)                              \
    static UInt8 override_Obj_size(className const * const this_) { return sizeof(*this_); } \
    UInt8 className##Class_size() { return sizeof(className); }                              \
    z_class_instance_impl(className, superClassName, __VA_ARGS__)
#define z_abstract_class_setup(className, superClassName, ...) z_abstract_class_setup_(className, superClassName, __VA_ARGS__)
#define abstract_class_setup(...) z_abstract_class_setup(Class_, super_Class_, __VA_ARGS__)

#define z_singleton_class_setup_(className, superClassName, ...)                             \
    className * className##_instance()                                                       \
    {                                                                                        \
        static className singleton;                                                          \
        return &singleton;                                                                   \
    }                                                                                        \
                                                                                             \
    static UInt8 override_Obj_size(className const * const this_) { return sizeof(*this_); } \
    UInt8 className##Class_size() { return sizeof(className); }                              \
    z_class_instance_impl(className, superClassName, __VA_ARGS__)
#define z_singleton_class_setup(className, superClassName, ...) z_singleton_class_setup_(className, superClassName, __VA_ARGS__)
#define singleton_class_setup(...) z_singleton_class_setup(Class_, super_Class_, __VA_ARGS__)

#if CObject_useStaticPool == true
    #if CObject_useHeap == true
        #include <stdlib.h>
        #define z_class_setup_(className, superClassName, ...)                                       \
            static UInt8 override_Obj_size(className const * const this_) { return sizeof(*this_); } \
            z_class_instance_impl(className, superClassName, __VA_ARGS__);                           \
            z_get_object_impl(className);                                                            \
            z_new_object_impl(className);                                                            \
            z_delete_object_impl(className);                                                         \
            UInt8 className##Class_size() { return sizeof(className); }
    #else
        #define z_class_setup_(className, superClassName, ...)                                       \
            static UInt8 override_Obj_size(className const * const this_) { return sizeof(*this_); } \
            z_class_instance_impl(className, superClassName, __VA_ARGS__);                           \
            z_get_object_impl(className);                                                            \
            UInt8 className##Class_size() { return sizeof(className); }
    #endif
#else
    #if CObject_useHeap == true
        #include <stdlib.h>
        #define z_class_setup_(className, superClassName, ...)                                       \
            static UInt8 override_Obj_size(className const * const this_) { return sizeof(*this_); } \
            z_class_instance_impl(className, superClassName, __VA_ARGS__);                           \
            z_new_object_impl(className);                                                            \
            z_delete_object_impl(className);                                                         \
            UInt8 className##Class_size() { return sizeof(className); }
    #else
        #define z_class_setup_(className, superClassName, ...)                                       \
            static UInt8 override_Obj_size(className const * const this_) { return sizeof(*this_); } \
            z_class_instance_impl(className, superClassName, __VA_ARGS__);                           \
            UInt8 className##Class_size() { return sizeof(className); }
    #endif
#endif
#define z_class_setup(className, superClassName, ...) z_class_setup_(className, superClassName, __VA_ARGS__)
#define class_setup(...) z_class_setup(Class_, super_Class_, __VA_ARGS__)

#define z_bind_virtual_fun_(className, functionName) \
    class_.virtFun.functionName = super_##className##_##functionName;
#define z_bind_virtual_fun(className, functionName) z_bind_virtual_fun_(className, functionName)
#define bind_virtual_fun(functionName) z_bind_virtual_fun(Class_, functionName)
#define bind_virtual_functions(...) z_for_each(bind_virtual_fun, __VA_ARGS__)

#define z_bind_override_fun_(className, type, superClassName, functionName, arguments) \
    ((superClassName##Class *) &class_)->virtFun.functionName = (type(*)(superClassName * const this_ z_va_args(z_strip_parentheses(arguments)))) super_##className##_##functionName
#define z_bind_override_fun(className, type, superClassName, functionName, arguments) z_bind_override_fun_(className, type, superClassName, functionName, arguments)
#define bind_override_fun(type, superClassName, functionName, arguments) z_bind_override_fun(Class_, type, superClassName, functionName, arguments)

#define z_strip_parentheses_and_apply_bind_override_fun(funSignature) bind_override_fun funSignature;
#define bind_override_functions(...) z_for_each(z_strip_parentheses_and_apply_bind_override_fun, __VA_ARGS__)

#endif // COBJECTUTILITIES_H

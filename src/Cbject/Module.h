#ifndef MODULE_H
#define MODULE_H
#include "Any.h"
#include "Utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/**
 * @name Module_Interface
 * @brief Module_Interface
 * @param
 */
typedef struct {
    size_t offset;
} Module_Interface;
/**
 * @brief Module_Interface
 * @return Module_Interface const*
 */
Module_Interface const * Module_Interface_(void);
/**
 * @brief Module
 */
typedef struct {
    size_t offset;
    size_t interfaceOffset;
} Module;
/**
 * @brief Initialize an Module
 * @param me Module reference
 * @param type Interface reference
 * @return Module* Initialized Module
 */
Module * Module_init(Module * const me);
/**
 * @brief Get the interface of a module
 */
#define interfaceOf_(me) \
    to_(Module_Interface, to_(Any, classOf_(objectOf_(me))) + interfaceOffsetOf_(me))
/**
 * @brief Get offset of a module
 */
#define offsetOf_(me) \
    to_(Module, me)->offset
/**
 * @brief Get the interface offset of a module
 */
#define interfaceOffsetOf_(me) \
    to_(Module, me)->interfaceOffset
/**
 * @brief
 *
 */
#define interface_(interfaceName) \
    interfaceName##_Interface_()
/**
 * @brief Set class of object
 * @param me Object reference
 * @param className Class name
 */
#define setUpModule_(className, interfaceName, ...)                                                      \
    initModule_(interfaceName, &VaArgs_first_(__VA_ARGS__)->i##interfaceName VaArgs_rest_(__VA_ARGS__)); \
    offsetOf_(&VaArgs_first_(__VA_ARGS__)->i##interfaceName) = offsetof(className, i##interfaceName);    \
    interfaceOffsetOf_(&VaArgs_first_(__VA_ARGS__)->i##interfaceName) = offsetof(className##_Class, i##interfaceName##_Interface)
/**
 * @brief
 *
 */
#define overrideModuleMethod_(className, interfaceName, me, methodName) \
    to_(interfaceName##_Interface, &to_(className##_Class, me)->i##interfaceName##_Interface)->methodName = methodName
/**
 * @brief Initialize an Module
 * @param me
 * @param className
 * @param interfaceClassName
 * @param typeName
 */
#define initModule_(interfaceName, ...) \
    interfaceName##_init(to_(interfaceName, VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))
/**
 * @brief Call an interface method
 * @param interfaceName Interface name
 * @param methodName Method name
 * @param ... (me Module reference, ... Method arguments)
 */
#define moduleMethodCall_(interfaceName, methodName, ...) \
    to_(interfaceName##_Interface, interfaceOf_(VaArgs_first_(__VA_ARGS__)))->methodName(__VA_ARGS__)
#endif // MODULE_H

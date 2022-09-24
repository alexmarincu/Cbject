#ifndef TRAIT_H
#define TRAIT_H
#include "Any.h"
#include "Utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/**
 * @name Trait_Interface
 * @brief Trait_Interface
 * @param
 */
typedef struct {
    size_t offset;
} Trait_Interface;
/**
 * @brief Trait_Interface
 * @return Trait_Interface const*
 */
Trait_Interface const * Trait_Interface_(void);
/**
 * @brief Trait
 */
typedef struct {
    size_t offset;
    size_t interfaceOffset;
} Trait;
/**
 * @brief Initialize an Trait
 * @param me Trait reference
 * @param type Interface reference
 * @return Trait* Initialized Trait
 */
Trait * Trait_init(Trait * const me);
/**
 * @brief Get the interface of a trait
 */
#define interfaceOf_(me) \
    to_(Trait_Interface, to_(Any, classOf_(objectOf_(me))) + interfaceOffsetOf_(me))
/**
 * @brief Get offset of a trait
 */
#define offsetOf_(me) \
    to_(Trait, me)->offset
/**
 * @brief Get the interface offset of a trait
 */
#define interfaceOffsetOf_(me) \
    to_(Trait, me)->interfaceOffset
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
#define setUpTrait_(className, interfaceName, ...)                                                      \
    initTrait_(interfaceName, &VaArgs_first_(__VA_ARGS__)->i##interfaceName VaArgs_rest_(__VA_ARGS__)); \
    offsetOf_(&VaArgs_first_(__VA_ARGS__)->i##interfaceName) = offsetof(className, i##interfaceName);   \
    interfaceOffsetOf_(&VaArgs_first_(__VA_ARGS__)->i##interfaceName) = offsetof(className##_Class, i##interfaceName##_Interface)
/**
 * @brief
 *
 */
#define overrideTraitMethod_(className, interfaceName, me, methodName) \
    to_(interfaceName##_Interface, &to_(className##_Class, me)->i##interfaceName##_Interface)->methodName = methodName
/**
 * @brief Initialize an Trait
 * @param me
 * @param className
 * @param interfaceClassName
 * @param typeName
 */
#define initTrait_(interfaceName, ...) \
    interfaceName##_init(to_(interfaceName, VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))
/**
 * @brief Call an interface method
 * @param interfaceName Interface name
 * @param methodName Method name
 * @param ... (me Trait reference, ... Method arguments)
 */
#define traitMethodCall_(interfaceName, methodName, ...) \
    to_(interfaceName##_Interface, interfaceOf_(VaArgs_first_(__VA_ARGS__)))->methodName(__VA_ARGS__)
#endif // TRAIT_H

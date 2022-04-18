#ifndef APPLICATION_H
#define APPLICATION_H
#include "Cbject.h"

defineClass_(Application);

/**
 * @brief ApplicationInterface
 */
struct ApplicationInterface {
    super_(ObjectInterface);
};

/**
 * @brief ApplicationClass
 */
struct ApplicationClass {
    super_(ObjectClass);
};

/**
 * @brief Get ApplicationInterface
 * @return ApplicationInterface const*
 */
ApplicationInterface const * ApplicationInterface_(void);

/**
 * @brief Get ApplicationClass
 * @return ApplicationClass const*
 */
ApplicationClass const * ApplicationClass_(void);

/**
 * @brief Get Application singleton
 * @return Application*
 */
Application * Application_(void);

/**
 * @brief
 * @param me
 */
void Application_main(Application * const me);

#endif // APPLICATION_H

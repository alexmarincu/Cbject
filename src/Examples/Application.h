#ifndef APPLICATION_H
#define APPLICATION_H
#include "Cbject.h"

class_(Application);

/**
 * @brief ApplicationOps
 */
struct ApplicationOps {
    extend_(ObjectOps);
};

/**
 * @brief ApplicationClass
 */
struct ApplicationClass {
    extend_(ObjectClass);
};

/**
 * @brief Get ApplicationOps
 * @return ApplicationOps const*
 */
ApplicationOps const * ApplicationOps_(void);

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

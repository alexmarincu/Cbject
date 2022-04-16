#ifndef APPLICATION_H
#define APPLICATION_H
#include "Cbject.h"

class_(Application);

/**
 * @brief ApplicationOperations
 */
struct ApplicationOperations {
    extend_(ObjectOperations);
};

/**
 * @brief ApplicationClass
 */
struct ApplicationClass {
    extend_(ObjectClass);
};

/**
 * @brief Get ApplicationOperations
 * @return ApplicationOperations const*
 */
ApplicationOperations const * ApplicationOperations_(void);

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

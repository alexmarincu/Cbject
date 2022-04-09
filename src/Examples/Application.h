#ifndef APPLICATION_H
#define APPLICATION_H
#include "Cbject.h"

/**
 * @brief
 */
typedef struct Application Application;

/**
 * @brief
 * @return Application*
 */
Application * Application_(void);

/**
 * @brief
 * @param me
 */
void Application_main(Application * const me);

/**
 * @brief Contains Application's operations (aka virtual functions)
 */
typedef struct ApplicationOperations {
    ObjectOperations objectOperations;
} ApplicationOperations;

/**
 * @brief
 * @return ApplicationOperations const*
 */
ApplicationOperations const * ApplicationOperations_(void);

/**
 * @brief
 * @return Class const*
 */
Class const * ApplicationClass_(void);

#endif // APPLICATION_H

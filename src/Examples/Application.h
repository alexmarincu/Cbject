#ifndef APPLICATION_H
#define APPLICATION_H
#include "../Cbject/Cbject.h"

/**
 * @brief ApplicationClass
 */
typedef struct {
    super_(ObjectClass);
} ApplicationClass;

typedef struct Application Application;

/**
 * @brief ApplicationInterface
 */
typedef struct {
    super_(ObjectInterface);
} ApplicationInterface;

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

#ifndef APPLICATION_H
#define APPLICATION_H
#include "../Cbject/Cbject.h"
typedef struct Application Application;
/**
 * @brief Application_Class
 */
typedef struct {
    extends_(Object_Class);
} Application_Class;
/**
 * @brief Get Application_Class
 * @return Application_Class const*
 */
Application_Class const * Application_Class_(void);
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

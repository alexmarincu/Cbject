#include "Application/Application.h"
#include <stdio.h>

Int8 main()
{
    Application * const application = Application_getInstance();
    Application_init(application, null);
    printf("application.objectSize() = %d\n", CObject_objectSize((CObject *) application));
    Application_start(application);
    return 0;
}

#include "Application/Application.h"
#include <stdio.h>

Int8 main()
{
    Application * const application = Application_getInstance();
    Application_init(application, null);
    printf("application.objectSize() = %d\n", Obj_size((Obj *) application));
    Application_start(application);
    Application_terminate(application);
    return 0;
}

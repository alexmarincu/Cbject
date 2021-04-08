#include "Application/Application.h"
#include <stdio.h>

int main()
{
    Application * const application = Application_instance();
    Application_init(application, null);
    printf("application.size() = %d\n", Object_size((Object *) application));
    Application_start(application);
    Application_terminate(application);
    return 0;
}

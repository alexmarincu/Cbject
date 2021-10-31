#include "Application/Application.h"
#include <stdio.h>

int main()
{
    Application * const application = Application_instance();
    printf("application.size() = %d\n", Object_size((Object *)application));
    Application_start(application);
    return 0;
}

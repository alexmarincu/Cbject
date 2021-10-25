#include "Application/Application.h"
#include <stdio.h>

int main()
{
    Application * const application = Application_instance();
    printf("application.size() = %d\n", Cbject_size((Cbject *) application));
    Application_start(application);
    return 0;
}

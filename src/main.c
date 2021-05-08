#include "Application.h"
#include <stdio.h>

int main()
{
    Application * const application = Application_instance();
    printf("application.size() = %d\n", Cbj_Base_size((Cbj_Base *) application));
    Application_start(application);
    Application_terminate(application);
    return 0;
}

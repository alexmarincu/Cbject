#include "Application.h"
int main(void) {
    Application_main(Application_getInstance());
    cbject_teardown(Application_getInstance());
    return 0;
}

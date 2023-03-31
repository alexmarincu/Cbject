#include "Application.h"

int main(void) {
    Application_main(Application_instance());
    cbject_release(Application_instance());
    return 0;
}

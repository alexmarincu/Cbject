#include "Application.h"

int main(void) {
    Application_main(Application_instance());
    cbject_utils_release(Application_instance());
    return 0;
}

#include "Application.h"
int main(void) {
    Application_main(x_singleton(Application));
    x_teardown(x_singleton(Application));
    return 0;
}

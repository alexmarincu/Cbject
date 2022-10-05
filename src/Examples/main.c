#include "Application.h"
int main(void) {
    Application_main(singleton_(Application));
    teardown_(singleton_(Application));
    return 0;
}

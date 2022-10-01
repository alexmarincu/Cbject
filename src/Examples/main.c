#include "Application.h"
int main(void) {
    Application * application = singleton_(Application);
    Application_main(application);
    application = teardown_(application);
    return 0;
}

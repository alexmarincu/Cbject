#include "Application.h"
/**
 * @brief
 * @return int
 */
int main(void) {
    Application * application = singleton_(Application);
    Application_main(application);
    application = teardown_(application);
    return 0;
}

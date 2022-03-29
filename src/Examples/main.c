#include "Application.h"

/**
 * @brief
 *
 * @return int
 */
int main(void) {
    Application * const application = Application_();
    Application_main(application);
    finalize_(application);
    return 0;
}

#include "Application.h"
/**
 * @brief
 * @return int
 */
int main(void) {
    Application * application = Application_();
    Application_main(application);
    application = deinit_(application);
    return 0;
}

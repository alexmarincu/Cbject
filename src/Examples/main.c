#include "Application.h"
#include "Circle.h"
#include "ColoredCircle.h"
#include "Drawable.h"
#include "Greeting.h"
#include "Rectangle.h"
#include "Shape.h"
int main(void) {
    initClass_(Application);
    initSingleton_(Application);
    initClass_(Shape);
    initInterface_(Drawable);
    initClass_(Rectangle);
    initClass_(Circle);
    initClass_(ColoredCircle);
    initClass_(Greeting);
    Application_main(singleton_(Application));
    teardown_(singleton_(Application));
    return 0;
}

/* tag::overview[]
Implementation for doOnce_() macro
end::overview[] */
#ifndef DOONCE_H
#define DOONCE_H
#include "pthread.h"
#define DoOnce_Mutex_staticAllocInit() \
    static pthread_mutex_t doOnceMutex = PTHREAD_MUTEX_INITIALIZER
#define DoOnce_Mutex_lock() \
    pthread_mutex_lock(&doOnceMutex)
#define DoOnce_Mutex_unlock() \
    pthread_mutex_unlock(&doOnceMutex)
/* tag::macro[]
= doOnce_()
====
[source,c]
----
#define doOnce_(block)
----
Run a block of code only once

.Remark
It uses a mutex to provide thread safety. The mutex settings need to be changed based on the concurency framework used. By default pthread is used.

.Usage example
----
doOnce_({
    functionCall();
});
----

.Params
* block - The block of code to be run
====
end::macro[] */
#define doOnce_(block)                     \
    static bool isDone = false;            \
    DoOnce_Mutex_staticAllocInit();        \
    DoOnce_Mutex_lock();                   \
    for (; isDone == false; isDone = true) \
        do block while (0);                \
    DoOnce_Mutex_unlock()
#endif // DOONCE_H

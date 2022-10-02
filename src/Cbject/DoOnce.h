/* tag::overview[]
Implementation for doOnce_() macro
end::overview[] */
#ifndef DOONCE_H
#define DOONCE_H
#include "pthread.h"
#define DoOnce_Mutex_type pthread_mutex_t
#define DoOnce_Mutex_init(doOnceMutex) \
    *doOnceMutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER
#define DoOnce_Mutex_lock(doOnceMutex) \
    pthread_mutex_lock(doOnceMutex)
#define DoOnce_Mutex_unlock(doOnceMutex) \
    pthread_mutex_unlock(doOnceMutex)
typedef DoOnce_Mutex_type DoOnce_Mutex;
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
    static DoOnce_Mutex doOnceMutex;       \
    DoOnce_Mutex_init(&doOnceMutex);       \
    DoOnce_Mutex_lock(&doOnceMutex);       \
    for (; isDone == false; isDone = true) \
        do block while (0);                \
    DoOnce_Mutex_unlock(&doOnceMutex)
#endif // DOONCE_H

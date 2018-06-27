/** **********************************************************************************************************************

 *  A mutual exclusion (OR Mutex) is a program object that prevents simultaneous access to a shared resource. This concept
    is used in concurrent programming with a critical section, a piece of code in which processes or threads access a
    shared resource.

***********************************************    Prototypes    *******************************************************
 *          pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
 *
 *          int pthread_mutex_lock(&mutex);  //blocks until lock acquired
 *
 *          int pthread_mutex_trylock(&mutex);  //tries to acquire and return if other thread holds the lock
 *
 *          int pthread_mutex_unlock(&mutex);
************************************************************************************************************************/

#include <iostream>
#include <pthread.h>

using namespace std;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * ExecRoutine(void *tid)
{
    // Start of the Critical Section.
    pthread_mutex_lock(&mutex);

    cout << "The Thread No is : "<<(int*)tid<<endl;

    // End of the Critical Section.
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);

}

int main()
{
    pthread_t ThID[5];

    for (int i=0; i<5; i++)
    {
        pthread_create(&ThID[i],NULL,ExecRoutine,(void *)i);
    }

    for(int j=0; j<5; j++)
    {
        pthread_join(ThID[j],NULL);
    }
    return 0;
}


/** **************************************************************************************************************
 * Study race Condition
 * Synchronization Bugs

Various Pthreads manual pages, for example: pthread_attr_init(3), pthread_atfork(3), pthread_cancel(3), pthread_cleanup_push(3),
pthread_cond_signal(3), pthread_cond_wait(3), pthread_equal(3),pthread_key_create(3), pthread_kill(3), pthread_once(3),
pthread_setcancelstate(3),pthread_setcanceltype(3), pthread_setspecific(3), pthread_sigmask(3), pthread_sigqueue(3),
and pthread_testcancel(3)
*****************************************************************************************************************/

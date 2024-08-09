/** *********************************************    Prototypes    *******************************************************
 *
 *  POSIX Threads       : Portable Operating System Interface.
 *  Traditional Thread  : Single thread of control.
 *  Modern Thread       : Multiple thread of control.
 *  Function            : 1. To Create 2. To Manage 3. To Schedule threads.

 * The pthread_detach() function marks the thread identified by thread as detached. When a detached thread
 * terminates, its resources are automatically released back to the system without the need for another
 * thread to join with the terminated thread. Due to this there is no way to determine its return value
 * of detached thread function. pthread_detach() will return non zero value in case of error.
 *
 * The function pthread_attr_init() is used to initialize object attributes to their default values.
 * The storage is allocated by the thread system during execution.
 *
 *          int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
 *
 *          int pthread_join(pthread_t thread, void **retval);
 *
 *          void pthread_exit(void *retval);
 *          
 *          int pthread_detach();
 * 
 *          int pthread_attr_init(pthread_attr_t *attr);
 * 
 *          int pthread_attr_destroy(pthread_attr_t *attr);
 *
 *          struct pthread_attr_t
 *          {
 *              unsigned p_state;
 *              void *stack;
 *              size_t s_size;
 *              struct sched_param param;
 *          };
 *
 *          struct sched_param
 *          {
 *              int sched_priority;
 *          };
 *
 * A mutual exclusion (OR Mutex) is a program object that prevents simultaneous access to a shared resource. This concept
 * is used in concurrent programming with a critical section, a piece of code in which processes or threads access a
 * shared resource.
 *
 *          pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
 *
 *          int pthread_mutex_lock(&mutex);  //blocks until lock acquired
 *
 *          int pthread_mutex_trylock(&mutex);  //tries to acquire and return if other thread holds the lock
 *
 *          int pthread_mutex_unlock(&mutex);
 ************************************************************************************************************************/

#define HAVE_STRUCT_TIMESPEC
#include <iostream>
#include <pthread.h>

using namespace std;

void* Method_ThreadAttach(void*);
void* Method_ThreadDetach(void*);
void* Method_ThreadMutex(void*);

int SystemSignal;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;                          

int main()
{
    int errCode;
    void** ThreadStatus;
    pthread_attr_t attr;
    pthread_t tid[5], ThID[5], threadId;

    // Attaching thread 
    for (int i = 0; i < 5; i++)
    {
        errCode = pthread_create(&tid[i], NULL, Method_ThreadAttach, (void*)&i);
        pthread_join(tid[i], (void**)&(ThreadStatus));                      
        cout << "Status of the exited with status : " << *ThreadStatus << endl << endl;

        if (errCode)
            cout << "Error in the thread creation with thread id : " << tid[i].x << endl;    
    }

    // Detaching thread
    errCode = pthread_attr_init(&attr);
    if (errCode) { cout << "Attribute initiliazation Failed" << endl; }
    else { cout << "Attribute initilize successfully" << endl; }

    errCode = pthread_create(&threadId, &attr, Method_ThreadDetach, &threadId);
    if (errCode) { cout << "Thread Creation Failed" << endl; }
    else { cout << "Thread Created Successfully" << endl; }

    errCode = pthread_detach(threadId);
    if (errCode) { cout << "Thread detach Failed" << endl; }
    else { cout << "Thread detached Successfully" << endl; }

    errCode = pthread_attr_destroy(&attr);
    if (errCode) { cout << "Attribute destruction Failed" << endl; }
    else { cout << "Attribute destroyed successfully" << endl<<endl; }


    // Thread Mutexes
    
    for (int i = 0; i < 5; i++)
        pthread_create(&ThID[i], NULL, Method_ThreadMutex, (void*)&i);
    for (int j = 0; j < 5; j++)
        pthread_join(ThID[j], NULL);


    system("pause");
    return 0;
}


void* Method_ThreadAttach(void* tid)
{
    int* ThreadID = (int*)tid;
    SystemSignal = 7;
    cout << "Printing Thread NO. : " << ThreadID << endl;

    pthread_exit(&SystemSignal);                                 
    return nullptr;
    //<- Here is 0 is the system signal (execution status of routine) returned to the main programme.
}

void* Method_ThreadDetach(void* tid)
{
    cout << "Start of Thread ID : " << (int*)tid << endl;
    cout << "End of Thread ID : " << (int*)tid << endl;

    return NULL;
}

void* Method_ThreadMutex(void* tid)
{
    // Start of the Critical Section.
    pthread_mutex_lock(&mutex);

    cout << "The Thread No is : " << (int*)tid << endl;

    // End of the Critical Section.
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
    return nullptr;
}

// Thread status must be always GLOBAL. When declared locally if thread goes out of scope, locally declared 
// variables also goes out of scope, hence garbage value as a status is read by the main function.

// If retval is not NULL, then pthread_join() copies the exit status of the target thread
// (i.e., the value that the target thread supplied to pthread_exit(3)) into the location pointed to by *retval.

// If retval is not NULL, then pthread_join() copies the address of the variable holding the exit status of the target
// thread (i.e., the value that the target thread supplied to pthread_exit(3)) into the location pointed to by retval.

//  Output can change on your system because both main and thread function are running in parallel.
//  If main function exits then all other threads will be exited. Hence If main process exits 1st,
//  output for child thread will not shown.
//
// Why to Detach Thread:
//  pthread_join does two things:
//
//  1.Wait for the thread to finish.
//  2.Clean up any resources associated with the thread.
//
//  If you exit the process without joining, then (2) will be done for you by the OS (although it won't
//  do thread cancellation cleanup, just nuke the thread from orbit), and (1) will not. So whether you
//  need to call pthread_join depends whether you need (1) to happen.
//
//  If you don't need the thread to run, then as everyone else is saying you may as well detach it.
//  A detached thread cannot be joined (so you can't wait on its completion), but its resources are
//  freed automatically if it does complete.

/** **************************************************************************************************************
 * Study race Condition
 * Synchronization Bugs

Various Pthreads manual pages, for example: pthread_atfork(3), pthread_cancel(3), pthread_cleanup_push(3),
pthread_cond_signal(3), pthread_cond_wait(3), pthread_equal(3),pthread_key_create(3), pthread_kill(3), pthread_once(3),
pthread_setcancelstate(3),pthread_setcanceltype(3), pthread_setspecific(3), pthread_sigmask(3), pthread_sigqueue(3),
and pthread_testcancel(3)
*****************************************************************************************************************/
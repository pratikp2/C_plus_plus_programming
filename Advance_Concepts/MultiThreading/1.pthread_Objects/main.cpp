/** *********************************************    Prototypes    *******************************************************
 *
 *  POSIX Threads       : Portable Operating System Interface.
 *  Traditional Thread  : Single thread of control.
 *  Modern Thread       : Multiple thread of control.
 *  Function            : 1. To Create 2. To Manage 3. To Schedule threads.
 *
 *          int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
 *
 *          int pthread_join(pthread_t thread, void **retval);
 *
 *          void pthread_exit(void *retval);
 ************************************************************************************************************************/

#include <iostream>
#include <pthread.h>

using namespace std;

void *PrintHello(void *);
int SystemSignal;                           // Thread status must be always GLOBAL. When declared locally if thread goes
                                            // out of scope, locally declared variables also goes out of scope, hence garbage
                                            // value as a status is read by the main function.

int main()
{
    pthread_t tid[5];
    int tr,i;
    void ** ThreadStatus;

    for(i=0;i<5;i++)
    {
        tr = pthread_create(&tid[i],NULL,PrintHello,(void *)i);             // The Format of pthread_create() don't have separate API formats for just to take
                                                                            // different data types as input (viz. int, char etc.). Hence the void pointer has
                                                                            // been passed to the API so that after passing void pointer the data type can be
                                                                            // retrieved by typecasting.

        pthread_join(tid[i],(void**)&(ThreadStatus));                       // int pthread_join(pthread_t thread, void **retval)


        cout << "Status of the exited with status : " << *ThreadStatus << endl<<endl;

        if(tr)
        {
            cout << "Error in the thread creation with thread id : "<<tid[i]<<endl;
        }
    }

    return 0;
}


void *PrintHello(void * tid)
{
    int ThreadID = (int)tid;
    SystemSignal = 7;
    cout << "Printing Thread NO. : "<< ThreadID << endl;

    pthread_exit(&SystemSignal);                                 // void pthread_exit(void *retval);
                                                                //<- Here is 0 is the system signal (execution status of routine) returned to the main programme.
}


//If retval is not NULL, then pthread_join() copies the exit status of the target thread
//(i.e., the value that the target thread supplied to pthread_exit(3)) into the location pointed to by *retval.

//If retval is not NULL, then pthread_join() copies the address of the variable holding the exit status of the target
//thread (i.e., the value that the target thread supplied to pthread_exit(3)) into the location pointed to by retval.


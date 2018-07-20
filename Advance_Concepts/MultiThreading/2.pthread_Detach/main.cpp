/** ********************************************************************************************************************************************
*
* The pthread_detach() function marks the thread identified by thread as detached. When a detached thread
* terminates, its resources are automatically released back to the system without the need for another
* thread to join with the terminated thread. Due to this there is no way to determine its return value
* of detached thread function. pthread_detach() will return non zero value in case of error.
*
*   int pthread_attr_init(pthread_attr_t *attr);
*       The function pthread_attr_init() is used to initialize object attributes to their default values.
*       The storage is allocated by the thread system during execution.
*
*   int pthread_attr_destroy(pthread_attr_t *attr);
*
*
***********************************************************************************************************************************************/
#include <iostream>
#include <pthread.h>

using namespace std;
void * DisplayFunc(void * argument)
{
    cout << "Start of Thread ID : " << (int*)argument << endl;
    cout << "End of Thread ID : " << (int*)argument << endl;

    return NULL;
}

int main ()
{
    int errCode;
    pthread_t threadId;
    pthread_attr_t attr;

    errCode =  pthread_attr_init(&attr);
    if (errCode){cout << "Attribute initiliazation Failed"<<endl;}
    else{cout << "Attribute initilize successfully" << endl<<endl;}

    errCode = pthread_create(&threadId,&attr,DisplayFunc,&threadId);

    if (errCode){cout << "Thread Creation Failed"<<endl;}
    else{cout << "Thread Created Successfully" << endl<<endl;}

    errCode = pthread_detach(threadId);

    if (errCode){cout << "Thread detach Failed"<<endl;}
    else{cout << "Thread detached Successfully" << endl<<endl;}

     errCode = pthread_attr_destroy(&attr);

    if (errCode){cout << "Attribute destruction Failed"<<endl;}
    else{cout << "Attribute destroyed successfully" << endl<<endl;}

    cout << "End of the Main Function"<< endl;

    return 0;
}

/* *******************************************************************************************************
*
* Output can change on your system because both main and thread function are running in parallel.
* If main function exits then all other threads will be exited. Hence If main process exits 1st,
* output for child thread will not shown.
*
*Why to Detach Thread:
* pthread_join does two things:
*
* 1.Wait for the thread to finish.
* 2.Clean up any resources associated with the thread.
*
* If you exit the process without joining, then (2) will be done for you by the OS (although it won't
* do thread cancellation cleanup, just nuke the thread from orbit), and (1) will not. So whether you
* need to call pthread_join depends whether you need (1) to happen.
*
* If you don't need the thread to run, then as everyone else is saying you may as well detach it.
* A detached thread cannot be joined (so you can't wait on its completion), but its resources are
* freed automatically if it does complete.
*
* ********************************************************************************************************

typedef struct
{
  int __detachstate;
  int __schedpolicy;
  struct sched_param __schedparam;
  int __inheritsched;
  int __scope;
  size_t __guardsize;
  int __stackaddr_set;
  void *__stackaddr;
  unsigned long int __stacksize;
}
pthread_attr_t;

*************************************************************************************************************/

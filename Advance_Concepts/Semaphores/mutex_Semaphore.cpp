/** **************************************************************************************************
 * Once semaphore is initiliaze it can not be or shoulden't be accessed directly, only via two atomic
 * operations : 1) wait 2)signal
 *
 * To solve critical section problem
 * To decide order of the execution among processes.
 * Resource Management
 ****************************************************************************************************/

#include <stdio.h>
#include <pthread.h>

typedef int Semaphore;
Semaphore S = 1;

unsigned int thread_status;
void signal() {S = S+1;}

void wait()
{
    while(S<=0) {printf("Wait Called : %d \n",S);};
    S = S-1;
}

void * functionSynchCheck(void * identifier)
{
    wait();
    char* id = (char*)identifier;
    printf("Called routine for thread id : %s \n",id);
    for (unsigned int i=0; i<1000; i++) {i++;}
    printf("\n");
    printf("Routine successfully exited for thread id : %s \n",id);
    signal();
    pthread_exit(NULL);
}

int main()
{
    int errorCode;
    pthread_t tid1,tid2;
    char one = '1',two = '2';

    errorCode = pthread_create(&tid1,NULL,functionSynchCheck,(void*)&one);
    if (errorCode){printf("Thread Createation failed with id %d \n",tid1);}
    else {printf("Thread Created Successfully with id %d \n",tid1);}

    errorCode = pthread_create(&tid2,NULL,functionSynchCheck,(void*)&two);
    if (errorCode){printf("Thread Createation failed with id %d \n",tid2);}
    else {printf("Thread Created Successfully with id %d \n",tid2);}

    errorCode = pthread_join(tid1,NULL);
    errorCode = pthread_join(tid2,NULL);
    return 0;
}

// The C++ standard does not define a semaphore type. You can write your own with an atomic counter, a mutex
// and a condition variable if you need, but most uses of semaphores are better replaced with mutexes and/or
// condition variables anyway

/** ************************************************  Prototype ***************************************************************
 *
*       sem_init(sem_t *sem, int pshared, unsigned int value);
*               sem :   Specifies the semaphore to be initialized.
*               value : Specifies the value to assign to the newly initialized semaphore.
*               pshared : This argument specifies whether or not the newly initialized semaphore is shared between processes or
*                   between threads. A non-zero value means the semaphore is shared between processes and a value of zero means
*                    it is shared between threads.
*
*       int sem_wait(sem_t *sem);
*
*       int sem_post(sem_t *sem);
*
*       sem_destoy(sem_t *mutex);
*
 ******************************************************************************************************************************/

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t mutex;

void * functionSynchCheck(void * identifier)
{
    sem_wait(&mutex);
    char* id = (char*)identifier;
    cout << "Called routine for thread id : " << id << endl;
    sleep(4);
    cout << "Routine successfully exited for thread id : " << id<< endl;
    sem_post(&mutex);
    pthread_exit(NULL);
}

int main()
{
    int errorCode;
    pthread_t tid1,tid2;
    char one = '1',two = '2';
    sem_init(&mutex,0,1);

    errorCode = pthread_create(&tid1,NULL,functionSynchCheck,(void*)&one);
    if (errorCode){ cout << "Thread Createation failed with id : " << tid1 << endl;}
    else {cout << "Thread Created Successfully with id : " << tid1 << endl;}

    sleep(2);
    errorCode = pthread_create(&tid2,NULL,functionSynchCheck,(void*)&two);
    if (errorCode){cout << "Thread Createation failed with id : " << tid2 << endl;}
    else {cout << "Thread Created Successfully with id : " << tid2 << endl;}

    errorCode = pthread_join(tid1,NULL);
    errorCode = pthread_join(tid2,NULL);
    sem_destroy(&mutex);
    return 0;
}


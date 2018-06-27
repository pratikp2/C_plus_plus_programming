/* ************************************************************************
* POSIX Threads : Portable Operating System Interface.
* Traditional Thread : Single thread of control.
* Modern Thread : Multiple thread of control.
* Function :     1. To Create 2. To Manage 3. To Schedule threads.
* ************************************************************************/

#include <iostream>
#include <pthread.h>

using namespace std;


void* print_message_function(void *ptr);


int main()
{
    pthread_t thread1,thread2;

    const char* message1 = "Thread1";\
    const char* message2 = "Thread2";

     pthread_create(&thread1,NULL,print_message_function,(void *)message1);
     pthread_create(&thread2,NULL,print_message_function,(void *)message2);

     pthread_join(thread1,NULL);
     pthread_join(thread2,NULL);
    return 0;
}

void* print_message_function(void *ptr)
{

    char *message;
    message = (char *)ptr;
    cout << "Thread = " << message <<endl;      // <------ Scheduling sequence will not be always same.
    return 0;
}

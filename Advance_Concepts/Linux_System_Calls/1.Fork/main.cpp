#include <iostream>
#include <unistd.h>         // Name of the header file that provides access to the POSIX operating system API.
                            // It is defined by the POSIX.1 standard .unistd.h is typically made up largely of
                            // system call wrapper functions such as fork, pipe and I/O primitives (read, write, close, etc.).
using namespace std;

int main()
{
    cout << endl <<"Hello world ...! "<<endl;      // The code segment After fork command will be executed twice.
                                                   // Hence this line will executed once.

    pid_t pid = fork();

    if (pid == 0)
    {
        cout <<"My Child Process & its Process Id is "<<pid << endl;  // Child Process gets process id 0
    }
    else
    {
        cout <<"My Parent Process & its Process Id is "<<pid<<endl;  // Parent Process gets process id any positive
    }                                                                // number assigned by the OS

    return 0;
}

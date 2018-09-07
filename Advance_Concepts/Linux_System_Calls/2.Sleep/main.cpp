#include <iostream>
#include <unistd.h>         // Name of the header file that provides access to the POSIX operating system API.
                            // It is defined by the POSIX.1 standard .unistd.h is typically made up largely of
                            // system call wrapper functions such as fork, pipe and I/O primitives (read, write, close, etc.).
using namespace std;

int main()
{
    unsigned int s = 5;
    cout << "Sleeping for 5 Seconds for 5 Seconds"  << endl;
    sleep(5);
    cout << "Waiting Finished ....!" << endl;
    return 0;
}

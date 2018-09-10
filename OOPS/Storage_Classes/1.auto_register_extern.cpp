#include "storagehelper.h"

int count;
extern int write_extern();


int main ()
{
    auto int var1 = 10;     //OR int var1 = 10;     // OR auto vatr1 = 10;
    register int var2 = 20;
    count = 5;


    cout << "Value for auto VAR 1       :  " << var1 << endl;
    cout << "Value for register VAR 2   :  " << var2 << endl;
    cout << "Value for extern VAR 3     :  " << write_extern() << endl;

    return 0;
}

// auto is automatic storage class which is default storage class of variables.
// In C++ 11 there as been improvement for automatic type deduction. Variables can be initiliaze
// using only auto storagr class. i,e. auto var1 = 10; which will atomatic consider var1 as
// integer type.

// register storage class declares register variables which have the same functionality as that of the auto
// variables. The only difference is that the compiler tries to store these variables in the register of the
// microprocessor if a free register is available. This makes the use of register variables to be much faster
// than that of the variables stored in the memory during the runtime of the program. If a free register is
// not available, these are then stored in the memory only.

// Compile with "g++ .\storagehelper.cpp .\1.auto_register_extern.cpp"      // no need to include header file in command
// Compile with "g++ storagehelper.cpp 1.auto_register_extern.cpp"

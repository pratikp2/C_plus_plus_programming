#include "storagehelper.h"

int main ()
{
    auto int var1 = 10;     //OR int var1 = 10;
    StorageHelper ObjStorageHelper;
    return 0;
}

// auto is automatic storage class which is default storage class of variables.
// In C++ 11 there as been improvement for automatic type deduction. Variables can be initiliaze
// using only auto storagr class. i,e. auto var1 = 10; which will atomatic consider var1 as
// integer type.

// Compile with "g++ .\storagehelper.cpp .\1.auto_register_extern.cpp"
// Compile with "g++ storagehelper.cpp 1.auto_register_extern.cpp"

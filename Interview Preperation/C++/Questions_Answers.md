# C++ Interview Questions and Answers


### What are advantages and disadvantages of C++ ?

***Advantages of C++ :***
- Object oriented
- Portable language (writing a program irrespective of operating system as well as Hardware)
- Low-level language like Assembly language on Machine language called portable.
- It is useful for the low-level programming language and very efficient for general purpose.
- C++ provide performance and memory efficiency.
- It provides a high-level abstraction.
In the language of the problem domain.
- C++ is compatible with  C.
- C++ used reusability of code.
- C++ used inheritance, polymorphism.
- C++ use multi-paradigm programming. The Paradigm means the style of programming .paradigm concerned about logics, structure,
and procedure of the program.
- C++ is multi-paradigm means it follows three paradigm Generic, Imperative, Object Oriented.

***Portability :***

- Portability allows developing program irrespective of hardware
- It allows moving the program development for one platform to another platform
- C compatible (COMP): Programs developed in ‘C’ language can be moved without any modifications into C++
- Which language having low-level features
- C++ is an object oriented embedded language which is having the - characteristics of low-level language & which is also developing
the embedded software.

***Disadvantages :***

- It has no security
- Complex in a very large high-level program.
- Used for platform specific application commonly.
- For a particular operating system or platform, the library set has usually chosen that locks.
- When C++ used for web applications complex and difficult to debug.
- C++ can’t support garbage collection.
- C++ is not secure because it has a pointer, friend function, and global variable.
- No support for threads built in.

***

### Can a Constructor/Destructor be private ?
If the constructor/destructor is declared as private, then the class cannot be instantiated. This is true, however it can be instantiated
from another method in the class. Similarly, if the destructor is private , then the object can only be deleted from inside the class as
well.

***
### Can constructor and destructor be virtual ? 
- To build an object the constructor must be of the same type as the object and because of this a constructor cannot be a virtual function.
- But the same thing does not apply to destructor. You would use a virtual destructor if you ever expect a derived class to be destroyed through a pointer to the base class.
***

### Why Destructors in C++ are called in the opposite order of that of Constructors.
- A derived class should be able to call methods and use data members of its base class. On the other hand, a base class does not normally call methods or use members of its derived class (generally, it doesn't know which derived class it's a part of).
- For this reason, base class is constructed first and destroyed last, so that it's valid while the constructor and destructor of its derived classes runs. There are many other scenarios that follow this pattern.
-  For example, at the closing brace of a block, local
variables declared in that block are destroyed in the reverse order of construction, because a variable created later could depend on the one created earlier.
***

### What is difference between Abstract Class and Interface ?
- An abstract class is a class that has at least a pure virtual method. You can't create instances of that class, but you can have implementation in it, that is shared with the derived classes.
- An interface is a pure virtual class, with no implementation whatsoever.Interfaces cannot contain any data types(only functions)
whereas abstract classes can contain both.
***

### Can we define Pure virtual function and if yes How to call it.

- We can define pure virtual function, but it has to be defined out side of the class body.
I can be called via derived class using scope resolution.
e.g, Interface :: Function();

- Pure virtual functions must not be called from a C++ constructor. As a general rule, you should never call any kind of virtual function in a constructor or destructor because those calls will never go to a more derived class than the currently executing constructor or destructor.
***

### What is the Logic behind giving body to a pure virtual Function ?

Ideally Derived classes who overrides pure virtual function may call original Pure virtual function implementation somewhere in their code.If part of the code of tow overridden functionalities from two distinct derived classes is similar then it makes sense to move it up in the hierarchy, i,e in Pure Virtual Function.
***

### Can we delete this pointer ? 

Ideally delete operator should not be used for this pointer. However, if used, then following points must be considered.

- delete operator works only for objects allocated using operator new . If the object is created using new, then we can do delete this, otherwise behavior is undefined.
- Once delete this is done, any member of the deleted object should not be accessed after deletion. 

Delete this is legal and does what you would expect, it calls your class's destructor and free the underlying memory.
After delete this returns, your this pointer value does not change, so it is now a dangling pointer that should not be dereferenced.
That includes implicit dereferencing using the class's member variables.
***

### What is difference between a class and a struct

***class :***
- Class is a reference type and its object is created on the heap memory.
- Class can inherit the another class.
- Class can have the all types of constructor and destructor.
- The member variable of class can be initialized directly.
 
***struct :***
- Structure is a value type that is why its object is created on the stack memory.
- Structure does not support the inheritance.
- Structure can only have the parametrized constructor, it means a structure can not have the non-parametrized constructor,default constructor and destructor also.
- The member variable of structure can not be initialized directly.
***

### why to make Object Volatile ?

- The volatile keyword is intended to prevent the compiler from applying any optimizations on objects that can change in ways that
cannot be determined by the compiler.
- Objects declared as volatile are omitted from optimization because their values can be changed by code outside the scope of current code at any time.
- The system always reads the current value of a volatile object from the memory location rather than keeping its value in temporary register at the point it is requested, even if a previous instruction asked for a value from the same object.

--Global variables modified by an interrupt service routine outside the scope(Geeks for Geeks)
--Global variables within a multi-threaded application
***

### why to make function Volatile ?

- volatile qualifier states that the member should be used with a volatile object(when used a volatile function all the member variables will become volatile as well), that can be useful if you have a set of functions which are thread-safe, and another set which is not.
- So you can design your class so that the thread-safe functions declared with volatile qualifier, and if you want an object of that
class to be manipulated with threads or processes you will declare it as volatile.
***

### What is difference between new Vs malloc();

|new                                | malloc                    |
|:-                                 |:-                         |
|calls constructor                  |doesn't calls constructors |
|It is an operator                  |It is a function           |
|Returns exact data type            |Returns void *             |
|on failure, Throws exception       |On failure,returns NULL    |
|Memory allocated from free store   |Memory allocated from heap |
|can be overridden                  |cannot be overridden       |
|size is calculated by compiler     |size is calculated manually|
***

### What is ostream and istream classes ?

- All C++ compilers come with classes for streaming input from the console and output to the console. These classes are defined by putting the directive #include <iostream> at the top of the code.
- The istream class has methods for detecting input errors and the
end of input data. The ostream class has methods for formatting output, i.e. specifying scientific notation, fixed decimal notation,
or a combination thereof, and for specifying the number of decimal digits displayed. 
- Using some of the features of these classes, we
add the capability of reading and writing our own custom types. Finally, the ifstream and ofstream classes let us read from and write
to named files.

***
### What difference between 0 , NULL and \0 ? 

- 0 :  Integer constant for representing ZERO.
- \0: Character constant to represent NULL (nochar)
- NULL: Macro to represent NULL pointer (May be expanded to ((void*)0))
- nullptr: C++ keyword to represent NULL pointer.
****

### Mutex Vs Semaphore

***Semaphore :***

A semaphore restricts the number of simultaneous users of a shared resource up to a maximum number. Threads can request access to the
resource (decrementing the semaphore), and can signal that they have finished using the resource (incrementing the semaphore).

***Mutex :***

Mutexes are typically used to serialize access to a section of re-entrant code that cannot be executed concurrently by more than one
thread. A mutex object only allows one thread into a controlled section, forcing other threads which attempt to gain access to that
section to wait until the first thread has exited from that section

There is an ambiguity between binary semaphore and mutex. We might have come across that a mutex is binary semaphore. But they are not.
A mutex is locking mechanism and Semaphore is signaling mechanism.
***

### Explain Compilation Process:

#### 1.Preprocessing	:
```
g++ -E myfile.cpp -o myfile.i
```
The preprocessor handles directives that begin with #, such as #include, #define, and #ifdef. It performs textual substitution before the actual compilation begins.
- ***File Inclusion*** : The #include directives are processed, and the content of the included files is inserted into the current file.
- ***Macro Expansion*** : The #define macros are expanded.
- ***Conditional Compilation*** : Sections of code within #ifdef, #ifndef, #if, #else, and #endif are included or excluded based on the conditions.
- ***Line Control*** : Directives like #line can change the apparent line number and filename for error messages.
 

#### 2.Compilation :
```
g++ -S myfile.i -o myfile.s
```
The compilation stage translates the preprocessed source code into assembly code. This is where the actual parsing and syntax analysis happen.
- ***Lexical Analysis*** : The preprocessed code is broken down into tokens.
- ***Syntax Analysis*** : The tokens are analyzed according to the grammar rules of C++ to check for syntax errors.
- ***Semantic Analysis*** : This checks for semantic errors (e.g., type checking).
- ***Intermediate Code Generation*** : An intermediate representation of the code is generated (often as an Abstract Syntax Tree, or AST).
- ***Optimization*** : Various optimizations are applied to the intermediate code.
- ***Assembly Code Generation*** : The optimized intermediate code is translated into assembly language specific to the target architecture.

#### 3.Assembly :
```
g++ -c myfile.s -o myfile.o
```
In this stage, the assembler converts the assembly code into machine code, generating object files.
- ***Translation :*** The assembly instructions are translated into binary machine code instructions.
- ***Object File Generation :*** The machine code is packaged into an object file with a .o or .obj extension, along with metadata and relocation information.

### 4.Linking :
```
g++ myfile.o -o myprogram
```
The linker combines one or more object files into a single executable. It resolves references between object files and includes any necessary libraries.
- ***Symbol Resolution*** : Resolves references to symbols (variables and functions) across multiple object files.
- ***Relocation*** : Adjusts addresses and pointers in the machine code to reflect the final memory layout.
- ***Library Inclusion*** : Links with static or dynamic libraries to resolve external references.
***

### Libraries and Executables.

***Executable*** : 
These are files consisting mostly driver logic or self contained code that can be run directly.

***Libraries*** : 
These are files that contain reusable code that can be invoked by another library or an executable.

***Static library(.a) OR (.lib)*** : 
- A library that can be linked directly into the final executable produced by the linker,it is contained in the executable it self
and hence there is no need to have the library into the system where the executable will be deployed.
- Library has to be present in
compile time for static linking.

***Shared library(.so)*** : 
A library that is linked but not embedded in the final executable, so will be loaded when the executable is launched and need to
be present in the system where the executable is deployed.

***Dynamic link library on windows(.dll)*** : 
- It is like a shared library(.so) on linux but there are some differences between the two implementations that are related to the OS

***(Windows vs Linux)*** :

- A DLL can define two kinds of functions: exported and internal. The exported functions are intended to be called by other modules,
as well as from within the DLL where they are defined.
- Internal functions are typically intended to be called only from within the DLL where they are defined.
- An SO library on Linux doesn't need special export statement to indicate exportable symbols, since all symbols are available to an
interrogating process.
- The dlopen(3) function opens a library and prepares it for use. In C its prototype is:
```
void * dlopen(const char *filename, int flag);
```
- The dlsym() function shall search for the named symbol in all objects loaded automatically as a result of loading the object referenced by handle (see dlopen()).
- Load ordering is used in dlsym() operations upon the global symbol object. The symbol resolution algorithm used shall be dependency order as described in dlopen().
```
void *dlsym(void *restrict handle, const char *restrict name);
```
***



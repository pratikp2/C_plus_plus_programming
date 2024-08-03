# C++ Definitions and Concepts

### Class:

- It is a user defined data type like blueprint, which holds its own data members and member functions.
***

###   OOPS Pillars  
***1. Abstraction***	: 

- Data abstraction refers to providing only essential information to the outside world and hiding their background details, i.e.,to represent the needed information in program without presenting the details.

***2. Encapsulation*** :

- Encapsulation is a process of combining data members and functions in a single unit called class. This is to prevent the access to the data directly, the access to them is provided through the Object of the class.

***3.1 Compile time Polymorphism*** :

- It is also known as Static binding, Early binding and overloading. Overloading is compile time polymorphism where more than one methods share the same name with different parameters or signature and
different return type.

- IMP :    Function overloading do not happens on function return type (Compiler will throw ambiguity error on same function name
but diff arg type)

***3.2 Runtime Polymorphism*** :

- It is also known as Dynamic binding, Late binding and overriding.
Overriding is run time polymorphism having same method with same parameters or signature, but associated in a class & its subclass.

***4. Inheritance***:

- The capability of a class to derive properties and characteristics from its base class is called Inheritance.

***
### Access specifier

There are 3 access specifiers for a class/struct/Union in C++. These access specifiers define how the members of the class can be accessed. Of course, any member of a class is accessible within that class(Inside any member function of that same class). Moving ahead to type of access specifiers, they are:

- ***Public*** :
The members declared as Public are accessible from outside the Class through an object of the class.
- ***Protected*** :
  The members declared as Protected are accessible from outside the class BUT only in a class derived from it.
- ***Private*** :
  These members are only accessible from within the class. No outside Access is allowed.
***
### STORAGE CLASSES


|STORAGE CLASSES|KEYWORD |LIFETIME		   |VISIBILITY  |INITIAL VALUE |
|:-------------:|:------:|:--------------: |:---------: |:------------:|
|Automatic		|auto 	 |	Function Block |Local 	    |	Garbage    |
|External		|extern  |	Whole Program  |Global 		|	Zero       |
|Static			|static  |	Whole Program  |Local 		|	Zero       |
|Register		|register|	Function Block |Local 		|	Garbage    |
|Mutable		|mutable |	Class 		   |Local 		|	Garbage    |
||

Storage classes in C++ specify the scope, lifetime, and linkage of variables or functions. They provide important information about how variables and functions are stored in memory, how long they persist, and their visibility within different parts of a program. Here are the main storage classes in C++:

- Register : Hints to the compiler to store the variable in a CPU register for faster access.
- Static : Retains the value between function calls and restricts visibility to the file if used at the file level.
- Extern : Declares a variable or function that is defined in another file or later in the same file.
- Mutable : Allows a member of an object to be modified even if the object is const.
***

### Class Dependence

***1. Association*** :

- Association is a relationship where all objects have their own lifecycle and there is no owner.
- one-to-one, one-to-many, many-to-one, many-to-many all these words define an association between objects.
- Let's take an example of Teacher and Student. Multiple students can associate with single teacher and single student can associate
with multiple teachers, but there is no ownership between the objects and both have their own lifecycle. Both can be created and
deleted independently.

***2. Aggregation*** : 

- Aggregation is a specialized form of Association where all objects have their own lifecycle, but there is ownership and child objects can not belong to another parent object.
- Let's take an example of Department and teacher. A single teacher can not belong to multiple departments, but if we delete the
department, the teacher object will not be destroyed. We can think about it as a “has-a” relationship.

***3. Composition*** : 

- Compositions again specialized form of Aggregation and we can call this as a “death” relationship. It is a strong type of Aggregation.
- Child object does not have its lifecycle and if parent object is deleted, all child objects will also be deleted.
- Let's take again an example of relationship between House and Rooms. House can contain multiple rooms - there is no independent life of room and any room can not belong to two different houses. If we delete the house - room will automatically be deleted.

***
### STL (Standard Template Library)  

The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms and iterators. It is a generalized library and so, its components are parameterized. A working knowledge of template classes is a prerequisite  for working with STL.

STL has four components

	1. Algorithms 		 
	2. Containers -- vector, list, deque ,set, multiset, map, multimap
	3. Functions  -- Functor is objects that can be treated as though they are a function or function pointer.
	4. Iterators  -- 1.begin() 2.end() 3.advance() 4.prev() 5.next() 

***
### ASCII Code 
ASCII (American Standard Code for Information Interchange) is the most common format for text files in computers and on the Internet.
In an ASCII file, each alphabetic, numeric, or special character is represented with a 7-bit binary number (a string of seven 0s or 1s).
128 possible characters are defined.

***
### Unicode Encoding

It assigns every character a unique number called a code point. One advantage of Unicode over other possible sets is that the first
256 code points are identical to ISO-8859-1, and hence also ASCII

https://stackoverflow.com/##s/2241348/what-is-unicode-utf-8-utf-16

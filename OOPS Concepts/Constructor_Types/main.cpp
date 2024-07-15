# include <iostream>
using namespace std;

class ConstructorTypes {

    private :
        int size;
        double * arr_ptr;

    public :
        //int x,y;
        ConstructorTypes();                                         // 1.Default Constructor
        ConstructorTypes(int var1,int var2);                        // 2.Parameterized Constructor
        ConstructorTypes(int var);                                  // 3.Conversion Constructor
        explicit ConstructorTypes(char val);                        // 4.Explicit Constructor
        ConstructorTypes(const ConstructorTypes&);                  // 5.Copy Constructor
        ConstructorTypes(ConstructorTypes&&);                       // 6.Move Constructor.
        ConstructorTypes& operator = (const ConstructorTypes &obj); // Assignment Operator
        ~ConstructorTypes();                                        // Destructor

        ConstructorTypes GiveObjectCopy(ConstructorTypes obj);
        void ProcessObjectCopy(ConstructorTypes obj);
};

ConstructorTypes :: ConstructorTypes() {
    cout << "Invoking Default Constructor" <<endl;
    size = 10;
    arr_ptr = new double [size];
}

ConstructorTypes :: ConstructorTypes(int size) {
    cout << "Invoking Parameterized Constructor as a Conversion Constructor." << endl;
    this -> size = size;
    arr_ptr = new double [this->size];
}

ConstructorTypes :: ConstructorTypes(int size1, int size2) {
    cout << "Invoking Parameterized Constructor." << endl;
    this -> size = (size1+size2);
    this -> arr_ptr = new double [this->size];
}

ConstructorTypes :: ConstructorTypes(char size) {
    cout << "Invoking Parameterized Constructor as Explicit Constructor." << endl;
    if (size == 'A') this -> size = 10;
    this -> arr_ptr = new double [this->size];
}

 ConstructorTypes :: ConstructorTypes(const ConstructorTypes& obj) {
    cout << "Invoking Copy Constructor." << endl;

    this -> size = obj.size;
    this -> arr_ptr = new double [size];

    for (int i=0; i<size; i++)
        this -> arr_ptr[i] = obj.arr_ptr[i];    // Making Expensive Deep Copy.
    
 }

ConstructorTypes :: ConstructorTypes(ConstructorTypes&& obj) {
    cout << "Invoking Move Constructor." << endl;

    this -> size = obj.size;
    this -> arr_ptr = new double [size];
    this -> arr_ptr = obj.arr_ptr;          // Making Inexpensive shallow Copy as object has temporary Lifespan.
    obj.arr_ptr = NULL;                     // Setting pointer to NULL as its memory is going to be destroyed.
                                            // Avoid dangling pointer due to shallow copy.
}

ConstructorTypes :: ~ConstructorTypes() {
    delete arr_ptr;
    arr_ptr = nullptr;
}

ConstructorTypes& ConstructorTypes :: operator = (const ConstructorTypes &obj) {
    cout << "Invoking Assignment Operator" << endl;
}

ConstructorTypes ConstructorTypes :: GiveObjectCopy(ConstructorTypes obj) {
    return obj;
}

void ConstructorTypes :: ProcessObjectCopy(ConstructorTypes obj) {
   // Any Definition
}


int main () {
  cout <<endl<< "1. ";
  ConstructorTypes obj1;                                        // 1. Default Constructor

  cout <<endl<<endl<< "2. ";
  ConstructorTypes obj2(5,5);                                   // 2. Parameterized Constructor

  cout <<endl<<endl<< "3. ";
  ConstructorTypes obj3 = 10;                                   // 3. Conversion Constructor

  cout <<endl<<endl<< "4. ";
  ConstructorTypes obj4('A');                                   // 4. Explicit Constructor
  //ConstructorTypes obj4 = 'A';

  cout <<endl<<endl<< "5. ";
  ConstructorTypes obj5 = obj1;                                 // 5. Copy Constructor

  cout <<endl<<endl<< "6. ";
  obj5.ProcessObjectCopy(move(obj5));                           // 6. Move Constructor

  cout <<endl<<endl<< "7. ";
  obj3.ProcessObjectCopy(obj3.GiveObjectCopy(obj3));            // 6. Move Constructor and Copy Constructor

  cout <<endl<<endl<< "8. ";
  obj1 = obj2;                                                  // 7. Assignment Operator

  return 0;
}

// 1. Default Constructor.
// When providing a parameterize constructor or copy constructor the make sure to provide definition for default
// constructor if object is being created using a default constructor (Code Line : ConstructorTypes obj1).

// 3. Conversion Constructor
// Invoked when user tries to assign a simple data type to an object whose pararameterized constructor takes same argument
// as that simple data type

// 4. Explicit Constructor
// Declared to restrict the explicit type conversion from and simple data type to an object, i.e, if someone tries to invoke
// the conversion constructor using explit type conversion and that constructor is declared explicit then compiler will throw
// an error like in code line "ConstructorTypes obj4 = 'A';". This is done to avoid errros due to improper initilizations.

// 6. Move Constructor.
// Deep copy is Expensive operation mainly used to avoid dangling pointer condition. Some times deep copy can cause
// more CPU and time usage when heavy memory operations are involved.

// E.g. for function "ProcessObjectCopy" which expects an object data type as an argument, a function was given as argument
// which returns object to the outer function as argument. In this scenario when inner function "GiveObjectCopy" was called
// it calls a copy constructor to copy the contend of object due to "pass by value". After inner function returns object
// it will be treated as rvalue reference as an argument to outer the function and again a copy constructor will be called
// due to "pass by value" mechanism for outer function. And the rvalue reference given by the inner function will be destroyed
// quickly as soon as copy constructor goes out scope. Now this will cause overhead for the system in terms of time and CPU
// i.e, doing heavy memory operations for creation of object will be destroyed quickly.

// In such cases we prefer to call "Move Constructor" which performs a shallow copy when copy constructor is getting called
// for second time for heavy memory operation. Instead of doing deep copy compiler will recognize the rvalue reference given
// by the inner function and call "Move constructor", in which shallow copy is performed on heavy data types and pointers of
// lvalue data type will be set to null to avoid dangling pointer case as lvalue data type will be destroyed after Move Constructor
// goes out scope.

// Move constructor can also be invoked by the move semantics as shown.
// Function(std :: move(datatype));

// 6.Assignment Operator.
// When passing object to the assignment operator by "pass by value" 1st copy constructor and then assignment
// operator will get called

//NOTE :
//compile with flag "g++ -std=c++11 main.cpp" to include "C++ 11" features,and make necessary
//changes to IDE compiler to compile "C++ 11" features.

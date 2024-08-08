# C++ Syntaxes 

### Two Dimensional Array

```
int **A = new int*[M];

    for (i=0; i<M; i++) {
        A[i] = new int[N];
        for (j=0; j<N; j++) { }    
    }

for (i=0; i<M; ++i) { delete []A[i]; }
delete []A;
```
***

### Constructor Initializer list

```
class SampleClass {
public:
    const char* myString;
    SampleClass(const char* str) : myString(str) { }
};

```
***
### Constructor delegation
```
class MyClass {
private:
    int number;
    std::string text;

public:
    // Primary constructor
    MyClass(int num, const std::string& str) : number(num), text(str) {}

    // Delegated Constructors
    MyClass(int num) : MyClass(num, "default text") { }
    MyClass() : MyClass(0, "default text") { }
};
```
***
### Constructors and Operators Prototyping
```
class ConstructorTypes {

    private :
        int size;
        double * arr_ptr;

    public :
    
        ConstructorTypes(int var);                // Conversion Constructor
        explicit ConstructorTypes(char val);      // Explicit Constructor
        ConstructorTypes(const ConstructorTypes&);// Copy Constructor
        ConstructorTypes(ConstructorTypes&&);     // Move Constructor.

        // Assignment Operator
        ConstructorTypes& operator = (const ConstructorTypes &obj); 

        //Move Assignment operator
        ConstructorTypes& operator = (ConstructorTypes &&obj); 
};
```
***

### Templates
```
// Function Template

template <typename Any>
void Function(Any &a, Any &b) { }

-------------------------------------------

// Class Template

template <class Datatype>
class Sample {
private:
    Datatype A, B;

public:
    Sample(Datatype A, Datatype B);
    static Datatype C;
};

template <class Datatype>
Datatype Sample<Datatype>::C;

template <class Datatype>
Sample<Datatype>::Sample(Datatype A, Datatype B){ }

void main() {
    Sample<int> ObjSample1(2, 10);
    Sample<int>::C = 15;
}

-----------------------------------------

// Template Specialization

template <>
class Explore<char> {
private:
    char A;
};

```
***
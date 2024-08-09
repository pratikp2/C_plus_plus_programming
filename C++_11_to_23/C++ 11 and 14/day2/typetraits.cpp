#include <iostream>
using namespace std;

template <typename T>
void printTypeDetails(T t){
	cout << typeid(t).name() << endl;
	
	if(is_scalar<T>::value)
		cout << "  Scalar type" << endl;
	if(is_pointer<T>::value)
		cout << "  Pointer type" << endl;
	if(is_class<T>::value)
	{
		cout << "  Class type" << endl;
		
		if(is_trivial<T>::value)
			cout << "  --Trivial type" << endl;
		if(is_standard_layout<T>::value)
			cout << "  --Standard layout type" << endl;
		if(is_pod<T>::value)
			cout << "  --POD type" << endl;
	}
}
class A{
public: int num;
};
class B{
public:
	int num;
private:
	int num2;
};

class C{
public:
	C(){}
};
class D{
public:
	virtual void Fun(){}
};

template<typename T>
void refType(T& t){
	remove_reference<T&>::type v{t};
	v++;
}
void main()
{
	int num{10};
	printTypeDetails(num);
	
	int* ptr{&num};
	printTypeDetails(ptr);
	
	printTypeDetails(A{});
	printTypeDetails(B{});
	printTypeDetails(C{});
	printTypeDetails(D{});
	
	refType(num);
	cout << num << endl;
}
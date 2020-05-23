#ifndef NUMbER_H
#define NUMbER_H

#ifdef DEBUG
#define FUNCSIG			std::cout << __FUNCSIG__ << std::endl;
#else
#define FUNCSIG
#endif


class Number{
public:
	Number():ptr(nullptr){}
	Number(int value){
		//FUNCSIG
		Alloc(value);
	}
	Number(const Number& rhs){
		//FUNCSIG
		Alloc(*rhs.ptr);	
	}
	Number& operator=(const Number& rhs){
		//FUNCSIG
		if(this != &rhs){
			Release();
			Alloc(*rhs.ptr);
		}
		return *this;
	}

#ifdef MOVE	
	Number(Number&& rhs)noexcept{
		//FUNCSIG
		ptr = rhs.ptr;
		rhs.ptr = nullptr;
	}
	Number& operator=(Number&& rhs){
		//FUNCSIG
		if(this != &rhs){
			Release();
			ptr = rhs.ptr;
			rhs.ptr = nullptr;
		}
		return *this;
	}
#endif	
	~Number(){
		//FUNCSIG
		Release();
	}
	int Value(){
		if(ptr != nullptr)
			return *ptr;
		return -1;
	}
	static int __Count(){
		return __count;
	}
private:
	void Alloc(int value){
		FUNCSIG
		ptr = new int(value);
		__count++;
	}
	void Release(){
		//FUNCSIG
		if(ptr != nullptr){
			delete ptr;
			ptr = nullptr;
		}		
	}
	int* ptr;
	static int __count;
};
int Number::__count = 0;

#endif
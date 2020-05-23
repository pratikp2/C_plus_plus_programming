#ifndef CUSTOMARRAY_H
#define CUSTOMARRAY_H

//#define INC 	5

template<typename T, int inc = 5>
class CustomArray{
public:
		CustomArray(){
			cap = inc;
			len = 0;
			data = new T[inc];
		}
		CustomArray(std::initializer_list<T> list){
			cap = list.size();
			len = 0;
			data = new T[cap];
			for(auto value : list)
				data[len++] = value;
		}
		~CustomArray(){
			if(data != nullptr)
				delete[] data;
		}
#ifdef MOVE
		void PushBack(T&& value){
			ResizeIf();
			data[len++] = std::move(value);
		}
#else
		void PushBack(T value){
			ResizeIf();
			data[len++] = value;
		}
#endif
		class Iterator{
		public:
			Iterator(T* p):ptrData(p){}
			bool operator!=(Iterator& rhs){return ptrData != rhs.ptrData;}
			Iterator operator++(){ptrData++; return *this;}
			T operator*(){return *ptrData;}
		private:
			T* ptrData;
		};
		Iterator begin(){return Iterator(data);}
		Iterator end(){return Iterator(data+len);}
		
		// int* begin(){return data;}
		// int* end(){return data+len;}
private:
	void ResizeIf(){
		if(len == cap){
			cap += inc;
			T* temp = new T[cap];
			for(int i = 0; i < len; i++)
#ifdef MOVE
				temp[i] = std::move_if_noexcept(data[i]);
#else
				temp[i] = data[i];
#endif			
			delete[] data;
			data = temp;
		}
	}
	
	T* data;	
	int cap;
	int len;
};

#endif
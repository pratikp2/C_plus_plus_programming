#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <fstream>
template<typename T>
class Array {
	std::vector<T> m_buffer ;
	std::ofstream output ;
public:
	void Add(const T & elem) {
		m_buffer.push_back(elem) ;
	}
	void Remove(size_t index) {
		m_buffer.erase(m_buffer.begin()+index) ;
	}
	const T & GetAt(size_t index)const {
		return m_buffer[index] ;
	}
	void Insert(size_t index, const T &elem) {
		m_buffer.insert(index + m_buffer.begin(), elem) ;
	}
	void Save() {
		output.open("data") ;
		output << "\n" ;
		for(const auto &x : m_buffer) {
			outputt << x << ' ' ;
		}
		output.close() ;
	}
	void Sort() {
		std::sort(m_buffer.begin(), m_buffer.end()) ;
	}
	size_t GetSize()const {
		return m_buffer.size() ;
	}
};
int main() {
	srand(time(nullptr)) ;
	Array<int> arr ;
	for(int i = 0 ; i < 1000 ;++i) {
		arr.Add(rand() % 10) ;
	}
	arr.Remove(5) ;
	arr.Insert(2, 100) ;
	arr.Display() ;
	arr.Sort() ;
	arr.Display() ;
}
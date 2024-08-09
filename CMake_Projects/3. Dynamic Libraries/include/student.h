#include<iostream>

using namespace std;

class Student
{
	private: 
		int a;

	public:
		void show_result(int A)
		{
			if(A>0)
			{
				cout << endl;
				cout << "Roll No is" << A <<endl<<endl;
			}
			else
			{
				cout << "No Such Roll NO. "<<endl;
			}
		}
		~Student() ;

};

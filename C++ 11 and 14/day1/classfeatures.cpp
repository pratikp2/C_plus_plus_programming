#include <iostream>
#include <string>
using namespace std;

class Address{
public:
	//Address(string a = "baner", string c = "pune"):area(a), city(c){}
	Address() = default;		//default constructor
	void SetCity(string c){city = c;}
	void SetArea(string a){area = a;}
private:
	string area = "baner";  //in-class initialization
	string city{"pune"};	//in-class initialization
};

class Employee{
public:
	Employee(string n):Employee(n, 200, 150){	//constructor delegation
		//cout << __FUNCSIG__ << endl;
	}
	Employee(string n, int r, int h):name(n), rate(r), hours(h){
		//cout << __FUNCSIG__ << endl;
		id = "Emp00" + std::to_string(++count);
	}
	Employee& operator=(const Employee& ) = delete;		//deleted method
	void SetRate(int r){ rate = r;}
	int Rate(){return rate;}
	int Hours(){return hours;}
	void SetHours(int h){hours = h;}
	static int TotalEmployees(){return count;}
	virtual int GetIncome(){return hours * rate;}
	virtual int GetBonus()final{return hours * rate * 0.1;}
	
private:
	string name;
	string id;
	int rate;
	int hours;
	static int count;
	Address addr;
};
int Employee::count = 0;

class SalesPerson final : public Employee{			//final class
public:
	using Employee::Employee;		//inherited contsturctor
	//int GetBonus(){return 0;}		//final method
	int GetIncome()override{return (Rate() * Hours()) + sales*0.05;} //override method
	void SetSales(int s){sales = s;}
	
private:
	int sales = 0;
};


// class Developer : public SalesPerson{		//final class
	// using SalesPerson::SalesPerson;
// };

class Developer : public Employee{
	using Employee::Employee;
};
int calculateSalary(initializer_list<Employee*> list){
	int totalSalary = 0;
	for(auto emp : list)
		totalSalary += emp->GetIncome();
	return totalSalary;
}	
void main()
{
	Employee emp1{"Jack"};
	Employee emp2{"Jill"};
	
	SalesPerson s1{"Jim"};
	s1.SetSales(100000);
	
	Developer d1{"Jane"};
	
	//emp1 = emp2;
	
	cout << "Total Employees: " << Employee::TotalEmployees() << endl;
	cout << "Total Salary: " << calculateSalary({&emp1, &emp2, &s1, &d1}) << endl;
	
}
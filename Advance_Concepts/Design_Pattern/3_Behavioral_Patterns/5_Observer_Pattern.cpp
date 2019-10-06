#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Car_Observer;

enum states
{
	Invalid = -2,
	Left = -1,
	Middle = 0,
	Right = 1,
};

class Car_Subject
{
	private:
		states m_position = states::Invalid;
		vector<Car_Observer*> m_observerList;
	
	public:
		void attach(Car_Observer * obs) {m_observerList.push_back(obs);}
		void detach(Car_Observer * obs) {m_observerList.erase(std::remove(m_observerList.begin(), m_observerList.end(), obs),m_observerList.end());}
		void notify();
		
		states getPosition() {return m_position;}
		
		void setPosition(states pos)
		{
			this-> m_position = pos;
			this->notify();
		}	
};

class Car_Observer
{
	private:
		Car_Subject * m_subject;
		
	public:
		Car_Observer(Car_Subject * objSubject)
		{
			m_subject = objSubject;
			m_subject->attach(this);
		}
		
		virtual void update() = 0;
	
	protected:
		Car_Subject * getCar(){ return m_subject; }
};

void Car_Subject :: notify()
{
	for(int i=0; i<m_observerList.size(); i++)
	{
		m_observerList[i]-> update();
	}
}

class LeftStateObserver : public Car_Observer
{
	public:
		LeftStateObserver(Car_Subject * subject) : Car_Observer(subject){}
		void update()
		{
			int pos = getCar()->getPosition();
			if(pos == states::Left) {cout << "In Left State";}
		}
};

class MiddleStateObserver : public Car_Observer
{
	public:
		MiddleStateObserver(Car_Subject * subject) : Car_Observer(subject){}
		void update()
		{
			int pos = getCar()->getPosition();
			if(pos == states::Middle) {cout << "In Middle State";}
		}
};

class RightStateObserver : public Car_Observer
{
	public:
		RightStateObserver(Car_Subject * subject) : Car_Observer(subject){}
		void update()
		{
			int pos = getCar()->getPosition();
			if(pos == states::Right) {cout << "In Right State";}
		}
};

int main()
{
	Car_Subject * ptrCarSubject = new Car_Subject();
	
	LeftStateObserver objLeftObserver(ptrCarSubject);
	MiddleStateObserver objMiddleObserver(ptrCarSubject);
	RightStateObserver objRightObserver(ptrCarSubject);
	
	char val;
	bool breakloop = false;
	
	cout << endl;
	cout << "**********************************************************" <<endl<<endl;
	cout << "	Press according to Following" << endl;
	cout << "		1. Press L to go Left" << endl;
	cout << "		2. Press M to go Middle" << endl;
	cout << "		3. Press R to go Right" << endl;
	cout << "		4. Press E to Exit" << endl<<endl;
	cout << "***********************************************************" <<endl;
	cout << endl;
	
	while(breakloop == false)
	{
		cout << endl;
		cout << "Input : ";
		cin >> val;
		
		switch(val)
		{
			case 'L':
			case 'l':
				ptrCarSubject->setPosition(states::Left);
				break;
			
			case 'M':
			case 'm':
				ptrCarSubject->setPosition(states::Middle);
				break;
			
			case 'R':
			case 'r':
				ptrCarSubject->setPosition(states::Right);
				break;
			
			case 'E':
			case 'e':
				breakloop = true;
				break;
				
				break;
			default:
				cout << "Please select proper state" << endl;
				break;	
		}
	}
	
	return 0;
}
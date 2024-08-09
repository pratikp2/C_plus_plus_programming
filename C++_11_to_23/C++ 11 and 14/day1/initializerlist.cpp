#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ErrorMsg{
public:
	ErrorMsg(string str){
		msgVect.push_back(str);
	}
	ErrorMsg(string str1, string str2){
		msgVect.push_back(str1);
		msgVect.push_back(str2);
	}
	ErrorMsg(initializer_list<string> list):msgVect(list){}
	
	void Show(){
		for(vector<string>::const_iterator it = msgVect.begin(); it!= msgVect.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
private:
	vector<string> msgVect;
};

void main()
{
	ErrorMsg msg1{"Error msg1"};
	msg1.Show();
	
	ErrorMsg msg2{"Msg string1", "Msg string2"};
	msg2.Show();

	ErrorMsg msg3{"Msg string1", "Msg string2", "new string1", "new string2"};
	msg3.Show();
	
	vector<int> intVect = {1,2,3,4,5};
}
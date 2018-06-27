#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef map<string,int> phoneMap;

int main()
{
 string name;
 int number;
 phoneMap phone;
 cout << "Enters three sets of name and number";
 for(int i=0;i<3;i++)
 {
 cin >> name;
 cin >> number;
 phone[name] = number;
 }
 //phoneMap :: iterator p;
 for(phoneMap:: iterator p=phone.begin();p!=phone.end();p++)
 {
 cout << p->first<< p->second;
 }

 phone.insert()
}

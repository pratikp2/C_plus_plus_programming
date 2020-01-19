#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
using namespace std;

struct DataTemplate
{
    int MaxSlices;
    int NoOfPizzas;
    map<int,int> slices;
};

struct DataTemplate* ConvertData(string);
string GetString();
void ProcessData(struct DataTemplate*);
void SetString(struct DataTemplate*);

int main()
{
    DataTemplate * ptr;
    string s = GetString();
    ptr = ConvertData(s);

    cout << "Input Str  :   " << s << endl << endl;
    cout << "Maxium No  :   " << ptr->MaxSlices << endl;
    cout << "Pizza No   :   " << ptr->NoOfPizzas << endl;
    cout << "Sequence   :   ";
    for(int i=0; i<ptr->slices.size(); i++)
        cout << ptr->slices[i] << " ";
    cout << endl<< endl;
    ProcessData(ptr);
    //SetString(ptr);

    return 0;
}

struct DataTemplate* ConvertData(string s)
{
    DataTemplate * ptr = new DataTemplate;

    string temp1(s,0,s.find(" "));
    ptr->MaxSlices = stoi(temp1);
    s.erase(0,s.find(" ")+1);

    string temp2 (s,0,s.find(" "));
    ptr->NoOfPizzas = stoi(temp2);
    s.erase(0,s.find(" ")+1);

    for(int i=0; i<ptr->NoOfPizzas; i++)
    {
        string temp(s,0,s.find(" "));
        s.erase(0,s.find(" ")+1);
        ptr->slices.insert(pair<int,int> (i,stoi(temp)));
    }
    return ptr;
}

void ProcessData(struct DataTemplate * ptr)
{
    int SliceSum = 0, Difference = 0;
    int size = ptr->slices.size();

    for(int i=0; i<size; i++)
        SliceSum = SliceSum + ptr->slices[i];

    if (SliceSum < ptr->MaxSlices)
        return;
    else
        Difference = SliceSum - ptr->MaxSlices;

    /*while (SliceSum <= ptr->MaxSlices)
    {

    }*/

    cout <<"Slices NO  :   "<<SliceSum << endl;
    cout <<"Difference :   "<<Difference << endl;
    cout << endl;
}

string GetString()
{
    string s1,s2;
    ifstream DATA_FILE;

    try
    {
        DATA_FILE.open("b_small.in",ios::in);
        getline(DATA_FILE,s1);
        getline(DATA_FILE,s2);
        s1 = s1 + " " + s2;
        DATA_FILE.close();
    }
    catch (exception x) { cout << "File Error ... !" << endl;}
    return s1;
}

void SetString(struct DataTemplate * ptr)
{
    int size = ptr->slices.size();
    string temp = "";
    try
    {
        ofstream DATA_FILE;
        DATA_FILE.open("Ans.out",ios::out);

        DATA_FILE << size <<endl;
        for(int i=0; i<size; i++)
            temp = temp + " " + to_string(ptr->slices[i]);
        temp.erase(0,1);
        DATA_FILE << temp <<endl;

        DATA_FILE.close();
    }
    catch (exception x){ cout << "File Error ... !" << endl;}
}

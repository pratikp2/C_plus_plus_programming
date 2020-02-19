#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int TARGET = 0;
int CURRENTSUM = 0;
std::string TEMP = "";

struct DataTemplate
{
    int MaxSlices;
    int NoOfPizzas;
    map<int, int> slices;

    DataTemplate()
    {
        this -> MaxSlices = 0;
        this->NoOfPizzas = 0;
    }
};

struct DataTemplate* ConvertData(string);
string GetString();
void ProcessData(struct DataTemplate*);
void SetString(struct DataTemplate*);
int RecursionBackTracking(DataTemplate*, int, int, string);

int main()
{
    DataTemplate* ptr;
    string s = GetString();
    ptr = ConvertData(s);

    /*cout << "Input Str  :   " << s << endl << endl;
    cout << "Maxium No  :   " << ptr->MaxSlices << endl;
    cout << "Pizza No   :   " << ptr->NoOfPizzas << endl;
    cout << "Sequence   :   ";
    for (unsigned int i = 0; i < ptr->slices.size(); i++)
        cout << ptr->slices[i] << " ";
    cout << endl << endl;*/

    ProcessData(ptr);
    SetString(ptr);

    return 0;
}

struct DataTemplate* ConvertData(string s)
{
    DataTemplate* ptr = new DataTemplate();
    size_t start = 0, end = 0;
    try
    {
        end = s.find(" ");
        ptr->MaxSlices = stoi(s.substr(start, end));

        start = end;
        end = s.find(" ", end + 1);
        ptr->NoOfPizzas = stoi(s.substr(start, end));
    }
    catch (...) {}

    for (int i = 0; i < ptr->NoOfPizzas; i++)
    {
        start = end;
        end = s.find(" ", end + 1);
        ptr->slices.insert(pair<int, int>(i, stoi(s.substr(start, end))));
    }
    return ptr;
}

void ProcessData(struct DataTemplate* ptr)
{
    //cout << "Combination Trace : "<<endl;
    cout << RecursionBackTracking(ptr,0, 0,"") << endl << endl;
    //cout << "Ans : " << CURRENTSUM << endl;
    //cout << "Ans : " << TEMP << endl;
}

int RecursionBackTracking(DataTemplate * ptr, int index, int sum, string s)
{
    if (index > ptr->NoOfPizzas || sum == ptr->MaxSlices)
    {
        if (sum > CURRENTSUM && sum <= ptr->MaxSlices)
        {
            CURRENTSUM = sum;
            TEMP = s;
        }
        else
            sum = CURRENTSUM;
        return sum;
    }

    int sum1 = RecursionBackTracking(ptr,index+1, sum, s);

    if(sum + ptr->slices[index] <= ptr->MaxSlices)
        sum = RecursionBackTracking(ptr, index+1, sum + ptr->slices[index], s + " " + to_string(ptr->slices[index]));

    sum = (sum > sum1) ? sum : sum1;

    cout << sum << " ";
    return sum;
}

string GetString()
{
    string s1, s2;
    ifstream DATA_FILE;

    try
    {
        DATA_FILE.open("a_example.in", ios::in);
        getline(DATA_FILE, s1);
        getline(DATA_FILE, s2);
        s1 = s1 + " " + s2;
        DATA_FILE.close();
    }
    catch (exception x) { cout << "File Error ... !" << endl; }
    return s1;
}

void SetString(struct DataTemplate* ptr)
{
    int size = 0;
    for (int i=0; i<TEMP.size(); i++)
        if(TEMP[i] == ' ')
            size++;
    try
    {
        ofstream DATA_FILE;
        DATA_FILE.open("Ans.out", ios::out);
        DATA_FILE << size << endl;
        TEMP.erase(0, 1);
        DATA_FILE << TEMP << endl;

        DATA_FILE.close();
    }
    catch (exception x) { cout << "File Error ... !" << endl; }
}

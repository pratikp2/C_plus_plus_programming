#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<cstring>
using namespace std;

void ExtractData(string s,vector<char> &data)
{
    int size = s.length();
    char holder[size+1];
    strcpy(holder, s.c_str());

    for(int i=0; i<size; i++)
    {
        data.push_back(holder[i]);
    }
}

void ConvertData(vector<int> &data, vector<char> &stringdata)
{
    int i = stringdata.size();
    string s = "";
    while(true)
    {
        while(stringdata[i] != ' ')
        {
            s=s+stringdata[i];
            i--;
        }
        if(i==0)
            break;
    }
    //data.push_back(atoi(stringdata[i]));
}

int main()
{
    string TEMP;
    ifstream DATA_FILE;
    vector<int> data;
    vector<char> stringdata;
    vector<char> :: iterator itr;

    try
    {
        DATA_FILE.open("a_example.in",ios::in);
        getline(DATA_FILE,TEMP);
        ExtractData(TEMP, stringdata);
        getline(DATA_FILE,TEMP);
        ExtractData(TEMP, stringdata);
        DATA_FILE.close();
    }
    catch (exception x) { cout << "File Error ... !" << endl;}

    //for (itr = stringdata.begin(); itr != stringdata.end(); ++itr){ cout << *itr << " ";}
    //cout << endl;

    return 0;
}


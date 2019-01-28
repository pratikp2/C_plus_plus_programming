#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    //ofstream file_("Sample_Text_File.txt");

    ofstream file_;
    file_.open("Sample_Text_File.txt");

    if (file_.is_open())
    {
        file_ << "Hello Wrold \n";
        file_.close();
    }

    return 0;
}


// ofstream file_("_.txt") will create new file with name passed as an argument. If file is already present file will be created newly
// and contends will be overwritten. Similar for file_.open("Sample_Text_File.txt").

#include <iostream>
//#include <ofstream>
//#include <ifstream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file_("mytext.txt");
    file_.open("mytext.txt");
    if (file_.is_open())
    {
        file_ << "Hello   is Ali\n" << endl;
        file_ << "I work for KPIT\n" << endl;
        file_.close();
    }
    std::cin.get();
    return 0;
}


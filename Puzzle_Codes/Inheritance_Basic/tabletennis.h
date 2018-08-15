#ifndef TABLETENNIS_H
#define TABLETENNIS_H

#include <iostream>
#include <cstring>

using namespace std;

class TableTennis
{
private :
    //static int Arr;
    char firstname[20];
    char lastname[20];
    bool hasTable;

public:
    TableTennis(const char *fn = "none",const char *ln = "none",bool table = false);
    void name() const ;

    bool HasTable() const
    {
        return hasTable ;
    }

    void resetTable(bool v)
    {
        hasTable = v;
    }

};

class RatedPlayer : public TableTennis
{
private :
    int Rating ;

public :
    RatedPlayer(int r = 0,const char *fn = "none",const char *ln = "none",bool table = false);
    RatedPlayer(int r,const TableTennis & tt);

    int rating() const
    {
        return Rating;
    }
    void resetRating(int r)
    {
        Rating = r;
    }
};

#endif // TABLETENNIS_H

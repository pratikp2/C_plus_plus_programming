#include "tabletennis.h"

//int TableTennis :: Arr = 20;

TableTennis::TableTennis(const char *fn,const char *ln,bool table)
{
    strncpy(firstname, fn, 20 - 1);
    firstname[20 - 1] = '\0';

    strncpy(lastname, ln, 20 - 1);
    lastname[20 - 1] = '\0';

    hasTable = table;
}

void TableTennis :: name() const
{
    cout << firstname << "," << lastname << endl;
}

RatedPlayer :: RatedPlayer (int r, const char *fn,const char *ln,bool table)
    : TableTennis(fn,ln,table)
{
    Rating = r;
}

RatedPlayer :: RatedPlayer (int r,const TableTennis & tt)
    :Rating(r),TableTennis(tt)
{

}

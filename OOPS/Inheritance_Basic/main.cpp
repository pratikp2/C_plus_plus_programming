#include<tabletennis.h>

int main()
{
    TableTennis player1("Tara","Boomdea", false);
    RatedPlayer rplayer1(1140,"Mallory","Duck", true);
    RatedPlayer rplayer2(1212, player1);

    rplayer1.name();
        if (rplayer1.HasTable())
            cout << ": has a table.\n";
        else
            cout << ": hasn’t a table.\n";

    player1.name();
        if (player1.HasTable())
            cout << ": has a table";
        else
            cout << ": hasn’t a table.\n";
            cout << "Name: ";

    rplayer1.name();
            cout << "; Rating: " << rplayer1.rating() << endl;

        cout << "Name: ";
    rplayer2.name();
        cout << "Rating: " << rplayer2.rating() << endl;
    return 0;


}


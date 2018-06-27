#include "shares.h"

int main()
{
   CShares Pratik_Shares;

   Pratik_Shares.aquireCompanyShares("KPIT",60,110);
   Pratik_Shares.show();

   Pratik_Shares.buy(100,110);
   Pratik_Shares.show();

   Pratik_Shares.sell(50,110);
   Pratik_Shares.show();

   Pratik_Shares.sell(200,110);
   Pratik_Shares.show();

    return 0;
}


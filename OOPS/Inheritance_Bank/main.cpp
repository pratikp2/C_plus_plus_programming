#include <iostream>
#include <facility.h>



int main()
{

Facility Piggy("Porcelot Pigg", 381299, 4000.00);
AddFacility Hoggy("Horatio Hogg", 382288, 3000.00);

Piggy.viewacct();
cout << endl;

Hoggy.viewacct();
cout << endl;

cout << "Depositing $1000 into the Hogg Account:\n";
Hoggy.deposit(1000.00);

cout << "New balance: $" << Hoggy.balance() << endl;
cout << "Withdrawing $4200 from the Pigg Account:\n";
Piggy.withdraw(4200.00);

cout << "Pigg account balance: $" << Piggy.balance() << endl;
cout << "Withdrawing $4200 from the Hogg Account:\n";
Hoggy.withdraw(4200.00);

Hoggy.viewacct();
return 0;
}



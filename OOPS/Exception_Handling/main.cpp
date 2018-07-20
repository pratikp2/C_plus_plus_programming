/** *********************************************************************************************************
    Why Exception Handling :
    1. Separation of Error Handling code from Normal Code :  The if else conditions to handle errors in
        traditional code and the actual code gets mixed up with the normal flow.
    2. Functions/Methods can handle any exceptions they choose :  A function can throw many exceptions,
        but may choose to handle some of them.
    3. Grouping of Error Types : We can create a hierarchy of exception objects, group exceptions in
        namespaces or classes, categorize them according to types.

    Rules :
    1. try block should be immediately followed by catch block( not single one of them should be misplaced missing).
    2. There can be multiple catch block (similar to overloading)
    3. An Exception can be thrown from out side try block only via function called through try.
    4. Every exception must be caught by the code or else it will terminate at runtime.(Including one throw and diff
       catch)
    5. If throw statement do not throw any data type program will terminate at Runtime (void and "..." will not work
        in catch as args)
    6. If thrown data type is not important and don't wanted to be processed simply mentioned data type int the catch
       block (like:- catch(int){} )
    7. Any type of data type can be thrown.(simple data types,pointers, object type.)
*************************************************************************************************************/

# include <iostream>
using namespace std;

int main ()
{
    int DadAge,SonAge;

    cout << "Please Enter the Dad's age" << endl;
    cin >> DadAge;
    cout << endl;

    cout << "Please Enter the Son's age" << endl;
    cin >> SonAge;
    cout << endl;


    try                     // Program statement that you want to monitor for exceptions are written in try block.
    {
        if(SonAge > DadAge)
        {
            throw 1;        // Any exceptions occurred int the try block is thrown.
        }
        else if ((SonAge+15) > DadAge)
        {
            throw 2;
        }
        else if (DadAge<25)
        {
            throw 3;
        }
        else
        {
            cout << "Entered ages are valid" << endl;
        }
    }

    catch(int x)            // An exception is caught in the catch block and handled in it.
    {
        if(x == 1)
        {
            cout << "Received error code : " << x <<endl;
            cout << "Father's age can not be smaller than Child's age." << endl;
        }
        else if(x == 2)
        {
            cout << "Received error code : " << x <<endl;
            cout << "Father's age should be greater than Child's age by at least 15 years." << endl;
        }
        else if(x == 3)
        {
            cout << "Received error code : " << x <<endl;
            cout << "Father's age should be greater than 24 years." << endl;
        }
        else
        {
            cout << "Received Invalid Error Code : "<< x << endl;
        }
    }

    catch(...) {}           // Can catch any type of exception (default)
//  catch (int *x) {}
//  catch(int) {}
//  catch(anyDataType x){}

    return 0;
}

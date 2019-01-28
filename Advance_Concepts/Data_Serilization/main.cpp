#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

class Person
{
private :
    string PersonName;
    string Occupation;
    string Location;
    string Reference;

public :
    Person(){}
    ~Person(){}

    void SetPersonName(string X){PersonName = X;}
    void SetPersonOccupation(string X){Occupation = X;}
    void SetPersonLocation(string X){Location = X;}
    void SetPersonReference(string X){Reference = X;}

    string GetPersonName(){return PersonName;}
    string GetPersonOccupation(){return Occupation;}
    string GetPersonLocation(){return Location;}
    string GetPersonReference(){return Reference;}

};

// Functions
void CreatePerson();
void EditPerson();
void DisplayPerson();
void SavePerson();
void LoadPerson();

Person * ptrPerson;

int main()
{
    int Choice = 0;
    ptrPerson = new Person();
    cout << "Personal Database" << endl;

    while (Choice !=6)
    {

        cout << " ------------------------------ Main Menu -----------------------------" << endl;
        cout << "|                                                                      |" << endl;
        cout << "|              1. Create a Person                                      |" << endl;
        cout << "|              2. Edit a Person's Information                          |" << endl;
        cout << "|              3. Display a Person                                     |" << endl;
        cout << "|              4. Save a Person                                        |" << endl;
        cout << "|              5. Load a Person                                        |" << endl;
        cout << "|              6. Quit                                                 |" << endl;
        cout << "|                                                                      |" << endl;
        cout << "-----------------------------------------------------------------------" << endl << endl;

        cout << "Enter the Choice from following" << endl;
        cin >> Choice;

        switch (Choice) {
        case 1: CreatePerson(); break;
        case 2: EditPerson(); break;
        case 3: DisplayPerson(); break;
        case 4: SavePerson(); break;
        case 5: LoadPerson(); break;
        case 6: cout << endl <<"Exiting Main Menu "; break;
        default: cout << endl << "Invalid Input ";break;
        }
    }

    return 0;
}

void CreatePerson()
{

}

void EditPerson()
{
    system("CLS");
    cout << " ---------------- Edit Person -------------" << endl;
    cin.ignore();
    string TEMP;

    cout << "NAME          : ";
    getline(cin,TEMP);
    ptrPerson->SetPersonName(TEMP);

    cout << "Occupation    : ";
    getline(cin,TEMP);
    ptrPerson->SetPersonOccupation(TEMP);

    cout << "Location       : ";
    getline(cin,TEMP);
    ptrPerson->SetPersonLocation(TEMP);

    cout << "References     : ";
    getline(cin,TEMP);
    ptrPerson->SetPersonReference(TEMP);
    cout << " ------------------------------------------" << endl;

}

void DisplayPerson()
{
    system("CLS");
    cout << " ------------------------ Person Information --------------------" << endl;
    cout << "|       1. NAME         : " << ptrPerson->GetPersonName() << endl;
    cout << "|       2. Occupation   : " << ptrPerson->GetPersonOccupation() << endl;
    cout << "|       3. Location     : " << ptrPerson->GetPersonLocation() << endl;
    cout << "|       4. References   : " << ptrPerson->GetPersonReference() << endl;
    cout << " ----------------------------------------------------------------" << endl;
}

void SavePerson()
{
    try
    {
        ofstream DATA_FILE;
        DATA_FILE.open("DATA1_FILE.txt",ios::out);

        DATA_FILE << ptrPerson->GetPersonName() << endl;
        DATA_FILE << ptrPerson->GetPersonOccupation() << endl;
        DATA_FILE << ptrPerson->GetPersonLocation() << endl;
        DATA_FILE << ptrPerson->GetPersonReference() << endl;

        DATA_FILE.close();

        cout << "Success .. ! Data was Saved to File" << endl;

    }
    catch (exception x)
    {
        cout << "File Error ... ! Could not save Person." << endl;
    }
}

void LoadPerson()
{
    try
    {
        string TEMP;
        ifstream DATA_FILE;
        DATA_FILE.open("DATA1_FILE.txt",ios::in);

        cout << "NAME          : ";
        getline(DATA_FILE,TEMP);
        ptrPerson->SetPersonName(TEMP);

        cout << "Occupation    : ";
        getline(DATA_FILE,TEMP);
        ptrPerson->SetPersonOccupation(TEMP);

        cout << "Location       : ";
        getline(DATA_FILE,TEMP);
        ptrPerson->SetPersonLocation(TEMP);

        cout << "References     : ";
        getline(DATA_FILE,TEMP);
        ptrPerson->SetPersonReference(TEMP);

        DATA_FILE.close();

        cout << "Success .. ! Data was Saved to File" << endl;

    }
    catch (exception x)
    {
        cout << "File Error ... ! Could not Load Person." << endl;
    }
}

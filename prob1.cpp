#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
char seating[13][6];
void load();
void store();
int mainMenu();
void askUser();
void clearScreen();
void typeCasting(string address);
void classIdx(int start, int stop);
void displayReserved();
int option = 0;
string address;
int addressCol;
int addressRow;
main()
{
    load();
    while (option < 6)
    {
        system("cls");
        option = mainMenu();
        if (option == 1)
        {
            load();
            cout << "Seats are loaded successfully" << endl;
            clearScreen();
        }
        else if (option == 2)
        {
            askUser();
            clearScreen();
        }
        else if (option == 3)
        {
            displayReserved();
            clearScreen();
        }
        else if (option == 4)
        {
            store();
            cout << "Seats are stored successfully" << endl;
            clearScreen();
        }
    }
}

// Function Definitions
int mainMenu()
{
    int option;
    cout << "Main Menu" << endl;
    cout << "---------------------" << endl;
    cout << "Select one of the following options..." << endl;

    cout << "1- Load Seats" << endl;
    cout << "2- Add ticket type and desired seats" << endl;
    cout << "3- Reserved Seats" << endl;
    cout << "4- Store Seats" << endl;

    cout << "Your Option..";
    cin >> option;
    return option;
}
void clearScreen()
{ //____clear screen_____
    cout << "Press any key to continue " << endl;
    getch();
    system("CLS");
}
void load()
{
    fstream file;
    string x;
    file.open("seat.txt", ios::in);
    while (!file.eof())
    {
        for (int i = 0; i < 13; i++)
        {
            getline(file, x);
            for (int j = 0; j < 6; j++)
            {
                seating[i][j] = x[j];
            }
        }
    }
    file.close();
}
void store()
{
    fstream file;
    file.open("seat.txt", ios::out);
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            file << seating[i][j];
        }
        file << endl;
    }
    file.close();
}

void displayReserved()
{
    cout << "\t"
         << "A"
         << "\t"
         << "B"
         << "\t"
         << "C"
         << "\t"
         << "D"
         << "\t"
         << "E"
         << "\t"
         << "F" << endl;
    for (int i = 0; i < 13; i++)
    {
        cout << "Row " << i + 1 << "\t";
        for (int j = 0; j < 6; j++)
        {
            cout << seating[i][j] << "\t";
        }
        cout << endl;
    }
}
void askUser()
{
    while (true)
    {
        int classOption;
        cout << "Main Menu >>  Add ticket type and desired seats " << endl;
        cout << "---------------------" << endl;
        cout << "Enter Ticket Type (Class) " << endl;
        cout << "1- First (Class) " << endl;
        cout << "2- Business (Class)" << endl;
        cout << "3- Economy (Class) " << endl;

        cin >> classOption;
        if (classOption == 1)
        {
            classIdx(0, 2);
        }
        else if (classOption == 2)
        {
            classIdx(2, 7);
        }
        else if (classOption == 3)
        {
            classIdx(7, 13);
        }
        cout << "Enter desired seats Row " << endl;
        cin >> address;

        char row = address[0] - 1;
        char col = address[1];
        addressRow = row - '0';
        typeCasting(address);
        if (seating[addressRow][addressCol] != 'X')
        {
            seating[addressRow][addressCol] = 'X';
            cout << "Seat is Reserved" << endl;
            break;
        }
        else
        {
            cout << "Seat is Already Reserved" << endl;
        }
    }
}
void classIdx(int start, int stop)
{
    cout << "\t"
         << "A"
         << "\t"
         << "B"
         << "\t"
         << "C"
         << "\t"
         << "D"
         << "\t"
         << "E"
         << "\t"
         << "F" << endl;
    for (int i = start; i < stop; i++)
    {
        cout << "Row " << i + 1 << "\t";
        for (int j = 0; j < 6; j++)
        {
            cout << seating[i][j] << "\t";
        }
        cout << endl;
    }
}
void typeCasting(string address)
{
    if (address[1] == 'A')
    {
        addressCol = 0;
    }
    if (address[1] == 'B')
    {
        addressCol = 1;
    }
    if (address[1] == 'C')
    {
        addressCol = 2;
    }
    if (address[1] == 'D')
    {
        addressCol = 3;
    }
    if (address[1] == 'E')
    {
        addressCol = 4;
    }
    if (address[1] == 'F')
    {
        addressCol = 5;
    }
}
#include <iostream>
using namespace std;

struct date
{
    int day;
    int month;
    int year;
};

void initDate(date &d)
{
    d.day = 1;
    d.month = 1;
    d.year = 1990;
}

void printDateonConsole(const date &d)
{
    cout << "Date is " << d.day << "/" << d.month << "/" << d.year << endl;
}

void acceptDatefromConsole(date &d)
{
    cout << "Enter the day: ";
    cin >> d.day;
    cout << "Enter the month: ";
    cin >> d.month;
    cout << "Enter the year: ";
    cin >> d.year;
}

bool leapyear(const date &d)
{
    if (d.year % 4 == 0)
    {
        if (d.year % 100 == 0)
        {
            if (d.year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}

int Menu()
{
    int choice;
    cout << "\nWhich operation do you want to perform?" << endl;
    cout << "1. Initialize Date" << endl;
    cout << "2. Print Date" << endl;
    cout << "3. Accept Date" << endl;
    cout << "4. Check Leap Year" << endl;
    cout << "5. EXIT" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    date mydate;
    int choice;

    do
    {
        choice = Menu();
        switch (choice)
        {
        case 1:
            cout << "Initializing the Date..." << endl;
            initDate(mydate);
            break;
        case 2:
            cout << "Your Date is: " << endl;
            printDateonConsole(mydate);
            break;
        case 3:
            cout << "Accepting Date from Console..." << endl;
            acceptDatefromConsole(mydate);
            break;
        case 4:
            if (leapyear(mydate))
                cout << "The year " << mydate.year << " is a leap year." << endl;
            else
                cout << "The year " << mydate.year << " is not a leap year." << endl;
            break;
        case 5:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Wrong choice, please try again!" << endl;
        }
    } while (choice != 5);

    return 0;
}

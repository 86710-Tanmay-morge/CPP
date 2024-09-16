#include <iostream>
using namespace std;
class date
{
    int day;
    int month;
    int year;

public:
    date()
    {
        day = 1;
        month = 1;
        year = 2000;
    }
    date(int x, int y, int z)
    {
        if (x < 32 && x > 0)
        {
            day = x;
        }
        else
            x = 1;
        if (y < 13 && y > 0)
        {
            month = y;
        }
        else
            x = 1;
        if (z < 2101 && z > 1900)
        {
            year = z;
        }
        else
            x = 2000;
    }
    void displaydate()
    {
        cout << "Date is :" << day << "-" << month << "-" << year;
    }
};
class person
{
    string name;
    string address;
    date birthdate;

public:
    person(string a, string b, date c) : name(a), address(b), birthdate(c)
    {
    }
    void display()
    {
        cout << "Name:" << name << endl;
        cout << "Address:" << address << endl;
        birthdate.displaydate();
    }
};
int main()
{
    date birthdate(01, 10, 2022);
    person p1("Tanmay", "India", birthdate);
    p1.display();
}
#include <iostream>
using namespace std;
class date
{
    int day;
    int month;
    int year;

public:
    void add(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void print()
    {
        cout << "date is" << day << "/" << month << "/" << year << endl;
    }
};
class person
{
public:
    string name;
    string address;
    date birthdate;
    void addperson(string n, string addr, int d, int m, int y)
    {
        name = n;
        address = addr;
        void add(int d, int m, int y);
    }
    void displayperson()
    {
        cout << "name : " << name;
        cout << "Address : " << address;
        void print();
    }
};
class Employee : public person
{
public:
    int id;
    int sal;
    string dept;
    date DOJ;
    void addemployee(string n, string addr, int ide, int sala, string depta, int dd, int md, int yd, int d, int m, int y)
    {
        id = ide;
        sal = sala;
        depta = dept;
        addperson(n, addr, d, m, y);
        DOJ.add(dd, md, yd);
    }
    void displayemployee()
    {
        cout << "employee ID: " << id << ", His salary is" << sal << ",his department is" << dept << endl;
        displayperson();
        cout << "his date of joining is" << endl;
        DOJ.print();
    }
};
int main()
{
    Employee emp;
    emp.addemployee("Tanmay", "Shrirampur", 101, 100000, "sales", 10, 5, 2024, 3, 4, 2003);
    emp.displayemployee();
    return 0;
}
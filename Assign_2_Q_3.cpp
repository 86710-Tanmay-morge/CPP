#include <iostream>
using namespace std;

namespace NStudent
{
    int rollno;
    int marks;
    string name;
}

void display()
{
    cout << NStudent::name << " of roll no " << NStudent::rollno << " has marks " << NStudent::marks << endl;
}

void accept()
{
    cout << "NAME: ";
    cin.ignore();
    getline(cin, NStudent::name);
    cout << "ROLL NO: ";
    cin >> NStudent::rollno;
    cout << "MARKS: ";
    cin >> NStudent::marks;
}

int menu()
{
    int num;
    cout << "1 TO ACCEPT" << endl;
    cout << "2 TO DISPLAY" << endl;
    cout << "PRESS 3 TO CONTINUE OR 4 TO EXIT" << endl;
    cin >> num;
    return num;
}

int main()
{
    int num;

    do
    {
        num = menu();

        if (num == 1)
        {
            accept();
        }
        else if (num == 2)
        {
            display();
        }
        else if (num == 4)
        {
            exit(0);
        }

    } while (num != 4);

    return 0;
}

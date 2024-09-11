#include <iostream>
using namespace std;

class Student
{
private:
    int Roll_no;
    string name;
    int Marks;

public:
    void initStudent()
    {
        this->Roll_no = 0;
        this->name = " ";
        this->Marks = 0;
    }
    void printStudentonConsole()
    {
        cout << "Student name is " << name << ".his rollno is " << Roll_no << "and his marks are" << Marks << "." << endl;
    }
    void acceptStudentfromConsole()
    {
        cout << "Enter the students name: ";
        cin >> name;
        cout << "Enter his marks: ";
        cin >> Marks;
        cout << "Enter the rollno: ";
        cin >> Roll_no;
    }

    static int Menu()
    {
        int choice;
        cout << "\nWhich operation do you want to perform?" << endl;
        cout << "1. Initialize Student" << endl;
        cout << "2. Print Student data" << endl;
        cout << "3. Accept student Data" << endl;
        cout << "4. EXIT" << endl;
        cin >> choice;
        return choice;
    }
};

int main()
{
    Student s;
    int choice;

    do
    {
        choice = s.Menu();
        switch (choice)
        {
        case 1:
            s.initStudent();
            cout << "Initializing the Student..." << endl;

            break;
        case 2:
            cout << "Your Data is: " << endl;
            s.printStudentonConsole();
            break;
        case 3:
            cout << "Accepting Data from Console..." << endl;
            s.acceptStudentfromConsole();
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
            break;

        default:
            cout << "Wrong choice, please try again!" << endl;
        }
    } while (choice != 4);

    return 0;
}

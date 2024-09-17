#include <iostream>
#include <string>
using namespace std;

class Student
{
    static int rollCounter;
    string name;
    char gender;
    int rollNumber;
    float marks[3];

public:
    Student()
    {
        rollNumber = ++rollCounter;
    }

    void acceptDetails()
    {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter gender (M/F): ";
        cin >> gender;
        cout << "Enter marks for 3 subjects:\n";
        for (int i = 0; i < 3; i++)
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void printDetails() const
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Gender: " << gender << endl;
        cout << "Percentage: " << calculatePercentage() << "%" << endl;
    }

    string getName() const
    {
        return name;
    }

    float calculatePercentage() const
    {
        float total = 0;
        for (int i = 0; i < 3; i++)
        {
            total += marks[i];
        }
        return (total / 3);
    }

    int getRollNumber() const
    {
        return rollNumber;
    }
};

int Student::rollCounter = 0;

int searchStudent(Student *arr[], int size, const string &name)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != nullptr && arr[i]->getName() == name)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Student *arr[5];
    int count = 0;
    int choice;

    while (true)
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Accept Student Details\n";
        cout << "2. Print All Student Details\n";
        cout << "3. Search Student by Name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count < 5)
            {
                arr[count] = new Student();
                arr[count]->acceptDetails();
                count++;
            }
            else
            {
                cout << "Maximum number of students reached.\n";
            }
            break;

        case 2:
            for (int i = 0; i < count; i++)
            {
                cout << "\nStudent " << i + 1 << " details:\n";
                arr[i]->printDetails();
            }
            break;

        case 3:
        {
            string searchName;
            cout << "Enter student name to search: ";
            cin >> searchName;
            int index = searchStudent(arr, count, searchName);
            if (index != -1)
            {
                cout << "Student found at index " << index << ":\n";
                arr[index]->printDetails();
            }
            else
            {
                cout << "Student not found.\n";
            }
            break;
        }

        case 4:
            for (int i = 0; i < count; i++)
            {
                delete arr[i];
            }
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    }
}

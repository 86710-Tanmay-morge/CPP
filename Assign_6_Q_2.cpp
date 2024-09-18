#include <iostream>
using namespace std;

class employee
{
    int id;
    double salary;

public:
    employee() {}
    employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;
    }
    virtual void accept()
    {
        cout << "Enter Emp_Id:" << endl;
        cin >> id;
        cout << "Enter Salary:" << endl;
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Emp_Id: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : virtual public employee
{
public:
    double bonus;
    Manager() {}
    Manager(int id, double salary, double bonus) : employee(id, salary)
    {
        this->bonus = bonus;
    }
    void accept() override
    {
        employee::accept();
        acceptmanager();
    }
    void display() override
    {
        employee::display();
        displaymanager();
    }
    void acceptmanager()
    {
        cout << "Enter Bonus:" << endl;
        cin >> bonus;
    }
    void displaymanager()
    {
        cout << "Bonus: " << bonus << endl;
    }
};

class Salesman : virtual public employee
{
public:
    double commission;
    Salesman() {}
    Salesman(int id, double salary, double commission) : employee(id, salary)
    {
        this->commission = commission;
    }
    void accept() override
    {
        employee::accept();
        acceptsalesman();
    }
    void display() override
    {
        employee::display();
        displaysalesman();
    }
    void acceptsalesman()
    {
        cout << "Enter Commission:" << endl;
        cin >> commission;
    }
    void displaysalesman()
    {
        cout << "Commission: " << commission << endl;
    }
};

class Salesmanager : public Salesman, public Manager
{
public:
    Salesmanager() {}
    Salesmanager(int id, double salary, double bonus, double commission)
        : employee(id, salary), Salesman(id, salary, commission), Manager(id, salary, bonus) {}

    void accept() override
    {
        employee::accept();
        acceptmanager();
        acceptsalesman();
    }
    void display() override
    {
        employee::display();
        displaymanager();
        displaysalesman();
    }
};

int main()
{
    employee *e = new Salesman;
    e->accept();
    e->display();

    employee *p = new Salesmanager;
    p->accept();
    p->display();

    delete e;
    delete p;

    return 0;
}

#include <iostream>
using namespace std;

class ToolBooth
{

    unsigned int totalCars;
    unsigned int payingCars;
    unsigned int unPayingCars;
    int totalAmount;

public:
    ToolBooth()
    {
        totalCars = 0;
        payingCars = 0;
        unPayingCars = 0;
        totalAmount = 0;
    }

    void payingCar()
    {
        totalCars++;
        payingCars++;
        totalAmount += 50;
    }
    void unPayingCar()
    {
        totalCars++;
        unPayingCars = totalCars - payingCars;
    }

    void display()
    {
        cout << "Total Cars :" << totalCars << endl;
        cout << "Paying Cars :" << payingCars << endl;
        cout << "Non paying Cars :" << unPayingCars << endl;
        cout << "Total Amount:" << totalAmount << endl;

        cout << totalCars << endl;
    }
};

int main()
{
    ToolBooth t1;
    t1.payingCar();
    t1.payingCar();
    t1.unPayingCar();
    t1.payingCar();
    t1.unPayingCar();
    t1.payingCar();
    t1.unPayingCar();
    t1.display();
}
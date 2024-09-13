#include <iostream>
using namespace std;

class Address
{
private:
    string Building;
    string street;
    string city;
    int pin;

public:
    Address()
    {
        Building = "";
        street = "";
        city = "";
        pin = 0;
    }

    Address(string bldg, string str, string cty, int p)
    {
        Building = bldg;
        street = str;
        city = cty;
        pin = p;
    }

    string getBuilding() { return Building; }
    string getStreet() { return street; }
    string getCity() { return city; }
    int getPin() { return pin; }

    void setBuilding(string bldg) { Building = bldg; }
    void setStreet(string str) { street = str; }
    void setCity(string cty) { city = cty; }
    void setPin(int p) { pin = p; }

    void accept()
    {
        cout << "Enter Building: ";
        cin >> Building;
        cout << "Enter Street: ";
        cin >> street;
        cout << "Enter City: ";
        cin >> city;
        cout << "Enter Pin: ";
        cin >> pin;
    }

    void display()
    {
        cout << "Building: " << Building << ", Street: " << street
             << ", City: " << city << ", Pin: " << pin << endl;
    }
};

int main()
{
    Address addr1;

    addr1.accept();

    addr1.display();

    Address addr2("Sunshine Apartments", "Sangamner street", "Shrirampur", 413709);

    addr2.display();

    addr1.setBuilding("Moonlight Apartments");
    addr1.setStreet("Church Street");
    addr1.setCity("goa");
    addr1.setPin(507415);

    cout << "Updated Address - Building: " << addr1.getBuilding()
         << ", Street: " << addr1.getStreet()
         << ", City: " << addr1.getCity()
         << ", Pin: " << addr1.getPin() << endl;

    return 0;
}
